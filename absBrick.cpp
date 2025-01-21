#include "absBrick.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstddef>
#include <memory> // shared ptr

AbsBrick::AbsBrick()
: m_shape{}
, m_is_active{false}
, m_count_hits{1}
{
    ;
}


AbsBrick::AbsBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, size_t a_count_hits, std::string a_type)
: m_shape{a_size}
, m_is_active{true}
, m_count_hits{a_count_hits}
, m_type{a_type}
{
    m_shape.setPosition(a_position);
    m_shape.setFillColor(a_fill_color);
}

bool AbsBrick::is_active() const
{
    return m_is_active;
}

void AbsBrick::activate()
{
    m_is_active = true;
}

void AbsBrick::deactivate()
{
    m_is_active = false;
}

sf::FloatRect AbsBrick::bounds()
{
    return m_shape.getGlobalBounds();
}

void AbsBrick::set_fill_color(sf::Color a_color)
{
    m_shape.setFillColor(a_color);
}

void AbsBrick::dec_count_hits()
{
    if(m_count_hits > 0)
    {
        --m_count_hits;
    }

    if(m_count_hits == 0)
    {
        m_is_active = false;
    }
}

std::string AbsBrick::type()
{
    return m_type;
}

void AbsBrick::draw(sf::RenderWindow& a_window)
{
    a_window.draw(m_shape);
}

sf::Vector2f AbsBrick::position()
{
    return m_shape.getPosition();
}

