#include "brick.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Brick::Brick()
: m_shape{}
, m_is_active{false}
{
}

Brick::Brick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color)
    : m_shape{a_size}, m_is_active{true}
{
    m_shape.setPosition(a_position);
    m_shape.setFillColor(a_fill_color);
}

void Brick::draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_shape);
}


bool Brick::is_active() const
{
    return m_is_active;
}

void Brick::activate()
{
    m_is_active = true;
}

void Brick::deactivate()
{
    m_is_active = false;
}

sf::FloatRect Brick::bounds()
{
    return m_shape.getGlobalBounds();
}

void Brick::set_fill_color(sf::Color a_color)
{
    m_shape.setFillColor(a_color);
}

/*
sf::RectangleShape Brick::shape()
{
    return m_shape;
}
*/

