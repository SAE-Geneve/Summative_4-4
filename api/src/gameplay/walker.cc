#include "gameplay/walker.h"

#include <iostream>

#include "sfml_vec2f.h"


Walker::Walker(float x, float y, float linear_speed) : SpriteEntity(x, y)
{
	setPosition(x, y);
	linear_speed_ = linear_speed;
	last_time_ = std::chrono::steady_clock::now();
}

void Walker::set_destination(float x, float y)
{
	destination_.x = x;
	destination_.y = y;
}

void Walker::set_linear_speed(float linear_speed)
{
	linear_speed_ = linear_speed;
}

void Walker::Tick()
{
	const auto now{ std::chrono::steady_clock::now() };
	const std::chrono::duration<float> elapsed_seconds{ now - last_time_ };
	last_time_ = std::chrono::steady_clock::now();

	auto delta_time = elapsed_seconds;

	std::cout << "Delta time ? : " << elapsed_seconds << std::endl;

	const sf::Vector2f actual_position = getPosition();
	const sf::Vector2f direction = Normalized(destination_ - actual_position);

	setPosition(
		actual_position + sf::Vector2f(direction.x * linear_speed_ * elapsed_seconds.count(),
			direction.y * linear_speed_ * elapsed_seconds.count())
	);

	std::cout << "Position [" << getPosition().x << ":" << getPosition().y << "]" << std::endl;

	// Update sprite position
	shape_.setPosition(getPosition());

}

