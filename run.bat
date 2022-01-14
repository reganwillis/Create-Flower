@ECHO off
:: Compiling Randomize Pixel Art

:: Compile modules individually
:: -Wall - turn on most warnings
:: -c - output an object file
:: -I<include path> - specify an include directory
CALL g++ -Wall -c main.cpp -IC:\SFML-gcc\SFML-2.5.1\include

:: Link modules into single executable
:: -L<library path> - specify a lib directory
CALL g++ -Wall main.o -o randomize-pixel-art -LC:\SFML-gcc\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system

:: Run executable
::CALL randomize-pixel-art.exe