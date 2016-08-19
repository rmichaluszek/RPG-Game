#include "Camera.h"
#include <iostream>


Camera::Camera()
{
	cameraZoom = 2.0f;
	camera.setCenter(sf::Vector2f(0, 0));
	camera.setSize(sf::Vector2f(1280 , 720 ));
	camera.zoom(cameraZoom);
	camera.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
	button[0].setButton(60, 60, 50, 50, true, sf::Color(233, 30, 99),"Esc",25);
	button[1].setButton(1280 / 2,100, 350, 90, false, sf::Color(233, 30, 99), "RESUME",50);
	button[2].setButton(1280 / 2,200, 350, 90, false, sf::Color(233, 30, 99), "OPTIONS", 50);
	button[3].setButton(1280 / 2, 300 , 350, 90, false, sf::Color(233, 30, 99), "HELP", 50);
	button[4].setButton(1280 / 2, 400 , 350, 90, false, sf::Color(233, 30, 99), "LOG OUT", 50);

	checkbox[0].setButton(1280 / 2, 500, 350, 90, false, sf::Color(233, 30, 99), "FULLSCREEN", 50);
}


Camera::~Camera()
{
}

void Camera::update(sf::RenderWindow &window, float deltaTime, sf::Event event)
{
	camera.setCenter(sf::Vector2f(targetPosition.x, targetPosition.y));

	for(int i = 0; i < 5; i++)
		button[i].update(window, deltaTime, camera.getCenter(), event);
	checkbox[0].update(window, deltaTime, camera.getCenter(), event);

	if (button[0].isPressed)
	{
		checkbox[0].spawn();
		button[1].spawn();
		button[2].spawn();
		button[3].spawn();
		button[4].spawn();
		button[0].unSpawn();
	}

	if (button[1].isPressed)
	{
		checkbox[0].unSpawn();
		button[1].unSpawn();
		button[2].unSpawn();
		button[3].unSpawn();
		button[4].unSpawn();
		button[0].spawn();
	}
		
}

void Camera::setTarget(sf::Vector2f targetPosition)
{
	this->targetPosition = targetPosition;
}

void Camera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 5; i++)
		target.draw(button[i]);

	target.draw(checkbox[0]);
}

sf::Vector2f Camera::getPosition()
{
	return camera.getCenter();
}

float Camera::getZoom()
{
	return cameraZoom;
}

void Camera::events(sf::Event event)
{
	checkbox[0].events(event);
	for (int i = 0; i < 5; i++)
	{
		button[i].events(event);
	}
}