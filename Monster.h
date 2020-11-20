//
// Created by Administrator on 22/10/2020.
//

#ifndef MY_GAME_ANIMATION_H
#define MY_GAME_ANIMATION_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Animation.h"
using namespace sf;
using namespace std;
class Monster : public RectangleShape {
private:
    sf::Vector2f velocity ;
    sf::Vector2f gravity;
    bool IsCollision;
    sf::FloatRect nearestGround;
    Animation *Run;
    Animation *Fall;
    Animation *Jump;
    Animation *Idle;
    Animation *Hit;
    Animation *CurrentAnimation;
    bool isRight;
    bool OnElevator=false;
    sf::Vector2f Template;
    sf::RectangleShape shape;
    float v_elevator=100.f;
public:
    Monster(){
        velocity = sf:: Vector2f (80.f, 300.f);
        gravity = sf:: Vector2f (0,200.f);
        IsCollision=false;
        Template.y=gravity.y;
    };


   // RectangleShape getBody();


    void Init();
    void UpdateMove(float deltatime);
    void CheckCollision(vector<sf::FloatRect> &groundbounds);
    void Update(float deltatime);
    void DrawAnimation(sf::RenderWindow &window);
    void Collision2(sf::RectangleShape &shape, float v_elevator);
    sf::FloatRect GetNearestGround(vector<sf::FloatRect> &groundbounds);






};



#endif //MY_GAME_ANIMATION_H
