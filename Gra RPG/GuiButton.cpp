#include "GuiButton.h"



GuiButton::GuiButton()
{
	font.loadFromFile("Data/Fonts/Lato-Bold.ttf");
}


GuiButton::~GuiButton()
{
}

void GuiButton::setButton(int x, int y, int width, int height, bool spawned, sf::Color color, std::string string,int fontSize)
{
	shape.setSize(sf::Vector2f((float)width, (float)height));
	shape.setPosition(x, y);
	shape.setOrigin(width / 2, height / 2);
	shape.setFillColor(color);
	if (!spawned)
		shape.setSize(sf::Vector2f(width, 0));

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

void GuiButton::update(sf::Window &window, float deltaTime, sf::Vector2f cameraPosition, sf::Event event)
{
	shape.setPosition(sf::Vector2f(x, y));
	text.setPosition(shape.getPosition()+sf::Vector2f(shape.getSize().x/2-width/2,shape.getSize().y/2-height/2));

	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	if (spawned & shape.getSize().y != height)
	{
		shape.setSize(sf::Vector2f(width, (height + shape.getSize().y) / 2.f));
		shape.setRotation(0);
	}
		
	if (!spawned & shape.getSize().y != 0)
	{
		shape.setRotation(180);
		shape.setSize(sf::Vector2f(width,shape.getSize().y / 2.f));
		text.setPosition(shape.getPosition() + sf::Vector2f(shape.getSize().x / 2 - width / 2, shape.getSize().y / 2 - height / 2 + (height-shape.getSize().y)));
	}
		
	if (mouseX > (shape.getPosition().x - shape.getSize().x/2 )  & mouseX < (shape.getPosition().x + shape.getSize().x/2 )   &&
		mouseY >(shape.getPosition().y - shape.getSize().y / 2)  & mouseY < (shape.getPosition().y + shape.getSize().y / 2 ) )
	{
		isFocused = true;
		shape.setFillColor(color - sf::Color(20, 20, 20, 0));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			shape.setFillColor(color - sf::Color(50, 50, 50, 0));
		}
	}
	else
	{
		isFocused = false;
		isPressed = false;
		shape.setFillColor(color);
	}

	text.setScale(1, shape.getSize().y/height);
	text.setColor(sf::Color(255, 255, 255, shape.getSize().y / height * 255));
}

void GuiButton::spawn()
{
	spawned = true;
}

void GuiButton::unSpawn()
{
	spawned = false;
}

void GuiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
	target.draw(text);
}

void GuiButton::events(sf::Event event)
{

	if (event.type == sf::Event::MouseButtonPressed & event.mouseButton.button == sf::Mouse::Left & shape.getSize().y >= height - 1 & isFocused)
	{
		isPressed = !isPressed;
	}

}