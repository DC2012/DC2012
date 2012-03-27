#!/bin/bash

if [[ $(cat /etc/issue) == *Arch* ]] 
then
    QM="qmake"
else
    QM="qmake-qt4"
fi

command -v $QM >/dev/null 2>&1 || { echo >&2 "You need to install qt-devel package to compile this project."; exit 1; }

cd ../../
rm *.o ui_*.h *.pro DC2012
$QM -project
$QM
make

if [[ $? -eq 0 ]]
then
    echo -e "\nProject Compiled! Go to the root of the project then run ./DC2012\n"
fi
