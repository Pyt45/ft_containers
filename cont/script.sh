#!/bin/sh

function run () {
	g++ test.cpp -D ns=ft -o ft
	g++ test.cpp -D ns=std -o std

	./ft $1 > ft_test
	./std $1 > std_test

	diff ft_test std_test
}

run 50