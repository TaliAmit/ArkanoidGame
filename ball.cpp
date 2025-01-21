#include "ball.hpp"

Ball::Ball(float a_radius, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_outline_color, sf::Vector2f a_step)
: m_shape{a_radius}
{
    m_shape.setPosition(a_position);
    m_shape.setFillColor(a_fill_color);
    m_shape.setOutlineColor(a_outline_color);
    m_shape.setOutlineThickness(-3.0);
    m_step = a_step;

    // m_shape.setOrigin(a_radius / 2.0f, a_radius / 2.0f);

}

void Ball::draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_shape);
    /*
    sf::CircleShape cen{m_shape.getRadius()/2.0, m_shape.getRadius()/2.0};
    cen.setFillColor(sf::Color::Black);
    cen.setPosition(circle_center());
    a_window.draw(cen);
    */

}

sf::Vector2f Ball::circle_center()
{
    sf::Vector2f center_position = m_shape.getPosition();
    float radius = m_shape.getRadius();

    center_position.x += radius;
    center_position.y += radius;

    return center_position;
}

void Ball::set_position(sf::Vector2f a_position)
{
    m_shape.setPosition(a_position);
}

void Ball::set_step_direction(sf::Vector2f a_step)
{
    m_step.x *= a_step.x;
    m_step.y *= a_step.y;
}

void Ball::set_step(sf::Vector2f a_step)
{
    m_step = a_step;
}

sf::CircleShape Ball::shape()
{
    return m_shape;
}

float Ball::radius()
{
    return m_shape.getRadius();
}

sf::Vector2f Ball::position()
{
    return m_shape.getPosition();
}

sf::Vector2f Ball::step()
{
    return m_step;
}

void Ball::move()
{
    m_shape.move(m_step);
}


