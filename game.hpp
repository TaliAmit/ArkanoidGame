#ifndef ARKANOID_GAME_HPP
#define ARKANOID_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <array>

#include "resourceManager.hpp"
#include "topScores.hpp"
#include "designRes.hpp"
#include "button.hpp"
#include "player.hpp"


class Game
{
public :
    explicit Game(ResourceManager& a_resource_manager, DesignRes& a_design_res);
    ~Game() = default;
    void run();

private :
    void handle_event(sf::Event a_event);
    void draw_pictures();
    void exit_game();

private :
    sf::RenderWindow m_window;
    ResourceManager& m_resource_manager;
    DesignRes& m_design_res;

    Player m_player;
    TopScores m_scores;

    Button m_start_game_btn;
    Button m_exit_game_btn;
    Button m_top_scores_btn;
};

#endif // ARKANOID_GAME_HPP