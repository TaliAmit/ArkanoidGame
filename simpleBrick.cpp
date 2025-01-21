#include "simpleBrick.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>   // shared ptr

#include "absBrick.hpp"

SimpleBrick::SimpleBrick()
: AbsBrick()
{
    ;
}

SimpleBrick::SimpleBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color)
: AbsBrick(a_size, a_position, a_fill_color, 1, "simple")
{
    ;
}

void SimpleBrick::get_hit()
{
    dec_count_hits();
    
    if(m_count_hits == 0)
    {
        m_is_active = false;
    }
}

std::shared_ptr<sf::Sprite> SimpleBrick::get_sprite()
{
    return nullptr;
}