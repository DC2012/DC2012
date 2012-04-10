#!/bin/bash

if [[ $(cat /etc/issue) == *Arch* ]] 
then
    QM="qmake"
else
    QM="qmake-qt4"
fi

command -v $QM >/dev/null 2>&1 || { echo >&2 "You need to install qt-devel package to compile this project."; exit 1; }

cd ../../
rm *.o DC2012 servermain Makefile ui_*.h *.pro
$QM -project
mv $(find . -name "*.pro") DC2012.pro
grep -v 'src/server' DC2012.pro > tmp.pro
mv tmp.pro DC2012.pro
sed -i '4iQT += phonon' DC2012.pro
$QM
make -j4

if [[ $? -ne 0 ]]
then
    exit
fi

g++ src/net/*.cpp src/player/*.cpp src/server/*.cpp -lpthread -lrt  -o servermain

if [[ $? -eq 0 ]]
then
    echo -e "\nProject Compiled! Go to the root of the project then run ./DC2012\n"
fi
