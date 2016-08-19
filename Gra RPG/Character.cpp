#include "Character.h"

Character::Character(void)
{
	texture.loadFromFile("image.jpg");
	sprite.setTexture(texture);
	moveSpeed = 3.0f;
}

Character::~Character(void)
{

}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}

void Character::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerRelPos.x = -moveSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerRelPos.x = moveSpeed;
	else
		playerRelPos.x = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		playerRelPos.y = -moveSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		playerRelPos.y = moveSpeed;
	else
		playerRelPos.y = 0;

	sprite.move(playerRelPos);
}