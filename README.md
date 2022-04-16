# Create Flower
This program takes in 4 pieces of pixel art flowers with the "basic" color scheme. It randomly choses 1 style of flower weighted as "common", "uncommon", "rare", and "ultra rare".

After the base flower has been chosen, a random color scheme will be mapped onto it. For "common", "uncommon", and "rare" flowers, the random color scheme will be mapped onto the "basic" palette. For "ultrarare" flowers, each pixel that fills in the flower will be a randomly generated color.

![common little flower stage 3](https://github.com/reganwillis/Create-Flower/blob/58f38bdf95587115ee7064fcfbfc95532e83bfc9/Input/little-flower-stage-3-common.png)

## Libraries
* [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/)

## Usage
### With Little Flower
This repository is designed to be used in the [Little Flower repository](https://github.com/reganwillis/Little-Flower) as a submodule. Every time a new game is started (on game open and after pressing the restart button) a new flower will be created.

### Independent Usage
Clone this repository and use the batch script instructions below to create and run the EXE. All libraries will need to be downloaded and all .dll files from SFML/bin need to be added to the folder where the EXE file will be executed. This project is set up to work with Little Flower's folder structure, so it will pull images from `Create-Flower/Input/little-flower-stage-<0-3>-<rarity>.png` and save the output images to `Create-Flower/Output/little-flower-stage-<0-3>.png`. Once `create-flower.exe` is created move it up a directory so that it can follow the path, or modify the paths in the code.

It will also save the final image to `../Create-Tezos-NFT/dist/little-flower-nft.jpg` to be used in Create-Tezos-NFT. It will save the output JSON attributes as a text file to `../Create-Tezos-NFT/dist/attributes.txt` with the format:

    {
        "rarity": "",
        "rgb_values": {
            "stem": "",
            "stem_detail": "",
            "center": "",
            "center_detail": "",
            "petals": "",
            "petals_detail": "",
            "eye": "",
            "pupil": "",
            "petals_background": "",
            "petals_foreground": ""
        }
    }
where "rarity" is "common", "uncommon", "rare", or "ultrarare" and the values for all the rgb_values attributes are in the format "(<0-255>, <0-255>, <0-255>)". These paths will also have to be modified to access them when using the project independently.

#### Batch Script
Use the command `run` in the windows command line to run the batch script. This will run the commands below:

compile the program:
    
    g++ -Wall -c src\CreateFlower.h -IC:\SFML-gcc\SFML-2.5.1\include
    g++ -Wall -c src\CreateFlower.cpp -o src\CreateFlower.o -IC:\SFML-gcc\SFML-2.5.1\include
    g++ -Wall -c src\main.cpp -o src\main.o -IC:\SFML-gcc\SFML-2.5.1\include
creates: `src\main.o`, `src\CreateFlower.o`

link the compiled file to the SFML libraries

    g++ -Wall src\main.o src\CreateFlower.o -o create-flower -LC:\SFML-gcc\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
creates: `create-flower.exe`

run new app:
`create-flower.exe`

#### Usage in Another Project
The file `src/main.cpp` shows how to include the class and use it in a main method. Run the code in a directory above this one, then access the files in the `./Output` folder to use in a project.

## Color Mapping
The color palettes are defined with SFML colors in the function `CreateFlower::initColorPalettes()`. The Palette type has attributes that are named according to the colors in the pixel art flowers: `stem`, `stem_detail`, `center`, `center_detail`, `petals`, `petals_detail`, `eye`, `pupil`, `petals_background`, and `petals_foreground`. The "basic" color palette match the color palette of the input images.