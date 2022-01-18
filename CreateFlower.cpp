#include "CreateFlower.h"

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

    // TODO: init any other curated color palettes

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

void CreateFlower::initFlower() {
    // initialize flower with no rarity
    this->flower.rarity.common = false;
    this->flower.rarity.uncommon = false;
    this->flower.rarity.rare = false;
    this->flower.rarity.ultrarare = false;

    // input flower image has basic color palette
    this->flower.palette = this->basic;

    std::cout << "\nflower initialized with no rarity and basic palette";  // debug
}

// get pixel art by randomly chosing one of 4 images
void CreateFlower::getBaseImage() {
    // choose random number
    int numOfImageChosen = rand() % 1000;
    std::cout << "\nBase Image: " << numOfImageChosen;  // debug

    // randomly load the image
    if (numOfImageChosen <= 899) {
        this->flower.img.loadFromFile("Images/little-flower-common.png");
        this->flower.rarity.common = true;
        std::cout << "\ncommon flower created";  // debug
    }
    else if (numOfImageChosen > 899 && numOfImageChosen <= 989) {
        this->flower.img.loadFromFile("Images/little-flower-uncommon.png");
        this->flower.rarity.uncommon = true;
        std::cout << "\nuncommon flower created";  // debug
    }
    else if (numOfImageChosen > 989 && numOfImageChosen <= 998) {
        this->flower.img.loadFromFile("Images/little-flower-rare.png");
        this->flower.rarity.rare = true;
        std::cout << "\nrare flower created";  // debug
    }
    else if (numOfImageChosen == 999) {
        this->flower.img.loadFromFile("Images/little-flower-ultrarare.png");
        this->flower.rarity.ultrarare = true;
        std::cout << "\nultrarare flower created";  // debug
    }
    else {
        // default
        std::cout << "\nERROR: numOfImageChosen out of bounds: " << numOfImageChosen << ". Loading common image.";
        this->flower.img.loadFromFile("Images/little-flower-common.png");
        this->flower.rarity.common = true;
        std::cout << "\ndefault common flower created";  // debug
    }
}

// generate random opaque colors using RGB values
sf::Color CreateFlower::generateRandomColor() {
    // choose random number
    int red = rand() % 255;
    int green = rand() % 255;
    int blue = rand() % 255;
    std::cout << "\nColor Palette: (" << red << ", " << green << ", " << blue << ")";  // debug

    return sf::Color(red, green, blue, 255);
}

// create color palette according to art
void CreateFlower::addColorPalette() {

    if (this->flower.rarity.common == true) {
        // fill flower palette with randomly generated colors
        this->flower.palette.stem = generateRandomColor();
        this->flower.palette.stem_detail = generateRandomColor();
        this->flower.palette.center = generateRandomColor();
        this->flower.palette.center_detail = generateRandomColor();
        this->flower.palette.petals = generateRandomColor();
        this->flower.palette.petals_detail = generateRandomColor();
        this->flower.palette.eye = generateRandomColor();
        this->flower.palette.pupil = generateRandomColor();
        std::cout << "\nflower palette set";  // debug
    }
    else {
        // default
        std::cout << "\nERROR: flower rarity not specified. Loading dark color palette.";
        this->flower.palette = this->dark;
    }
    // TODO: else if (this->flower.rarity.uncommon == true) {}
    // TODO: else if (this->flower.rarity.rare == true) {}
    // TODO: else if (this->flower.rarity.ultrarare == true) {}
}

// change pixel colors of image according to new palette
void CreateFlower::changePixelColorsToPalette() {
    // traverse through all pixels
    for (size_t i = 0; i < this->flower.img.getSize().x; ++i) {
        for (size_t j = 0; j < this->flower.img.getSize().y; ++j) {
            sf::Color currPixelColor = this->flower.img.getPixel(i, j);

            // change pixel colors according to new palette
            if (currPixelColor == this->basic.stem)
                this->flower.img.setPixel(i, j, this->flower.palette.stem);
            else if (currPixelColor == this->basic.stem_detail)
                this->flower.img.setPixel(i, j, this->flower.palette.stem_detail);
            else if (currPixelColor == this->basic.center)
                this->flower.img.setPixel(i, j, this->flower.palette.center);
            else if (currPixelColor == this->basic.center_detail)
                this->flower.img.setPixel(i, j, this->flower.palette.center_detail);
            else if (currPixelColor == this->basic.petals)
                this->flower.img.setPixel(i, j, this->flower.palette.petals);
            else if (currPixelColor == this->basic.petals_detail)
                this->flower.img.setPixel(i, j, this->flower.palette.petals_detail);
            else if (currPixelColor == this->basic.eye)
                this->flower.img.setPixel(i, j, this->flower.palette.eye);
            else if (currPixelColor == this->basic.pupil)
                this->flower.img.setPixel(i, j, this->flower.palette.pupil);
        }
    }
}

// constructor
CreateFlower::CreateFlower() {
    this->initColorPalettes();
    this->initFlower();
    this->getBaseImage();
    this->addColorPalette();
    this->changePixelColorsToPalette();
}

// deconstructor
CreateFlower::~CreateFlower() {}

sf::Image CreateFlower::getFlowerImg() {
    return this->flower.img;
}