#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Safety / Correctness:
 * to is a value of kind byte, which is mutable
 * from is a string, also of kind byte, but immutable
 * at is an integer
 
 the asserts hold since they are part of the precondition
 If we would read out-of-bounds, we abort.
 Otherwise, our read remains within the bounds of already allocated memory.
 Thus, the accesses in line 34 are safe, since we can get mutable access to these,
 since we have mutable access to the 'to' value and remain within the bounds of string_length()
*/
value caml_string_put(value to, value from, value at)
{
  CAMLparam3 (to, from, at);
  assert(Is_block(to));
  assert(Tag_val(to) == String_tag);
  assert(Is_block(from));
  assert(Tag_val(from) == String_tag);
  assert(Is_long(at));
  uintnat idx = Long_val(at);
  mlsize_t to_len = caml_string_length(to);
  mlsize_t from_len = caml_string_length(from);
  if (idx + from_len > to_len) {
    CAMLreturn(Val_false);
  }
  for (mlsize_t i = 0; i < from_len; i++) {
    Byte_u(to, i + idx) = Byte_u(from, i);
  }
  CAMLreturn (Val_true);
}

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