#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Player::Player(size_t a_lives)
: m_lives{a_lives}
, m_name{"Anonimus"}
{
    m_score = 0;
    m_game_time = 0;
}

bool Player::operator<(const Player &a_other) const
{
    if(m_score < a_other.m_score)
    {
        return true;
    }
    else if(m_score == a_other.m_score)
    {
        if(m_game_time < a_other.m_game_time)
        {
            return true;
        }
    }

    return false;
}

size_t Player::lives() const
{
    return m_lives;
}

std::string Player::name() const
{
    return m_name;
}

uint32_t Player::score() const
{
    return m_score;
}

uint64_t Player::game_time() const
{
    return m_game_time;
}

void Player::set_name(std::string a_name)
{
    m_name = a_name;
}

void Player::set_game_time(float a_game_time)
{
    m_game_time = a_game_time;
}

void Player::add_to_score(size_t a_score)
{
    m_score += a_score;
}

// not in use in the current state
void Player::dec_from_score(size_t a_score)
{
    if(m_score - a_score >= 0)
    {
        m_score -= a_score;
    }
    else
    {
        m_score = 0;
    }
}

void Player::loose_life()
{
    if(m_lives > 0)
    {
        --m_lives;
    }
}

void Player::gain_life()
{
    ++m_lives;
}

bool Player::is_dead() const
{
    return m_lives == 0;
}
