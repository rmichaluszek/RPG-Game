#pragma once

#include <SFML/Graphics.hpp>

class SpawnMap : public sf::Drawable
{
public:
	SpawnMap(void);
	~SpawnMap(void);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawFrontground(sf::RenderWindow& window) const;
	virtual void update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition);
private:
	const static int arrayCount = 15;

	sf::Vector2f partPos[arrayCount];
	sf::Texture	texture[arrayCount];
	sf::Sprite
		sprMainBridge[4],
		sprCenterBridge,
		sprBridgeBarrier[8],
		sprBridgeBarrierCorner[4],
		sprBc[20];

			  
	float partScale[arrayCount];
};