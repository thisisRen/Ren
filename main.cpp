
#include <iostream>
#include "Animation.h"
using namespace sf;
using namespace std;
int main(){
    sf::RenderWindow window (sf:: VideoMode(800,600), "Adventure of Monster" );
    sf::Event event;
    Sprite background;
    Texture texture;
    texture.loadFromFile("../Nature_environment_01.png");
    background.setTexture(texture);
    background.setTextureRect(IntRect(0,0,texture.getSize().x,texture.getSize().y));

    Animation animation;
   // animation.Init("../Run.png",12);
    animation.Init("../Double Jump.png",6);

    animation.setPosition(Vector2f(50,50));
    float deltaTime;
    sf::Clock clock;


    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();

        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf:: Keyboard:: Escape)
                        window.close();
                    break;
            }
        }
        window.clear(Color::Blue);


        animation.DoubleJump(deltaTime);




        window.draw(animation);
        window.display();

    }
    return 0;
}








