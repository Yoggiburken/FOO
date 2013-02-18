#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include"spelare.hpp"

#ifndef NAMESPACE_SF
#define NAMESPACE_SF
using namespace sf;
#endif

#ifndef NAMESPACE_STD
#define NAMESPACE_STD
using namespace std;
#endif

int main()
{
    int WIDTH=300;
    int HEIGHT=300;
    double player1shoottimer;
    bool Player1ShoottimerReady = true;
    RenderWindow App(VideoMode(WIDTH, HEIGHT, 32),"Test");
    
    Spelare spelare1(1, "Albin", WIDTH, HEIGHT);
    Spelare spelare2(2, "David", WIDTH, HEIGHT);
    
    Clock clock;
    Time ElapsedTime;
    
    Event event;
    while(App.isOpen()){
        while(App.pollEvent(event)){
            if(event.type==Event::Closed){
                App.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                App.close();
            }
        }
        ElapsedTime=clock.getElapsedTime();
        clock.restart();
        if(Keyboard::isKeyPressed(Keyboard::P)){
            spelare2.move(up, ElapsedTime);
        } 
        if(Keyboard::isKeyPressed(Keyboard::L)){
            spelare2.move(down, ElapsedTime);
        } 
        if(Keyboard::isKeyPressed(Keyboard::W)){
            spelare1.move(up, ElapsedTime);
        } 
        if(Keyboard::isKeyPressed(Keyboard::D)){
            spelare1.move(down, ElapsedTime);
        } 
        if(Keyboard::isKeyPressed(Keyboard::K)){
            spelare2.shoot();
        }
        if(Keyboard::isKeyPressed(Keyboard::Space) && Player1ShoottimerReady){
            spelare1.shoot();
            Player1ShoottimerReady = false;
        } 
        if(!Player1ShoottimerReady){
            player1shoottimer += ElapsedTime.asSeconds();
            if(player1shoottimer >= 0.1){
                Player1ShoottimerReady = true;
                player1shoottimer =0;
            }
        }
        spelare1.repair(ElapsedTime);
        spelare2.repair(ElapsedTime);
        spelare1.bulletCollision(spelare2);
        spelare2.bulletCollision(spelare1);
        spelare1.flyingBullets(ElapsedTime);
        spelare2.flyingBullets(ElapsedTime);

        App.clear(Color::White);
        spelare1.draw(App);
        spelare2.draw(App);
        App.display();
    }
}