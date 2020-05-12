#include "FighterClass.h"

bool Fighter::addPoints(int* points_value, int p)
{
       if (p <= points)
       {
           *points_value += p;
           points -= p;
           return true;
       }
       return false;
}

double Fighter::force()
{
       return 1 + force_points;
}

bool Fighter::critical()
{
    double randNum = rand() / static_cast<double>(RAND_MAX);
    double crit = 1/(1+pow(critical_points/4.0, 4));

    if (randNum > crit)
        return true;
    else
        return false;
}

double Fighter::defence()
{
       return 1/(1+pow(defence_points/4.0, 4));
}

bool Fighter::agility()
{
       double agil = 1/(1+pow(agility_points/4.0, 4));
       double randNum = rand() / static_cast<double>(RAND_MAX);

      if (randNum > agil)
          return true;
      else
          return false;
}


Fighter::Fighter()
{
    health = 100;
    health_points = force_points = critical_points = defence_points = agility_points = 0;
    points = 10;
}
Fighter::Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points):
    health_points(health_points), force_points(force_points), critical_points(critical_points),
    defence_points(defence_points), agility_points(agility_points)
{
    points = 0;
    health = 100 + health_points * 100;
}

double Fighter::attack()
{
    if (critical())
        return 2*force();
    else
        return force();
}

double Fighter::damage(double dmg)
{
       double fullDamage = (1-agility()) * defence() * dmg;
       health -= fullDamage;

       return fullDamage;
}

bool Fighter::is_dead()
{
       if (health <= 0)
           return true;
       else
           return false;
}

bool Fighter::add_health_points(int points) { return addPoints(&health_points, points); }
bool Fighter::add_force_points(int points) { return addPoints(&force_points, points); }
bool Fighter::add_defence_points(int points) { return addPoints(&defence_points, points); }
bool Fighter::add_agility_points(int points) { return addPoints(&agility_points, points); }
bool Fighter::add_critical_points(int points) { return addPoints(&critical_points, points); }



