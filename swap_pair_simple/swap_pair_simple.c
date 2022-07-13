#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <stdio.h>
value caml_swap_pair_simple(value p)
{
  CAMLparam1 (p);
  CAMLlocal3 (result, fst, snd);
  result = caml_alloc (2, 0);
  fst = Field(p, 0);
  snd = Field(p, 1);

  caml_modify(&Field(result, 0), snd);
  caml_modify(&Field(result, 1), fst);
  CAMLreturn(result);
}