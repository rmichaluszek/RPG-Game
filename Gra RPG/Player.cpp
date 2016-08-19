#include "Player.h"
#include <math.h>
#include <iostream>

Player::Player(void)
{
	rotation = 0;
	line.setFillColor(sf::Color::Red);
	line.setSize(sf::Vector2f(200.0, 3.0));

	texture.loadFromFile("Data/Textures/Terrain/part1.png");
	sprite.setPosition(0, 0);
	sprite.setTexture(texture);
	moveSpeed = 4.0f;
}

Player::~Player(void)
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
	target.draw(line);
}

void Player::update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition, float cameraZoom)
{
	sf::Vector2f mousepos(sf::Mouse::getPosition(window));
	sf::Vector2f norm;

	norm.x = mousepos.x - 1280/cameraZoom - (line.getPosition().x - cameraPosition.x);
	norm.y = mousepos.y - 720/cameraZoom -  (line.getPosition().y - cameraPosition.y);

	double rot = atan2(norm.y, norm.x);
	rot = rot * 180.f / 3.14;

	line.setRotation(rot);

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
	line.move(playerRelPos);
}

sf::Vector2f Player::getPosition()
{
	return sprite.getPosition();
}