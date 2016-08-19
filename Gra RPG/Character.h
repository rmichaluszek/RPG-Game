#pragma once

//PE - Pre alfa
#define VERSION "PE-0.1"

#include <SFML\Graphics.hpp>

class Character : public sf::Drawable
{
public:
	Character(void);
	~Character(void);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void update();
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f playerRelPos;

	float moveSpeed;
};

