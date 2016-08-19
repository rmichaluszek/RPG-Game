#pragma once
#include <SFML/Graphics.hpp>

class GuiCheckBox : public sf::Drawable
{
public:
	bool isPressed;
	bool isFocused;
	GuiCheckBox();
	~GuiCheckBox();
	virtual void setButton(int x, int y, int width, int height, bool spawned, sf::Color color, std::string string, int fontSize);
	virtual void update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition, sf::Event event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void spawn();
	virtual void unSpawn();
	virtual void events(sf::Event event);
private:
	sf::Text text;
	sf::RectangleShape shape[4];
	sf::Color color;
	sf::Font font;
	sf::ConvexShape convex;
	int x, y, width, height;
	bool spawned,leftPressed;
};

