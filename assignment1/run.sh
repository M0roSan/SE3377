#!/usr/bin/bash
#  Masahiro Yoshida 
#   SE3377.002
echo Running 'hw1' with 0 arguments:
./hw1 >> stdout.txt 2>> stderr.txt
echo -e "\t" stdout appended to stdout.txt
echo -e "\t" stderr appended to stderr.txt
echo

echo Running 'hw1' with 1 argument:
./hw1 abc >> stdout.txt 2>> stderr.txt
echo -e "\t" stdout appended to stdout.txt
echo -e "\t" stderr appended to stderr.txt
echo

echo Running 'hw1' with 5 arguments:
./hw1 a b c d e >> stdout.txt 2>> stderr.txt
echo -e "\t" stdout appended to stdout.txt
echo -e "\t" stderr apeended to stderr.txt

