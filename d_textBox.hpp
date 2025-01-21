#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox
{
public :
    explicit TextBox(size_t a_size, /*sf::Color a_color,*/ bool a_is_selected);
    ~TextBox() = default;

    void typed_on(sf::Event a_input);
    void set_font(sf::Font a_font);
    void set_position(sf::Vector2f a_position);

    void set_is_selected(bool a_is_selected);
    void set_has_limit(bool a_ToF); // ToF = true or false
    void set_limit(size_t a_limit);

    std::string text();

    void draw(sf::RenderWindow& a_window);

private :

    void input_logic(int a_char_typed);
    void delete_last_character();

private :
    sf::Text m_textbox;
    std::ostringstream m_text;

    bool m_is_selected;
    bool m_has_limit;
    size_t m_limit;  
};

#endif // TEXT_BOX_HPP