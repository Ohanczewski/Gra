#include "Game_engine.h"

//Constructor 
Game_engine::Game_engine()
{
	this->initVariables();
	this->initWindow();
}

//Destructor
Game_engine::~Game_engine()
{
	delete this->window;
}

//private Functions
void Game_engine::initWindow()
{
	this->videomode.width = 800;
	this->videomode.height = 900;
	this->window = new sf::RenderWindow(this->videomode, "Janusz Dietczuk", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game_engine::initVariables()
{
	this->end = false;
}

//public Functions
void Game_engine::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game_engine::updateWindow()
{
	this->pollEvents();
	this->player.updatePlayer();
	if (this->player.checkTopCollision() == true || this->player.checkBottomCollision() == true)
		this->window->close();
}

void Game_engine::renderWindow()
{
	this->window->clear();

	//Rednering sth
	this->player.renderPlayer(this->window);

	this->window->display();
}

const bool Game_engine::running() const
{
	return this->window->isOpen();
}


