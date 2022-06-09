#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Enemy
{
private:
	//Variables

	//Functions


public:
	//Constructor
	Enemy();

	//Destructor
	~Enemy();

	//Functions
	void updateEnemy();
	void renderEnemy(sf::RenderTarget & target);
	
};

