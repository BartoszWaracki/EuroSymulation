#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Ball.h"
#include "Field.h"
#include <iostream>
#include "Footballer.h"
#include "GameObject.h"
#include "Team.h"

using namespace std;
using namespace sf;

int main() {
    sf::Clock clock;
    float time;

    // Creating window, setting width, Height, title
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow MainWindow(sf::VideoMode(
            desktopMode.width,
            desktopMode.height,
            desktopMode.bitsPerPixel),"Euro Simulator"
    );
    MainWindow.setVerticalSyncEnabled(true);
    MainWindow.setFramerateLimit(120);

    //Tworzenie boiska
    float x,y;
    sf::Sprite sprite;
    sf::Texture texture;
    Field field(2.55,2.05,texture,sprite);
    field.getFieldPosition(x,y,sprite, texture);
    field.matchTimer();
    field.matchResult();

    // Tworzenie zb
    std::shared_ptr<Team> team1 = std::make_shared<Team>(Team::Side::Right);
    std::shared_ptr<Team> team2 = std::make_shared<Team>(Team::Side::Left);

    std::vector<Footballer*> footballers;  // Kontener przechowujący wskaźniki na piłkarzy
    std::vector<Footballer*> opponents;
    std::string file;
    std::string file1;
    if(team1->getSide() == Team::Side::Left){

        file1 ="/Users/bartosz/CLionProjects/HelloSFML/redFootballer.png";
        file = "/Users/bartosz/CLionProjects/HelloSFML/blueFootballer.jpeg";
    }
    else {
        file1 ="/Users/bartosz/CLionProjects/HelloSFML/blueFootballer.jpeg";
        file ="/Users/bartosz/CLionProjects/HelloSFML/redFootballer.png";
    }

    Footballer* footballer1 = new Footballer(sf::Vector2f(130,810), team1,file1);
    footballers.push_back(footballer1);
    Footballer* footballer2 = new Footballer(sf::Vector2f(600,290), team1,file1);
    footballers.push_back(footballer2);


    Footballer* footballer3 = new Footballer(sf::Vector2f(1500,810), team2,file);
    footballers.push_back(footballer3);
    Footballer* footballer4 = new Footballer(sf::Vector2f(1900,690), team2,file);
    footballers.push_back(footballer4);

    std::string file2;
    Vector2f vect{1275,780};
    Ball *ball = new Ball(vect,file2);
//  mozna zrobic dodawanie obserwatorów do piłkarzy (jeśli wymagane)
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));

    while (MainWindow.isOpen()) {

        Event event;
        while (MainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                MainWindow.close();
        }
        MainWindow.clear();

        ball->update(x,y);    // Ball moves with some velocity

        for (auto& footballer : footballers) {
            footballer->executeGameplay(footballers,ball);
        }

        field.timerUpdate();
        MainWindow.draw(field);

        for (auto& footballer : footballers) {
            MainWindow.draw(*footballer);
            rectangle.setPosition(footballer->getPosition());
            MainWindow.draw(rectangle);
        }
        MainWindow.draw(*ball);
        MainWindow.display();
    }
// Zwolnienie pamięci po obiektach
    for (auto footballer : footballers) {
        delete footballer;
    }
    delete ball;
    return 0;
}
