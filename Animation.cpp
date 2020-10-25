//
// Created by Administrator on 22/10/2020.
//

#include "Animation.h"


void Animation::Init(std::string name, int z) {
    m_currentFrame.y = 1;
    m_frameTime = 0.05f;
    m_Sprite = new sf::Sprite();
    sf::Texture* texture;
    texture = new sf::Texture();
    std::cout << texture->loadFromFile(name);

    m_Sprite->setTexture(*texture);
    m_Size = sf::Vector2u(texture->getSize().x / z, texture->getSize().y);
}
void Animation:: Run(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if(m_currentFrame.x==12){
            m_currentFrame.x=0;
        }
        m_currentTime-=m_frameTime;
    }
    m_posUV.x = m_currentFrame.x * m_Size.x;

    m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));
}

void Animation:: DoubleJump(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if(m_currentFrame.x==6){
            m_currentFrame.x=0;
        }
        m_currentTime-=m_frameTime;
    }
    m_posUV.x = m_currentFrame.x * m_Size.x;

    m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));
}

void Animation:: Hit(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if(m_currentFrame.x==7){
            m_currentFrame.x=0;
        }
        m_currentTime-=m_frameTime;
    }
    m_posUV.x = m_currentFrame.x * m_Size.x;

    m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));
}
void Animation:: WallJump(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if(m_currentFrame.x==7){
            m_currentFrame.x=0;
        }
        m_currentTime-=m_frameTime;
    }
    m_posUV.x = m_currentFrame.x * m_Size.x;

    m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));
}
void Animation:: Idle(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if(m_currentFrame.x==11){
            m_currentFrame.x=0;
        }
        m_currentTime-=m_frameTime;
    }
    m_posUV.x = m_currentFrame.x * m_Size.x;

    m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));
}
