#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
value caml_swap_pair_ref(value p)
{
  CAMLparam1 (p);
  CAMLlocal2 (deref, tmp);
  printf("Ocaml p     Value tag %hhx size %ld ptr 0x%lx\n", Tag_val(p), Wosize_val(p), p);
  deref = Field(p, 0);
  printf("Ocaml deref Value tag %hhx size %ld ptr 0x%lx\n", Tag_val(deref), Wosize_val(deref), p);
  tmp = Field(deref, 0);
  caml_modify(&Field(deref, 0), Field(deref, 1));
  caml_modify(&Field(deref, 1), tmp);
  CAMLreturn (Val_unit);
}