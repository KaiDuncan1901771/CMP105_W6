#include "Player3.h"


Player3::Player3()
{
	scale = 200.0f;
	speed = 1000.0f;
	target = sf::Vector2f(30, 30);
	stepVelocity = sf::Vector2f(0, 0);
	gravity = sf::Vector2f(0, 9.8f) * scale;
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	diffX = 0;
	diffY = 0;
	dragging = false;
	go = false;
}

Player3::~Player3()
{

}

void Player3::handleInput(float dt)
{
	if (input->isMouseLDown())
	{
		input->setMouseLDown(true);

		dragging = true;
		x2 = input->getMouseX();
		y2 = input->getMouseY();
	}
	else
	{
		input->setMouseLDown(false);
		if (dragging == true)
		{
			setPosition(100, 300);
			system("CLS");
			dragging = false;
			diffX = x2 - x1;
			diffY = y2 - y1;
			std::cout << "X movement: " << diffX << " " << "Y movement: " << diffY;
			go = true;
		}
		else
		{
			x1 = input->getMouseX();
			y1 = input->getMouseY();
		}
	}
}

void Player3::update(float dt)
{
	if (go == true)
	{
		target = sf::Vector2f(input->getMouseX(), input->getMouseY());
		direction = sf::Vector2f(-diffX, -diffY) - getPosition();
		direction = Vector::normalise(direction);
		velocity = (direction * speed); //fixed speed;
		setPosition(getPosition() + (velocity * dt));

		//Apply gravity force, increasing velocity

	//Move shape by new velocity
		sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
		stepVelocity += gravity * dt;
		setPosition(getPosition() + pos);

		//Check for collision with bottom of window
		if (getPosition().y >= 600)
		{
			setPosition(getPosition().x, 600);
			stepVelocity = sf::Vector2f(0, 0);
			go = false;
		}


	}
}

