#!/bin/bash

if [[ $(cat /etc/issue) == *Arch* ]] 
then
    QM="qmake"
else
    QM="qmake-qt4"
fi

rm -rf ~/GameTest
cp -R ../../ ~/GameTest

cd ~/GameTest
rm src/env/*
rm -rf src/env/ClientShell
rm -rf src/player

cp src/graphics/gamewindow.* .
rm src/graphics/*
mv gamewindow.* src/graphics/

$QM -project
$QM
make
./GameTest
cd ..
