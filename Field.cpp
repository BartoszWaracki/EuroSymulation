
#include "Field.h"
Field::Field(float x,float y,Texture& texture,Sprite& sprite){
    if (!MainMenuTexture.loadFromFile("/Users/bartosz/CLionProjects/HelloSFML/pitch.png")) {
        system("pause");
    }
    MainMenuTexture.setSmooth(true);
    texture = MainMenuTexture;
    MainMenuSprite.setTexture(MainMenuTexture);
    MainMenuSprite.setScale(x,y); //2.55 //2.05
    sprite = MainMenuSprite;
}
void Field::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->MainMenuSprite,state);
    target.draw(this->timerText);
    target.draw(this->resultGuest);
    target.draw(this->resultHome);
}

void Field::getFieldPosition(float& xBoundary, float& yBoundary,Sprite target, Texture texture){
    target.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    xBoundary = target.getOrigin().x*7.3;
    yBoundary = target.getOrigin().y*5.85;
}

void Field::matchTimer(){

    matchStartTime =  clock.getElapsedTime().asSeconds();
    timeLeft = matchDuration;

    timerText.setString(std::to_string(matchDuration));

    if (!timerFont.loadFromFile("/Users/bartosz/CLionProjects/HelloSFML/arial.ttf")) {
        system("pause");
    }

    timerText.setFont(timerFont);
    timerText.setCharacterSize(30);
    timerText.setPosition(1255,100);
    timerText.setFillColor(Color::White);
    timerText.setStyle(Text::Bold);
}
void Field::timerUpdate(){
    timeLeft = matchDuration - static_cast<int>(clock.getElapsedTime().asSeconds());
    timerText.setString(std::to_string(timeLeft));
    if(timeLeft == 0){
        timeLeft = matchDuration;
    }

}
void Field::matchResult(){

    resultGuest.setString(std::to_string(goalGuest)+" :");

    resultHome.setString(std::to_string(goalHome));

    if (!resultFont.loadFromFile("/Users/bartosz/CLionProjects/HelloSFML/arial.ttf")) {
        system("pause");
    }

    resultGuest.setFont(resultFont);
    resultGuest.setCharacterSize(70);
    resultGuest.setPosition(1200,20);
    resultGuest.setFillColor(Color::White);
    resultGuest.setStyle(Text::Bold);
    resultHome.setFont(resultFont);
    resultHome.setCharacterSize(70);
    resultHome.setPosition(1310,20);
    resultHome.setFillColor(Color::White);
    resultHome.setStyle(Text::Bold);
}
void Field::resultUpdate(){
}
void Field::resetResult(){
    goalHome = 0;
    goalGuest = 0;

}
void Field::getMatchResult(){

}