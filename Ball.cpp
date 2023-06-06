
#include "Ball.h"
Ball::Ball(Vector2f position, std::string file): GameObject(position,file) {
    ballImage.loadFromFile("/Users/bartosz/CLionProjects/HelloSFML/Ball.png");
    if(!ballImage.loadFromFile("/Users/bartosz/CLionProjects/HelloSFML/Ball.png")) {
        system("pause");
    }
    ballImage.setSmooth(true);
    ballImageSprite.setTexture(ballImage);
    ballImageSprite.setOrigin(ballImage.getSize().x/2,ballImage.getSize().y/2);
    ballImageSprite.setPosition(position.x,position.y);

}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->ballImageSprite,state);
}

void Ball::update(float windowWidth, float windowHeight)
{
    //redFootballerSprite.move(this->velocity);
  ballImageSprite.move(this->velocityX);

    if(this->left() <70) {
        velocityX.x = BallVelocity;
    }
    else if(this->right() > windowWidth){

        velocityX.x = -BallVelocity;
    }

    if(this->top() <100) {
        velocityX.y = BallVelocity;
    }
    else if(this->bottom() > windowHeight){

        velocityX.y = -BallVelocity;
    }

}

float Ball::left() {
    return this->ballImageSprite.getPosition().x - ballImageSprite.getPosition().x/2;

}

float Ball::right() {
    return this->ballImageSprite.getPosition().x + ballImageSprite.getPosition().x/2;
}

float Ball::top() {
    return this->ballImageSprite.getPosition().y - ballImageSprite.getPosition().y/2;
}

float Ball::bottom() {
    return this->ballImageSprite.getPosition().y + ballImageSprite.getPosition().y/2;
}

Vector2f  Ball::getPosition(){
    return ballImageSprite.getPosition();
}

Vector2f  Ball::setPosition(Vector2f &v){
    ballImageSprite.setPosition(v);
}

void Ball::stopBall(){
    this->velocityX.y = 0;
    this->velocityX.x = 0;
}

void Ball::kickBall(Vector2f& v){
        velocityX.y = v.y;
        velocityX.x = v.x;
}
void Ball::passTheBall(){
    ballImageSprite.move(this->velocityX);
    //ballImageSprite.setPosition(100,100);
}
