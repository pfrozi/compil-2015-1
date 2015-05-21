#!/bin/bash
echo Tentando remover pasta build...
rm -R -f build
echo Criando pasta build...
mkdir build
cd build/
echo Realizando MAKE...
cmake -DETAPA_1=OFF -DETAPA_2=OFF -DETAPA_3=OFF -DETAPA_4=OFF -DETAPA_5=ON ..
make
echo FIM!
