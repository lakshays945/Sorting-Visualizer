#pragma once
#include "Utility.h"
#include "Manager.h"
#include "SFML/Graphics.hpp"

class Button{
public:
    sf::RenderWindow *m_Window = nullptr;
    Vector2D m_Position;
    ACTION m_Action = Reset;
    sf::RectangleShape m_Rectangle;
    sf::Text m_Text;
    Manager *m_Manager = nullptr;
    int m_Width = 10;
    int m_Height = 10;
    float Time = 0;
    float CooldownTime = 0.1;
    sf::Clock clock;
    Button();
    Button(int width, int height, sf::Font &font, ACTION action);
    void Listen(sf::Vector2i mousePos);
    void OnClick();
    void DrawButton();
};
