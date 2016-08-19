#pragma once
#include <SFML/Graphics.hpp>

class GuiButton : public sf::Drawable
{
public:
	bool isPressed;
	bool isFocused;
	GuiButton();
	~GuiButton();
	virtual void setButton(int x, int y, int width, int height, bool spawned, sf::Color color,std::string string, int fontSize);
	virtual void update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition,sf::Event event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void spawn();
	virtual void unSpawn();
	virtual void events(sf::Event event);
private:
	sf::Text text;
	sf::RectangleShape shape;
	sf::Color color;
	sf::Font font;
	int x, y, width, height;
	bool spawned;
};

