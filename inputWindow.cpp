#include "inputWindow.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cctype>

#include "resourceManager.hpp"
#include "topScores.hpp"
#include "player.hpp"


InputWindow::InputWindow(sf::RenderWindow& a_window, Player &a_player, TopScores &a_scores)
: m_window{a_window}
, m_player{a_player}
, m_scores{a_scores}
, m_design_res{}
, m_name{""}
, m_is_finish{false}
{
    ;
}

void InputWindow::draw_objects()
{
    ResourceManager& resourceManager = ResourceManager::instance();
    m_design_res.draw_image(m_window, *resourceManager.sprite(BackgroundImageEnum::input_screen), sf::Vector2f(0.0,0.0));
    m_design_res.draw_image(m_window, *resourceManager.sprite(GeneralImageEnum::top_score_headline), sf::Vector2f(0.0,50.0));

    std::shared_ptr<sf::Font> font = ResourceManager::instance().font(FontEnum::game_font);

    m_design_res.draw_text(m_window, "Please enter your name :", (*font), sf::Vector2f(150.0, 350.0), 40, sf::Color(243,231,206));
    m_design_res.draw_text(m_window, m_name, (*font), sf::Vector2f(280.0, 450.0), 40, sf::Color::Cyan);

}


void InputWindow::handle_event(sf::Event a_event)
{
    if (a_event.type == sf::Event::Closed)
    {
        m_window.close();
    }
    
    if (a_event.type == sf::Event::TextEntered)
    {
        char ch = static_cast<char>(a_event.text.unicode);
        if (isalpha(ch))
        {
            if(m_name.size() < PLAYER_NAME_LETTERS)
            {
                m_name += ch;
                draw_objects();
            }
            
        }
    }

    if(a_event.type == sf::Event::KeyPressed)
    {
        if(a_event.key.code == sf::Keyboard::BackSpace)
        {
            if (!m_name.empty())
            {
                m_name.pop_back();
                draw_objects();
            }
        }

        if(a_event.key.code == sf::Keyboard::Enter)
        {
            if(m_name != "")
            {
                m_player.set_name(m_name); 
                m_scores.insert_score_info(m_player);   
                m_is_finish = true;
            }
            
        }
    }
}


void InputWindow::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            handle_event(event);
        }

        if(m_is_finish)
        {
            break;
        }

        m_window.clear();
        draw_objects();
        m_window.display();
    }

    if(m_is_finish)
    {
        m_scores.run();
    }
}
