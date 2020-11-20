//
// Created by Administrator on 11/11/2020.
//

#ifndef MAIN_CPP_DOOR_H
#define MAIN_CPP_DOOR_H
#include "Animation.h"
#include "Key.h"
using namespace sf;
using namespace std;

class Door : public RectangleShape{
private:
    Animation *Closing;
    Animation *Opening;
    Animation *Idle;
    Animation *DoorAnimation;
    bool Congrat = true;
    bool haveKey;


public:
    void Init();
    void Update(float deltatime);
    void DrawAnimation(sf::RenderWindow &window);
    void Collision(sf::RectangleShape shape);
    void checkKey(bool isHaveKey);
    bool Check();

};


#endif //MAIN_CPP_DOOR_H
