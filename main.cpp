// generate pixel art
// TODO: turn into separate class with source and header file

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

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
    // TODO: randomly choose one of 5 images
    // load in the image
    sf::Image loadedImg;
    loadedImg.loadFromFile("Images/little-flower.png");

    // TODO: randomly choose a color palette
    // TODO: if color palette chosen was basic -> do not change the image
    // TODO: else -> recreate the image with new color palette

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

    return 0;
}

/*
// TODO: function to randomly choose which pixel art to draw and what color
float getRandom(float percentChosen) {
    // random
    //srand(static_cast<unsigned>(time(NULL)));
    srand(static_cast<unsigned>(time(NULL)));

    // random between two vars
    //static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 0.f;

    // random between 0 and 4?
    int type = rand() % 5;
    return rand()%5 < (percentChosen * 5);
}*/