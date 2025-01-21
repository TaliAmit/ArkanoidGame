#ifndef ARKANOID_EXPLODE_BRICK_HPP
#define ARKANOID_EXPLODE_BRICK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "absBrick.hpp"

class ExplodeBrick : public AbsBrick
{
public:
    explicit ExplodeBrick();
    explicit ExplodeBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color);    
    ExplodeBrick(const ExplodeBrick& a_other) = default;
    ExplodeBrick(ExplodeBrick&& a_other) = default;
    ~ExplodeBrick() override = default;

    ExplodeBrick& operator=(const ExplodeBrick& other) = default;
    
    void get_hit() override;
    std::shared_ptr<sf::Sprite> get_sprite() override;

};

#endif // ARKANOID_EXPLODE_BRICK_HPP