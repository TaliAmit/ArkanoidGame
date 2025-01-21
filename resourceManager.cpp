#include "resourceManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

const std::map<BackgroundImageEnum, std::string> background_pic_paths
{
    {BackgroundImageEnum::game_options_screen, "pictures/leafs.jpg"},
    {BackgroundImageEnum::simulation_screen, "pictures/forest.jpg"},
    {BackgroundImageEnum::top_scores_screen,"pictures/top_ten_scores.jpg"},
    {BackgroundImageEnum::input_screen,"pictures/input_screen.jpg"}
};


const std::map<GeneralImageEnum, std::string> general_pic_paths
{
    {GeneralImageEnum::game_logo, "pictures/logo.png"},
    {GeneralImageEnum::player_lives_pic, "pictures/heart.png"},
    {GeneralImageEnum::brick_crack_1, "pictures/brick_crack_1.png"},
    {GeneralImageEnum::brick_crack_2, "pictures/brick_crack_2.png"},
    {GeneralImageEnum::top_score_headline, "pictures/top_score.png"}
};


const std::map<ButtonImageEnum, std::string> button_pic_paths
{
    {ButtonImageEnum::exit_game, "pictures/exit_btn.png"},
    {ButtonImageEnum::start_game, "pictures/start_btn.png"},
    {ButtonImageEnum::top_scores, "pictures/top_ten_btn.png"}
};

const std::map<FontEnum, std::string> fonts_paths
{
    {FontEnum::game_font, "fonts/MigaeSemibold-3zd2M.otf"}
};

const std::map<MusicEnum, std::string> music_paths
{
    {MusicEnum::simulation, "music/mainWindow.ogg"},
    {MusicEnum::top_scores, "music/topTenWindow.ogg"}
};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



ResourceManager::ResourceManager()
{
    initialize_background_resources();
    initialize_general_resources();
    initialize_button_resources();

    initialize_fonts();
    initialize_music();
}

void ResourceManager::initialize_fonts()
{
    for(const auto& [key, path] : fonts_paths)
    {
        auto font = std::make_shared<sf::Font>();

        if(!(*font).loadFromFile(path))
        {
            std::cout << "Error loading font file!" << std::endl;
        }

        m_fonts[key] = font;
    }
}

void ResourceManager::initialize_music()
{
    for(const auto& [key, path] : music_paths)
    {
        auto music = std::make_shared<sf::Music>();

        if(!(*music).openFromFile(path))
        {
            std::cout << "Error loading music file!" << std::endl;
            continue;
        }

        m_music[key] = music;
    }
    
}

void ResourceManager::initialize_background_resources()
{
    for (const auto& [key, path] : background_pic_paths)
    {
        auto texture = std::make_shared<sf::Texture>();

        if (!texture->loadFromFile(path))
        {
            std::cout << "Error loading background texture: " << path << std::endl;
            continue;
        }

        m_background_textures[key] = texture;
        m_background_sprites[key] = std::make_shared<sf::Sprite>(*m_background_textures[key]);   
    }
}

void ResourceManager::initialize_general_resources()
{
    for (const auto& [key, path] : general_pic_paths)
    {
        auto texture = std::make_shared<sf::Texture>();

        if (!texture->loadFromFile(path))
        {
            std::cout << "Error loading general image texture: " << path << std::endl;
            continue;
        }

        m_general_textures[key] = texture;
        m_general_sprites[key] = std::make_shared<sf::Sprite>(*m_general_textures[key]);
    }
}

void ResourceManager::initialize_button_resources()
{
    for (const auto& [key, path] : button_pic_paths)
    {
        auto texture = std::make_shared<sf::Texture>();

        if (!texture->loadFromFile(path))
        {
            std::cout << "Error loading button image texture: " << path << std::endl;
            continue;
        }

        m_button_textures[key] = texture;
        m_button_sprites[key] = std::make_shared<sf::Sprite>(*m_button_textures[key]);
    }
}

ResourceManager &ResourceManager::instance()
{
    static ResourceManager _instance;
    return _instance;
}



std::shared_ptr<sf::Sprite> ResourceManager::sprite(BackgroundImageEnum a_enum)
{
    ResourceManager& instance = ResourceManager::instance();
    return instance.m_background_sprites.at(a_enum);
}


std::shared_ptr<sf::Sprite> ResourceManager::sprite(GeneralImageEnum a_enum)
{
    ResourceManager& instance = ResourceManager::instance();
    return instance.m_general_sprites.at(a_enum);
}

std::shared_ptr<sf::Sprite> ResourceManager::sprite(ButtonImageEnum a_enum)
{
    ResourceManager& instance = ResourceManager::instance();
    return instance.m_button_sprites.at(a_enum);
}


std::shared_ptr<sf::Font> ResourceManager::font(FontEnum a_enum)
{
    ResourceManager& instance = ResourceManager::instance();
    return instance.m_fonts.at(a_enum);
}

std::shared_ptr<sf::Music> ResourceManager::music(MusicEnum a_enum)
{
    ResourceManager& instance = ResourceManager::instance();
    return instance.m_music.at(a_enum);
}


