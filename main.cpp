
#include <iostream>
#include "Monster.h"
#include "Item.h"
#include "Animation.h"
#include "Door.h"
#include "Key.h"
#include "BackGAnimation.h"
using namespace sf;
using namespace std;
int main(){

    sf::RenderWindow window (sf:: VideoMode(800,640), "Adventure of Monster" );
    sf::Event event;
    Texture texture, texture2, texture3, texture4, texture5,texture6 ,texture7, texture8, texture9, texture10 ,
            texture11,texture12,texture13,texture14,texture15,texture16, texture17, texture18, texture19, texture20, texture22, texture23;

    //background
    BackGAnimation background;
    background.LoadFile("../Databackground//back.png");


    float deltaTime;
    sf::Clock clock;
    float m_vplayer = 200.f;


    vector<sf::FloatRect > groundbounds;
    vector<sf::FloatRect > groundbounds1;


//map
    Image img;
   if (img.loadFromFile("../Databackground//MAP.png")) {
        cout << "Load successfull!";
    }
    vector<RectangleShape> mapGame;
    int h= img.getSize().y/8;

    for (int y = 0; y < img.getSize().y; y++) {
        for (int x = 0; x < img.getSize().x; x++) {

            texture2.loadFromFile("../Databackground//tile22.png");
           if (img.getPixel(x, y)==sf::Color(41,220,59)) { // so sánh màu trên pixel map rồi generate nó ra- Đây là a so sánh nhanh, các e có thể so sánh bằng mã hexdecimal của màu đó
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture2);
                mapGame.push_back(shape);
                groundbounds.push_back(shape.getGlobalBounds());
           }

            texture3.loadFromFile("../Databackground//tile88.png");
           if (img.getPixel(x, y)==sf::Color(190,74,167)){
               RectangleShape shape(Vector2f(16, 16));
               shape.setPosition(16* x, 16 * y);
               shape.setTexture(&texture3);
               mapGame.push_back(shape);
           }
            texture4.loadFromFile("../Databackground//tile63.png");
            if (img.getPixel(x, y)==sf::Color(234,209,19)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture4);
                mapGame.push_back(shape);
                groundbounds.push_back(shape.getGlobalBounds());
            }
            texture5.loadFromFile("../Databackground//tile26.png");
            if (img.getPixel(x, y)==sf::Color(177,9,74)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture5);
                mapGame.push_back(shape);
            }

            texture6.loadFromFile("../Databackground//tile76.png");
            if (img.getPixel(x, y)==sf::Color(41,53,220)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture6);
                mapGame.push_back(shape);
            }

            texture7.loadFromFile("../Databackground//tile87.png");
            if (img.getPixel(x, y)==sf::Color(66,103,100)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture7);
                mapGame.push_back(shape);
            }

            texture8.loadFromFile("../Databackground//tile25.png");
            if (img.getPixel(x, y)==sf::Color(204,233,230)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture8);
                mapGame.push_back(shape);
            }

            //water
            texture9.loadFromFile("../Databackground//tile13.png");
            if (img.getPixel(x, y)==sf::Color(41,220,211)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture9);
                mapGame.push_back(shape);

                groundbounds1.push_back(shape.getGlobalBounds());
            }
            //water
            texture10.loadFromFile("../Databackground//tile35.png");
            if (img.getPixel(x, y)==sf::Color(71,120,155)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture10);
                mapGame.push_back(shape);
            }

            texture11.loadFromFile("../Objects//trees1_1.png");
            if (img.getPixel(x, y)==sf::Color(55,4,42)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture11);
                mapGame.push_back(shape);
            }

            texture12.loadFromFile("../Objects//rectangle5.png");
            if (img.getPixel(x, y)==sf::Color(101,211,152)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture12);
                mapGame.push_back(shape);
            }

            texture13.loadFromFile("../Objects//rocks1_2.png");
            if (img.getPixel(x, y)==sf::Color(78,72,76)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture13);
                mapGame.push_back(shape);
            }
            texture14.loadFromFile("../Databackground//tile69.png");
            if (img.getPixel(x, y)==sf::Color(220,128,41)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture14);
                mapGame.push_back(shape);

                groundbounds.push_back(shape.getGlobalBounds());
            }
            texture15.loadFromFile("../Databackground//tile87.png");
            if (img.getPixel(x, y)==sf::Color(168,56,31)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture15);
                mapGame.push_back(shape);
            }

            texture16.loadFromFile("../Databackground//tile116.png");
            if (img.getPixel(x, y)==sf::Color(139,186,191)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture16);
                mapGame.push_back(shape);
            }

            texture17.loadFromFile("../Databackground//tile113.png");
            if (img.getPixel(x, y)==sf::Color(225,180,216)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture17);
                mapGame.push_back(shape);
            }

            texture18.loadFromFile("../Databackground//tile81.png");
            if (img.getPixel(x, y)==sf::Color(115,5,86)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture18);
                mapGame.push_back(shape);
            }

            texture19.loadFromFile("../Databackground//tile114.png");
            if (img.getPixel(x, y)==sf::Color(17,164,49)){
                RectangleShape shape(Vector2f(16, 16));
                shape.setPosition(16* x, 16 * y);
                shape.setTexture(&texture19);
                mapGame.push_back(shape);
            }

        }
    }






    // anything
    Monster monster;
    Door door;
    Item aItem;
    vector <Item> item;
    Key key;



    // cac item
    vector<Item*> listItem;
    for (int y = 0; y < img.getSize().y; y++) {
        for (int x = 0; x < img.getSize().x; x++) {
            if (img.getPixel(x, y)==sf::Color(240,6,6)) {
                auto item = new Item();
                auto skin = new Animation(sf::Vector2i(17.f, 1.f), 0.05f);
                Texture *texture;
                texture = new Texture();

                texture->loadFromFile("../Fruits//Melon.png");
                skin->setTexture(*texture);
                skin->CalculateSize();
                skin->ApplyRect();
                skin->setOrigin(item->getSize() * 0.5f);
                item->setAnimation(skin);//Dung ham nay roi thi khong can Init

                item->setPosition(x * 16, y * 16);
                item->setSize(sf::Vector2f(16, 16));


                listItem.push_back(item);

            }

        }
    }

// elevator
    Texture texture21;
    texture21.loadFromFile("../Databackground//ok.png");
    sf:: RectangleShape elevator ;
    elevator.setPosition(sf::Vector2f (550.f,200.f));
    elevator.setSize(sf::Vector2f(145.f,34.f));
    elevator.setTexture(&texture21);



    float v_elevator = 100.f;

    //monster
        Animation animation(sf::Vector2i(11,1), 0.05f);
        animation.setPosition(10,100);


    monster.setPosition(10,100);
    monster.setSize(sf::Vector2f (16,16));
    monster.setOrigin({ monster.getLocalBounds().width*0.5f, monster.getLocalBounds().height * 0.5f});
    monster.Init();
    bool Alive=true;

    //door
        Animation animation2(sf::Vector2i(1,1),0.05f);
        animation2.setPosition(758.f,516.f);


    door.setPosition(758.f,516.f);
    door.setSize(sf::Vector2f (46.f,56.f));
    door.setOrigin({ door.getLocalBounds().width*0.5f, door.getLocalBounds().height * 0.5f});
    door.Init();


    //key
        Animation animation3(sf::Vector2i(1,1),0.05f);
        animation3.setPosition(750.f,50.f);

    key.setPosition(750.f,50.f);
    key.setSize(sf::Vector2f (20.f,20.f));
    key.Init();





    float Time=0;
    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();


        while(window.pollEvent(event)){
            Time+=deltaTime;
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf:: Keyboard:: Escape)
                        window.close();
                    break;
            }
        }

        window.clear(Color(206,231,242,95));

        if(elevator.getPosition().y<= 80.f ){
            v_elevator= abs(v_elevator);

        }
        if(elevator.getPosition().y>= 550.f){
            v_elevator= -abs(v_elevator);

        }

        elevator.move(sf::Vector2f(0.f, v_elevator * deltaTime));

        background.Update(deltaTime);
        background.Draw(window);

        monster.Collision2(elevator,v_elevator);
        monster.UpdateMove(deltaTime);
        monster.Update(deltaTime);
        monster.CheckCollision(groundbounds);
        animation.Update(deltaTime);
        window.draw(monster);


        door.Update(deltaTime);
        door.Collision(monster);


        key.Update(deltaTime);
        key.Collision(monster);

        for (auto z : mapGame) {
            window.draw(z);
        }
        for (auto it: listItem){
            it->Update(deltaTime);
            it->Collision(monster);
        }
        for (auto it: listItem){
            it->DrawAnimation(window);
        }

        door.DrawAnimation(window);
        window.draw(elevator);
        monster.DrawAnimation(window);
        key.DrawAnimation(window);

        door.checkKey(key.Check());
        if(key.Check()== true){

            if(door.Check()==true) {

                Time += deltaTime;

                if (Time > 7) {
                    BackGAnimation Gameover;
                    Gameover.GameOver(window);


                }

            }

        }

        window.display();

    }
    return 0;
}








