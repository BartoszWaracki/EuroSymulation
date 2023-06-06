
#include "GameObject.h"
GameObject::GameObject(sf::Vector2f position,string file){
    startPosition = position;
    if(ID == "footballerHome"){
        file = "/Users/bartosz/CLionProjects/HelloSFML/redFootballer.png";
    }
    else if(ID == "footballerGuest"){
        file= "/Users/bartosz/CLionProjects/HelloSFML/blueFootballer.png";
    }
    else if(ID == "ball"){
        file= "/Users/bartosz/CLionProjects/HelloSFML/ball.png";
    }
    else if(ID == "field"){
        file = "/Users/bartosz/CLionProjects/HelloSFML/pitch.png";
    }

    if(!texture.loadFromFile(file)) {
        system("pause");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    sprite.setPosition(position);
}

void GameObject::update(){
    sprite.move(velocity);
}
void GameObject::draw(RenderTarget &target, RenderStates state) const{
    target.draw(this->sprite,state);
}
void GameObject::resetPosition(){
    this->sprite.setPosition(startPosition);
}