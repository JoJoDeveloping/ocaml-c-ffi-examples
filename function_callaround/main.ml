external callme : (unit -> string) -> unit = "caml_callme"

let () = callme (fun () -> "Hello, World!")