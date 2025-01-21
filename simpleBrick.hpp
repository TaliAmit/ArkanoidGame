#ifndef ARKANOID_SIMPLE_BRICK_HPP
#define ARKANOID_SIMPLE_BRICK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "absBrick.hpp"

class SimpleBrick : public AbsBrick
{
public:
    explicit SimpleBrick();
    explicit SimpleBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color);    
    SimpleBrick(const SimpleBrick& a_other) = default;
    SimpleBrick(SimpleBrick&& a_other) = default;
    ~SimpleBrick() override = default;

    SimpleBrick& operator=(const SimpleBrick& other) = default;
    
    void get_hit() override;
    std::shared_ptr<sf::Sprite> get_sprite() override;

};

#endif // ARKANOID_SIMPLE_BRICK_HPP