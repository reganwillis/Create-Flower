#include "CreateFlower.h"

// get pixel art by randomly chosing one of 4 images
sf::Image CreateFlower::getImage() {
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

void CreateFlower::initColorPalettes() {
    // define basic color palette (should match input image palette)
    this->basic.outline = sf::Color(0, 0, 0, 255);
    this->basic.stem = sf::Color(0, 168, 0, 255);
    this->basic.stem_detail = sf::Color(0, 104, 0, 255);
    this->basic.center = sf::Color(160, 82, 45, 255);
    this->basic.center_detail = sf::Color(205, 133, 63, 255);
    this->basic.petals = sf::Color(238, 221, 130, 255);
    this->basic.petals_detail = sf::Color(218, 165, 32, 255);
    this->basic.eye = sf::Color(156, 252, 252, 255);
    this->basic.pupil = sf::Color(0, 72, 252, 255);

    // define dark color palette
    this->dark.outline = sf::Color(0, 0, 0, 255);
    this->dark.stem = sf::Color::Blue;
    this->dark.stem_detail = sf::Color::Red;
    this->dark.center = sf::Color::Blue;
    this->dark.center_detail = sf::Color::Red;
    this->dark.petals = sf::Color::Cyan;
    this->dark.petals_detail = sf::Color::Red;
    this->dark.eye = sf::Color::Cyan;
    this->dark.pupil = sf::Color::Blue;

    // define rare color palette
    this->rare.outline = sf::Color(0, 0, 0, 255);
    this->rare.stem = sf::Color::Green;
    this->rare.stem_detail = sf::Color::Red;
    this->rare.center = sf::Color::Green;
    this->rare.center_detail = sf::Color::Red;
    this->rare.petals = sf::Color::Yellow;
    this->rare.petals_detail = sf::Color::Red;
    this->rare.eye = sf::Color::Yellow;
    this->rare.pupil = sf::Color::Green;

    // define ultrarare color palette
    this->ultrarare.outline = sf::Color(0, 0, 0, 255);
    this->ultrarare.stem = sf::Color::White;
    this->ultrarare.stem_detail = sf::Color::Red;
    this->ultrarare.center = sf::Color::White;
    this->ultrarare.center_detail = sf::Color::Red;
    this->ultrarare.petals = sf::Color::Magenta;
    this->ultrarare.petals_detail = sf::Color::Red;
    this->ultrarare.eye = sf::Color::Magenta;
    this->ultrarare.pupil = sf::Color::Blue;
}

// get color palette by randomly chosing one of 4 color palettes
CreateFlower::Palette CreateFlower::getColorPalette() {
    // choose random number
    int numOfColorPaletteChosen = rand() % 1000;
    std::cout << "\nColor Palette: " << numOfColorPaletteChosen;  // debug

    // declare color palette
    CreateFlower::Palette colorPaletteChosen;

    // randomly load the color palette
    if (numOfColorPaletteChosen <= 899)
        colorPaletteChosen = this->basic;
    else if (numOfColorPaletteChosen > 899 && numOfColorPaletteChosen <= 989)
        colorPaletteChosen = this->dark;
    else if (numOfColorPaletteChosen > 989 && numOfColorPaletteChosen <= 998)
        colorPaletteChosen = this->rare;
    else if (numOfColorPaletteChosen == 999)
        colorPaletteChosen = this->ultrarare;
    else {
        // default
        std::cout << "ERROR: numOfColorPaletteChosen out of bounds: " << numOfColorPaletteChosen << ". Loading basic color palette.";
        colorPaletteChosen = this->basic;
    }

    return colorPaletteChosen;
}

// change pixel colors of image according to new palette
sf::Image CreateFlower::changePixelColorsToPalette(sf::Image img, CreateFlower::Palette palette) {
    // if color palette chosen was basic do not change the image
    if (palette.petals == basic.petals)  // TODO: overload = operator for more complete equality check
        return img;

    // traverse through all pixels
    for (size_t i = 0; i < img.getSize().x; ++i) {
        for (size_t j = 0; j < img.getSize().y; ++j) {
            sf::Color currPixelColor = img.getPixel(i, j);

            // change pixel colors according to new palette
            if (currPixelColor == this->basic.stem)
                img.setPixel(i, j, palette.stem);
            else if (currPixelColor == this->basic.stem_detail)
                img.setPixel(i, j, palette.stem_detail);
            else if (currPixelColor == this->basic.center)
                img.setPixel(i, j, palette.center);
            else if (currPixelColor == this->basic.center_detail)
                img.setPixel(i, j, palette.center_detail);
            else if (currPixelColor == this->basic.petals)
                img.setPixel(i, j, palette.petals);
            else if (currPixelColor == this->basic.petals_detail)
                img.setPixel(i, j, palette.petals_detail);
            else if (currPixelColor == this->basic.eye)
                img.setPixel(i, j, palette.eye);
            else if (currPixelColor == this->basic.pupil)
                img.setPixel(i, j, palette.pupil);
        }
    }

    return img;
}

// constructor
CreateFlower::CreateFlower() {
    sf::Image img = this->getImage();
    this->initColorPalettes();
    CreateFlower::Palette colors = this->getColorPalette();
    this->flower = this->changePixelColorsToPalette(img, colors);
}

// deconstructor
CreateFlower::~CreateFlower() {}

sf::Image CreateFlower::getFlower() {
    return this->flower;
}