external print_bytes : bytes -> unit = "caml_string_print"
external put_bytes : bytes -> string -> int -> bool = "caml_string_put"

let () = let buf = (Bytes.of_string "Hello, World!") in
         print_bytes buf;
         if put_bytes buf "Foo!!" 8 then (print_endline "OK"; print_bytes buf)
                                    else print_endline "Err!"