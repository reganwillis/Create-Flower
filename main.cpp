#include "CreateFlower.h"

int main()
{
    // init random seed
    srand(time(0));

    // create flower
    CreateFlower createFlower;
    sf::Image img = createFlower.getFlowerImg();
    img.saveToFile("./Images/createdFlower.png");

    return 0;
}