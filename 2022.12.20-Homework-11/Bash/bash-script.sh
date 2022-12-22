#!/bin/bash

cd /
cd d/proga/Programmirovaniye-2022-23/2022.12.20-Homework-11/Bash
#pwd
#ls -l
./1.exe &
./2.exe &
./3.exe &
wait
if cmp OutputOrig1.txt OutputCopy1.txt
then echo "1 coincide"
fi

if cmp OutputOrig2.txt OutputCopy2.txt
then echo "2 coincide"
fi

if cmp OutputOrig3.txt OutputCopy3.txt
then echo "3 coincide"
fi
sleep 5