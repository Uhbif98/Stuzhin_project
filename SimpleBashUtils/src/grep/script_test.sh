#!/bin/bash
FILE_TXT=("text.txt")
FILE2_TXT=("text2.txt")
OPTIONS1=("-i" "-v" "-c" "-l" "-n" "-h" "-s")
OPTIONS1_1=("i" "v" "c" "l" "n" "h" "s")
OPTIONS2=("h" "[0-9]")

clang-format -n *.c
cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]}; 
            do
                valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ./s21_grep $option1 $option2 $first_file $second_file
            done
        done
    done    


for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]}; do
            for option2 in ${OPTIONS2[@]}; 
                do
                    ./s21_grep $option1 $option2 $first_file $second_file > res1.txt
                    grep $option1 $option2 $first_file $second_file > res2.txt
                    diff res1.txt res2.txt
                    if [ $? -eq 0 ]; then
                        echo "$option1 $option2 $first_file $second_file TEST COMPLIT"
                    else
                        echo "$option1 $option2 $first_file $second_file TEST FALSE"
                    fi
                done
            done
        done
    done

for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]}; do
            for option2 in ${OPTIONS1_1[@]}; do
                    ./s21_grep $option1$option2 "h" $first_file $second_file > res1.txt
                    grep $option1$option2 "h" $first_file $second_file > res2.txt
                    diff res1.txt res2.txt
                    if [ $? -eq 0 ]; then
                        echo "$option1$option2 h $first_file $second_file TEST COMPLIT"
                    else
                        echo "$option1$option2 h $first_file $second_file TEST FALSE"
                    fi
                done
            done
        done
    done


for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]}; do
            for option2 in ${OPTIONS2[@]}; do
                    ./s21_grep $option1 -e $option2 $first_file $second_file > res1.txt
                    grep $option1  -e $option2 $first_file $second_file > res2.txt
                    diff res1.txt res2.txt
                    if [ $? -eq 0 ]; then
                        echo "$option1 -e $option2 $first_file $second_file TEST COMPLIT"
                    else
                        echo "$option1 -e  $option2 $first_file $second_file TEST FALSE"
                    fi
                done
            done
        done
    done

for first_file in ${FILE_TXT[@]}; do
    for second_file in ${FILE2_TXT[@]}; do
        for option1 in ${OPTIONS1[@]}; do
            for option2 in ${OPTIONS2[@]}; do
                    ./s21_grep $option1 -f reg_test.txt $first_file $second_file > res1.txt
                    grep $option1  -f reg_test.txt $first_file $second_file > res2.txt
                    diff res1.txt res2.txt
                    if [ $? -eq 0 ]; then
                        echo "$option1 -f reg_test.txt $first_file $second_file TEST COMPLIT"
                    else
                        echo "$option1 -f reg_test.txt $first_file $second_file TEST FALSE"
                    fi
                done
            done
        done
    done