#ifndef ARKANOID_ABS_BRICK_HPP
#define ARKANOID_ABS_BRICK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory> // shared ptr

class AbsBrick
{
public:
    explicit AbsBrick();
    explicit AbsBrick(sf::Vector2f a_size, sf::Vector2f a_position, sf::Color a_fill_color, size_t a_count_hits, std::string a_type);
    virtual ~AbsBrick() = default;

    void draw(sf::RenderWindow& a_window);
    virtual std::shared_ptr<sf::Sprite> get_sprite() = 0;
    virtual void get_hit() = 0;
    
    bool is_active() const;
    /*virtual*/void activate();
    /*virtual*/void deactivate();

    std::string type();

    sf::FloatRect bounds();
    void set_fill_color(sf::Color a_color);
    sf::Vector2f position();
    void dec_count_hits();

protected:    
    sf::RectangleShape m_shape; // direct access for drawing actions
    bool m_is_active;
    size_t m_count_hits;
    std::string m_type;
};

#endif // ARKANOID_ABS_BRICK_HPP