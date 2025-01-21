#ifndef ARKANOID_MUSIC_PLAYER_HPP
#define ARKANOID_MUSIC_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class MusicPlayer
{
public :
    explicit MusicPlayer() = default;
    ~MusicPlayer() = default;

    void load_music(const std::string a_file_path);

    void play_music();
    void stop_music();
    void pause_music();

private :
    sf::Music m_music;
};

#endif // ARKANOID_MUSIC_PLAYER_HPP