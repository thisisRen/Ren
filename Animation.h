//
// Created by Administrator on 22/10/2020.
//

#ifndef MY_GAME_ANIMATION_H
#define MY_GAME_ANIMATION_H

#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;
class Animation : public sf::Drawable, public sf::Transformable {

protected:
    float m_frameTime; //tg chuyen hinh anh
    sf::Vector2u m_currentFrame; // vi tri frame hien tai
    float m_currentTime; // dem tg

    sf::Vector2u m_Size; //kich thuoc nhan vat
    sf::Vector2i m_posUV; // vi tri nhan vat
private:
    sf::Sprite* m_Sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(*m_Sprite, states);
    }

public:
    Animation(){
        m_currentFrame = sf::Vector2u(0, 0);
        m_posUV = sf::Vector2i(0, 0);
    };

    void Run(float deltatime);
    void WallJump(float deltaTime);
    void DoubleJump(float deltaTime);
    void Hit(float deltaTime);
    void Idle(float deltaTime);
    void Init(std::string name, int z);



};



#endif //MY_GAME_ANIMATION_H
