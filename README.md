# Create Flower
This program takes in 4 pieces of pixel art flowers with the "basic" color scheme. It randomly choses 1 piece of art and randomly generates the color scheme. The art pieces are weighted as "common", "uncommon", "rare", and "ultra rare".

After the base art piece has been chosen, a random color scheme will be mapped onto the artwork. For "common", "uncommon", and "rare" art, the random color scheme will be mapped onto the "basic" palette. For "ultrarare" art, each pixel that fills in the flower will be a randomly generated color.

*add image of different color schemes on different levels of rarity*

## Usage
This program uses [Simple and Fast Multimedia Library](https://www.sfml-dev.org/). [Download the library](https://www.sfml-dev.org/download.php) and copy all the *.dll files from the bin into this repository. The *.dll files must be in the same level as the output .exe file. Include the path to the library in the g++ compilations as shown in `run.bat`.
The file `main.cpp` shows how to include the class and use it in a main method. This program will save the output files to `./Output/little-flower-stage-<0-3>.png`.

## Color Mapping
The color palettes are defined with SFML colors in the function `CreateFlower::initColorPalettes()`. The Palette type has attributes that are named according to the colors in the pixel art flowers: `background`, `outline`, `stem`, `stem_detail`, `center`, `center_detail`, `petals`, `petals_detail`, `eye`, `pupil`, `petals_background`, and `petals_foreground`. The "basic" color palette match the color palette of the input images.