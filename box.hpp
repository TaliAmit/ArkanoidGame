#ifndef ARKANOID_BOX_HPP
#define ARKANOID_BOX_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Box
{
public:    
    explicit Box(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_outline_color);
    Box(const Box& a_other) = default;
    Box(Box&& a_other) = default;
    ~Box() = default;

    void draw(sf::RenderWindow& a_window);
    sf::FloatRect bounds();

private:
    sf::RectangleShape m_shape;
};

#endif // ARKANOID_BOX_HPP