#include<vector>
#ifndef NAMESPACE_STD
#define NAMESPACE_STD
using namespace std;
#endif

#ifndef NAMESPACE_SF
#define NAMESPACE_SF
using namespace sf;
#endif

enum PlayerMovement {up, down};


class Spelare{
    int Health;
    RectangleShape tank;
    RectangleShape cannon;
    char ShootingDirection;
    vector<RectangleShape>Bullets;
    
public:
    Spelare(int PlayerNum, string SetName, int ScreenWidth, int ScreenHeight);
    void draw(RenderWindow &App);
    void move(PlayerMovement UpDown, Time &ElapsedTime);
    void shoot();
    void flyingBullets(Time &ElapsedTime);
};

Spelare::Spelare(int PlayerNum, string SetName, int ScreenWidth, int ScreenHeight)
{
    Health=100;
    
    tank.setSize(Vector2f(ScreenWidth/10, ScreenHeight/10));
    cannon.setSize(Vector2f(ScreenWidth/20, ScreenHeight/64));
    
    if(PlayerNum==1){
        tank.setFillColor(Color::Red);
        cannon.setFillColor(Color::Red);
        tank.setPosition(ScreenWidth/40, ScreenHeight/2);
        cannon.setPosition(ScreenWidth/8, ScreenHeight/2 + ScreenHeight/20-ScreenHeight/128);
        ShootingDirection = 1;
    } else{
        tank.setFillColor(Color::Blue);
        cannon.setFillColor(Color::Blue);
        tank.setPosition(ScreenWidth-ScreenWidth/8, ScreenHeight/2);
        cannon.setPosition(ScreenWidth-ScreenWidth/8-ScreenWidth/20, ScreenHeight/2 + ScreenHeight/20-ScreenHeight/128);
        ShootingDirection = -1;
    }
}

void Spelare::draw(RenderWindow &App)
{
    App.draw(tank);
    App.draw(cannon);
    for (int i=0; i<Bullets.size(); i++) {
        App.draw(Bullets[i]);
    }
}

void Spelare::move(PlayerMovement UpDown, Time &ElapsedTime)
{
    if(UpDown == up){
        tank.move(0, -500 * ElapsedTime.asSeconds());
        cannon.move(0, -500 * ElapsedTime.asSeconds());
    } else{
        tank.move(0, 500 * ElapsedTime.asSeconds());
        cannon.move(0, 500 * ElapsedTime.asSeconds());
    }
}

void Spelare::shoot()
{
    RectangleShape tempObject;
    tempObject.setSize(Vector2f(cannon.getSize().x / 1.5, cannon.getSize().y / 1.5));
    tempObject.setPosition(tank.getPosition().x + tank.getSize().x + cannon.getSize().x/2, tank.getPosition().y + tank.getSize().y/2);
    tempObject.setFillColor(Color::Black);
    Bullets.push_back(tempObject);
}

void Spelare::flyingBullets(Time &ElapsedTime)
{
    for (int i=0; i < Bullets.size(); i++){
        if(Bullets[i].getPosition().x > 300 || Bullets[i].getPosition().x < 0){
            Bullets.erase(Bullets.begin()+i);
        }
        else{
            Bullets[i].move(300 * ElapsedTime.asSeconds() * ShootingDirection, 0);
        }
    }
}