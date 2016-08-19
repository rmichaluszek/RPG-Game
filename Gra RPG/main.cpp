#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "SpawnMap.h"
#include "Camera.h"

int main()
{
	std::cout << "Game version : " << VERSION << std::endl;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Gra RPG", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Player player;
	SpawnMap spawn;
	Camera camera;
	sf::Shader shader;
	sf::RenderTexture rTexture,rTexture2;

	sf::Clock deltaClock;
	deltaClock.restart();
	rTexture.create(1280, 720);
	rTexture2.create(1280, 720);

	if(!shader.loadFromFile("blur.frag", sf::Shader::Fragment))
	{
		// error...
	}


	while (window.isOpen())
	{
		//Events
		float deltaTime = deltaClock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			camera.events(event);
		}
		//Logic
		player.update(window,deltaTime,camera.getPosition(),camera.getZoom());
		spawn.update(window, deltaTime,camera.getPosition());

		camera.setTarget(player.getPosition());
		camera.update(window, deltaTime, event);

		rTexture.setView(camera.camera);

		//Rendering

		rTexture.clear(sf::Color(0, 0 ,0, 255));
		rTexture.draw(spawn);
		rTexture.draw(player);
		

		shader.setParameter("blur_radius", sf::Vector2f(2/1280.f, 0));
		rTexture.display();
		
		rTexture2.draw(sf::Sprite(rTexture.getTexture()),&shader);
		shader.setParameter("blur_radius", sf::Vector2f(0.000f, 2 / 720.f));
		rTexture2.display();

		window.draw(sf::Sprite(rTexture2.getTexture()), &shader);

		window.draw(camera);
		window.display();
	}

	return EXIT_SUCCESS;
}