#!/usr/bin/bash
# Maasahiro Yoshida
# SE3377.002case 
echo setting TEMPDIR environment variable to /scratch
TMPDIR=/scratch; export TMPDIR
echo Compiling file1.cc
g++ -c file1.cc 
echo Compiling file12.cc
g++ -c file12.cc
echo Linking files to create executable hw1
g++ -o hw1 file1.o file12.o
echo Done
