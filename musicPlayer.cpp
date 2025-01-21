#include "musicPlayer.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>


void MusicPlayer::load_music(const std::string a_file_path)
{
    if (!m_music.openFromFile(a_file_path))
    {
        std::cout << "Error loading music file!" << std::endl;
    } 
}



void MusicPlayer::play_music()
{   
    m_music.setLoop(true); 
    m_music.play();
}

void MusicPlayer::stop_music()
{
    m_music.stop();
}

void MusicPlayer::pause_music()
{
    m_music.pause();
}