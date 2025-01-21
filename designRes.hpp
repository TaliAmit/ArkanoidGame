#ifndef ARKANOID_DESIGN_RES_HPP
#define ARKANOID_DESIGN_RES_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class DesignRes
{
public :
    explicit DesignRes() = default;
    ~DesignRes() = default;
    
    //void load_font(const std::string a_font_path);

    //void draw_text(sf::RenderWindow& a_window, const std::string a_text_str, const sf::Vector2f a_position, const unsigned int a_size, const sf::Color a_color);
    void draw_text(sf::RenderWindow &a_window, const std::string a_text_str, sf::Font a_font, const sf::Vector2f a_position, const unsigned int a_size, const sf::Color a_color);
    //void draw_image(sf::RenderWindow &a_window, const std::string pic_path, const sf::Vector2f a_position);

    void draw_image(sf::RenderWindow &a_window, sf::Sprite a_sprite, const sf::Vector2f a_position);

    //void draw_img(sf::RenderWindow &a_window, std::string pic_path, sf::Vector2f a_scale, sf::Vector2f a_position);
    //sf::Font font();
    
private:
    //sf::Font m_font;   
};




#endif // ARKANOID_DESIGN_RES_HPP
