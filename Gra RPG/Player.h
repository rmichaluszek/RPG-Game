#pragma once

#include <SFML/Graphics.hpp>

#include "Character.h"

class Player : public Character
{
public:
	Player(void);
	~Player(void);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(sf::Window &window,float deltaTime, sf::Vector2f cameraPosition, float cameraZoom);

	sf::Vector2f getPosition();

private:
	sf::RectangleShape line;
	sf::View camera;
	float rotation;
};