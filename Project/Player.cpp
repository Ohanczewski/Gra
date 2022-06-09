#include "Player.h"

//private Functions
void Player::initVariables()
{
	this->horizontal_speed = 5.f;
	this->vertical_speed = 5.f;
}

void Player::initShape()
{
	this->object.setFillColor(sf::Color::Cyan);
	this->object.setSize(sf::Vector2f(50.f, 50.f));
	this->object.setPosition(sf::Vector2f(375.f, 400.f));
}

//Constructor
Player::Player()
{
	this->initVariables();
	this->initShape();
}

//Destructor
Player::~Player()
{

}

//public Functions
void Player::updatePlayer()
{
	this->horizontalMove();
	this->Jump();
}

void Player::renderPlayer(sf::RenderTarget* target)
{
	target->draw(this->object);
}

void Player::horizontalMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		object.move(0, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (checkLeftCollision()==false)
			object.move(-this->horizontal_speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (checkRightCollision()==false)
			object.move(this->horizontal_speed, 0);
	}
}

void Player::Jump()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		object.move(0, -this->vertical_speed);
	}
	else
	{
		object.move(0, this->vertical_speed);
	}
}

bool Player::checkLeftCollision()
{
	sf::FloatRect player = this->object.getGlobalBounds();
	if (player.left < 0.f)
	{
		std::cout << "Lewa kolizja" << std::endl;
		object.move(0, 0);
		return true;
	}
	else
		return false;
}

bool Player::checkRightCollision()
{
	sf::FloatRect player = this->object.getGlobalBounds();
	if (player.left + player.width > 800.f)
	{
		std::cout << "Prawa kolizja" << std::endl;
		object.move(0, 0);
		return true;
	}
	else
		return false;
}

bool Player::checkTopCollision()
{
	sf::FloatRect player = this->object.getGlobalBounds();
	if (player.top < 0.f)
	{
		std::cout << "Gora kolizja" << std::endl;
		return true;
	}
}

bool Player::checkBottomCollision()
{
	sf::FloatRect player = this->object.getGlobalBounds();
	if (player.top + player.height > 900.f)
	{
		std::cout << "Dol kolizja" << std::endl;
		return true;
	}
}




