
#ifndef HELLOSFML_TEAM_H
#define HELLOSFML_TEAM_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Footballer.h"

class Footballer;

class Team
{
public:
    enum Side { Left, Right };
private:

    std::vector<std::shared_ptr<Footballer>> footballers;
    Side side;
public:
    Side getSide() const;
    Team(Side side);
    ~Team();

    void getOpponentGoal();
    void getGoal();
    std::vector<std::shared_ptr<Footballer>> getFootballers() const;
    void addFootballer( std::shared_ptr<Footballer>& footballer);
    void setGoal();

    void setFootballersGoalPart();

    void resetPosition() const;
};



#endif //HELLOSFML_TEAM_H
