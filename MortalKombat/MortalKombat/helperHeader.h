#ifndef HELPERHEADER_H
#define HELPERHEADER_H

#include "FighterClass.h"

enum fightMode
{
    BOTvBOT = 1,
    USERvBOT,
    USERvUSER
};

Fighter botFighter();
Fighter userFighter();
void fight(Fighter fighter1, Fighter fighter2);

#endif // HELPERHEADER_H
