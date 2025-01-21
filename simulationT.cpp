#include <unistd.h> 
#include "simulationT.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <array>
#include <map>
#include <random>
#include <iostream> // debug
#include <cstddef>  // size_t
#include <cmath>    // pi, abs


#include "gameConsts.hpp"
#include "topScores.hpp"
#include "collision.hpp"
#include "designRes.hpp"

#include "explodeBrick.hpp"
#include "simpleBrick.hpp"
#include "strongBrick.hpp"

#include "player.hpp"
#include "vaus.hpp"
#include "ball.hpp"
#include "box.hpp"

#include "inputWindow.hpp"
#include "resourceManager.hpp"

SimulationT::SimulationT(sf::RenderWindow& a_window, ResourceManager& a_resource_manager, DesignRes& a_design_res, Player& a_player, TopScores& a_scores)
: m_window{a_window}
, m_player{a_player}
, m_box{sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2f(0.0, 50.0), sf::Color(100,100,100), outline_color}
, m_ball{BALL_RADUIS, sf::Vector2f(MIDDLE_WIDTH - BALL_RADUIS, WINDOW_HEIGHT - VAUS_HEIGHT - 2.3 * BALL_RADUIS), sf::Color(210,184,104), outline_color, BALL_STEP}
, m_vaus{sf::Vector2f(VAUS_WIDTH, VAUS_HEIGHT), sf::Vector2f(MIDDLE_WIDTH - 0.5 * VAUS_WIDTH, WINDOW_HEIGHT - VAUS_HEIGHT), sf::Color(76,108,100), outline_color}
, m_count_active_bricks{NUM_OF_BRICKS}
, m_scores{a_scores}
, m_resource_manager{a_resource_manager}
, m_design_res{a_design_res}
, m_is_paused{true}
, m_is_running{true}
, m_is_end_simulation{false}
{
    m_clock.restart();
    initialize_bricks();
    initialize_ball_step();

    // InputWindow input_win{m_window, m_player, m_scores};
    // input_win.run();
}

SimulationT::~SimulationT()
{
    for(auto brick : m_bricks)
    {
        delete brick;
    }
}


void SimulationT::initialize_bricks()
{
    float first_height = 100 - BRICK_Y_GAP;
    float x = BRICK_X_GAP;
    float y = 0.0;
    int idx = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    for(int i = 0; i < BRICKS_ROWS; ++i)
    {
        y = first_height + i * (float)BRICK_HEIGHT + i * BRICK_Y_GAP;

        for(int j = 0; j < BRICKS_COLUMNS; ++j)
        {
            x = j * (BRICK_WIDTH + BRICK_X_GAP);

            switch(dis(gen))
            {
            case 0:
                m_bricks[idx] = new SimpleBrick{sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT), sf::Vector2f(x, y), lines_colors[i]};
                break;
            case 1:
                m_bricks[idx] = new StrongBrick{sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT), sf::Vector2f(x, y), lines_colors[i]};
                break;
            case 2:
                m_bricks[idx] = new ExplodeBrick{sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT), sf::Vector2f(x, y), lines_colors[i]};
                break;
            default:
                break;
            }

            ++idx;
        }
    }
}

void SimulationT::initialize_ball_step()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(BALL_LOWER_BOUND_ANGLE, BALL_UPPER_BOUND_ANGLE);

    float angle = distribution(gen);
    angle *= M_PI / 180.0;
    m_ball.set_step(sf::Vector2f(BALL_SPEED * cos(angle), (-1) * BALL_SPEED * sin(angle)));
}



void SimulationT::draw_objects()
{
    m_box.draw(m_window);

    m_design_res.draw_image(m_window, *m_resource_manager.sprite(BackgroundImageEnum::simulation_screen), sf::Vector2f(0.0,0.0));
    m_design_res.draw_image(m_window, *m_resource_manager.sprite(GeneralImageEnum::player_lives_pic), sf::Vector2f(10.0,0.0));

    m_vaus.draw(m_window);
    m_ball.draw(m_window);

    draw_bricks();

    std::shared_ptr<sf::Font> font = m_resource_manager.font(FontEnum::game_font);
    std::string score_str = "Score : " + std::to_string(m_player.score());
    m_design_res.draw_text(m_window, score_str, (*font), sf::Vector2f(580.0, 20.0), 36, sf::Color(210,184,104));


    std::string lives_str = std::to_string(m_player.lives());
    m_design_res.draw_text(m_window, lives_str, (*font), sf::Vector2f(50.0, 20.0), 36, sf::Color(106,168,79));

    if(m_player.is_dead())
    {        
        m_design_res.draw_text(m_window, "Game Over", (*font), sf::Vector2f(75.0, 200.0), 121, sf::Color(0,0,0));
        m_is_end_simulation = true;
    }
    else if(m_count_active_bricks == 0)
    {
        m_design_res.draw_text(m_window, "Congratulations! You won", (*font), sf::Vector2f(75.0, 200.0), 50, sf::Color::Black); // (106,198,79)
        m_is_end_simulation = true;
    }
}



void SimulationT::draw_bricks()
{
    for(size_t i = 0; i < NUM_OF_BRICKS; ++i)
    {
        if(!m_bricks[i]->is_active())
        {
            m_bricks[i]->set_fill_color(sf::Color::Transparent);
        }
        else
        {
            m_bricks[i]->draw(m_window);
            std::shared_ptr<sf::Sprite> sprite = m_bricks[i]->get_sprite();

            if(sprite)
            {
                m_design_res.draw_image(m_window, *sprite, m_bricks[i]->position());
            } 
        }  
    }
}



void SimulationT::wait(float a_seconds) const
{
    sf::Clock clock;

    sf::Time target_time = sf::seconds(a_seconds); 
    sf::Time elapsed_time = sf::Time::Zero;

    while (elapsed_time < target_time)
    {
        sf::Time delta = clock.restart();
        elapsed_time += delta;
    }
}




void SimulationT::handle_event(sf::Event a_event)
{
    if (a_event.type == sf::Event::Closed)
    {
        exit_game();
    }

    if (a_event.type == sf::Event::KeyPressed)
    {
        switch(a_event.key.code)
        {
        case sf::Keyboard::Escape:
            m_is_end_simulation = true;
            break;

        case sf::Keyboard::Space:
            if(is_paused())
            {
                resume_game();
            }
            else
            {
                pause_game();
            }
            break;

        case sf::Keyboard::Left:
            if(!m_is_paused)
            {
                m_vaus.move_left(vaus_default_movement);
                 handle_vaus_left_collision();
            }
            break;

        case sf::Keyboard::Right:
            if(!m_is_paused)
            {
                m_vaus.move_right(vaus_default_movement);
                handle_vaus_right_collision();
            }
            break;  

        default:
            break;        
        }
    }      
}




void SimulationT::handle_vaus_right_collision()
{
    if(!m_collision.vaus_box_right_collision(m_vaus, m_box, vaus_default_movement.x))
    {
        m_vaus.move_right(vaus_default_movement);
    }
    else
    {
        float next_pos_x = BOX_WIDTH - VAUS_WIDTH;
        m_vaus.set_position(sf::Vector2f(next_pos_x, WINDOW_HEIGHT - VAUS_HEIGHT));
    }
}




void SimulationT::handle_vaus_left_collision()
{
    if(!m_collision.vaus_box_left_collision(m_vaus, m_box, (-1) * vaus_default_movement.x))
    {
        m_vaus.move_left(vaus_default_movement);
    }
    else
    {
        m_vaus.set_position(sf::Vector2f(0.0, WINDOW_HEIGHT - VAUS_HEIGHT));
    } 
}



void SimulationT::handle_collisions()
{    
    // need to change this
    m_collision.ball_box_walls_collision(m_ball, m_box);

    m_ball.set_step_direction(m_collision.ball_vaus_collision_new(m_ball, m_vaus));

    handle_ball_box_floor_collision();
    handle_brick_hit_collision(); 
}

void SimulationT::handle_ball_box_floor_collision()
{
    if(m_collision.ball_box_floor_collision(m_ball, m_box))
    {
        m_player.loose_life();
        draw_objects();

        if(!m_player.is_dead())
        {
            reset_game();
            
        }
        else
        {
            end_curr_simulation();
        }
    }
}

void SimulationT::handle_brick_hit_collision()
{
    sf::Vector2f ball_direction;

    for(size_t i = 0; i < NUM_OF_BRICKS; ++i)
    {
        if(m_bricks[i]->is_active())
        {
            ball_direction = m_collision.ball_brick_collision_new(m_ball, m_bricks[i]);

            if(ball_direction != sf::Vector2f(1.0, 1.0))
            {
                m_ball.set_step_direction(ball_direction);
                m_bricks[i]->get_hit();
                
                if(!m_bricks[i]->is_active())
                {
                    --m_count_active_bricks;
                    std::string type = m_bricks[i]->type();
                    m_player.add_to_score(bricks_scores.at(type));
                    
                    if(m_bricks[i]->type() == "explode")
                    {
                        recursive_exploding(i);
                    } 
                }  

                draw_objects();

                if(m_count_active_bricks == 0)
                {
                    end_curr_simulation();
                }
            }
        }
    }  
 }

 void SimulationT::recursive_exploding(size_t a_idx)
 {
    for(size_t i = 0; i < NUM_OF_BRICKS; ++i)
    {
        if(is_a_neighbor(a_idx, i) && m_bricks[i]->is_active())
        {
            m_bricks[i]->get_hit();

            if(!m_bricks[i]->is_active())
            {
                m_player.add_to_score(bricks_scores.at( m_bricks[i]->type()));
                --m_count_active_bricks;

                if(m_count_active_bricks == 0)
                {
                    return;
                }

                if(m_bricks[i]->type() == "explode")
                {
                    recursive_exploding(i);
                }
            }
        }
    }   
 }


 bool SimulationT::is_a_neighbor(size_t a_center_idx, size_t a_idx)
 {
    int center_row = a_center_idx / BRICKS_COLUMNS; 
    int center_col = a_center_idx % BRICKS_COLUMNS;  

    int neighbor_row = a_idx / BRICKS_COLUMNS;     
    int neighbor_col = a_idx % BRICKS_COLUMNS;    
    
    if (abs(neighbor_col - center_col) <= 1 && abs(neighbor_row - center_row) <= 1)
    {
        return true;
    }

    return false;
 }

void SimulationT::end_curr_simulation()
{
    m_is_running = false;
    sf::Time game_time = m_clock.getElapsedTime();
    m_player.set_game_time(game_time.asSeconds());
    std::cout << "Game time : " << m_player.game_time() << std::endl; 
}

// bool SimulationT::is_winner() const
// {
//     std::cout << "count_active_bricks : " << m_count_active_bricks << std::endl;
//     return m_count_active_bricks == 0;  
// }

bool SimulationT::is_game_over() const
{
    return m_player.is_dead();
}

bool SimulationT::is_paused() const
{
    return m_is_paused;
}

bool SimulationT::is_running() const
{
    return m_is_running;
}

void SimulationT::pause_game()
{
    m_is_paused = true;
}

void SimulationT::resume_game()
{
    m_is_paused = false;
}

void SimulationT::exit_game()
{
    m_window.close();
}

void SimulationT::reset_game()
{
    m_is_paused = true;
    m_ball.set_position(sf::Vector2f(MIDDLE_WIDTH - BALL_RADUIS, WINDOW_HEIGHT - VAUS_HEIGHT - 2.3 * BALL_RADUIS));
    m_vaus.set_position(sf::Vector2f(MIDDLE_WIDTH - 0.5 * VAUS_WIDTH, WINDOW_HEIGHT - VAUS_HEIGHT));

    initialize_ball_step();
    m_is_running = true;
}




void SimulationT::run()
{
    std::shared_ptr<sf::Music> music = m_resource_manager.music(MusicEnum::simulation);
    (*music).setLoop(true);
    (*music).play();

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            handle_event(event);
        }

        if(m_is_end_simulation)
        {
            break;
        }
        
        if(is_running())
        {
            if(!m_is_paused)
            {
                m_ball.move();
                handle_collisions();
            }
        }

        m_window.clear();
        draw_objects(); 
        m_window.display();
    }

    wait(3);
    (*music).stop();

    if(m_scores.is_a_top_score(m_player))
    {
        InputWindow input_win{m_window, m_player, m_scores};
        input_win.run();
    }
    else
    {
        m_scores.run();
    }
}
