external swap_pair_ref : (string * string) ref -> unit = "caml_swap_pair_ref"

let () = let k = ref ("Wrong", "Foo") in swap_pair_ref k; print_endline (fst (!k))
