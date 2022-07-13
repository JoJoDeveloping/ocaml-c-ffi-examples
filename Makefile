.PHONY: all

all: swap_pair_simple/bin swap_pair_ref/bin inspect_value/bin string_builder/bin function_callaround/bin red_blue_tags/bin

clean:
	find . -name '*.cmi' -delete
	find . -name '*.cmx' -delete
	find . -name '*.o' -delete
	find . -name 'bin' -delete


swap_pair_simple/bin: swap_pair_simple/main.ml swap_pair_simple/swap_pair_simple.c
	ocamlopt -o swap_pair_simple/bin swap_pair_simple/main.ml swap_pair_simple/swap_pair_simple.c

swap_pair_ref/bin: swap_pair_ref/main.ml swap_pair_ref/main.c
	ocamlopt -o swap_pair_ref/bin swap_pair_ref/main.ml swap_pair_ref/main.c

inspect_value/bin: inspect_value/main.ml inspect_value/main.c
	ocamlopt -o inspect_value/bin inspect_value/main.ml inspect_value/main.c

string_builder/bin: string_builder/main.ml string_builder/main.c
	ocamlopt -o string_builder/bin string_builder/main.ml string_builder/main.c

function_callaround/bin: function_callaround/main.ml function_callaround/main.c
	ocamlopt -o function_callaround/bin function_callaround/main.ml function_callaround/main.c

red_blue_tags/bin: red_blue_tags/main.ml red_blue_tags/main.c
	ocamlopt -o red_blue_tags/bin red_blue_tags/main.ml red_blue_tags/main.c
