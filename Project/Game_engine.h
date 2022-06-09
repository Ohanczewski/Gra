#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

class Game_engine
{
private: 
	//Variables
	sf::RenderWindow *window;
	sf::VideoMode videomode;
	sf::Event event;
	//Player in game engine
	Player player;

	bool end;

	//Functions
	void initWindow();
	void initVariables();
public: 
	//Constructor 
	Game_engine();
	//Destructor
	~Game_engine();

	//Functions
	const bool running() const;
	void pollEvents();
	void renderWindow();
	void updateWindow();

};

