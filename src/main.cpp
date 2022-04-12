#include "Sorter.h"
#include "Manager.h"
#include "Button.h"
#include <vector>
#include <time.h>

const int ResX = 1600;
const int ResY = 800;

sf::Font RobotoFont;

void DrawStaticArray(sf::RenderWindow &window, std::vector<Bar> &Bars){
    for(int i=0; i<Bars.size(); i++){
        Bars[i].DrawBar(window);
    }
}

int main(){
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(ResX, ResY), "Sorting Visualizer");
    if(!RobotoFont.loadFromFile("resources/Roboto.ttf")){
        std::cout<<"Error loading font\n";
    }
    Manager MainManager(&window,RobotoFont);
    std::vector<Button> Buttons;
    for(int i=0; i<10; i++){
        Buttons.push_back(Button(100,60,RobotoFont,(ACTION)i));
        Buttons[i].m_Position = {1250+120*(i%3), 150+150*(i/3)};
        Buttons[i].m_Window = &window;
        Buttons[i].m_Manager = &MainManager;
        Buttons[i].m_Text.setPosition({1250+120*(i%3), 150+150*(i/3)});
    }
    Buttons[MergeSort].m_Rectangle.setFillColor(sf::Color::Green);
    MainManager.m_ButtonArray = &Buttons;
    MainManager.DrawThings();
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(int i=0; i<Buttons.size(); i++){
                    Buttons[i].Listen(mousePos);
                }
            }
        }
        /*window.clear(sf::Color(100,100,100));
        DrawStaticArray(window,MainManager.m_CurrentSorter->MainArray);*/
        //window.display();
    }
    return 0;
}