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


for f in tests/e5/input/*; do
    tempfile="${f##*/}"
    filename="${tempfile%.*}"

    echo ------------------------------------------------------------
    echo TESTE: $filename
    echo ----------------------
    echo EXECUTANDO
    echo ----------------------
    ./main < ./$f > ./ilocs/$filename.iloc
    echo ----------------------
    echo AMARELA CODE
    echo ----------------------
    cat ./$f 
    echo
    echo ----------------------
    echo ILOC CODE
    echo ----------------------
    cat ./ilocs/$filename.iloc
    echo
    echo ----------------------
    read -n1 -r -p "Press any key to continue..." key
    echo
done

echo FIM!
