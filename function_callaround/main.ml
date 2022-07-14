external callme : int ref -> (unit -> unit) -> unit = "caml_callme"

let () = let r = ref 0 in callme r (fun () -> r := 42)