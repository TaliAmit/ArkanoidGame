#include "textBox.hpp"

#include <iostream>

TextBox::TextBox(size_t a_size, /*sf::Color a_color,*/ bool a_is_selected)
: m_textbox{}
, m_text{}
{
    m_textbox.setCharacterSize(a_size);
    //m_textbox.setFillColor(a_color);
    m_is_selected = a_is_selected;

    if(a_is_selected)
    {
        m_textbox.setString("_");
    }
    else
    {
        m_textbox.setString("");
    }
}

void TextBox::typed_on(sf::Event a_input)
{
    if(m_is_selected)
    {
        int char_typed = a_input.text.unicode;

        if(char_typed < 128)
        {
            if(m_has_limit)
            {
                if(m_text.str().length() < m_limit)
                {
                    input_logic(char_typed);
                }
                else
                {
                    if(char_typed == DELETE_KEY)
                    {
                        delete_last_character();
                    }
                }
            }
            else
            {
                input_logic(char_typed);
            }
        }
    }
}

void TextBox::set_font(sf::Font a_font)
{
    m_textbox.setFont(a_font);
}

void TextBox::set_position(sf::Vector2f a_position)
{
    m_textbox.setPosition(a_position);
}

// I dont get it - yet...
void TextBox::set_is_selected(bool a_is_selected)
{
    m_is_selected = a_is_selected;

    if(!m_is_selected)
    {
        std::string str = m_text.str();
        std::string new_str = "";

        for(size_t i = 0; i < str.length() - 1; ++i)
        {
            new_str = str[i];
        }

        m_textbox.setString(new_str);
    }
}

void TextBox::set_has_limit(bool a_ToF)
{
    m_has_limit = a_ToF;
}

void TextBox::set_limit(size_t a_limit)
{
    m_limit = a_limit;
}

// I dont get it - yet...
std::string TextBox::text()
{
    return m_text.str();
}


void TextBox::draw(sf::RenderWindow &a_window)
{
    std::cout << "I'm here 33533 \n";
    a_window.draw(m_textbox);
    std::cout << "I'm here 44544 \n";
}



void TextBox::input_logic(int a_char_typed)
{
    switch(a_char_typed)
    {
    case DELETE_KEY:
        if(m_text.str().length() > 0)
        {
            delete_last_character();
        }
        break;
    case ENTER_KEY: break;
    case ESCAPE_KEY: break;
    default :
        m_text << static_cast<char>(a_char_typed);
        break;
    }

}

void TextBox::delete_last_character()
{
    std::string text = m_text.str();
    std::string new_text = "";

    for(size_t i = 0; i < text.length() - 1; ++i)
    {
        new_text[i] += text[i];
    }

    m_text.str("");
    m_text << new_text;

    m_textbox.setString(m_text.str());
}

/*
void TextBox::delete_last_character() 
{
    if (m_text.str().empty())
    {
        return;
    }

    m_text.str().erase(m_text.str().length() - 1);
    m_textbox.setString(m_text.str());
}
*/

