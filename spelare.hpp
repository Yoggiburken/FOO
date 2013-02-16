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
    char ShootingDirection;
    vector<RectangleShape>Bullets;
    int dmg;
    
public:
    Spelare(int PlayerNum, string SetName, int ScreenWidth, int ScreenHeight);
    void draw(RenderWindow &App);
    void bulletCollision(Spelare &spelare);
    void move(PlayerMovement UpDown, Time &ElapsedTime);
    void shoot();
    void flyingBullets(Time &ElapsedTime);
    RectangleShape tank;
    RectangleShape cannon;
    RectangleShape healthbar;
    int Health;
};

Spelare::Spelare(int PlayerNum, string SetName, int ScreenWidth, int ScreenHeight)
{
    Health=100;
    dmg=10;
    
    tank.setSize(Vector2f(ScreenWidth/10, ScreenHeight/10));
    cannon.setSize(Vector2f(ScreenWidth/20, ScreenHeight/64));
    
    if(PlayerNum==1){
        tank.setFillColor(Color::Red);
        cannon.setFillColor(Color::Red);
        tank.setPosition(ScreenWidth/40, ScreenHeight/2);
        cannon.setPosition(ScreenWidth/8, ScreenHeight/2 + ScreenHeight/20-ScreenHeight/128);
        ShootingDirection = 1;
        healthbar.setFillColor(Color::Red);
        healthbar.setOutlineColor(Color::Black);
        healthbar.setOutlineThickness(2);
        healthbar.setPosition(10, 5);
        healthbar.setSize(Vector2f(Health, 20));
    } else{
        tank.setFillColor(Color::Blue);
        cannon.setFillColor(Color::Blue);
        tank.setPosition(ScreenWidth-ScreenWidth/8, ScreenHeight/2);
        cannon.setPosition(ScreenWidth-ScreenWidth/8-ScreenWidth/20, ScreenHeight/2 + ScreenHeight/20-ScreenHeight/128);
        ShootingDirection = -1;
        healthbar.setFillColor(Color::Red);
        healthbar.setOutlineColor(Color::Black);
        healthbar.setOutlineThickness(2);
        healthbar.setPosition(300-Health-10, 5);
        healthbar.setSize(Vector2f(Health, 20));
    }
}

void Spelare::bulletCollision(Spelare &spelare)
{
    if(Bullets.size()   !=  0){
        double BulletSizeX      =   Bullets[0].getSize().x;
        double BulletSizeY      =   Bullets[0].getSize().y;
        
        double CannonPositionX  =   spelare.cannon.getPosition().x;
        double CannonSizeX      =   spelare.cannon.getSize().x;
        double CannonPositionY  =   spelare.cannon.getPosition().y;
        double CannonSizeY      =   spelare.cannon.getSize().y;
        
        double TankPositionX    =   spelare.tank.getPosition().x;
        double TankSizeX        =   spelare.tank.getSize().x;
        double TankPositionY    =   spelare.tank.getPosition().y;
        double TankSizeY        =   spelare.tank.getSize().y;
    
        for(int i=0; i<Bullets.size(); i++){
            double BulletPositionX  =   Bullets[i].getPosition().x;
            double BulletPositionY  =   Bullets[i].getPosition().y;
            
            //collision with cannon
            if(BulletPositionX   >   CannonPositionX){
                if(BulletPositionX   <   CannonPositionX + CannonSizeX){
                    if(BulletPositionY  >   CannonPositionY){
                        if(BulletPositionY  <   CannonPositionY + CannonSizeY){
                            spelare.Health -= dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    } else if(BulletPositionY + BulletSizeY   >   CannonPositionY){
                        if(BulletPositionY + BulletSizeY    < CannonPositionY + CannonSizeY){
                            spelare.Health -=dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    }
                }
            } else if(BulletPositionX + BulletSizeX   >   CannonPositionX){
                if(BulletPositionX + BulletSizeX    <   CannonPositionX + CannonSizeX){
                    if(BulletPositionY  >   CannonPositionY){
                        if(BulletPositionY  <   CannonPositionY + CannonSizeY){
                            spelare.Health -= dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    } else if(BulletPositionY + BulletSizeY   >   CannonPositionY){
                        if(BulletPositionY + BulletSizeY    < CannonPositionY + CannonSizeY){
                            spelare.Health  -=  dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    }
                }
            }
            
            //collision with tank
            if(BulletPositionX   >   TankPositionX){
                if(BulletPositionX   <   TankPositionX + TankSizeX){
                    if(BulletPositionY  >   TankPositionY){
                        if(BulletPositionY  <   TankPositionY + TankSizeY){
                            spelare.Health  -=  dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    } else if(BulletPositionY + BulletSizeY   >   TankPositionY){
                        if(BulletPositionY + BulletSizeY    <   TankPositionY + TankSizeY){
                            spelare.Health  -=  dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    }
                }
            } else if(BulletPositionX + BulletSizeX   >   TankPositionX){
                if(BulletPositionX + BulletSizeX    <   TankPositionX + TankSizeX){
                    if(BulletPositionY  >   TankPositionY){
                        if(BulletPositionY  <   TankPositionY + TankSizeY){
                            spelare.Health  -=  dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    } else if(BulletPositionY + BulletSizeY   >   TankPositionY){
                        if(BulletPositionY + BulletSizeY    < TankPositionY + TankSizeY){
                            spelare.Health -=dmg;
                            Bullets.erase(Bullets.begin()+i);
                            spelare.healthbar.setSize(Vector2f(spelare.Health, 20));
                            continue;
                        }
                    }
                }
            }
        }
    }
}


void Spelare::draw(RenderWindow &App)
{
    App.draw(tank);
    App.draw(cannon);
    App.draw(healthbar);
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
           

