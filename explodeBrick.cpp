#include "explodeBrick.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>   // shared ptr
#include <iostream> // debug
#include "absBrick.hpp"


ExplodeBrick::ExplodeBrick()
: AbsBrick()
{
    ;
}

ExplodeBrick::ExplodeBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color)
: AbsBrick(a_size, a_position, a_fill_color, 3, "explode")
{
    ;
}

void ExplodeBrick::get_hit()
{
    dec_count_hits();

    switch(m_count_hits)
    {
        //223,168, 58
        case 2: m_shape.setFillColor(sf::Color(84, 9, 9)); break;
        case 1: m_shape.setFillColor(sf::Color(144,96, 1)); break;
        case 0: m_is_active = false; break;
    }
}

std::shared_ptr<sf::Sprite> ExplodeBrick::get_sprite()
{
    return nullptr;
}