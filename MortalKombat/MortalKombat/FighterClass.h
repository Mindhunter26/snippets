#ifndef FIGHTERCLASS_H
#define FIGHTERCLASS_H

#include <cmath>

class Fighter
{
private:
    int health_points;
    int health;
    int force_points;
    int defence_points;
    int agility_points;
    int critical_points;
    int points;

    double force();
    bool critical();
    double defence();
    bool agility();

public:
    Fighter();
    Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points);

    double attack();
    double damage(double dmg);
    bool is_dead();

    bool add_health_points(int points);
    bool add_force_points(int points);
    bool add_defence_points(int points);
    bool add_agility_points(int points);
    bool add_critical_points(int points);
};
#endif // FIGHTERCLASS_H
