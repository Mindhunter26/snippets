#include <iostream>
#include <time.h>
#include <cmath>
#include "FighterClass.h"
#include "helperHeader.h"

int main()
{
    srand(time(0));
    fightMode mode;
    int chooseMode;
    do
    {
      std::cout << "Select the battle type:\n1 - Bot vs Bot\n2 - User vs Bot\n3 - User vs User\n";
      std::cin >> chooseMode;

      if (chooseMode != 1 && chooseMode != 2 && chooseMode != 3)
        std::cout <<"Select right type!\n";

    } while (chooseMode != 1 && chooseMode != 2 && chooseMode != 3);

    mode = (fightMode)chooseMode;

    Fighter fighter1, fighter2;

    switch (mode)
    {
    case BOTvBOT:
        fighter1 = botFighter();
        fighter2 = botFighter();
        break;
    case USERvBOT:
        fighter1 = userFighter();
        fighter2 = botFighter();
        break;
    case USERvUSER:
        fighter1 = userFighter();
        fighter2 = userFighter();
        break;
    }

    fight(fighter1, fighter2);
}
