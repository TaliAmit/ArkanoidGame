#ifndef ARKANOID_BUTTON_HPP
#define ARKANOID_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Button
{
public :
    explicit Button(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, sf::Color a_border_color);
    ~Button() noexcept = default;
    bool is_click_event(sf::Vector2i a_mouse_pos);
    void set_position(sf::Vector2f a_position);
    void set_fill_color(sf::Color a_color);
    void set_border_color(sf::Color a_color);
    void draw(sf::RenderWindow& a_window);

private :
    sf::RectangleShape m_shape;
};

#endif // ARKANOID_BUTTON_HPP