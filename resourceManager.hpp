#ifndef ARKANOID_resource_MANAGER_HPP
#define ARKANOID_resource_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <cstddef>  // size_t
#include <memory>   // shared ptr



enum class BackgroundImageEnum
{
    game_options_screen,
    simulation_screen,
    top_scores_screen,
    input_screen
};

enum class GeneralImageEnum
{
    game_logo,
    player_lives_pic,
    brick_crack_1,
    brick_crack_2,
    top_score_headline
};

enum class ButtonImageEnum
{
    start_game,
    exit_game,
    top_scores
};

enum class FontEnum
{
    game_font
};



enum class MusicEnum
{
    simulation,
    top_scores
};


class ResourceManager // singelton
{
public:

    ResourceManager(const ResourceManager& a_other) = delete;
    ResourceManager& operator=(const ResourceManager& a_other) = delete;

    static ResourceManager& instance();
    
    std::shared_ptr<sf::Sprite> sprite(BackgroundImageEnum a_enum);
    std::shared_ptr<sf::Sprite> sprite(GeneralImageEnum a_enum);
    std::shared_ptr<sf::Sprite> sprite(ButtonImageEnum a_enum);

    std::shared_ptr<sf::Font> font(FontEnum a_enum);
    std::shared_ptr<sf::Music> music(MusicEnum a_enum);

private:

    explicit ResourceManager();
    ~ResourceManager() = default;

    std::map<MusicEnum, std::shared_ptr<sf::Music>> m_music;
    std::map<FontEnum, std::shared_ptr<sf::Font>> m_fonts;

    std::map<BackgroundImageEnum, std::shared_ptr<sf::Sprite>> m_background_sprites;
    std::map<GeneralImageEnum, std::shared_ptr<sf::Sprite>> m_general_sprites;
    std::map<ButtonImageEnum, std::shared_ptr<sf::Sprite>> m_button_sprites;

    std::map<BackgroundImageEnum, std::shared_ptr<sf::Texture>> m_background_textures;
    std::map<GeneralImageEnum, std::shared_ptr<sf::Texture>> m_general_textures;
    std::map<ButtonImageEnum, std::shared_ptr<sf::Texture>> m_button_textures;

    void initialize_fonts();
    void initialize_music();

    void initialize_background_resources();
    void initialize_general_resources();
    void initialize_button_resources();

};

#endif // ARKANOID_resource_MANAGER_HPP
