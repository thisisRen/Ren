//
// Created by Administrator on 10/11/2020.
//

#ifndef MAIN_CPP_ITEM_H
#define MAIN_CPP_ITEM_H
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include <iostream>
using namespace sf;
class Item : public RectangleShape {
private:
    bool Alive=true;
    Animation *skin;// cai nay the lam gi. nó là skin ròi dó, bây h load ảnh cho nó nữa
    Animation *Bling;
    Animation *CurrentItem;
public:
    Item();
    void Init();
    void Update(float deltaTime);
    void DrawAnimation(sf::RenderWindow &window);
    void Collision(sf::RectangleShape shape);
    void setAnimation(Animation* newAni);
};


#endif //MAIN_CPP_ITEM_H
