#!/bin/bash
FILE_TXT=("text.txt")
FILE2_TXT=("text2.txt")
OPTIONS1=("-b" "-n" "-s" "-e" "-t" "--number-nonblank" "--number" "--squeeze-blank")

clang-format -n *.c *.h
cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]};
            do
                valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ./s21_cat $option1 $first_file $second_file
            done
        done
    done

for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]};
            do
                ./s21_cat $option1 $first_file $second_file > res1.txt
                cat $option1 $first_file $second_file > res2.txt
                diff res1.txt res2.txt
                if [ $? -eq 0 ]; then
                    echo "$option1 $first_file $second_file TEST COMPLIT"
                else
                    echo "$option1 $first_file $second_file TEST FALSE"
                fi
            done
        done
    done