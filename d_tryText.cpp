#include "tryText.hpp"

// Implementation details (can be placed in a separate .cpp file)

TextBox::TextBox(const sf::Font& font, unsigned int charSize,
                const sf::Color& color, const std::string& initialText)
    : m_font(font), m_characterSize(charSize), m_textColor(color), m_text(initialText), m_limit(0)
{
    // Default constructor sets no limit
}

void TextBox::setFont(const sf::Font& font) {
    m_font = font;
}

void TextBox::setCharacterSize(unsigned int size) {
    m_characterSize = size;
}

void TextBox::setColor(const sf::Color& color) {
    m_textColor = color;
}

void TextBox::setLimit(unsigned int limit) {
    m_limit = limit;
}

void TextBox::draw(sf::RenderTarget& target) const {
    sf::Text text(m_text, m_font, m_characterSize);
    text.setFillColor(m_textColor);
    // (Optional) Set position, outline, etc. here
    target.draw(text);
}

void TextBox::handleEvent(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::TextEntered:
            handleTextEntered(event);
            break;
        case sf::Event::KeyPressed:
            handleKeyPressed(event);
            break;
        default:
            // Handle other events if needed
            break;
    }
}

void TextBox::handleTextEntered(sf::Event event)
{
    if (event.type == sf::Event::TextEntered)
    {
        char ch = static_cast<char>(event.text.unicode);
        processTextInput(ch);
    }
    
}

void TextBox::handleKeyPressed(sf::Event event) {
    if (event.key.code == sf::Keyboard::BackSpace) {
        processBackspace();
    }
}

void TextBox::processTextInput(char character) {
    // Check if we have reached the text limit (if set)
    if (m_limit > 0 && m_text.length() >= m_limit) {
        return; // Don't add character if limit is reached
    }

    // Handle valid printable characters (ASCII or extended)
    if (std::isprint(character)) {
        m_text += character;
    }
}

void TextBox::processBackspace() {
    if (!m_text.empty()) {
        m_text.erase(m_text.length() - 1);
    }
}
