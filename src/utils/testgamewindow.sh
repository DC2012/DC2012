#!/bin/bash

if [[ $(cat /etc/issue) == *Arch* ]] 
then
    QM="qmake"
else
    QM="qmake-qt4"
fi

rm -rf ~/GameTest
mkdir -p ~/GameTest/graphics
cp ../graphics/gamewindow.* ~/GameTest/graphics
cp ../main.cpp ~/GameTest
cd ~/GameTest
$QM -project
$QM
make
