@ECHO off
:: Compiling Randomize Pixel Art

:: Compile modules individually
:: -Wall - turn on most warnings
:: -c - output an object file
:: -I<include path> - specify an include directory
CALL g++ -Wall -c src\CreateFlower.h -IC:\SFML-gcc\SFML-2.5.1\include
CALL g++ -Wall -c src\CreateFlower.cpp -o src\CreateFlower.o -IC:\SFML-gcc\SFML-2.5.1\include
CALL g++ -Wall -c src\main.cpp -o src\main.o -IC:\SFML-gcc\SFML-2.5.1\include

:: Link modules into single executable
:: -L<library path> - specify a lib directory
CALL g++ -Wall src\main.o src\CreateFlower.o -o create-flower -LC:\SFML-gcc\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system

:: Run executable
CALL create-flower.exe