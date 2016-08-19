#include "SpawnMap.h"

SpawnMap::SpawnMap(void)
{
	texture[0].loadFromFile("Data/Textures/Terrain/part1.png");
	texture[1].loadFromFile("Data/Textures/Terrain/part2.png");
	texture[2].loadFromFile("Data/Textures/Terrain/barrier.png");
	texture[3].loadFromFile("Data/Textures/Terrain/barrier_corner.png");
	texture[4].loadFromFile("Data/Textures/Terrain/barrier_corner_lighter.png");
	texture[5].loadFromFile("Data/Textures/Terrain/bcpart1.png");
	texture[6].loadFromFile("Data/TExtures/Terrain/bcpart2.png");
	texture[7].loadFromFile("Data/Textures/Terrain/bcpart3.png");
	texture[8].loadFromFile("Data/Textures/Terrain/bcpart4.png");
	texture[9].loadFromFile("Data/Textures/Terrain/bcpart5.png");
	texture[10].loadFromFile("Data/Textures/Terrain/bcpart6.png");

	sprMainBridge[0].setPosition(-2048 - 256, 0);
	sprMainBridge[1].setPosition(2048 + 256, 0);
	sprMainBridge[2].setPosition(0, -2048 - 256);
	sprMainBridge[3].setPosition(0, 2048 + 256);

	sprBridgeBarrier[0].setPosition(-2048 - 256, -232);
	sprBridgeBarrier[1].setPosition(2048 + 256, -232);
	sprBridgeBarrier[2].setPosition(-232, -2048 - 256);
	sprBridgeBarrier[3].setPosition(-232, 2048 + 256);
	sprBridgeBarrier[4].setPosition(-2048 - 256,232);
	sprBridgeBarrier[5].setPosition(2048 + 256,232);
	sprBridgeBarrier[6].setPosition(232, -2048 - 256);
	sprBridgeBarrier[7].setPosition(232, 2048 + 256);

	sprMainBridge[2].setRotation(-90);
	sprMainBridge[3].setRotation(-90);

	sprBridgeBarrier[2].setRotation(-90);
	sprBridgeBarrier[3].setRotation(-90);
	sprBridgeBarrier[6].setRotation(-90);
	sprBridgeBarrier[7].setRotation(-90);

	for (int i = 0; i < 4; i++)
	{
		sprMainBridge[i].setTexture(texture[0]);
		sprMainBridge[i].setOrigin(1024, 128);
		sprMainBridge[i].setScale(2, 2);
		
		sprBridgeBarrierCorner[i].setOrigin(16, 16);
		sprBridgeBarrierCorner[i].setScale(2, 2);
		sprBridgeBarrierCorner[i].setRotation(i * -90);

		sprBridgeBarrier[i].setTexture(texture[2]);
		sprBridgeBarrier[i+4].setTexture(texture[2]);
		sprBridgeBarrier[i].setOrigin(1024, 16);
		sprBridgeBarrier[i+4].setOrigin(1024, 16);
		sprBridgeBarrier[i].setScale(2, 2);
		sprBridgeBarrier[i + 4].setScale(2, 2);
	}

	sprBridgeBarrierCorner[0].setTexture(texture[3]);
	sprBridgeBarrierCorner[1].setTexture(texture[3]);
	sprBridgeBarrierCorner[2].setTexture(texture[4]);
	sprBridgeBarrierCorner[3].setTexture(texture[4]);

	sprCenterBridge.setTexture(texture[1]);
	sprCenterBridge.setOrigin(128, 128);
	sprCenterBridge.setScale(2, 2);

	sprBridgeBarrierCorner[0].setPosition(-232, -232);
	sprBridgeBarrierCorner[1].setPosition(-232, 232);
	sprBridgeBarrierCorner[2].setPosition(232, 232);
	sprBridgeBarrierCorner[3].setPosition(232, -232);


	sprBc[1].setTexture(texture[7]);
	sprBc[1].setScale(4, 4);
	sprBc[1].setOrigin(256, 256);
	sprBc[1].setPosition(-2048, -512);

	sprBc[6].setTexture(texture[10]);
	sprBc[6].setScale(1.5,1.5);
	sprBc[6].setOrigin(256, 256);
	sprBc[6].setPosition(-1024, 512);

	sprBc[10].setTexture(texture[5]);
	sprBc[10].setScale(2, 2);
	sprBc[10].setOrigin(256, 256);
	sprBc[10].setPosition(-512-256, 512+256);

	sprBc[8].setTexture(texture[8]);
	sprBc[8].setScale(2, 2);
	sprBc[8].setOrigin(256, 256);
	sprBc[8].setPosition(-1024+256, -1024+256);

	sprBc[9].setTexture(texture[9]);
	sprBc[9].setScale(2.2, 2.2);
	sprBc[9].setOrigin(128, 128);
	sprBc[9].setPosition(-512, -512);

	sprBc[19].setTexture(texture[6]);
	sprBc[19].setScale(2, 2);
	sprBc[19].setOrigin(256, 256);
	sprBc[19].setPosition(-1024 - 256, -512 );

}

SpawnMap::~SpawnMap(void)
{
}

void SpawnMap::update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition)
{
	sprBc[1].setPosition(-1548 + cameraPosition.x*0.3, 0 + cameraPosition.y*0.3);
	sprBc[6].setPosition(-1024 + cameraPosition.x*0.1, 600 + cameraPosition.y*0.1);
	sprBc[19].setPosition(-1600 - cameraPosition.x*0.2, -660 - cameraPosition.y*0.2);
}

void SpawnMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprBc[1]);
	target.draw(sprBc[6]);
	target.draw(sprBc[8]);
	target.draw(sprBc[9]);
	target.draw(sprBc[10]);
	

	target.draw(sprMainBridge[0]);
	target.draw(sprMainBridge[1]);
	target.draw(sprMainBridge[2]);
	target.draw(sprMainBridge[3]);
	target.draw(sprCenterBridge);
	
	target.draw(sprBridgeBarrier[0]);
	target.draw(sprBridgeBarrier[1]);
	target.draw(sprBridgeBarrier[2]);
	target.draw(sprBridgeBarrier[3]);
	target.draw(sprBridgeBarrier[4]);
	target.draw(sprBridgeBarrier[5]);
	target.draw(sprBridgeBarrier[6]);
	target.draw(sprBridgeBarrier[7]);
	
	target.draw(sprBridgeBarrierCorner[0]);
	target.draw(sprBridgeBarrierCorner[1]);
	target.draw(sprBridgeBarrierCorner[2]);
	target.draw(sprBridgeBarrierCorner[3]);

	
}

void SpawnMap::drawFrontground(sf::RenderWindow& window) const
{
	window.draw(sprBc[19]);
}