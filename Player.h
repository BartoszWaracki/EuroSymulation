//#include <SFML/Graphics.hpp>
//#include "Ball.h"
//#include <unistd.h>
//#pragma once
//#ifndef HELLOSFML_PLAYER_H
//#define HELLOSFML_PLAYER_H
//using namespace sf;
//
//class Player : public sf::Drawable
//{ public:
//    Player(float t_X,float t_Y);
//    ~Player() = default;
//    const Vector2f FootballTarget{2467,780};
//    bool decideShooting = false;
//    bool surroundingClean = false;
//    bool havingBall = false;
//    bool shootingDistance = false;
//    bool ballPassed = false;
//    bool canShoot = false;
//    void moveAfterPassing(Player& player);
//    Vector2f  getPosition();
//    Vector2u getSize();
//
//
//    void Shoot(Player& player, Ball& ball);
//    void checkShootDistance(Player& player, Ball& ball);
//    void collisiomTest(Player & player , Ball & ball, Player &player2);
//    void ballPass(Player& player,Ball& ball,Player& player2);
//    void checkSurroundings(Player& player,Ball& ball, Player& player1);
//    void draw(RenderTarget &target, RenderStates state) const override;
//    void setPosition(Vector2f& v);
//    std::string getPlayerID();
//    Vector2f getStartingPoint();
//    void update();
//
////private:
//    std::string ID;
//    Vector2f startingPoint;
//    Texture footballerImage;
//    Sprite redFootballerSprite;
//    float PlayerStep;
//    const float playerVelocity{20.0f};
//    Vector2f velocity{playerVelocity,playerVelocity };
//
//
//// trzeba dodac jakis ruch pilakrza po podaniu + dodac enemich
//// trzeba tez pomyslec o tym jak uniknac tego ze pilka jest przechwytywana bardzo szybko
//// trzeba srobic observera i przeksztalcic projekt
//
//
//
//};

//#endif //HELLOSFML_PLAYER_H
