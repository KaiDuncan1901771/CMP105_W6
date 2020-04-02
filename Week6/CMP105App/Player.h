#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
class Player: public GameObject
{
public:
	Player();
	~Player();

	void update(float dt);
	void handleInput(float dt);

private:
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	bool isJumping;
};

