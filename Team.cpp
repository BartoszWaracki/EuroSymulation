
#include "Team.h"
Team::Team(Side side) : side(side)
{
}

Team::~Team()
{
}
Team::Side Team::getSide() const
{
    return side;
}
void Team::addFootballer(std::shared_ptr<Footballer>& footballer)
{
    footballers.push_back(footballer);
}
std::vector<std::shared_ptr<Footballer>> Team::getFootballers() const
{
    return footballers;
}
//void Team::resetPosition() const
//{
//    for (auto& footballer : getFootballers())
//        footballer->resetPosition();
//}