//
// Created by Administrator on 05/11/2020.
//

#ifndef MAIN_CPP_ANIMATION_H
#define MAIN_CPP_ANIMATION_H

#include "SFML/Graphics.hpp"
#include <iostream>
#pragma once


class Animation: public sf::Sprite{

public:
    Animation(sf::Vector2i numFrames, float frameTime);
    void CalculateSize();
    void ApplyRect();
    void Update(float deltaTime);
    void Update2(float deltaTime);
    void setDirect(bool isRight);
    bool IsRight();
private:
    void CalculateRectUV();
    sf::Vector2i m_NumFrames;
    sf::Vector2i m_CurrentFrame;

    sf::IntRect m_Rect;
    sf::Vector2i m_Size;
    sf::Vector2i m_RectUV;

    float m_FrameTime;
    float m_CurrentTime;
    bool m_IsRight;
};

#endif //MAIN_CPP_ANIMATION_H
