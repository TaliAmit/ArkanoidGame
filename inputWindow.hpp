#ifndef ARKANOID_INPUT_WINDOW_HPP
#define ARKANOID_INPUT_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <array>

#include "simulation.hpp"
#include "designRes.hpp"
#include "musicPlayer.hpp"
//#include "textBox.hpp"
//#include "button.hpp"

class InputWindow
{
public :
    explicit InputWindow(sf::RenderWindow& a_window, Player& a_player, TopScores& a_scores);
    ~InputWindow() = default;
    void run();

private :
    void handle_event(sf::Event a_event);
    void draw_objects();

private :

    sf::RenderWindow& m_window;
    Player& m_player;
    TopScores& m_scores;
    DesignRes m_design_res;
    std::string m_name; 

    bool m_is_finish;
};

#endif // ARKANOID_INPUT_WINDOW_HPP