#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	playerTexture.loadFromFile("gfx/Beach_Ball.png");
	player.setTexture(&playerTexture);
	player.setSize(sf::Vector2f(30, 30));
	player.setPosition(500, 100);
	player.setInput(input);

	player2Texture.loadFromFile("gfx/Goomba.png");
	player2.setTexture(&player2Texture);
	player2.setSize(sf::Vector2f(30, 30));
	player2.setPosition(30, 30);
	player2.setInput(input);

	player3Texture.loadFromFile("gfx/MushroomTrans.png");
	player3.setTexture(&player3Texture);
	player3.setSize(sf::Vector2f(30, 30));
	player3.setPosition(100, 300);
	player3.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
//	player.handleInput(dt);
//	player2.handleInput(dt);
	player3.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	player2.update(dt);
	player3.update(dt);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player);
	window->draw(player2);
	window->draw(player3);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}