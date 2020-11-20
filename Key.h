//
// Created by Administrator on 12/11/2020.
//

#ifndef MAIN_CPP_KEY_H
#define MAIN_CPP_KEY_H
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include <iostream>
using namespace sf;

class Key : public RectangleShape {
private:
    bool haveKey=false;
    Animation *key;
public:
    Key();
    void Init();
    void Update(float deltaTime);
    void DrawAnimation(sf::RenderWindow &window);
    void Collision(sf::RectangleShape shape);
    bool Check();
};


#endif //MAIN_CPP_KEY_H
