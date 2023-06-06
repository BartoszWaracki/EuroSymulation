
#ifndef HELLOSFML_FOOTBALLER_H
#define HELLOSFML_FOOTBALLER_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Team.h"
#include "Ball.h"
#include "Field.h"

using namespace sf;
#include "Ball.h"
    class Ball;
    class Team;
class FootballerObserver
{
public:
    virtual void onPositionChanged(const sf::Vector2f& newPosition) = 0;
};

    class Footballer : public GameObject
    {
    private:
        const Vector2f ownGoal{110,780};
        const sf::Vector2f FootballTarget{2467,780};
        float condition;
        float precision;
        float speed;
        float strength;
        Vector2f getStartingPoint();
        std::vector<FootballerObserver*> observers;
        std::shared_ptr<Team> team;
        sf::Vector2f startPosition;
        Texture texture;
        sf::Sprite sprite;
        std::string ID;
        Vector2f velocity;

    public:
        Footballer(sf::Vector2f position, std::shared_ptr<Team> team,std::string file);
        ~Footballer();
        void moveTowardTarget(float targetX, float targetY);
        bool opponent;
        bool decideShooting = false;
        bool surroundingClean = false;
        bool havingBall = false;
        bool shootingDistance = false;
        bool ballPassed = false;
        bool canShoot = false;
        void moveAfterPassing(Footballer* footballer,std::vector<Footballer*>& footballers, Ball* ball);
        sf::Vector2f  getPosition();
        Vector2u getSize();

        void addObserver(FootballerObserver* observer);
        void Shoot(Footballer* footballer, Ball* ball);
        void checkShootDistance(Footballer* footballer, Ball* ball);
        void collisiomTest(Ball* ball, std::vector<Footballer*>& footballers);
        void ballPass(std::vector<Footballer*>& footballers, Ball* ball);
        void checkSurroundings(Footballer* footballer, Ball* ball, std::vector<Footballer*>& footballers);
        void draw(RenderTarget &target, RenderStates state) const;
        void setPosition(Vector2f& v);
        std::string getPlayerID();
        void update();
        bool isOpponent() const;
        void executeGameplay(std::vector<Footballer*>& footballers, Ball* ball);
        float distance(const sf::Vector2f& a, const sf::Vector2f& b);
        void normalize(sf::Vector2f& vector);


        void removeObserver(FootballerObserver* observer)
        {
            auto it = std::find(observers.begin(), observers.end(), observer);
            if (it != observers.end())
                observers.erase(it);
        }

        void notifyObservers(const sf::Vector2f& newPosition)
        {
            for (auto observer : observers)
            {
                observer->onPositionChanged(newPosition);
            }
        }


    };



#endif //HELLOSFML_FOOTBALLER_H
