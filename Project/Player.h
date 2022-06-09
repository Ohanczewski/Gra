#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Player
{
private: 
	//Variables
	sf::RectangleShape object;
	float horizontal_speed;
	float vertical_speed;

	//Functions
	void initVariables();
	void initShape();
public: 
	//Functions
	Player();
	~Player();

	void updatePlayer();
	void renderPlayer(sf::RenderTarget *target);
	void horizontalMove();
	void Jump();
	bool checkLeftCollision();
	bool checkRightCollision();
	bool checkTopCollision();
	bool checkBottomCollision();
};

