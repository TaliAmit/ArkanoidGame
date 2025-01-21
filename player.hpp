#ifndef ARKANOID_PLAYER_HPP
#define ARKANOID_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstddef> // size_t

class Player
{
public:
    explicit Player(size_t a_lives);
    Player(const Player& a_other) = default;
    Player(Player&& a_other) = default;
    ~Player() = default;

    bool operator<(const Player& a_other) const;

    size_t lives() const;
    std::string name() const;
    uint32_t score() const;
    uint64_t game_time() const;

    void draw(sf::RenderWindow& a_window) const;

    void set_name(std::string a_name);
    void set_game_time(float a_game_time);

    void add_to_score(size_t a_score);
    void dec_from_score(size_t a_score);
    
    void gain_life();
    void loose_life();

    bool is_dead() const;

private:    
    size_t m_lives;
    uint32_t m_score;
    std::string m_name;
    uint64_t m_game_time;
};

#endif // ARKANOID_PLAYER_HPP