#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Player3: public GameObject
{
public:
	Player3();
	~Player3();

	void update(float dt);
	void handleInput(float dt);

private:
	float speed;
	sf::Vector2f direction;
	sf::Vector2f velocity;
	sf::Vector2f target;
	sf::Vector2f stepVelocity;
	sf::Vector2f gravity;
	float scale;

	int x1, x2, y1, y2, diffX, diffY;
	bool dragging;
	bool go;
};

