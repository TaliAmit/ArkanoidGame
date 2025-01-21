#ifndef ARKANOID_VAUS_HPP
#define ARKANOID_VAUS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Vaus
{
public:    
    explicit Vaus(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_outline_color);
    Vaus(const Vaus& a_other) = default;
    Vaus(Vaus&& a_other) = default;
    ~Vaus() = default;

    void draw(sf::RenderWindow& a_window);

    void move_left();
    void move_right();
    void move_left(sf::Vector2f a_movement);
    void move_right(sf::Vector2f a_movement);
    void stop_moving();
    void set_position(sf::Vector2f a_position);

    sf::Vector2f position();
    sf::FloatRect bounds();

private:
    sf::RectangleShape m_shape;
};

#endif // ARKANOID_VAUS_HPP