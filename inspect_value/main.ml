external print_info : 'a -> unit = "caml_print_information"

type recref = EmptyRef | RecRef of recref ref

type mylist = Nil | Cons of int * mylist
type 'a box = Box of 'a

let () = let k1 = ref EmptyRef in let k2 = ref (RecRef k1) in k1 := RecRef k2;
                  print_info k2;
                  print_info [1,2,3,4,5,1337];
                  print_info (fun x -> x);
                  print_info 13.37;
                  print_info "Hello, World!";
                  print_info (Some (Some (Some ())));
                  print_info 42;
                  print_info (ref 42);
                  print_info (Box 42);
                  print_info (Cons (1, (Cons (2, (Cons (42, Nil))))))
