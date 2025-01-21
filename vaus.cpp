#include "vaus.hpp"
#include "gameConsts.hpp"

Vaus::Vaus(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_outline_color)
: m_shape{a_size}
{
    m_shape.setPosition(a_position);
    m_shape.setFillColor(a_fill_color);
    m_shape.setOutlineColor(a_outline_color);
}

void Vaus::draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_shape);
}

void Vaus::move_left()
{
    m_shape.move(sf::Vector2f(-20.0, 0.0));
}

void Vaus::move_right()
{
    m_shape.move(sf::Vector2f(20.0, 0.0));
}

void Vaus::move_left(sf::Vector2f a_movement)
{
    m_shape.move(-a_movement);
}

void Vaus::move_right(sf::Vector2f a_movement)
{
    m_shape.move(a_movement);
}

void Vaus::stop_moving()
{
    m_shape.move(sf::Vector2f(0.0, 0.0));
}

void Vaus::set_position(sf::Vector2f a_position)
{
    m_shape.setPosition(a_position);
}

sf::Vector2f Vaus::position()
{
    return m_shape.getPosition();
}

sf::FloatRect Vaus::bounds()
{
    return m_shape.getGlobalBounds();
}
