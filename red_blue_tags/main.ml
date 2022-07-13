type red
type blue

external make_red : unit -> red = "caml_make_red"
external make_blue : unit -> blue = "caml_make_blue"
external check_red_blue : red -> blue -> bool = "caml_check_red_blue" (* Change types to make it crash *)

let b = let r = make_red () in let b = make_blue () in print_endline (if check_red_blue r b then "true" else "false")