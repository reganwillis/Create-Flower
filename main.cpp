#include "CreateFlower.h"

int main()
{
    // init random seed
    srand(time(0));

    // create flower
    CreateFlower createFlower;
    sf::Image img = createFlower.getFlower();
    img.saveToFile("./Images/chosenImage.png");

    return 0;
}