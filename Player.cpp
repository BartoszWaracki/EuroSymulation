//#include <vector>
//#include "Player.h"
//#include "random"
//#include <iostream>
//
//Player::Player(float t_X, float t_Y) {
//    startingPoint.x = t_X;
//    startingPoint.y = t_Y;
//    if(t_X> 100 && t_X <= 200){
//        ID = "bramkarz";
//    }
//    if(t_X> 200 && t_X <= 500){
//        ID = "obronca";
//    }
//    if(t_X> 500 && t_X <= 750){
//        ID = "pomocnik";
//    }
//    if(t_X> 750 ){
//        ID = "napastnik";
//    }
//
//    if(!footballerImage.loadFromFile("/Users/bartosz/CLionProjects/HelloSFML/redFootballer.png")) {
//        system("pause");
//    }
//    footballerImage.setSmooth(true);
//    redFootballerSprite.setTexture(footballerImage);
//    redFootballerSprite.setOrigin(footballerImage.getSize().x/2,footballerImage.getSize().y/2);
//    redFootballerSprite.setPosition(t_X,t_Y);
//
//}
//
//std::string Player::getPlayerID() {
//    return ID;
//}
//
//Vector2f Player::getStartingPoint() {
//    return startingPoint;
//}
//void Player::draw(RenderTarget& target, RenderStates state) const
//{
//    target.draw(this->redFootballerSprite,state);
//}
//void Player::setPosition(Vector2f& v){
//    v = redFootballerSprite.getPosition();
//}
//void Player::update()
//{
//    redFootballerSprite.move(this->velocity);
//}
//
//Vector2f Player::getPosition(){
//    return redFootballerSprite.getPosition();
//}
//
//Vector2u Player::getSize() {
//    return footballerImage.getSize();
//}
//
//void Player::collisiomTest(Player & player , Ball & ball, Player &player2 ){
//
//    if (abs(ball.getPosition().x - player.getPosition().x) <= 10 && abs(ball.getPosition().y - player.getPosition().y) <= 10)  {
//
//        ball.stopBall();
//        Vector2f v = player.getPosition();
//        ball.setPosition(v);
//        player.havingBall = true;
//        player.ballPassed = false;
//
//    }
//    if (abs(ball.getPosition().x - player2.getPosition().x) <= 15 && abs(ball.getPosition().y - player2.getPosition().y) <= 15) {
//
//        ball.stopBall();
//        Vector2f v = player2.getPosition();
//        ball.setPosition(v);
//        player2.havingBall = true;
//        player.ballPassed = false;
//
//    }
//}
//
//void Player::ballPass(Player& player,Ball& ball,Player& player2){
//    Vector2f vect;
//    if(player.havingBall == true)
//    {
//        if (player.getPosition() != player2.getPosition()) {
//
//            if (player.getPosition().x >= player2.getPosition().x && player.getPosition().y >= player2.getPosition().y) {
//                float radius = 12.2;
//                if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 20;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 20;
//                    ball.kickBall(vect);
//                }
//                else{
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 40;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 40;
//                    ball.kickBall(vect);
//                }
//                player.havingBall = false;
//                player.ballPassed = true;
//
//
//            }
//            if (player.getPosition().x < player2.getPosition().x && player.getPosition().y < player2.getPosition().y) {
//                float radius = 12.2;
//                if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 20;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 20;
//                    ball.kickBall(vect);
//                }
//                else{
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 40;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 40;
//                    ball.kickBall(vect);
//                }
//                player.havingBall = false;
//                player.ballPassed = true;
//
//
//
//            }
//            if (player.getPosition().x < player2.getPosition().x && player.getPosition().y > player2.getPosition().y) {
//                float radius = 12.2;
//                if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 20;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 20;
//                    ball.kickBall(vect);
//                }
//                else{
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 40;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 40;
//                    ball.kickBall(vect);
//                }
//                player.havingBall = false;
//                player.ballPassed = true;
//
//
//
//            }
//            if (player.getPosition().x > player2.getPosition().x && player.getPosition().y < player2.getPosition().y) {
//                float radius = 12.2;
//                if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 20;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 20;
//                    ball.kickBall(vect);
//                }
//                else{
//                    vect.x = (player2.getPosition().x - player.getPosition().x) / 40;
//                    vect.y = (player2.getPosition().y - player.getPosition().y) / 40;
//                    ball.kickBall(vect);
//                }
//                player.havingBall = false;
//                player.ballPassed = true;
//
//            }
//
//        }
//    }
//    if(player2.havingBall == true)
//    {
//        if (player2.getPosition() != player.getPosition()) {
//
//                if (player2.getPosition().x >= player.getPosition().x && player2.getPosition().y >= player.getPosition().y) {
//                    float radius = 12.2;
//                    if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 20;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 20;
//                        ball.kickBall(vect);
//                    }
//                    else{
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 40;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 40;
//                        ball.kickBall(vect);
//                    }
//                    player2.havingBall = false;
//                    player2.ballPassed = true;
//
//                }
//
//                if (player2.getPosition().x < player.getPosition().x && player2.getPosition().y < player.getPosition().y) {
//                    float radius = 12.2;
//                    if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 20;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 20;
//                        ball.kickBall(vect);
//                    }
//                    else{
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 40;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 40;
//                        ball.kickBall(vect);
//                    }
//                    player2.havingBall = false;
//                    player2.ballPassed = true;
//
//                }
//                if (player2.getPosition().x < player.getPosition().x && player2.getPosition().y > player.getPosition().y) {
//                    float radius = 12.2;
//                    if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 20;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 20;
//                        ball.kickBall(vect);
//                    }
//                    else{
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 40;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 40;
//                        ball.kickBall(vect);
//                    }
//                    player2.havingBall = false;
//                    player2.ballPassed = true;
//
//                }
//
//                if (player2.getPosition().x > player.getPosition().x && player2.getPosition().y < player.getPosition().y) {
//                    float radius = 12.2;
//                    if(sqrt(pow((player.getPosition().x-ball.getPosition().x),2)+pow((player.getPosition().y-ball.getPosition().y),2)) < radius){
//                        vect.x = (player.getPosition().x - player2.getPosition().x/20);
//                        vect.y = (player.getPosition().y - player2.getPosition().y/20);
//                        ball.kickBall(vect);
//                    }
//                    else{
//                        vect.x = (player.getPosition().x - player2.getPosition().x) / 40;
//                        vect.y = (player.getPosition().y - player2.getPosition().y) / 40;
//                        ball.kickBall(vect);
//                    }
//                    player2.havingBall = false;
//                    player2.ballPassed = true;
//
//                }
//
//        }
//    }
//
//}
//
//// dodac enemies i i jakies zasady z bramkami i ze swoja druzyna i ruch do bramki tez
//// badac otoczenie pilkarza i wyznaczac najkrotsza droge do srodka bramki xd
//// dodac ruch po podaniu pilkarza
//void Player::checkSurroundings(Player& player,Ball& ball, Player& player1){
//    checkShootDistance(player1,ball);
//    checkShootDistance(player,ball);
//    int const radius = 400;
//
//    collisiomTest(player,ball,player1);
//
//
//
//    if(player.havingBall == true ){
//
//        if((sqrt(pow((player.getPosition().x-player1.getPosition().x),2)+pow((player.getPosition().y-player1.getPosition().y),2)) > radius)&&(player.decideShooting == false)){
//            player.surroundingClean = true;
//            Vector2f v = player.getPosition();
//            ball.setPosition(v);
//            player.velocity.x = 30;
//            player.velocity.y = 0;
//            player.update();
//
//        }
//        if((sqrt(pow((player.getPosition().x-player1.getPosition().x),2)+pow((player.getPosition().y-player1.getPosition().y),2)) <= radius)&&(player.decideShooting == false)){
//            player.surroundingClean = false;
//            player.velocity.x = 0;
//            player.velocity.y = 0;
//            player.update();
//            ballPass(player,ball,player1);
//
//
//        }
//        if(player.decideShooting == true){
//            Shoot(player,ball);
//
//        }
//
//    }
//    if(player1.havingBall == true){
//
//        if((sqrt(pow((player.getPosition().x-player1.getPosition().x),2)+pow((player.getPosition().y-player1.getPosition().y),2)) > radius)&&(player1.decideShooting == false)){
//            player1.surroundingClean = true;
//            Vector2f v = player1.getPosition();
//            ball.setPosition(v);
//            player1.velocity.x = 30;
//            player1.velocity.y = 0;
//            player1.update();
//
//        }
//        if((sqrt(pow((player.getPosition().x-player1.getPosition().x),2)+pow((player.getPosition().y-player1.getPosition().y),2)) <= radius)&&(player1.decideShooting == false)){
//            player1.surroundingClean = false;
//            player1.velocity.x = 0;
//            player1.velocity.y = 0;
//            player1.update();
//            ballPass(player1,ball,player);
//            // ten sie rusza a ten wyzej go nasladuje i za nim biegnie
//            player1.velocity.x = rand() % 50 + 20;
//           // player1.velocity.y = rand() % 70 - 35;
//            player1.update();
//
//        }
//        if(player1.decideShooting == true){
//            Shoot(player1,ball);
//        }
//    }
//
//}
//
//void Player::checkShootDistance(Player& player, Ball& ball){
//    Vector2f v{2467,900};
//     // bramka prawa
//if((sqrt(pow((player.getPosition().x-v.x),2)+pow((player.getPosition().y-v.y),2)) <= 500)&& player.getPosition().x >= 1400){
//    player.decideShooting = true;
//}}
//
//void Player::Shoot(Player& player, Ball& ball){
//    if(player.decideShooting == true){
//        Vector2f  vect;
//        // dodac mnozniki w zaleznosci od pozycji
//        vect.x = (FootballTarget.x - player.getPosition().x) / 20;
//        vect.y = (FootballTarget.y - player.getPosition().y) / 20;
//        ball.kickBall(vect);
//        decideShooting = false;
//
//    }
//}
//
//void Player::moveAfterPassing(Player& player){
//        player.update();
//}
//// TRZEBA POMYSLEC JAK ZATRZYMAC PILKARZA TYLKO RAZ w miejscu spotkania z drugim
//// trzeba zachowanie dla kazdego pilakrza w zaleznosci od ID zrobic
//// jezeli wokol pilkarza bedzie enemy to podaj pilke do najblizszego pilkarza i jezeli obronca to powroc na swoje miejsce jezeli pomocnkk to
//// staraj sie uczestniczyc w akcji a jezeli napad to wybiegaj na pozycje