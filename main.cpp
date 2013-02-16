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
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            spelare1.shoot();
        }
        spelare1.bulletCollision(spelare2);
        spelare2.bulletCollision(spelare1);
        spelare1.flyingBullets(ElapsedTime);

        
        App.clear(Color::White);
        spelare1.draw(App);
        spelare2.draw(App);
        App.display();
    }
}