#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <stdio.h>

void print_indent(int ind) {
  for (int i = 0; i < ind; i++) {
    printf("  ");
  }
}

struct list {
  value seen;
  struct list* next;
};

int list_contains(struct list* list, value val) {
  while(list) {
    if (list->seen == val) return 1;
    list = list->next;
  }
  return 0;
}

/**
 * Correctness / Safety:
 *   If the value is a long, we can just print it.
 *   Otherwise, if it is a block / tuple of kind 0, we recursively scan its children.
 *   If it does not have tag 0, we just print them.
 *   In particular, we stay within memory bounds because we only ever access up to the size limit.
 */
void print_information(value p, int indent, struct list* seen) {
  CAMLparam1(p);
  CAMLlocal1(tmp);
  if (list_contains(seen, p)) {
    print_indent(indent);
    if (Is_long(p)) {
      printf("Circularity: Number %ld already seen!\n", Long_val(p));
    } else if (Is_block(p)) {
      printf("Circularity: Block 0x%lx already seen!\n", p);
    } else {
      printf("Circularity: Unknown %lx already seen!\n", p);
    }
    CAMLreturn0;
  }
  struct list next;
  next.seen = p;
  next.next = seen;
  if (Is_long(p)) {
    intnat number = Long_val(p);
    print_indent(indent);
    printf("Number: %ld\n", number);
  } else if (Is_block(p)) {
    print_indent(indent);
    unsigned char tag = Tag_val(p);
      if ((unsigned)tag < (unsigned)No_scan_tag) {
      mlsize_t size = Wosize_val(p);
      printf("Block @ 0x%lx: Tag = %hhu (tuple), Size = %lu\n", p, tag, size);
      for (mlsize_t idx = 0; idx < size; idx++) {
        tmp = Field(p, idx); 
        if (tag != 0) {
          print_indent(indent + 1);
          printf("Field: 0x%08lx\n", (tmp));
        } else {
          print_information(tmp, indent + 1, &next);
        }
      }
    } else {
      mlsize_t size = Bosize_val(p);
      printf("Block @ 0x%lx: Tag = %hhu (bytes), Size = %lu\n", p, tag, size);
      for (mlsize_t idx = 0; idx < size; idx++) {
        unsigned char byte = Byte_u(p, idx);
        print_indent(indent + 1);
        printf("Byte %lu: %hhu = %hhx\n", idx, byte, byte);
      }
    }
  } else {
    print_indent(indent);
    printf("Unknown %lx\n", p);
  }
  CAMLreturn0;
}

value caml_print_information(value p)
{
  CAMLparam1 (p);
  print_information(p, 0, NULL);
  CAMLreturn (Val_unit);
}