#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int i = 0;

value caml_make_red(value unit) {
  CAMLparam1 (unit);
  CAMLlocal1 (res);
  res = caml_alloc(1, 0);
  i++;
  Store_field(res, 0, Val_long(i));
  CAMLreturn(res);
}

value caml_make_blue(value unit) {
  CAMLparam1 (unit);
  CAMLlocal1 (res);
  res = caml_alloc(1, 0);
  i++;
  Store_field(res, 0, Val_long(i));
  CAMLreturn(res);
}

/**
 * The semantic types of red and blue are such that they can never contain the same value.
 * Thus if one is red and one is blue, the assert can never be triggered, and this is semantically well-typed.
 */
value caml_check_red_blue(value red, value blue) {
  CAMLparam2 (red, blue);
  int red_v = Long_val(Field(red, 0));
  int blue_v = Long_val(Field(blue, 0));
  assert(red_v != blue_v);
  if (red_v != blue_v) {
    CAMLreturn(Val_true);
  } else {
    CAMLreturn(Val_false);
  }
}