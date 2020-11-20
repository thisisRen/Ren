//
// Created by Administrator on 10/11/2020.
//

#include "Item.h"
#include <iostream>
using namespace std;
Item ::Item() {
    this->setPosition(100.f,100.f);
    this->setSize(sf::Vector2f (16.f,16.f));
    this->setFillColor(sf::Color(0,0,0,0));//cai dat cho cai khung xuong trong suot
    this->setOutlineColor(sf::Color::Red);//Set mau vien cho khung
    this->setOutlineThickness(1.f);//set do day cho vien

}
void Item ::Init() {
    skin = new Animation(sf::Vector2i(17.f,1.f),0.05f);
    Bling = new Animation(sf::Vector2i(6.f,1.f),0.05f);

    Texture *texture;
    texture=new Texture();

    if(texture->loadFromFile("../Fruits//Melon.png")){
        skin->setTexture(*texture);
        skin->CalculateSize();
        skin->ApplyRect();
        skin->setOrigin(this->getSize()*0.5f);
    }

    texture=new Texture();
    if(texture->loadFromFile("../Fruits//Collected.png")){
        Bling->setTexture(*texture);
        Bling->CalculateSize();
        Bling->ApplyRect();
        Bling->setOrigin(this->getSize()*0.5f);
    }
    CurrentItem=skin;
}

void Item ::DrawAnimation(sf::RenderWindow &window) {
    if (Alive==false){
      //  window.draw(*Bling);
        return;
    }
    window.draw(*skin);//ve dai anh animation
   // window.draw(*this);//ve cai khung


}

void Item::Collision(sf::RectangleShape shape) {
    if (this->getGlobalBounds().intersects(shape.getGlobalBounds())) Alive=false;

}

void Item::Update(float deltaTime) {
    if (Alive==false){
//        Bling->Update(deltaTime);//Update animation cho skin
//        Bling->setPosition(this->getPosition());
        return;
    }

    skin->Update(deltaTime);//Update animation cho skin
    skin->setPosition(this->getPosition());


}

void Item::setAnimation(Animation *newAni) {
    skin=newAni;//ham nay de cai dat animation cho skin
    //neu ma dung ham nay, thi minh khong can Init nua. boi vi animation dc khoi tao o ngoai roi, minh chi can truyen vao thoi
}
