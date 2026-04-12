#include <GUI/GUI.hpp>
#include <StoreManager/StoreManager.hpp>
#include <FileManager/FileManager.hpp>
#include <Analytics/Analytics.hpp>

#include <SFML/Window/Event.hpp>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>

//Constructor for Button, initializes the rectangle and text with given parameters and positions the text in the center of the button
GUI::Button::Button(const sf::Font& font, const std::string& str, sf::Vector2f pos, sf::Vector2f size,
	sf::Color bgColor, sf::Color hColor, sf::Color txtColor, std::function<void()> callback)
	: rect(size), text(font, str, 18), onClick(callback), normalColor(bgColor), hoverColor(hColor), textColor(txtColor) 
{
	rect.setPosition(pos);
	rect.setFillColor(bgColor);
	rect.setOutlineColor(sf::Color(200, 200, 200));
	rect.setOutlineThickness(1.f);
	text.setFillColor(textColor);
	sf::FloatRect bounds = text.getLocalBounds();
	text.setPosition({
		pos.x + (size.x - bounds.size.x) / 2.f - bounds.position.x,
		pos.y + (size.y - bounds.size.y) / 2.f - bounds.position.y
		});
}

//Constructor for TableCell, initializes the rectangle and text with given parameters and positions the text in the center of the cell
GUI::TableCell::TableCell(const sf::Font& font, const std::string& str, sf::Vector2f pos, sf::Vector2f size,
	sf::Color bgColor, sf::Color txtColor, bool isHeader)
	: rect(size), text(font, str, 16) 
{
	rect.setPosition(pos);
	rect.setFillColor(bgColor);
	rect.setOutlineColor(sf::Color(220, 220, 220));
	rect.setOutlineThickness(1.f);
	text.setFillColor(txtColor);
	if (isHeader) text.setStyle(sf::Text::Bold);
	text.setPosition({ pos.x + 10.f, pos.y + (size.y - text.getLocalBounds().size.y) / 2.f - text.getLocalBounds().position.y });
}

std::string GUI::formatCurrency(float value) 
{
	std::stringstream ss;
	ss << "Rs. " << std::fixed << std::setprecision(2) << value;
	return ss.str();
}

std::string GUI::wrapText(sf::Text& text, float maxWidth, const std::string& str) 
{
	std::string currentLine{}, wrappedString{}, word{};
	std::istringstream words(str);
	while (words >> word) {
		std::string testLine = currentLine + (currentLine.empty() ? "" : " ") + word;
		text.setString(testLine);
		if (text.getLocalBounds().size.x > maxWidth) 
		{
			wrappedString += currentLine + "\n";
			currentLine = word;
		}
		else { currentLine = testLine; }
	}
	return wrappedString + currentLine;
}

void GUI::Button::update(sf::Vector2f mousePos) {rect.setFillColor(rect.getGlobalBounds().contains(mousePos) ? hoverColor : normalColor);}

bool GUI::Button::isClicked(sf::Vector2f mousePos) const {return rect.getGlobalBounds().contains(mousePos);}

void GUI::Button::draw(sf::RenderWindow& window) const 
{
	window.draw(rect);
	window.draw(text);
}

void GUI::TableCell::draw(sf::RenderWindow& window) const 
{
	window.draw(rect);
	window.draw(text);
}

void GUI::drawTable(sf::RenderWindow& window, const sf::Font& font, const std::string& title, sf::Vector2f pos,
	const std::vector<std::string>& headers, const std::vector<std::vector<std::string>>& rows, const std::vector<float>& colWidths) 
{
	sf::Text tText(font, title, 22);
	tText.setFillColor(sf::Color(120, 120, 120));
	tText.setStyle(sf::Text::Bold);
	tText.setPosition(pos);
	window.draw(tText);

	sf::Vector2f curPos(pos.x, pos.y + 35.0f);
	for (size_t i = 0; i < headers.size(); ++i) 
	{
		TableCell(font, headers[i], curPos, { colWidths[i], 32.f }, colorTableHead, sf::Color::White, true).draw(window);
		curPos.x += colWidths[i];
	}
	for (const auto& row : rows) 
	{
		curPos.y += 32.f; curPos.x = pos.x;
		for (size_t i = 0; i < row.size(); ++i) 
		{
			TableCell(font, row[i], curPos, { colWidths[i], 32.f }, sf::Color::White, colorText).draw(window);
			curPos.x += colWidths[i];
		}
	}
}

void GUI::drawCartSection(sf::RenderWindow& window, const sf::Font& font, StoreManager* sm) 
{
	// DUMMY DATA: Replace with sm->getCartItems() later or some similar function
	std::vector<std::vector<std::string>> rows(8, { "---", "0", "0.00", "0.00" });
	rows[0] = { "Samosa", "2", "120.00", "240.00" };

	drawTable(window, font, "CART ITEMS", { 300, 40 }, { "Item", "Qty", "Price", "Subtotal" }, rows, { 200, 80, 120, 120 });

	sf::Text total(font, "Total: " + formatCurrency(000.0f), 16);
	total.setFillColor(colorText); total.setStyle(sf::Text::Bold);
	total.setPosition({ 300, 370 }); // Moved relative to 8-row table, dont change this unless you change the table row count or cell height
	window.draw(total);
}

void GUI::drawDatabaseSection(sf::RenderWindow& window, const sf::Font& font, FileManager* fm) 
{
	// DUMMY DATA: Replace with fm->getDatabaseRows() later or some similar function
	std::vector<std::vector<std::string>> rows(8, { "---", "---", "---", "0", "0.00" });
	rows[0] = { "14:32", "1001", "Samosa", "1", "40.00" };

	drawTable(window, font, "DATABASE LOG", { 300, 410 }, { "Time", "ID", "Item", "Qty", "Profit" }, rows, { 100, 80, 180, 60, 100 });
}

void GUI::drawAnalyticsSection(sf::RenderWindow& window, const sf::Font& font, Analytics* an) 
{
	sf::Text title(font, "BUSINESS INSIGHTS", 24);
	title.setFillColor(colorAccentBlue); 
	title.setPosition({ 1100, 40 });
	window.draw(title);

	sf::RectangleShape box({ 460, 760 });
	box.setPosition({ 1100, 80 }); 
	box.setFillColor(sf::Color::White);
	box.setOutlineThickness(1.f); 
	box.setOutlineColor(sf::Color(200, 200, 200));
	window.draw(box);

	sf::Text content(font, "", 17);
	content.setFillColor(colorText); 
	content.setPosition({ 1115, 95 });
	std::string str = "Analytics will appear here after clicking 'Analyze Database'. This panel is ready for your custom suggestion algorithm with text wrapping.";
	content.setString(wrapText(content, 430.f, str));
	window.draw(content);
}

void GUI::setupControls(const sf::Font& font, std::vector<Button>& buttons, StoreManager* sm, FileManager* fm, Analytics* an) 
{
	buttons.emplace_back(font, "Update Cart", sf::Vector2f(25, 80), sf::Vector2f(210, 40), sf::Color::White, sf::Color(240, 240, 240), colorText, []() { std::cout << "[UI] Update Cart Clicked\n"; });
	buttons.emplace_back(font, "Complete Sale", sf::Vector2f(25, 130), sf::Vector2f(210, 45), colorAccentBlue, sf::Color(50, 90, 130), sf::Color::White, []() { std::cout << "[UI] Complete Sale Clicked\n"; });
	buttons.emplace_back(font, "Clear Cart", sf::Vector2f(25, 185), sf::Vector2f(210, 40), colorAccentRed, sf::Color(180, 50, 50), sf::Color::White, []() { std::cout << "[UI] Clear Cart Clicked\n"; });

	std::vector<std::string> items = { "Samosa", "Lays", "Pepsi", "Kurkure", "Roll", "Prince", "Juice", "Candle" };
	for (size_t i = 0; i < items.size(); ++i) {
		float y = 260.0f + (static_cast<float>(i) * 50.0f);
		buttons.emplace_back(font, items[i], sf::Vector2f(25, y), sf::Vector2f(130, 40), sf::Color::White, sf::Color::White, colorText, nullptr);
		buttons.emplace_back(font, "+", sf::Vector2f(160, y), sf::Vector2f(35, 40), sf::Color(220, 235, 220), sf::Color(200, 220, 200), colorText, [sm, n = items[i]]() { std::cout << "Add " << n << "\n"; });
		buttons.emplace_back(font, "-", sf::Vector2f(200, y), sf::Vector2f(35, 40), sf::Color(235, 220, 220), sf::Color(220, 200, 200), colorText, [sm, n = items[i]]() { std::cout << "Rem " << n << "\n"; });
	}

	buttons.emplace_back(font, "Update Database", sf::Vector2f(25, 700), sf::Vector2f(210, 45), sf::Color::White, sf::Color(240, 240, 240), colorText, []() { std::cout << "[UI] Update Database Clicked\n"; });
	buttons.emplace_back(font, "Analyze Database", sf::Vector2f(25, 755), sf::Vector2f(210, 45), colorAccentBlue, sf::Color(50, 90, 130), sf::Color::White, []() { std::cout << "[UI] Analyze Database Clicked\n"; });
}

void GUI::initGUI(StoreManager* sm, FileManager* fm, Analytics* an) 
{
	sf::RenderWindow window(sf::VideoMode({ 1600u, 900u }), "ProfitLens POS");
	window.setFramerateLimit(60);
	sf::Font font;
	if (!font.openFromFile("5-Assets/Fonts/DMSans.ttf")) throw std::runtime_error("Failed to load font");

	std::vector<Button> buttons;
	setupControls(font, buttons, sm, fm, an);

	while (window.isOpen()) 
	{
		while (const std::optional event = window.pollEvent()) 
		{
			if (event->is<sf::Event::Closed>()) window.close();
			if (const auto* m = event->getIf<sf::Event::MouseButtonPressed>()) 
			{
				sf::Vector2f p = window.mapPixelToCoords(m->position);
				for (auto& b : buttons) if (b.isClicked(p) && b.onClick) b.onClick();
			}
			if (const auto* mm = event->getIf<sf::Event::MouseMoved>()) 
			{
				sf::Vector2f p = window.mapPixelToCoords(mm->position);
				for (auto& b : buttons) b.update(p);
			}
		}
		window.clear(colorBg);
		sf::RectangleShape side({ 260, 900 }); side.setFillColor(colorSidebar); 
		window.draw(side);
		drawCartSection(window, font, sm);
		drawDatabaseSection(window, font, fm);
		drawAnalyticsSection(window, font, an);
		for (const auto& b : buttons) b.draw(window);
		window.display();
	}
}