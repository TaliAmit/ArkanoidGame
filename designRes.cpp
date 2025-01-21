#include "designRes.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

// void DesignRes::draw_image(sf::RenderWindow& a_window, const std::string pic_path, const sf::Vector2f a_position)
// {
//     sf::Texture pic;

//     if (!pic.loadFromFile(pic_path))
//     {
//         std::cout<< "Error loading picture file!" << std::endl;
//     }

//     sf::Sprite sprt_pic(pic);
//     sprt_pic.setPosition(a_position.x, a_position.y);

//     a_window.draw(sprt_pic);
// }

void DesignRes::draw_image(sf::RenderWindow& a_window, sf::Sprite a_sprite, const sf::Vector2f a_position)
{
    a_sprite.setPosition(a_position.x, a_position.y);

    a_window.draw(a_sprite);
}



// void DesignRes::draw_text(sf::RenderWindow& a_window, const std::string a_text_str, const sf::Vector2f a_position, const unsigned int a_size, const sf::Color a_color)
// {
//     sf::Text txt;

//     txt.setString(a_text_str);
//     txt.setFont(m_font);
//     txt.setCharacterSize(a_size);
//     txt.setFillColor(a_color);
//     txt.setPosition(a_position.x, a_position.y);

//     a_window.draw(txt);
// }


void DesignRes::draw_text(sf::RenderWindow& a_window, const std::string a_text_str, sf::Font a_font, const sf::Vector2f a_position, const unsigned int a_size, const sf::Color a_color)
{
    sf::Text txt;

    txt.setString(a_text_str);
    txt.setFont(a_font);
    txt.setCharacterSize(a_size);
    txt.setFillColor(a_color);
    txt.setPosition(a_position.x, a_position.y);

    a_window.draw(txt);
}



// void DesignRes::load_font(const std::string a_font_path)
// {
//     if (!m_font.loadFromFile(a_font_path))
//     {
//         std::cout << "Error loading font file!" << std::endl;
//     }

    
// }


// sf::Font DesignRes::font()
// {
//     return m_font;
// }



/*
void DesignRes::draw_img(sf::RenderWindow& a_window, std::string pic_path, sf::Vector2f a_scale, sf::Vector2f a_position)
{
    sf::Texture pic;

    if (!pic.loadFromFile(pic_path))
    {
        std::cout<< "Error loading picture file!" << std::endl;
    }

    sf::Sprite sprt_pic(pic);
    sprt_pic.setScale(a_scale.x, a_scale.y);
    sprt_pic.setPosition(a_position.x, a_position.y);

    a_window.draw(sprt_pic);
}
*/

// sf::Font FontLoader::font()
// {
//     return m_font;
// }
