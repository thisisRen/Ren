
//Created by Administrator on 22/10/2020.


#include "Monster.h"

void Monster::Init() {
    Run = new Animation(sf::Vector2i(12,1), 0.05f);
    Fall = new Animation(sf::Vector2i(1,1), 0.05f);
    Jump = new Animation(sf::Vector2i(1,1), 0.05f);
    Idle = new Animation(sf::Vector2i(11,1), 0.05f);
    Hit = new Animation(sf::Vector2i(7,1), 0.05f);
    Texture *texture;
    texture=new Texture();

    if(texture->loadFromFile("../Datamain//Run.png") ){
        Run->setTexture(*texture);
        Run->CalculateSize();
        Run->setDirect(true);
        Run->ApplyRect();
    }
    texture=new Texture();
    if(texture->loadFromFile("../Datamain//Hit.png") ){
        Hit->setTexture(*texture);
        Hit->CalculateSize();
        Hit->setDirect(true);
        Hit->ApplyRect();


    }
    texture=new Texture();
    if(texture->loadFromFile("../Datamain//Jump.png") ){
        Jump->setTexture(*texture);
        Jump->CalculateSize();
        Jump->setDirect(true);
        Jump->ApplyRect();
    }
    texture=new Texture();
    if(texture->loadFromFile("../Datamain//Fall.png") ){
        Fall->setTexture(*texture);
        Fall->CalculateSize();
        Fall->setDirect(true);
        Fall->ApplyRect();

    }
    texture=new Texture();
    if(texture->loadFromFile("../Datamain//Idle.png") ){
        Idle->setTexture(*texture);
        Idle->CalculateSize();
        Idle->setDirect(true);
        Idle->ApplyRect();

    }
    CurrentAnimation = Idle;
    isRight=true;


}
//check groundbounds
void Monster::CheckCollision(vector<sf::FloatRect> &groundbounds) {
    nearestGround=GetNearestGround(groundbounds)  ;
    IsCollision=this->getGlobalBounds() .intersects(nearestGround)  ;


}

void Monster::Collision2(sf::RectangleShape &shape, float v_elevator){
    if (this->getGlobalBounds().intersects(shape.getGlobalBounds())){
        OnElevator=true;
        this->v_elevator=v_elevator;
        return;
    }
    OnElevator= false;
}


void Monster :: UpdateMove(float deltaTime){
    CurrentAnimation=Idle;
    sf::Vector2f Template(0,gravity.y + this->getSize().y*0.5f );
    if( IsCollision== true) Template.y=0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        CurrentAnimation=Run;
        Template.x= -velocity.x;
        isRight=false;
        if(this->getPosition().x - this->getSize().x/2 <=  0) Template.x=0;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        CurrentAnimation=Run;
        Template.x= velocity.x;
        isRight=true;
        if(this->getPosition().x +this->getSize().x >= 800) Template.x=0;


    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        CurrentAnimation=Jump;
        Template.y= -velocity.y;
        CurrentAnimation->setDirect(isRight);
        if(this->getPosition().y -this->getSize().y <= 0) Template.y=0;
    }

    else{
        CurrentAnimation->setDirect(isRight);
    }
    if (this->getPosition().y+Template.y*deltaTime >nearestGround.top){

        CurrentAnimation=Fall;
        sf::Vector2f  pos(this->getPosition());
        pos.y=nearestGround.top-nearestGround.height;
        this->setPosition(pos);
        Template.y=0.f;
    }
    if(OnElevator==true){
        CurrentAnimation=Idle;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            CurrentAnimation=Run;
        }
        Template.y= v_elevator;
    }
    this->move(Template*deltaTime);




}

void Monster ::Update(float deltatime) {
        CurrentAnimation->setPosition(this->getPosition());
        CurrentAnimation->Update(deltatime);

}
void Monster ::DrawAnimation(sf::RenderWindow &window) {
    window.draw(*CurrentAnimation);
}

sf::FloatRect Monster::GetNearestGround(vector<sf::FloatRect> &groundbounds){

    sf::Vector2f size(0.1f,0.1f);
    for (int y=this->getPosition().y;y<800;y+=1){
        sf::Vector2f point(this->getPosition().x,y);
        sf::FloatRect max(point,size);
        for (auto it: groundbounds){
              if (it.intersects(max)){
                  return it;
              }
        }
    }
    return sf::FloatRect (0,800,640,1);
}




