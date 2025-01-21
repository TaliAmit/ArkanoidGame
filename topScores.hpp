#ifndef ARKANOID_TOP_TEN_SCORES_HPP
#define ARKANOID_TOP_TEN_SCORES_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <tuple>
#include <list>
#include "gameConsts.hpp"
#include "designRes.hpp"
#include "musicPlayer.hpp"
#include "player.hpp"
#include "textBox.hpp"
#include "resourceManager.hpp"


class TopScores
{
public :
    using Score_info =  std::tuple<std::string, uint32_t, uint64_t>; // last member : uint64_t

    explicit TopScores(sf::RenderWindow& a_window, DesignRes& a_design_res, ResourceManager& a_resource_manager);
    ~TopScores() noexcept = default;

    const std::list<Score_info>& scores() const;
    void insert_score_info(Player& a_player); // insert its name, score, game_time
    bool is_a_top_score(const Player& a_player); 

    void run();

private :
    void handle_event(sf::Event a_event);

    void draw_objects();
    void draw_ten_top_scores(sf::Font a_font);
    void load_scores_from_file();
    void save_scores_to_file();

    void exit_game();

private :
    sf::RenderWindow& m_window;
    DesignRes& m_design_res;

    std::string m_fileName;

    std::list<Score_info> m_top_scores; 
    size_t m_inserted_scores;
    size_t m_inserted_to_file;
    bool m_go_back;
    ResourceManager& m_resource_manager; 
};
#endif // ARKANOID_TOP_TEN_SCORES_HPP
