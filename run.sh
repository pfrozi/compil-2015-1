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

echo ------------------------------------------------------------
echo 1o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/00.iks > ./ilocs/00.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/00.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/00.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 2o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/01.iks > ./ilocs/01.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/01.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/01.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 3o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/02.iks > ./ilocs/02.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/02.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/02.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 4o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/03.iks > ./ilocs/03.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/03.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/03.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 5o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/04.iks > ./ilocs/04.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/04.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/04.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 6o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/05.iks > ./ilocs/05.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/05.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/05.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 7o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/06.iks > ./ilocs/06.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/06.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/06.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 8o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/07.iks > ./ilocs/07.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/07.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/07.iloc
echo ----------------------
read -n1 -r -p "Press any key to continue..." key
echo ------------------------------------------------------------
echo 9o TESTE
echo ----------------------
echo EXECUTANDO
echo ----------------------
./main < ./tests/e5/input/08.iks > ./ilocs/08.iloc
echo ----------------------
echo AMARELA CODE
echo ----------------------
cat ./tests/e5/input/08.iks 
echo ----------------------
echo ILOC CODE
echo ----------------------
cat ./ilocs/08.iloc
echo ----------------------

echo FIM!
