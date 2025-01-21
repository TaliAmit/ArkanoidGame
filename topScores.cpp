#include "topScores.hpp"

#include <tuple>
#include <string>
#include <fstream>
#include <iostream>
#include <iosfwd> // delete this
#include <algorithm>

#include "gameConsts.hpp"
#include "designRes.hpp"
#include "musicPlayer.hpp"
#include "player.hpp"

TopScores::TopScores(sf::RenderWindow& a_window, DesignRes& a_design_res, ResourceManager& a_resource_manager)
: m_window{a_window}
, m_design_res{a_design_res}
, m_fileName{TOP_SCORES_FILE_NAME}
, m_top_scores{}
, m_inserted_scores{0}
, m_go_back{false}
, m_resource_manager{ResourceManager::instance()}
{
    ;    
}

void TopScores::load_scores_from_file()
{
    std::fstream fin;

    fin.open(TOP_SCORES_FILE_NAME, std::ios::in | std::ios::binary);

    if(!fin)
    {
        std::cout << "Error - Could not open file" << std::endl;
        return;
    }

    for (size_t i = 0; i < m_inserted_scores; ++i)
    {
        std::string name;
        name.resize(32, ' ');
        fin.read(&name[0], sizeof(char) * name.size()); 
        name.erase(name.find_last_not_of(' ') + 1);
      
        uint32_t score;
        fin.read(reinterpret_cast<char*>(&score), sizeof(score));

        uint64_t time_in_ms;
        fin.read(reinterpret_cast<char*>(&time_in_ms), sizeof(time_in_ms));

        m_top_scores.push_back(std::make_tuple(name, score, time_in_ms));
    }

    fin.close();
}

/*
void TopScores::save_scores_to_existing_file()
{
    std::fstream fout;

    fout.open(TOP_SCORES_FILE_NAME, std::ios::out | std::ios::app | std::ios::binary);

    if(!fout)
    {
        std::cout << "Error - Could not open file" << std::endl;
        return;
    }

    for(auto itr = m_top_scores.begin(); itr < m_inserted_to_file; ++itr)
    {
        // get to the right place and write to the existing
        // file from this place and until the m_inserted_scores if number
        // of scores are less than 10
    }

    for (Score_info& score_info : m_top_scores)
    {
        std::string name = name = std::get<0>(score_info);
        name.resize(32, ' ');
        const char* c_name = name.c_str();
        uint32_t score = std::get<1>(score_info);
        uint64_t game_time = std::get<2>(score_info);

        fout.write(c_name, sizeof(c_name));
        fout.write(reinterpret_cast<const char*>(&score), sizeof(score));
        fout.write(reinterpret_cast<const char*>(&game_time), sizeof(game_time));
    }

    fout.close(); 
}
*/

void TopScores::save_scores_to_file()
{
    std::fstream fout;

    fout.open(TOP_SCORES_FILE_NAME, std::ios::out /*| std::ios::app*/ | std::ios::binary);

    if(!fout)
    {
        std::cout << "Error - Could not open file" << std::endl;
        return;
    }

    for (Score_info& score_info : m_top_scores)
    {
        std::string name = name = std::get<0>(score_info);
        name.resize(32, ' ');
        const char* c_name = name.c_str();
        uint32_t score = std::get<1>(score_info);
        uint64_t game_time = std::get<2>(score_info);

        fout.write(c_name, sizeof(c_name));
        fout.write(reinterpret_cast<const char*>(&score), sizeof(score));
        fout.write(reinterpret_cast<const char*>(&game_time), sizeof(game_time));
    }

    fout.close(); 
}

void TopScores::insert_score_info(Player &a_player)
{
    Score_info to_insert{a_player.name(),a_player.score(), a_player.game_time()};

    if(m_top_scores.empty())
    {
        m_top_scores.push_front(to_insert);
        std::cout << "is empty? " << m_top_scores.empty() << std::endl;
        std::cout << "name : " << std::get<1>(*m_top_scores.begin()) << std::endl;
        return;
    }

    for(auto itr = m_top_scores.begin(); itr != m_top_scores.end(); ++itr)
    {
        if(std::get<1>(*itr) > a_player.score()
        || (std::get<1>(*itr) == a_player.score() && std::get<2>(*itr) > a_player.game_time()))
        {
            m_top_scores.insert(itr, to_insert);
            break;
        }
    }

    if(m_inserted_scores >= TOP_SCORES_AMOUNT)
    {
        m_top_scores.pop_front();
    }
    else
    {
        ++m_inserted_scores;
    }
}

bool TopScores::is_a_top_score(const Player &a_player)
{
    if(m_inserted_scores < TOP_SCORES_AMOUNT)
    {
        return true;
    }

    Score_info& score_info = m_top_scores.front();

    float score = std::get<1>(score_info);
    float game_time = std::get<2>(score_info);

    return (score < a_player.score()
    || ( score == a_player.score() && game_time < a_player.game_time() ));
}

const std::list<TopScores::Score_info>& TopScores::scores() const
{
    return m_top_scores;
}

void TopScores::handle_event(sf::Event a_event)
{
    if (a_event.type == sf::Event::Closed)
    {
        exit_game();
    }
    
    if(a_event.type == sf::Event::KeyPressed)
    {
       if(a_event.key.code == sf::Keyboard::Escape)
       {
            m_go_back = true; 
       }
    }
}



void TopScores::draw_objects()
{
    std::shared_ptr<sf::Sprite> sprite = m_resource_manager.sprite(BackgroundImageEnum::top_scores_screen);
    m_design_res.draw_image(m_window, (*sprite), sf::Vector2f(0.0,0.0)); 

    std::shared_ptr<sf::Font> font = m_resource_manager.font(FontEnum::game_font);
    m_design_res.draw_text(m_window, "Top 10 Scores", (*font), sf::Vector2f(190.0, 50.0), 60, sf::Color(10,20,20));

    draw_ten_top_scores(*font);
}

void TopScores::draw_ten_top_scores(sf::Font a_font)
{
    m_design_res.draw_text(m_window, "Name  Score  Time", a_font, sf::Vector2f(220.0, 170.0), 40, sf::Color(10,20,20));

    float first_x_pos = 220.0;
    float first_y_pos = 250.0;

    float x_space = 150.0;
    float y_space = 30.0;

    float x = first_x_pos;
    float y = first_y_pos;

    for(auto [name, score, time] : m_top_scores)
    {
        std::cout << "name : " << name << std::endl;
        m_design_res.draw_text(m_window, name, a_font, sf::Vector2f(x, y), 40, sf::Color(100,200,20));
        m_design_res.draw_text(m_window, std::to_string(score), a_font, sf::Vector2f(x + x_space, y), 40, sf::Color(100,200,20));
        m_design_res.draw_text(m_window, std::to_string(time/60) + ":" + std::to_string(time%60), a_font, sf::Vector2f(x + 2*x_space, y), 40, sf::Color(100,200,20));

        x = first_x_pos;
        y += y_space;
    }
}

void TopScores::exit_game()
{
    m_window.close();
}

void TopScores::run()
{
    std::shared_ptr<sf::Music> music = m_resource_manager.music(MusicEnum::top_scores);
    (*music).setLoop(true);
    (*music).play();
    

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            handle_event(event);
        }

        m_window.clear();
        draw_objects();
        m_window.display();

        if(m_go_back == true)
        {
            m_go_back = false;
            (*music).stop();
            break;
        }
    }
}

