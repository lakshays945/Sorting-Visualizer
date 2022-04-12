#include "Sorter.h"

void Sorters::GenerateRandomArray(int size){
    if(size>1000){
        std::cout<<"Error :: Enter a size less that or equal to 1000\n";
        return;
    }
    MainArray.clear();
    if(size == 0) size++;
    float width = 2200.0/(3*size-1);
    float gap = width/2;
    if(size>400){
        width = 1100.0/size;
        gap = 0;
    }
    float Xpos = 50+width/2;
    for(int i=0; i<size; i++){
        MainArray.push_back(Bar(std::ceil(width),10+rand()%500));
        MainArray[i].m_Position = {Xpos, 700};
        Xpos += width+gap;
    }
}

void Sorters::DrawBarArray(){
    if(!End){
        Window->clear(sf::Color(100,100,100));
        for(int i=0; i<MainArray.size(); i++){
            MainArray[i].DrawBar(*Window);
            MainArray[i].m_Color = sf::Color::Black;
        }
        Window->draw(DelayTimeText);
        Window->display();
    }
    Pause(PauseTime);
}

void Sorters::Pause(int time){ //time in milliseconds
    sf::Clock clock;
    while(clock.getElapsedTime().asMilliseconds() < PauseTime){
        sf::Event event;
        while (Window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                End = true;
                Window->close();
                PauseTime = -1;
            }
            else if(event.type == sf::Event::KeyReleased){
                switch(event.key.code){
                    case sf::Keyboard::E:
                        End = true;
                        PauseTime = -1;
                        break;
                }
            }
        }
    }
}