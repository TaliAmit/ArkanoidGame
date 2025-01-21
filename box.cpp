#include "box.hpp"

Box::Box(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_outline_color)
: m_shape{a_size}
{
    m_shape.setPosition(a_position);
    m_shape.setFillColor(a_fill_color);
    m_shape.setOutlineColor(a_outline_color);
}

void Box::draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_shape);
}

sf::FloatRect Box::bounds()
{
    return m_shape.getGlobalBounds();
}
