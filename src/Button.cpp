#include "Button.h"

std::string ButtonTexts[10] = {"Sort","Merge","Quick","Bubble","Insertion","Size+","Size-","Speed+","Speed-","Reset"};

Button::Button(){
    m_Rectangle.setSize({m_Width,m_Height});
    m_Rectangle.setOrigin({m_Width/2,m_Height/2});
    m_Rectangle.setFillColor(sf::Color::White);
}

Button::Button(int width, int height, sf::Font &font, ACTION action){
    m_Action = action;
    m_Text.setFont(font);
    m_Text.setString(ButtonTexts[(int)action]);
    m_Text.setCharacterSize(24);
    sf::FloatRect rect = m_Text.getLocalBounds();
    m_Text.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
    m_Text.setColor(sf::Color::Black);
    m_Width = width;
    m_Height = height;
    m_Rectangle.setSize({m_Width,m_Height});
    m_Rectangle.setOrigin({m_Width/2,m_Height/2});
    m_Rectangle.setFillColor(sf::Color::White);

}

void Button::Listen(sf::Vector2i mousePos){
    if(clock.getElapsedTime().asSeconds() < CooldownTime) return;
    if(abs(mousePos.x-m_Position.x)<=m_Width/2 && abs(mousePos.y-m_Position.y)<=m_Height/2){
        OnClick();
        clock.restart();
    }
}

void Button::OnClick(){
    m_Manager->PerformAction(m_Action);
}

void Button::DrawButton(){
    m_Rectangle.setPosition({m_Position.x,m_Position.y});
    m_Window->draw(m_Rectangle);
    m_Window->draw(m_Text);
}