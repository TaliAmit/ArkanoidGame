#include "button.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

Button::Button(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_border_color)
: m_shape{a_size}
{
    m_shape.setPosition(a_position);
    m_shape.setFillColor(a_fill_color);
    m_shape.setOutlineColor(a_border_color);
}

bool Button::is_click_event(sf::Vector2i a_mouse_pos)
{
    const sf::Vector2f& button_pos = m_shape.getPosition();
    const sf::Vector2f& button_size = m_shape.getSize();

    if(a_mouse_pos.x >= button_pos.x
    && a_mouse_pos.x <= button_pos.x + button_size.x // + button_bounds.width
    && a_mouse_pos.y >= button_pos.y
    && a_mouse_pos.y <= button_pos.y + button_size.y) // + button_bounds.height
    {
        return true;
    }

    return false;
}

void Button::set_position(sf::Vector2f a_position)
{
    m_shape.setPosition(a_position);
}

void Button::set_fill_color(sf::Color a_color)
{
    m_shape.setFillColor(a_color);
}

void Button::set_border_color(sf::Color a_color)
{
    m_shape.setOutlineColor(a_color);
}

void Button::draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_shape);
}
