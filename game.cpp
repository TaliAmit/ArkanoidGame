#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "gameConsts.hpp"
#include "simulationT.hpp"
#include "topScores.hpp"
#include "player.hpp"
#include "button.hpp"

Game::Game(ResourceManager& a_resource_manager, DesignRes& a_design_res)
: m_window{sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid", sf::Style::Titlebar | sf::Style::Close}
, m_resource_manager{a_resource_manager}
, m_design_res{a_design_res}
, m_player{PLAYER_LIVES}
, m_scores{m_window, m_design_res, m_resource_manager}
, m_start_game_btn{sf::Vector2f(200.0,60.0), sf::Vector2f(300.0,500.0), sf::Color::Transparent, sf::Color::Transparent}
, m_exit_game_btn{sf::Vector2f(200.0,60.0), sf::Vector2f(550.0,500.0), sf::Color::Transparent, sf::Color::Transparent}
, m_top_scores_btn{sf::Vector2f(200.0,60.0), sf::Vector2f(50.0,500.0), sf::Color::Transparent, sf::Color::Transparent}
{
    ;
}

void Game::handle_event(sf::Event a_event)
{
    if (a_event.type == sf::Event::Closed)
    {
        exit_game();
    }

    if (a_event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(m_window);

        if(m_start_game_btn.is_click_event(mouse_pos))
        {
            m_window.clear();
            SimulationT simulation{m_window, m_resource_manager, m_design_res, m_player, m_scores};
            simulation.run();

            // Simulation simulation{m_window, m_resource_manager, m_design_res, m_player, m_scores};
        }

        if(m_exit_game_btn.is_click_event(mouse_pos))
        {
            exit_game();
        }

        if(m_top_scores_btn.is_click_event(mouse_pos))
        {
            m_window.clear();
            m_scores.run();
        }   
    }
}

void Game::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            handle_event(event);
        }

        m_window.clear();
        draw_pictures();
        m_window.display();
    }
}

void Game::draw_pictures()
{
    m_design_res.draw_image(m_window, *m_resource_manager.sprite(BackgroundImageEnum::game_options_screen), sf::Vector2f(0.0,0.0));
    m_design_res.draw_image(m_window, *m_resource_manager.sprite(GeneralImageEnum::game_logo), sf::Vector2f(0.0,0.0));
    m_design_res.draw_image(m_window, *m_resource_manager.sprite(ButtonImageEnum::start_game), sf::Vector2f(300.0,500.0));
    m_design_res.draw_image(m_window, *m_resource_manager.sprite(ButtonImageEnum::exit_game), sf::Vector2f(550.0,500.0));
    m_design_res.draw_image(m_window, *m_resource_manager.sprite(ButtonImageEnum::top_scores), sf::Vector2f(50.0,500.0));
}

void Game::exit_game()
{
    m_window.close();
}
