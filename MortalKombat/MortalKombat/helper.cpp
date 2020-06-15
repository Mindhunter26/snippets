#include "FighterClass.h"
#include <iostream>

Fighter botFighter()
{
    Fighter f;
    f.add_health_points(1);
    f.add_force_points(1);
    f.add_defence_points(1);
    f.add_agility_points(3);
    f.add_critical_points(4);

    return f;
}

Fighter userFighter()
{
  int healthPoints, forcePoints, defencePoints, agilityPoints, criticalPoints;
  std::cout << "Spread points(hp, fp, dp, ap, cp)";
  std::cin >> healthPoints >> forcePoints >> defencePoints >> agilityPoints >> criticalPoints;
  Fighter f(healthPoints, forcePoints, defencePoints, agilityPoints, criticalPoints);

  return f;
}

void fight(Fighter fighter1, Fighter fighter2)
{
    bool isUserTurn = true;

    while (!fighter1.is_dead() && !fighter2.is_dead())
    {
        if (isUserTurn)
        {
            fighter2.damage(fighter1.attack());
            std::cout << "fighter2 received " << fighter2.damage(fighter1.attack()) << std::endl;
        }
        else
        {
            fighter1.damage(fighter2.attack());
            std::cout << "fighter1 received " << fighter1.damage(fighter2.attack()) << std::endl;
        }

        isUserTurn = !isUserTurn;
    }
    std::cout << std::endl;
    if (fighter1.is_dead())
        std::cout << "fighter2 wins\n";
    else
        std::cout << "fighter1 wins\n";

}
