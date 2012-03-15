#!/bin/bash

if [[ $(cat /etc/issue) == *Arch* ]] 
then
    QM="qmake"
else
    QM="qmake-qt4"
fi

rm -rf ~/GameTest
mkdir -p ~/GameTest/graphics
mkdir -p ~/GameTest/graphics/sprites
cp ../graphics/gamewindow.* ~/GameTest/graphics
cp ../main.cpp ~/GameTest
cp ../../sprites/tileLand1.png ~/GameTest/graphics/sprites
cp ../../sprites/tileWater1.png ~/GameTest/graphics/sprites
cp ../../sprites/spriteShip1.png ~/GameTest/graphics/sprites
cp ../../sprites/spriteCursor.png ~/GameTest/graphics/sprites
cd ~/GameTest
sed -ie 's/\.\.\/\.\.\//graphics\//g' graphics/gamewindow.cpp 
$QM -project
$QM
make
./GameTest
