#pragma once
#include <SFML/Graphics.hpp>
#include "GuiButton.h"
#include "GuiCheckBox.h"

class Camera : public sf::Drawable
{
public:
	GuiCheckBox checkbox[2];
	GuiButton button[5];
	Camera();
	~Camera();
	sf::View camera;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(sf::RenderWindow &window, float deltaTime, sf::Event event);
	virtual void setTarget(sf::Vector2f targetPosition);
	virtual void events(sf::Event event);

	sf::Vector2f getPosition();
	float getZoom();

private:
	
	sf::Vector2f targetPosition;
	float cameraZoom;
};

