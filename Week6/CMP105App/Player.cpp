#include "Player.h"

Player::Player()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	stepVelocity = sf::Vector2f(0, 0);
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
	velocity = sf::Vector2f(150, 0);
}

Player::~Player()
{

}

void Player::update(float dt)
{
	//Apply gravity force, increasing velocity

	//Move shape by new velocity
	sf::Vector2f pos = stepVelocity * dt + 0.5f*gravity*dt*dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	//Check for collision with bottom of window
	if (getPosition().y >= 500)
	{
		isJumping = false;
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);
	}

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(velocity * dt);
	}

	if (input->isMouseLDown())
	{
		setPosition(input->getMouseX(), input->getMouseY());

	}
}