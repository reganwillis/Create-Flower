// generate pixel art
// TODO: turn into separate class with source and header file

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    sf::Image loadedImg;
    loadedImg.loadFromFile("Images/little-flower.png");
    loadedImg.saveToFile("./Images/testing-save.png");

    // get array of pixels
    const sf::Uint8* imagePixelArr = loadedImg.getPixelsPtr();

    // create empty array to store new pixels
    size_t numPix = loadedImg.getSize().x * loadedImg.getSize().y;
    sf::Uint8 newPixelVals[numPix] = {};
    //newPixelVals = imagePixelArr;

    for (size_t i = 0; i < numPix; ++i) {
        sf::Uint8 red = imagePixelArr[4 * i];
        sf::Uint8 green = imagePixelArr[4 * i + 1];
        sf::Uint8 blue = imagePixelArr[4 * i + 2];
        sf::Uint8 alpha = imagePixelArr[4 * i + 3];
        //newPixelVals[i] = imagePixelArr[i];
    }
    std::cout << numPix;

    sf::Image testImage;
    testImage.create(64, 64, sf::Color::Black);

    for (size_t i = 0; i < 64; ++i) {
        for (size_t j = 0; j < 64; ++j) {
            sf::Color currPixelColor = loadedImg.getPixel(i, j);
            if (currPixelColor.r == 255 && currPixelColor.g == 255 && currPixelColor.b == 255 && currPixelColor.a == 255)
                testImage.setPixel(i, j, currPixelColor);
        }
    }

    testImage.saveToFile("./Images/test6.png");

    return 0;
}
/*
    // TODO: basic structure
    // TODO: randomly choose one of 5 images
    // load in the image
    // TODO: randomly choose a color palette
    // TODO: if color palette chosen was basic -> do not change the image
    // else -> recreate the image with new color palette
    // save new image to desktop


    // import pixel art
    //sf::Texture littleFlowerImg;
    //sf::Sprite flower;
    //littleFlowerImg.loadFromFile("Images/little-flower.png");
    //flower.setTexture(littleFlowerImg);
    sf::Image loadedImg;
    loadedImg.loadFromFile("Images/little-flower.png");

    // get array of pixels
    const sf::Uint8* imagePixelArr = loadedImg.getPixelsPtr();
    //std::cout << imagePixelArr[0];

    //std::copy(imagePixelArr, copyOf);

    // create empty array to store new pixels
    size_t numPix = loadedImg.getSize().x * loadedImg.getSize().y;
    sf::Uint8 newPixelVals[numPix];

    
    std::vector<std::vector<sf::Uint8>> pixelVals;
    for (size_t i = 0; i < numPix; ++i) {
        sf::Uint8 red = imagePixelArr[4 * i];
        sf::Uint8 green = imagePixelArr[4 * i + 1];
        sf::Uint8 blue = imagePixelArr[4 * i + 2];
        sf::Uint8 alpha = imagePixelArr[4 * i + 3];
        pixelVals.push_back({red, green, blue, alpha});
        for (int j = 0; j < 4; ++j) {
            //std::cout <<
            //if ((int)imagePixelArr[j] != (int)255255255255)
            //std::cout << (int)imagePixelArr[j];
        }
        //std::cout << std::endl;
        newPixelVals[i] = imagePixelArr[i];
        //std::cout << imagePixelArr[i];
        //std::cout << (int)red << ", " << (int)green << ", " << (int)blue << ", " << (int)alpha << std::endl;
    }
    std::cout << numPix;

    sf::Image testImage;
    //image.create(64, 64, pixelArr);
    testImage.create(64, 64, newPixelVals);
    testImage.saveToFile("./Images/test5.png";
    if (testImage.saveToFile("./Images/test5.png")) {
        std::cout << "successful";
    }
    else {
        std::cout << "failed";
    }
    //std::vector<std::vector<int>> pixelVals;
    int x = loadedImg.getSize().x;
    int y = loadedImg.getSize().y;

    for (int i = 0; i < x; i++){
        //std::cout << imagePixelArr[i] << std::endl;
        for (int j = 0; j < y; j++){
            const sf::Color color = loadedImg.getPixel(i, j);
            //pixelVals.push_back({(int)color.r, (int)color.g, (int)color.b, (int)color.a});
            //std::cout << (int)color.r << ", ";
            //std::cout << (int)color.g << ", ";
            //std::cout << (int)color.b << ", ";
            //std::cout << (int)color.a;
            //std::cout << std::endl;
            //const st::Color color = imagePixelArr
            //std::cout << imagePixelArr[i];

            //cout <<"these are red pixels in array " << pixelValues[z++]  << "   " << z << endl;
        }
        //std::cout << std::endl;
    }
    //int arrayLength = loadedImg.getSize().x * loadedImg.getSize().y * 4;
    //for (int i = 0; i < arrayLength; ++ i) {
    //    std::cout << imagePixelArr[i];
    //}

    // draw art

    const unsigned numPixels = 4096;  // (64x64)

    /*std::vector<std::vector<int>> pixelVec;
    for (unsigned int i = 0; i < (4*numPixels); ++i) {
        pixelVec.push_back({0, 255, 0, 255});
    }

    // 4 vals for each pixel
    sf::Uint8 pixelArr[4 * numPixels] = {
        0, 255, 0, 255, 0, 255, 0, 255
    };

    sf::Uint8 pixelArr[4 * numPixels] = {};
    
    //sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test");
    sf::Image image;
    //image.create(64, 64, pixelArr);
    image.create(64, 64, newPixelVals);
    //image.copy(loadedImg, 0, 0);
    //image.create(64, 64, pixelArr);

    //image.create(64, 64, sf::Color(0, 0, 0));
/*    sf::Sprite sprite;
    sf::Uint8 *pixels  = new sf::Uint8[800 * 600 * 4];
    // TODO: create array of pixels and use that to draw
        // array of sf::Uint8 with size width * height * 4
        // components are stored in RGBA order
    for(int x = 0; x < 800; x++)
    {
        for(int y = 0; y < 600; y++)
        {
            pixels[(y * x)*4] = 255; // R?
            pixels[(y * x)*4 + 1] = 255; // G?
            pixels[(y * x)*4 + 2] = 255; // B?
            pixels[(y * x)*4 + 3] = 255; // A?
        }
    }

    // TODO: pass pixel array to sf::Image when it is ready to be displayed
    image.LoadFromPixels(800, 600, pixels);
    sprite.SetImage(image);
    //window.Draw(sprite);
    //window.Display();

    // testing getPixel
    sf::Color pixelColor = image.getPixel(1, 1);
    //std::cout << pixelColor.toInteger();

    // testing setPixel
    unsigned int pixelToSet = 0;
    image.setPixel(pixelToSet, pixelToSet, sf::Color::Blue);

    // for pixel in image, set pixel
    //for (auto &pixel : image.getPixel()) {}

    // save art to Images folder
    image.saveToFile("./Images/test4.png");

    return 0;
}
*/
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
}

// function to draw pixel art using sfml
void drawArt() {
    sf::RenderTexture newDrawing;
    newDrawing.create(64, 64);
    newDrawing.clear();
    newDrawing.draw();
    const sf::Texture& texture = newDrawing.getTexture();
}*/