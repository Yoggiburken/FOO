#ifndef NAMESPACE_STD
#define NAMESPACE_STD
using namespace std;
#endif

#ifndef NAMESPACE_SF
#define NAMESPACE_SF
using namespace sf;
#endif


class Spelare{
    int Health;
    RectangleShape shape;
    RectangleShape cannon;
    
public:
    Spelare(int PlayerNum, string SetName, int ScreenWidth, int ScreenHeight);
    void draw(RenderWindow &App);
    void move(bool up, Time ElapsedTime);
};

Spelare::Spelare(int PlayerNum, string SetName, int ScreenWidth, int ScreenHeight)
{
    Health=100;
    Name.setString(SetName.c_str());
    
    shape.setSize(Vector2f(ScreenWidth/10, ScreenHeight/10));
    cannon.setSize(Vector2f(ScreenWidth/20, ScreenHeight/64));
    
    if(PlayerNum==1){
        shape.setFillColor(Color::Red);
        cannon.setFillColor(Color::Red);
        shape.setPosition(ScreenWidth/40, ScreenHeight/2);
        cannon.setPosition(ScreenWidth/8, ScreenHeight/2 + ScreenHeight/20-ScreenHeight/128);
    } else{
        shape.setFillColor(Color::Blue);
        cannon.setFillColor(Color::Blue);
        shape.setPosition(ScreenWidth-ScreenWidth/8, ScreenHeight/2);
        cannon.setPosition(ScreenWidth-ScreenWidth/8-ScreenWidth/20, ScreenHeight/2 + ScreenHeight/20-ScreenHeight/128);
    }
}

void Spelare::draw(RenderWindow &App)
{
    App.draw(shape);
    App.draw(cannon);
}

void Spelare::move(bool up, Time ElapsedTime)
{
    if(up==true){
        shape.move(0, -500*ElapsedTime.asSeconds());
        cannon.move(0, -500*ElapsedTime.asSeconds());
    } else{
        shape.move(0,500*ElapsedTime.asSeconds());
        cannon.move(0,500*ElapsedTime.asSeconds());
    }
}