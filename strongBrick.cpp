#include "strongBrick.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream> // debug

#include "absBrick.hpp"
#include "resourceManager.hpp"
#include "designRes.hpp"

StrongBrick::StrongBrick()
: AbsBrick()
{
    ;
}

StrongBrick::StrongBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color)
: AbsBrick(a_size, a_position, a_fill_color, 3, "strong")
{
    ;
}

void StrongBrick::get_hit()
{
    dec_count_hits();
    
    if(m_count_hits == 0)
    {
        m_is_active = false;
    }
}

std::shared_ptr<sf::Sprite> StrongBrick::get_sprite()
{
    switch(m_count_hits)
    {
    case 3: return nullptr;
    case 2: return ResourceManager::instance().sprite(GeneralImageEnum::brick_crack_1);
    case 1: return ResourceManager::instance().sprite(GeneralImageEnum::brick_crack_2);
    default: break;
    }

    return nullptr;
}