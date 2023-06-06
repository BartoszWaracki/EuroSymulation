
#include "Footballer.h"
#include <iostream>


Footballer::Footballer(sf::Vector2f position, std::shared_ptr<Team> team,std::string file) : GameObject(position,file),team(team)
{
    if(position.x>1255){opponent = true;}
    else{opponent = false;}
    // 780 srodek
// gora 150 wyszla calym obwodem
// dol  1416 wyszla calym obwodem
// lewa  83 wyszla calym obwodem
// prawa 2467 wyszla calym obwodem
    if((position.x> 100 && position.x <= 200) || (position.x>2367 && position.x <= 2467)){
        ID = "goalkeeper";
    }
    if((position.x> 200 && position.x <= 500) ||(position.x> 2067 && position.x <= 2367)){
        if((position.y <500 && position.y > 150)|| position.y >  1416 && position.y < 1060 ){ID = "sideDeffender";}
        else{ID = "midDeffender";}
    }
    if((position.x> 500 && position.x <= 750)||((position.x> 1817 && position.x <= 2067))){
        ID = "midfielder";
    }
    if((position.x> 750 && position.x <= 1255) || (position.x> 1400 && position.x <= 1817) ){
        if((position.y <500 && position.y > 150)|| position.y >  1416 && position.y < 1060 ){ID="sideForward";}
        else{ID = "forward";}
    }
    if(!texture.loadFromFile(file)) {
        system("pause");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    sprite.setPosition(position);
}
//void Footballer::ballPass(Footballer* footballer, Ball* ball, Footballer* otherFootballer) {
//    sf::Vector2f vect;
//
//    if (footballer->havingBall) {
//        if (footballer->getPosition() != otherFootballer->getPosition()) {
//            if (footballer->getPosition().x >= otherFootballer->getPosition().x && footballer->getPosition().y >= otherFootballer->getPosition().y) {
//                float radius = 12.2;
//                if (sqrt(pow((footballer->getPosition().x - ball->getPosition().x), 2) + pow((footballer->getPosition().y - ball->getPosition().y), 2)) < radius) {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 10;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 10;
//                    ball->kickBall(vect);
//                }
//                else {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 40;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 40;
//                    ball->kickBall(vect);
//                }
//                footballer->havingBall = false;
//                footballer->ballPassed = true;
//            }
//            else if (footballer->getPosition().x < otherFootballer->getPosition().x && footballer->getPosition().y < otherFootballer->getPosition().y) {
//                float radius = 12.2;
//                if (sqrt(pow((footballer->getPosition().x - ball->getPosition().x), 2) + pow((footballer->getPosition().y - ball->getPosition().y), 2)) < radius) {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 20;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 20;
//                    ball->kickBall(vect);
//                }
//                else {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 40;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 40;
//                    ball->kickBall(vect);
//                }
//                footballer->havingBall = false;
//                footballer->ballPassed = true;
//            }
//            else if (footballer->getPosition().x < otherFootballer->getPosition().x && footballer->getPosition().y > otherFootballer->getPosition().y) {
//                float radius = 12.2;
//                if (sqrt(pow((footballer->getPosition().x - ball->getPosition().x), 2) + pow((footballer->getPosition().y - ball->getPosition().y), 2)) < radius) {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 20;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 20;
//                    ball->kickBall(vect);
//                }
//                else {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 40;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 40;
//                    ball->kickBall(vect);
//                }
//                footballer->havingBall = false;
//                footballer->ballPassed = true;
//            }
//            else if (footballer->getPosition().x > otherFootballer->getPosition().x && footballer->getPosition().y < otherFootballer->getPosition().y) {
//                float radius = 12.2;
//                if (sqrt(pow((footballer->getPosition().x - ball->getPosition().x), 2) + pow((footballer->getPosition().y - ball->getPosition().y), 2)) < radius) {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 20;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 20;
//                    ball->kickBall(vect);
//                }
//                else {
//                    vect.x = (otherFootballer->getPosition().x - footballer->getPosition().x) / 40;
//                    vect.y = (otherFootballer->getPosition().y - footballer->getPosition().y) / 40;
//                    ball->kickBall(vect);
//                }
//                footballer->havingBall = false;
//                footballer->ballPassed = true;
//            }
//        }
//    }
//}

Footballer::~Footballer()
{
}

void Footballer::moveAfterPassing(Footballer* footballer, std::vector<Footballer*>& footballers, Ball* ball)
{
    if (this == footballer) {
        // If the current footballer is the one we're passing to, skip the rest of this iteration.
        return;
    }
    Vector2f goalPossition;
    Vector2f ballPos = ball->getPosition();
    std::string playerType = footballer->getPlayerID();
    bool teamHasBall = (ball->getHolder() != nullptr) && (ball->getHolder()->isOpponent() == footballer->isOpponent());

    if (playerType == "goalkeeper" && !teamHasBall) {
        // Define the bounds for the goalkeeper and the ball
        float goalieMinY {650}, goalieMaxY {920}, ballMinY {150}, ballMaxY {1416};

        // Calculate the goalkeeper's new Y position based on the ball's Y position
        float newY = ((ballPos.y - ballMinY) / (ballMaxY - ballMinY)) * (goalieMaxY - goalieMinY) + goalieMinY;

        // Make sure the new Y position is within the goalkeeper's bounds
        newY = std::max(goalieMinY, std::min(newY, goalieMaxY));

        // Update the goalkeeper's Y position
        Vector2f vect {this->getPosition().x, newY};
        this->setPosition(vect);

    } else if (playerType == "defender") {
        float deffMinX {150}, deffMaxX {1416},deffMinY {150}, deffMaxY {780};
        float targetX = 0, targetY = 0;
        if (teamHasBall) {
            targetX = (deffMinX + deffMaxX) / 2;  // środek pola gry
            targetY = ballPos.y;  // idzie w kierunku piłki
        } else {
            targetX = deffMinX + (deffMaxX - deffMinX) / 3;  // pozostaje w tylnej 1/3 pola gry
            targetY = deffMinY + (deffMaxY - deffMinY) / 2;  // pozostaje w środku swojej strefy
        }

    } else if (playerType == "sideDefender") {
        // Obrona jest ograniczona do swojej połowy boiska
        if (teamHasBall) {
            // Move forward
        } else {
            // Move back to the defense
        }

    }else if (playerType == "midfielder") {
        // Pomocnicy mogą przekraczać połowę boiska
        if (teamHasBall) {
            // Move forward
        } else {
            // Move back to the defense, but not as far back as defenders
        }
    }else if (playerType == "sideForward") {
        // Napastnicy są najbardziej wysunięci do przodu i nie wracają do obrony
        if (teamHasBall) {
            // Move
        } else {
            // Stay in the front, do not move back to defense
        }
    } else if (playerType == "forward") {
        // Napastnicy są najbardziej wysunięci do przodu i nie wracają do obrony
        if (teamHasBall) {
            // Move
        } else {
            // Stay in the front, do not move back to defense
        }
    }
}



sf::Vector2f Footballer::getPosition()
{
    return sprite.getPosition();
}



void Footballer::Shoot(Footballer* footballer, Ball* ball) {
    if (footballer->decideShooting == true) {
        sf::Vector2f vect;
        // Dodaj mnożniki w zależności od pozycji
        vect.x = (FootballTarget.x - footballer->getPosition().x) / 20;
        vect.y = (FootballTarget.y - footballer->getPosition().y) / 20;
        ball->kickBall(vect);
        footballer->decideShooting = false;
    }
}


void Footballer::checkShootDistance(Footballer* footballer, Ball* ball) {
    const sf::Vector2f v{2467, 900};
    // Bramka prawa // dopisac lewa
    if ((sqrt(pow((footballer->getPosition().x - v.x), 2) + pow((footballer->getPosition().y - v.y), 2)) <= 500) && footballer->getPosition().x >= 1400) {
        footballer->decideShooting = true;
    }
}

//void Footballer::collisiomTest(Footballer* footballer, Ball* ball, std::vector<Footballer*>& footballers)
//{
//    for (Footballer* otherFootballer : footballers)
//    {
//        if (otherFootballer == footballer)
//            continue;
//
//        if (abs(ball->getPosition().x - footballer->getPosition().x) <= 10 && abs(ball->getPosition().y - footballer->getPosition().y) <= 10) {
//            ball->stopBall();
//            Vector2f v = footballer->getPosition();
//            ball->setPosition(v);
//            footballer->havingBall = true;
//        }
//
//        if (abs(ball->getPosition().x - otherFootballer->getPosition().x) <= 15 && abs(ball->getPosition().y - otherFootballer->getPosition().y) <= 15) {
//            ball->stopBall();
//            Vector2f v = otherFootballer->getPosition();
//            ball->setPosition(v);
//            otherFootballer->havingBall = true;
//        }
//    }
//}
void Footballer::ballPass(std::vector<Footballer*>& footballers, Ball* ball) {
    bool isOpponentNearby = false;
    Footballer* closestTeammate = nullptr;
    float minDist =std::numeric_limits<float>::max();


    for (auto& otherFootballer : footballers) {
        float dist = distance(this->getPosition(), otherFootballer->getPosition());
        if (otherFootballer->isOpponent() && dist <= 400) {
            isOpponentNearby = true;
        }
        if (!otherFootballer->isOpponent() && otherFootballer != this && dist < minDist) {
            minDist = dist;
            closestTeammate = otherFootballer;
        }
    }

    if (this->havingBall) {
        if (isOpponentNearby) {
            if (closestTeammate) {
                sf::Vector2f passVector = closestTeammate->getPosition() - this->getPosition();
                // dodac jakas metode co robi wektor o stalej dlugosci i zeby pilka miala zawse stala predkosc
                //ball->kickBall(passVector);
                // dodac metode w zalezmosci od id zeby po podaniu wracal albo cos
                // sprite nie ruszaja sie wiec metoda update chyba do zmiany
                ball->velocityX.x = passVector.x / 20;
                ball->velocityX.y = passVector.y / 20;
                ball->passTheBall();
                this->havingBall = false;
                this->ballPassed = true;
                ball->setHolder(nullptr);  // Piłka jest teraz wolna
            } else {
                // If there's an opponent nearby but no available teammate, retreat towards own goal.
                this->velocity = this->ownGoal - this->getPosition();
                normalize(this->velocity);
                this->update();

                // Continue to look for the closest teammate while retreating.
                Footballer* retreatingClosestTeammate = nullptr;
                float minRetreatDist = std::numeric_limits<float>::max();
                for (auto& otherFootballer : footballers) {
                    if (!otherFootballer->isOpponent() && otherFootballer != this) {
                        float dist = distance(this->getPosition(), otherFootballer->getPosition());
                        if (dist < minRetreatDist) {
                            minRetreatDist = dist;
                            retreatingClosestTeammate = otherFootballer;
                        }
                    }
                }
                // If a teammate is found during the retreat, pass the ball to them.
                if (retreatingClosestTeammate) {
                    sf::Vector2f passVector = retreatingClosestTeammate->getPosition() - this->getPosition();
                    normalize(passVector);
                    ball->kickBall(passVector);
                    this->havingBall = false;
                    this->ballPassed = true;
                    ball->setHolder(nullptr);  // The ball is now free
                }
            }
        } else {
            // If there's no opponent nearby, move towards the opponent's goal.
            this->velocity = FootballTarget - this->getPosition();
            normalize(this->velocity);  // Make sure the speed stays consistent.
            this->update();
        }
    }

}


void Footballer::collisiomTest(Ball* ball, std::vector<Footballer*>& footballers) {
    for (Footballer* player : footballers) {
        if (abs(ball->getPosition().x - player->getPosition().x) <= 15 && abs(ball->getPosition().y - player->getPosition().y) <= 15) {
            ball->stopBall();
            Vector2f v = player->getPosition();
            ball->setPosition(v);
            player->havingBall = true;
            ball->setHolder(player);
        }
    }
}
void Footballer::executeGameplay(std::vector<Footballer*>& footballers, Ball* ball) {
    if (havingBall) {
        ballPass(footballers, ball);
    } else {
        collisiomTest(ball, footballers);
    }
}

void Footballer::checkSurroundings(Footballer* footballer, Ball* ball, std::vector<Footballer*>& footballers)
{

    checkShootDistance(footballer, ball);
    int const radius = 400;

    collisiomTest( ball, footballers);

    if (footballer->havingBall == true) {
        bool passMade = false;
        for (Footballer* otherFootballer : footballers) {
            if (otherFootballer == footballer)
                continue;

            if ((sqrt(pow((footballer->getPosition().x - otherFootballer->getPosition().x), 2) + pow((footballer->getPosition().y - otherFootballer->getPosition().y), 2)) > radius) && (footballer->decideShooting == false)) {
                sf::Vector2f v = footballer->getPosition();
                ball->setPosition(v);
                footballer->velocity.x = 30;
                footballer->velocity.y = 0;
                footballer->update();
                break;
            }

            if ((sqrt(pow((footballer->getPosition().x - otherFootballer->getPosition().x), 2) + pow((footballer->getPosition().y - otherFootballer->getPosition().y), 2)) <= radius) && (footballer->decideShooting == false)) {
                footballer->surroundingClean = false;
                footballer->velocity.x = 0;
                footballer->velocity.y = 0;
                footballer->update();
                ballPass(footballers,ball);
                break;
//                footballer->velocity.x = rand() % 50 + 20;
//                footballer->velocity.y = rand() % 70 - 35;
//                footballer->update()

            }

            if (footballer->decideShooting == true) {
                Shoot(footballer, ball);
                footballer->decideShooting = false;
            }
        }

    }
}

void Footballer::update()
{

    sprite.move(this->velocity);

    // to nie dziala trzeba inaczej
}

void Footballer::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->sprite,state);
}

void Footballer::setPosition(sf::Vector2f& v)
{
    sprite.setPosition(v);
}

std::string Footballer::getPlayerID()
{
    return ID;
}

void Footballer::addObserver(FootballerObserver *observer)
{
    observers.push_back(observer);
}
bool Footballer::isOpponent() const { return opponent; }
float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void Footballer::normalize(sf::Vector2f& vector) {
    float length = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
}
float Footballer::distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
void Footballer::moveTowardTarget(float targetX, float targetY) {
    float speed = 0.5;  // Stała prędkość zawodnika

    // Oblicz kierunek ruchu
    Vector2f direction = Vector2f(targetX, targetY) - this->getPosition();

    // Normalizuj kierunek
    float length = std::sqrt(direction.x*direction.x + direction.y*direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    Vector2f position;
    // Aktualizuj pozycję
    position.x += direction.x * speed;
    position.y += direction.y * speed;
    this->setPosition(position);

    // Upewnij się, że zawodnik nie opuszcza boiska
    if (this->getPosition().x < 120){position.x = 120;this->setPosition(position);}
    if (this->getPosition().y < 0) {position.y = 0;this->setPosition(position);}
    if (position.x > 2450) {position.x = 2450;this->setPosition(position);}
    if (position.y > 1416) {position.y = 1416;this->setPosition(position);}
}




