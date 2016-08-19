#include "GuiCheckBox.h"


GuiCheckBox::GuiCheckBox()
{
	font.loadFromFile("Data/Fonts/Lato-Bold.ttf");
}


GuiCheckBox::~GuiCheckBox()
{
}

void GuiCheckBox::setButton(int x, int y, int width, int height, bool spawned, sf::Color color, std::string string, int fontSize)
{
	leftPressed = false;
	isPressed = true;

	for (int i = 0; i < 3; i++)
	{
		shape[i].setSize(sf::Vector2f((float)width, (float)height));
		shape[i].setFillColor(color);
	}

	shape[0].setPosition(x, y);
	shape[0].setOrigin(width / 2, height / 2);

	shape[1].setPosition(x+width/2+height/2, y);
	shape[1].setOrigin(height/2, height / 2);

	shape[2].setPosition(x + width / 2 + height / 2, y);
	shape[2].setOrigin(height / 2*0.8, height / 2*0.8);

	shape[3].setPosition(x + width / 2 + height / 2, y);
	shape[3].setOrigin(height / 2 * 0.8, height / 2 * 0.8);

	if (!spawned)
	{
		for (int i = 0; i < 4; i++)
		{
			shape[i].setSize(sf::Vector2f(width, 0));
		}
	}
	
	text.setCharacterSize(fontSize);
	text.setColor(sf::Color(255, 255, 255, 255));
	text.setFont(font);
	text.setString(string);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	this->color = color;
	this->x = x;
	this->y = y;
	this->spawned = spawned;
	this->width = width;
	this->height = height;
}

void GuiCheckBox::update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition, sf::Event event)
{
	shape[0].setPosition(sf::Vector2f(x, y ));
	shape[1].setPosition(sf::Vector2f(x +width/2+height/2, y));
	shape[2].setPosition(sf::Vector2f(x + width / 2 + height / 2, y ));
	shape[3].setPosition(sf::Vector2f(x + width / 2 + height / 2 , y ));
	text.setPosition(shape[0].getPosition() + sf::Vector2f(shape[0].getSize().x / 2 - width/2, shape[0].getSize().y / 2 - height / 2));

	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	if (spawned & shape[0].getSize().y != height)
	{
		shape[0].setSize(sf::Vector2f(width, (height + shape[0].getSize().y) / 2.f));
		shape[0].setRotation(0);
		shape[1].setSize(sf::Vector2f(height, (height + shape[0].getSize().y) / 2.f));
		shape[1].setRotation(0);
		shape[2].setSize(sf::Vector2f(height*0.8, ((height + shape[0].getSize().y) / 2.f)*0.8));
		shape[2].setRotation(0);
	}

	if (!spawned & shape[0].getSize().y != 0)
	{

		shape[0].setRotation(180);
		shape[0].setSize(sf::Vector2f(width, shape[0].getSize().y / 2.f));
		shape[1].setRotation(180);
		shape[1].setSize(sf::Vector2f(height, shape[0].getSize().y / 2.f));
		shape[2].setRotation(180);
		shape[2].setSize(sf::Vector2f(height*0.8, shape[0].getSize().y / 2.f *0.8));
		text.setPosition(shape[0].getPosition() + sf::Vector2f(shape[0].getSize().x / 2 - width / 2, shape[0].getSize().y / 2 - height / 2 + (height - shape[0].getSize().y)));
	}


	if (mouseX > (shape[0].getPosition().x - shape[0].getSize().x / 2)  & mouseX < (shape[0].getPosition().x + shape[0].getSize().x / 2) &&
		mouseY >(shape[0].getPosition().y - shape[0].getSize().y / 2)  & mouseY < (shape[0].getPosition().y + shape[0].getSize().y / 2))
	{
		shape[0].setFillColor(color - sf::Color(20, 20, 20, 0));
		isFocused = true;
	}
	else
	{
		isFocused = false;
		shape[0].setFillColor(color);
		shape[1].setFillColor(color);
		shape[2].setFillColor(color-sf::Color(90,90,90,0));
	}

	if(isPressed & spawned)
		shape[3].setSize(sf::Vector2f(height*0.8,( shape[3].getSize().y + height*0.8) / 2.f));
	if(!isPressed || !spawned)
		shape[3].setSize(sf::Vector2f(height*0.8, shape[3].getSize().y  / 2.f));

	text.setScale(1, shape[0].getSize().y / height);
	text.setColor(sf::Color(255, 255, 255, shape[0].getSize().y / height * 255));
}

void GuiCheckBox::spawn()
{
	spawned = true;
}

void GuiCheckBox::unSpawn()
{
	spawned = false;
}

void GuiCheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape[0]);
	target.draw(shape[1]);
	target.draw(shape[2]);
	target.draw(shape[3]);
	target.draw(text);
}

void GuiCheckBox::events(sf::Event event)
{

	if (event.type == sf::Event::MouseButtonPressed & event.mouseButton.button == sf::Mouse::Left & shape[0].getSize().y >= height - 1 & isFocused)
	{
		isPressed = !isPressed;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shape[0].setFillColor(color - sf::Color(60, 60, 60, 0));
	}
}