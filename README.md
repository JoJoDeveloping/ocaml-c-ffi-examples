# OCaml FFI examples

## How to build?

Simply run `make`

## What are the examples
* `function_callaround`: Passing a function to C and calling it from there
* `inspect_value`: DFS on the heap, starting at some block. Also prints useful information about the internal makeup of objects
* `red_blue_tags`: Example 98 from the [Semantics Lecture Notes](https://cms.sic.saarland/semantics_ws2122/dl/4/Lecture_Notes_04.02..pdf)
* `string_builder`: Modifying OCaml `bytes` in place since they are mutable
* `swap_pair_ref`: Modify a reference to a pair in-place
* `swap_pair_simple`: Compute `fun (a,b) -> (b,a)` in C