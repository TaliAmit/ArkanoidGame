#ifndef ARKANOID_SIMULATION_TEST_HPP
#define ARKANOID_SIMULATION_TEST_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream> // debug
#include <random>
#include <array>
#include <map>

#include "simpleBrick.hpp"
#include "strongBrick.hpp"
#include "explodeBrick.hpp"
#include "musicPlayer.hpp"
#include "topScores.hpp"
#include "gameConsts.hpp"
#include "collision.hpp"
#include "designRes.hpp"
#include "player.hpp"
#include "vaus.hpp"
#include "ball.hpp"
#include "box.hpp"


class SimulationT
{
public:
    explicit SimulationT(sf::RenderWindow& a_window, ResourceManager& a_resource_manager, DesignRes& a_design_res, Player& a_player, TopScores& a_scores);
    SimulationT(const SimulationT& a_other) = delete;
    SimulationT(SimulationT&& a_other) = delete;
    ~SimulationT();

    void run();

private:

    //bool is_winner() const; 
    bool is_game_over() const;
    bool is_paused() const;
    bool is_running() const;

    void pause_game();
    void resume_game();
    void exit_game();
    void reset_game();

    void top_score_player();

    void end_curr_simulation();     // when loosing life or get killed

    void handle_event(sf::Event a_event);
    void handle_collisions();
    void handle_ball_box_floor_collision();

    void draw_objects();
    void draw_bricks();

    void wait(float a_seconds) const;

    void initialize_ball_step();
    void initialize_bricks();

    void handle_vaus_right_collision(); 
    void handle_vaus_left_collision(); 
    void handle_brick_hit_collision(); 

    bool is_a_neighbor(size_t a_center_idx, size_t a_idx);
    void recursive_exploding(size_t a_idx);

private:

    sf::RenderWindow& m_window;

    Player& m_player;
    Box m_box;
    Ball m_ball;
    Vaus m_vaus;
    std::array<AbsBrick*, NUM_OF_BRICKS> m_bricks;
    size_t m_count_active_bricks;

    TopScores& m_scores;
    Collision m_collision; // change this to a refference
    ResourceManager& m_resource_manager;
    DesignRes& m_design_res;
    sf::Clock m_clock;

    bool m_is_paused;
    bool m_is_running;
    bool m_is_end_simulation;
};


#endif // ARKANOID_SIMULATION_TEST_HPP
