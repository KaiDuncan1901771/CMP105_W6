#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Player2: public GameObject
{
public:
	Player2();
	~Player2();

	void update(float dt);
	void handleInput(float dt);

private:
	float acceleration;
	float speed;
	sf::Vector2f velocity;
	sf::Vector2f direction;
	sf::Vector2f target;

};

