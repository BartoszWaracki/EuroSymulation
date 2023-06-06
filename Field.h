#include <SFML/Graphics.hpp>
#pragma once
#ifndef HELLOSFML_FIELD_H
#define HELLOSFML_FIELD_H
using namespace sf;

class Field: public sf::Drawable {
public:
    Field(float x,float y, Texture& texture,Sprite & sprite);
    void getFieldPosition(float& xBoundary, float& yBoundary,Sprite target, Texture texture);
    void matchTimer();
    void timerUpdate();
    void matchResult();
    void resultUpdate();
    void resetResult();
    void getMatchResult();
private:
    const std::string ID  = "field";
    Sprite MainMenuSprite;
    Texture MainMenuTexture;
    void draw(RenderTarget &target, RenderStates state) const override;
    Text timerText;
    Text resultGuest,resultHome;
    Font resultFont;
    Clock clock;
    int goalHome = 0;
    int goalGuest = 0;
    int matchStartTime ;
    int matchDuration = 90 ;
    int timeLeft;
    Font timerFont;
};


#endif //HELLOSFML_PLAYER_H
