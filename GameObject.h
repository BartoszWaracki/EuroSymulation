#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Ball.h"
#include "Field.h"
using namespace std;
#ifndef HELLOSFML_GAMEOBJECT_H
#define HELLOSFML_GAMEOBJECT_H
class GameObject: public sf::Drawable {
public:
    GameObject(sf::Vector2f position,string file);
    virtual ~GameObject() = default;
    virtual void update();
    virtual void draw(RenderTarget &target, RenderStates state) const override;
    Vector2f  getPosition();
    Vector2f  setPosition(Vector2f& v);
    void resetPosition();

protected:
    sf::Vector2f startPosition;
    Texture texture;
    sf::Sprite sprite;
    std::string ID;
    Vector2f velocity;
};


#endif //HELLOSFML_GAMEOBJECT_H
