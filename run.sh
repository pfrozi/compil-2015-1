#!/bin/bash
echo Tentando remover pasta build...
rm -R -f build
echo Criando pasta build...
mkdir build
cd build/
echo Realizando MAKE...
cmake -DETAPA_1=OFF -DETAPA_2=OFF -DETAPA_3=OFF -DETAPA_4=OFF -DETAPA_5=ON ..
make
mkdir ilocs
echo ----------------------
echo 1o TESTE
echo ----------------------
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/00.iks 
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/00.iks > ./ilocs/00.iloc
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/00.iloc
echo ----------------------
echo FIM!
