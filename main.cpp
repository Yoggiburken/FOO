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
        
        if(Keyboard::isKeyPressed(Keyboard::P)){
            ElapsedTime = clock.getElapsedTime();
            spelare2.move(up, ElapsedTime);
        }
        if(Keyboard::isKeyPressed(Keyboard::L)){
            ElapsedTime = clock.getElapsedTime();
            spelare2.move(down, ElapsedTime);
        }
        if(Keyboard::isKeyPressed(Keyboard::W)){
            ElapsedTime = clock.getElapsedTime();
            spelare1.move(up, ElapsedTime);
        }
        if(Keyboard::isKeyPressed(Keyboard::D)){
            ElapsedTime = clock.getElapsedTime();
            spelare1.move(down, ElapsedTime);
        }
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            spelare1.shoot();
        }
        spelare1.flyingBullets(ElapsedTime);
        clock.restart();
        
        App.clear(Color::White);
        spelare1.draw(App);
        spelare2.draw(App);
        App.display();
    }
}