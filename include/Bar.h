#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"

class Bar{
public:
    int m_Height = 10;
    int m_Width = 10;
    Vector2D m_Position;
    sf::RectangleShape m_Rectangle;
    sf::Color m_Color;

    Bar(){
        m_Color = sf::Color::Black;
        m_Rectangle.setSize({m_Width,m_Height});
        m_Rectangle.setOrigin(sf::Vector2f(m_Width/2,m_Height));
        m_Rectangle.setFillColor(m_Color);
    }

    Bar(int width, int height){
        m_Width = width;
        m_Height = height;
        m_Color = sf::Color::Black;
        m_Rectangle.setSize({m_Width,m_Height});
        m_Rectangle.setOrigin(sf::Vector2f(m_Width/2,m_Height));
        m_Rectangle.setFillColor(m_Color);
    }

    void DrawBar(sf::RenderWindow &window){
        if(m_Rectangle.getFillColor() != m_Color) m_Rectangle.setFillColor(m_Color);
        m_Rectangle.setPosition(m_Position.x,m_Position.y);
        m_Rectangle.setSize({m_Width,m_Height});
        m_Rectangle.setOrigin(sf::Vector2f(m_Width/2,m_Height));
        window.draw(m_Rectangle);
    }
};