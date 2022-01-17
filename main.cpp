// generate pixel art
// TODO: turn into separate class with source and header file

#include <iostream>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// get pixel art by randomly chosing one of 4 images
sf::Image getImage() {
    // choose random number
    int numOfImageChosen = rand() % 1000;
    std::cout << numOfImageChosen;  // debug

    // declare image
    sf::Image imageChosen;

    // randomly load the image
    if (numOfImageChosen <= 899)
        imageChosen.loadFromFile("Images/little-flower-common.png");
    else if (numOfImageChosen > 899 && numOfImageChosen <= 989)
        imageChosen.loadFromFile("Images/little-flower-uncommon.png");
    else if (numOfImageChosen > 989 && numOfImageChosen <= 998)
        imageChosen.loadFromFile("Images/little-flower-rare.png");
    else if (numOfImageChosen == 999)
        imageChosen.loadFromFile("Images/little-flower-ultrarare.png");
    else {
        // default
        std::cout << "ERROR: numOfImageChosen out of bounds: " << numOfImageChosen << ". Loading common image.";
        imageChosen.loadFromFile("Images/little-flower-common.png");
    }

    return imageChosen;
}

// TODO: color palette by randomly chosing one of 4 color palettes

// TODO: pass in color palette
sf::Color changePixelColor(sf::Color currColor) {
    sf::Color newColor;

    // common palette background
    if (currColor.r == 255 && currColor.g == 255 && currColor.b == 255 && currColor.a == 255) {
        newColor.r = 0;
        newColor.g = 0;
        newColor.b = 0;
        newColor.a = 0;
    }
    else {
        newColor = currColor;
    }

    return newColor;
}

int main()
{
    // init random seed
    srand(time(0));

    // TESTING getImage FUNCTION
    sf::Image img = getImage();
    img.saveToFile("./Images/chosenImage.png");

    // TODO: randomly choose a color palette
    // TODO: if color palette chosen was basic -> do not change the image
    // TODO: else -> recreate the image with new color palette
    
    // TESTING changePixelColor FUNCTION
    /*
    // create new image with same dimensions as old image
    sf::Image newImg;
    newImg.create(loadedImg.getSize().x, loadedImg.getSize().y, sf::Color::Black);

    for (size_t i = 0; i < loadedImg.getSize().x; ++i) {
        for (size_t j = 0; j < loadedImg.getSize().y; ++j) {
            sf::Color currPixelColor = loadedImg.getPixel(i, j);
            newImg.setPixel(i, j, changePixelColor(currPixelColor));
        }
    }

    // save new image to desktop
    newImg.saveToFile("./Images/newImg.png");
    */
    return 0;
}