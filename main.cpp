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
    std::cout << "Image: " << numOfImageChosen;  // debug

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

// color palettes (basic should match input image palette)
struct color_palette {
    sf::Color outline;
    sf::Color stem;
    sf::Color stem_detail;
    sf::Color center;
    sf::Color center_detail;
    sf::Color petals;
    sf::Color petals_detail;
    sf::Color eye;
    sf::Color pupil;
} basic, dark, rare, ultrarare;

// get color palette by randomly chosing one of 4 color palettes
color_palette getColorPalette() {
    // define basic color palette (temporary colors)
    basic.outline = sf::Color(0, 0, 0, 255);
    basic.stem = sf::Color(0, 168, 0, 255);
    basic.stem_detail = sf::Color(0, 104, 0, 255);
    basic.center = sf::Color(160, 82, 45, 255);
    basic.center_detail = sf::Color(205, 133, 63, 255);
    basic.petals = sf::Color(238, 221, 130, 255);
    basic.petals_detail = sf::Color(218, 165, 32, 255);
    basic.eye = sf::Color(156, 252, 252, 255);
    basic.pupil = sf::Color(0, 72, 252, 255);

    // define dark color palette (temporary colors)
    dark.outline = sf::Color(0, 0, 0, 255);
    dark.stem = sf::Color::Blue;
    dark.stem_detail = sf::Color::Red;
    dark.center = sf::Color::Blue;
    dark.center_detail = sf::Color::Red;
    dark.petals = sf::Color::Cyan;
    dark.petals_detail = sf::Color::Red;
    dark.eye = sf::Color::Cyan;
    dark.pupil = sf::Color::Blue;

    // define rare color palette (temporary colors)
    rare.outline = sf::Color(0, 0, 0, 255);
    rare.stem = sf::Color::Green;
    rare.stem_detail = sf::Color::Red;
    rare.center = sf::Color::Green;
    rare.center_detail = sf::Color::Red;
    rare.petals = sf::Color::Yellow;
    rare.petals_detail = sf::Color::Red;
    rare.eye = sf::Color::Yellow;
    rare.pupil = sf::Color::Green;

    // define ultrarare color palette (temporary colors)
    ultrarare.outline = sf::Color(0, 0, 0, 255);
    ultrarare.stem = sf::Color::White;
    ultrarare.stem_detail = sf::Color::Red;
    ultrarare.center = sf::Color::White;
    ultrarare.center_detail = sf::Color::Red;
    ultrarare.petals = sf::Color::Magenta;
    ultrarare.petals_detail = sf::Color::Red;
    ultrarare.eye = sf::Color::Magenta;
    ultrarare.pupil = sf::Color::Blue;

    // choose random number
    int numOfColorPaletteChosen = rand() % 1000;
    std::cout << "\nColor Palette: " << numOfColorPaletteChosen;  // debug

    // declare color palette
    color_palette colorPaletteChosen;

    // randomly load the color palette
    if (numOfColorPaletteChosen <= 899)
        colorPaletteChosen = basic;
    else if (numOfColorPaletteChosen > 899 && numOfColorPaletteChosen <= 989)
        colorPaletteChosen = dark;
    else if (numOfColorPaletteChosen > 989 && numOfColorPaletteChosen <= 998)
        colorPaletteChosen = rare;
    else if (numOfColorPaletteChosen == 999)
        colorPaletteChosen = ultrarare;
    else {
        // default
        std::cout << "ERROR: numOfColorPaletteChosen out of bounds: " << numOfColorPaletteChosen << ". Loading basic color palette.";
        colorPaletteChosen = basic;
    }

    return colorPaletteChosen;
}

// change pixel colors of image according to new palette
sf::Image changePixelColorsToPalette(sf::Image img, color_palette palette) {
    // if color palette chosen was basic do not change the image
    if (palette.petals == basic.petals)  // TODO: overload = operator for more complete equality check
        return img;

    // traverse through all pixels
    for (size_t i = 0; i < img.getSize().x; ++i) {
        for (size_t j = 0; j < img.getSize().y; ++j) {
            sf::Color currPixelColor = img.getPixel(i, j);

            // change pixel colors according to new palette
            if (currPixelColor == basic.stem)
                img.setPixel(i, j, palette.stem);
            else if (currPixelColor == basic.stem_detail)
                img.setPixel(i, j, palette.stem_detail);
            else if (currPixelColor == basic.center)
                img.setPixel(i, j, palette.center);
            else if (currPixelColor == basic.center_detail)
                img.setPixel(i, j, palette.center_detail);
            else if (currPixelColor == basic.petals)
                img.setPixel(i, j, palette.petals);
            else if (currPixelColor == basic.petals_detail)
                img.setPixel(i, j, palette.petals_detail);
            else if (currPixelColor == basic.eye)
                img.setPixel(i, j, palette.eye);
            else if (currPixelColor == basic.pupil)
                img.setPixel(i, j, palette.pupil);
        }
    }

    return img;
}

int main()
{
    // init random seed
    srand(time(0));

    // get random image
    sf::Image img = getImage();

    // get random color palette
    color_palette colors = getColorPalette();

    // create new image with new color palette
    sf::Image newImg = changePixelColorsToPalette(img, colors);
    newImg.saveToFile("./Images/chosenImage.png");

    return 0;
}