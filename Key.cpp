//
// Created by Administrator on 12/11/2020.
//

#include "Key.h"
#include <iostream>
using namespace std;
Key ::Key() {
    this->setPosition(70.f,50.f);
    this->setSize(sf::Vector2f (20.f,20.f));
    this->setFillColor(sf::Color(0,0,0,0));//cai dat cho cai khung xuong trong suot
    this->setOutlineColor(sf::Color::Red);//Set mau vien cho khung
    this->setOutlineThickness(1.f);//set do day cho vien

}
void Key ::Init() {
    key = new Animation(sf::Vector2i(1.f,1.f),0.05f);


    Texture *texture;
    texture=new Texture();

    texture->loadFromFile("../Objects//key.png");
    key->setTexture(*texture);
    key->CalculateSize();
    key->ApplyRect();

}
void Key ::DrawAnimation(sf::RenderWindow &window) {
    if (haveKey==true) return;
    window.draw(*key);//ve dai anh animation
    //window.draw(*this);//ve cai khung

}

void Key::Collision(sf::RectangleShape shape) {
    if (this->getGlobalBounds().intersects(shape.getGlobalBounds())) haveKey=true;
}

void Key::Update(float deltaTime) {
    if (haveKey==true) return;
    key->setPosition(this->getPosition());//Update vi tri cho skin

}

bool Key::Check() {
    if(haveKey==true) return true;
    else return false;
}
