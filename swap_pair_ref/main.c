#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
value caml_swap_pair_ref(value p)
{
  CAMLparam1 (p);
  CAMLlocal4 (result, deref, fst, snd);
  result = caml_alloc (2, 0);
  deref = Field(p, 0);
  fst = Field(deref, 0);
  snd = Field(deref, 1);

  caml_modify(&Field(result, 0), snd);
  caml_modify(&Field(result, 1), fst);
  caml_modify(&Field(p, 0), result);
  CAMLreturn (Val_unit);
}