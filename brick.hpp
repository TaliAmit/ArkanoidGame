#ifndef ARKANOID_BRICK_HPP
#define ARKANOID_BRICK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Brick
{
public:
    explicit Brick();    
    explicit Brick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color);
    Brick(const Brick& a_other) = default;
    Brick(Brick&& a_other) = default;
    ~Brick() = default;

    Brick& operator=(const Brick& other) = default;
    
    void draw(sf::RenderWindow& a_window);
    bool is_active() const;
    void activate();
    void deactivate();

    sf::FloatRect bounds();
    void set_fill_color(sf::Color a_color);
    //sf::RectangleShape shape();

private:
    sf::RectangleShape m_shape;
    bool m_is_active;
};

#endif // ARKANOID_BRICK_HPP