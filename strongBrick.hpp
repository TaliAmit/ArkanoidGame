#ifndef ARKANOID_STRONG_BRICK_HPP
#define ARKANOID_STRONG_BRICK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "absBrick.hpp"

class StrongBrick : public AbsBrick
{
public:
    explicit StrongBrick();
    explicit StrongBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color);    
    StrongBrick(const StrongBrick& a_other) = default;
    StrongBrick(StrongBrick&& a_other) = default;
    ~StrongBrick() override = default;

    StrongBrick& operator=(const StrongBrick& other) = default;

    void get_hit() override;
    std::shared_ptr<sf::Sprite> get_sprite() override;

};

#endif // ARKANOID_STRONG_BRICK_HPP