#!/bin/sh

function run () {
    clang++ -std=c++98 -Wall -Wextra -Werror test.cpp -D ns=ft -o ft
    clang++ -std=c++98 -Wall -Wextra -Werror test.cpp -D ns=std -o std

    ./ft $1 > ft_test
    ./std $1 > std_test

    diff ft_test std_test
}

run 50