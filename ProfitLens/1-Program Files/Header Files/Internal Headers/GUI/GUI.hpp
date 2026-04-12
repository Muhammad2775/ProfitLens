#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <functional>
#include <optional>

//These classes have been forward declared. Learn about forward declaration
class StoreManager;
class FileManager;
class Analytics;

class GUI {
public:
    void initGUI(StoreManager* storeManager, FileManager* fileManager, Analytics* analytics);

private:
    struct Button 
    {
        sf::RectangleShape rect;
        sf::Text text;
        std::function<void()> onClick;
        sf::Color normalColor{}, hoverColor{}, textColor{};
        bool isHovered{ false };

        Button(const sf::Font& font, const std::string& str, sf::Vector2f pos, sf::Vector2f size,
            sf::Color bgColor, sf::Color hColor, sf::Color txtColor, std::function<void()> callback = nullptr);

        void draw(sf::RenderWindow& window) const;
        void update(sf::Vector2f mousePos);
        bool isClicked(sf::Vector2f mousePos) const;
    };

    struct TableCell 
    {
        sf::RectangleShape rect;
        sf::Text text;

        TableCell(const sf::Font& font, const std::string& str, sf::Vector2f pos, sf::Vector2f size,
            sf::Color bgColor, sf::Color txtColor, bool isHeader = false);

        void draw(sf::RenderWindow& window) const;
    };

    void drawCartSection(sf::RenderWindow& window, const sf::Font& font, StoreManager* sm);
    void drawDatabaseSection(sf::RenderWindow& window, const sf::Font& font, FileManager* fm);
    void drawAnalyticsSection(sf::RenderWindow& window, const sf::Font& font, Analytics* an);

    void drawTable(sf::RenderWindow& window, const sf::Font& font, const std::string& title, sf::Vector2f pos,
        const std::vector<std::string>& headers, const std::vector<std::vector<std::string>>& rows,
        const std::vector<float>& colWidths);

    std::string wrapText(sf::Text& text, float maxWidth, const std::string& str);
    std::string formatCurrency(float value);
    void setupControls(const sf::Font& font, std::vector<Button>& buttons, StoreManager* sm, FileManager* fm, Analytics* an);

    //RGB values for each color are defined, change accordingly if necessary
    const sf::Color colorBg{ 250, 250, 252 };
    const sf::Color colorSidebar{ 235, 238, 241 };
    const sf::Color colorText{ 45, 50, 55 };
    const sf::Color colorAccentRed{ 210, 70, 70 };
    const sf::Color colorAccentBlue{ 60, 110, 150 };
    const sf::Color colorTableHead{ 190, 200, 210 };
};