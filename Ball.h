#pragma once
#ifndef HELLOSFML_BALL_H
#define HELLOSFML_BALL_H
#include <SFML/Graphics.hpp>
#include "Footballer.h"
#include "GameObject.h"
using namespace sf;
class Footballer;

class Ball : public GameObject {
public:
    Ball(Vector2f position, std::string file);
    Ball() = delete;
    ~Ball() = default;
    void update(float windowWidth, float windowHeight);
    void draw(RenderTarget& target, RenderStates state) const ;
    Vector2f getPosition();
    Vector2f setPosition(Vector2f& v);

    float left();
    float right();
    float top();
    float bottom();

    void stopBall();
    void kickBall(Vector2f& v);
    void passTheBall();

    // Dodajemy uchwyt do piłkarza trzymającego piłkę
    Footballer* getHolder() { return holder; }
    void setHolder(Footballer* newHolder) { holder = newHolder; }

    const std::string ID = "ball";

//private:
    Sprite ballImageSprite;
    Texture ballImage;
    const float BallVelocity{5.0f};
    Vector2f velocityX{BallVelocity, BallVelocity};

    // Dodajemy pole dla uchwytu piłkarza
    Footballer* holder = nullptr;
};

#endif //HELLOSFML_BALL_H
