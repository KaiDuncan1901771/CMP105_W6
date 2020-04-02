#include "Player2.h"


Player2::Player2()
{
	speed = 50.0f;
	acceleration = 50.f;
	target = sf::Vector2f(30, 30);
}

Player2::~Player2()
{

}

void Player2::update(float dt)
{
	//calculate direction and move
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity = (direction * speed); //fixed speed;
	setPosition(getPosition() + (velocity * dt));

	//if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
		speed = 50.0f;
	}

	speed+= 0.01;
}

void Player2::handleInput(float dt)
{
	
}