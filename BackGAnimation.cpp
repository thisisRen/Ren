//
// Created by Administrator on 15/11/2020.
//

#include "BackGAnimation.h"

void BackGAnimation::LoadFile(string fileName) {
    text.loadFromFile(fileName);
    s1.setTexture(&text);
    s2.setTexture(&text);

    s1.setSize(sf::Vector2f(800, 640));
    s2.setSize(sf::Vector2f(800, 640));

    s1.setPosition(Vector2f(0, 0));
    s2.setPosition(Vector2f(s1.getSize().x, 0));
}
void BackGAnimation::Update(float deltaTime){
    s1.move(-speed*deltaTime, 0);
    s2.move(-speed * deltaTime, 0);
    if (s2.getPosition().x <= 0.f){
        s1.setPosition(Vector2f(0, 0));
        s2.setPosition(Vector2f(s1.getSize().x, 0));
    }
}

void BackGAnimation::Draw(RenderWindow& window){
    window.draw(s1);
    window.draw(s2);
}

void BackGAnimation::GameOver(RenderWindow& window){
    Texture tmp;
    tmp.loadFromFile("../Databackground/background2.png");
    RectangleShape GO((Vector2f)window.getSize());
    GO.setTexture(&tmp);
    window.draw(GO);
}

void BackGAnimation::Start(RenderWindow & window) {
    Texture tmp;
    tmp.loadFromFile("../Databackground/background2.png");
    RectangleShape S((Vector2f)window.getSize());
    S.setTexture(&tmp);
    window.draw(S);
}
