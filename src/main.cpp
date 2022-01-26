#include "CreateFlower.h"
#include <random>

int main()
{
    // random
    // https://docs.microsoft.com/en-us/cpp/standard-library/random-device-class?redirectedfrom=MSDN&view=msvc-170
    std::random_device gen;
    std::srand(gen());

    // get random flower (rarity & colors)
    CreateFlower createFlower;

    return 0;
}