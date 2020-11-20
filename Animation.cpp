//
// Created by Administrator on 05/11/2020.
//

#include "Animation.h"


Animation::Animation(sf::Vector2i numFrames, float frameTime){
    m_IsRight=true;
    m_NumFrames = numFrames;
    m_FrameTime = frameTime;
    m_CurrentTime = 0.f;
    m_CurrentFrame = sf::Vector2i(0, 0);
}

//setOrigin ve giua 1 frame
void Animation::CalculateSize(){
    m_Size = sf::Vector2i(this->getTexture()->getSize().x / m_NumFrames.x, this->getTexture()->getSize().y / m_NumFrames.y);
    setOrigin((sf::Vector2f)m_Size*0.5f);
}

void Animation::ApplyRect(){
    m_Rect = sf::IntRect(m_RectUV, m_Size);
    this->setTextureRect(m_Rect);
}

//vi tri cua frame hien tai
void Animation::CalculateRectUV(){
    m_RectUV = sf::Vector2i(m_CurrentFrame.x * m_Size.x, m_CurrentFrame.y * m_Size.y);
}

//toa do frame hien tai
void Animation::Update(float deltaTime){
    m_CurrentTime += deltaTime;
    if(IsRight()==true){
        setScale(1,1);
    }
    else setScale(-1,1);


    if (m_CurrentTime >= m_FrameTime){
        m_CurrentFrame.x++;//cach chay cac frame đây. viết thêm hàm update mới.
        if (m_CurrentFrame.x == m_NumFrames.x) {
            m_CurrentFrame.x = 0;
        }
        m_CurrentTime -= m_FrameTime;
        CalculateRectUV();
        ApplyRect();
    }
}


void Animation::setDirect(bool isRight){
    m_IsRight=isRight;
}
bool Animation::IsRight() {
    return m_IsRight;
}

void Animation::Update2(float deltaTime) {
    m_CurrentTime += deltaTime;
    if (m_CurrentTime >= m_FrameTime){
        if (m_CurrentFrame.x < m_NumFrames.x-1) {
            m_CurrentFrame.x++;
            CalculateRectUV();
            ApplyRect();
        }
        m_CurrentTime -= m_FrameTime;

    }
}
