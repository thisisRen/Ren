//
// Created by Administrator on 15/11/2020.
//

#ifndef MAIN_CPP_BACKGANIMATION_H
#define MAIN_CPP_BACKGANIMATION_H
#include"SFML/Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;

class BackGAnimation {
public:
    void LoadFile(string fileName);

    void Update(float deltaTime);

    void Draw(RenderWindow&);

    void GameOver(RenderWindow&);

    void Start(RenderWindow&);


private:
    sf::RectangleShape s1, s2;
    Texture text;
    float speed = 40.0f;
};


#endif //MAIN_CPP_BACKGANIMATION_H
