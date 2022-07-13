external swap_pair_simple : int * string -> string * int = "caml_swap_pair_simple"

let () = print_endline (fst (swap_pair_simple (42, "Foo")))
