#ifndef ARKANOID_BALL_HPP
#define ARKANOID_BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Ball
{
public:    
    explicit Ball(float a_radius, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_outline_color, sf::Vector2f a_step);
    Ball(const Ball& a_other) = default;
    Ball(Ball&& a_other) = default;
    ~Ball() = default;

    void draw(sf::RenderWindow& a_window);

    sf::Vector2f circle_center();
    void set_position(sf::Vector2f a_position);
    void set_step_direction(sf::Vector2f a_step);
    void set_step(sf::Vector2f a_step);

    sf::CircleShape shape();
    float radius();
    sf::Vector2f position();
    sf::Vector2f step();
    void move();

private:
    sf::CircleShape m_shape;
    sf::Vector2f m_step;
};

#endif // ARKANOID_BALL_HPP