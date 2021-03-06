#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * The value p is a string or a byte, and we do not need mutable access.
 * We only read from it, and remain within bounds.
 */
value caml_string_print(value p)
{
  CAMLparam1 (p);
  assert(Is_block(p));
  assert(Tag_val(p) == String_tag);
  mlsize_t length = caml_string_length (p);
  fwrite(Bp_val(p), length, 1, stdout);
  fwrite("\n", 1, 1, stdout);
  fflush(stdout);
  CAMLreturn (Val_unit);
}

/**
 * Correctness: p is a function of type unit -> string
*/
value caml_callme(value ref, value p)
{
  CAMLparam2 (ref, p);
  printf("Before: %ld\n", Long_val(Field(ref, 0)));
  caml_callback(p, Val_unit);
  printf("After: %ld\n", Long_val(Field(ref, 0)));
  CAMLreturn (Val_unit);
}