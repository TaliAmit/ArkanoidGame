#ifndef ARKANOID_TRY_TEXT_HPP
#define ARKANOID_TRY_TEXT_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <limits> // for numeric_limits

class TextBox {
public:
    // Constructor with optional parameters for font, size, color, and initial text
    TextBox(const sf::Font& font = sf::Font(), unsigned int charSize = 20,
            const sf::Color& color = sf::Color::White, const std::string& initialText = "");

    // Setters for font, character size, color, and text limit
    void setFont(const sf::Font& font);
    void setCharacterSize(unsigned int size);
    void setColor(const sf::Color& color);
    void setLimit(unsigned int limit);

    // Getters for character size, color, and text (const version for safety)
    unsigned int getCharacterSize() const { return m_characterSize; }
    const sf::Color& getColor() const { return m_textColor; }
    const std::string& getText() const { return m_text; }

    // Method to draw the text box on an SFML window
    void draw(sf::RenderTarget& target) const;

    // Event handling methods for user input
    void handleEvent(const sf::Event& event); // Single handleEvent function

    void handleTextEntered(sf::Event event);

private:
    // Member variables for font, size, color, text, and text limit
    sf::Font m_font;
    unsigned int m_characterSize;
    sf::Color m_textColor;
    std::string m_text;
    unsigned int m_limit;

    void handleKeyPressed(sf::Event event);

    // Helper functions for handling specific input events
    void processTextInput(char character);
    void processBackspace();
};


#endif // ARKANOID_TRY_TEXT_HPP

