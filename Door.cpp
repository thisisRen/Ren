//
// Created by Administrator on 11/11/2020.
//

#include "Door.h"
void Door ::Init() {
    Closing = new Animation(sf::Vector2i(3,1),0.05f);
    Opening = new Animation(sf::Vector2i(5,1),0.05f);
    Idle = new Animation(sf::Vector2i(1,1),0.05f);

    Texture *texture;
    texture=new Texture();

    if(texture->loadFromFile("../Door//Closing.png") ) {
        Closing->setTexture(*texture);
        Closing->CalculateSize();
        Closing->ApplyRect();
        Closing->setOrigin(this->getSize()*0.5f);
    }

    texture=new Texture();
    if(texture->loadFromFile("../Door//Opening.png") ) {
        Opening->setTexture(*texture);
        Opening->CalculateSize();
        Opening->ApplyRect();
        Opening->setOrigin(this->getSize()*0.5f);
    }

    texture=new Texture();
    if(texture->loadFromFile("../Door//Idle.png") ) {
        Idle->setTexture(*texture);
        Idle->CalculateSize();
        Idle->ApplyRect();
        Idle->setOrigin(this->getSize()*0.5f);
    }

    DoorAnimation=Idle;

}
void Door ::Update(float deltaTime) {
    DoorAnimation->setPosition(this->getPosition());
    if(Congrat==true)DoorAnimation->Update(deltaTime);
    else{
        DoorAnimation->Update2(deltaTime);
    }


}

void Door ::DrawAnimation(sf::RenderWindow &window){

    if( this->Check()==true ){
        DoorAnimation= Opening;
    }
    window.draw(*DoorAnimation);
   // window.draw(*this);
}
void Door::Collision(sf::RectangleShape shape) {// truyen cai gif vao day? monster
    if (this->getGlobalBounds().intersects(shape.getGlobalBounds())){
        Congrat=false;
        return;
    }
    Congrat=true;
}
bool Door::Check(){
    if(Congrat==false && haveKey) return true;
    else return false;
}

void Door::checkKey(bool isHaveKey) {
    haveKey=isHaveKey;
}
