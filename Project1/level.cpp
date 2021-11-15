#include "level.h"

level::level(float _x, float _y, int _id) : x(_x), y(_y), checkid(_id)
{
	shape = RectangleShape(Vector2f(100, 100));
	shape.setFillColor(Color::White);
	shape.setPosition(_x, _y);
	checkid = _id;
}

void level::draw(RenderWindow& _window)
{
	_window.draw(shape);
}

int level::id()
{
	return checkid;
}

FloatRect level::getArea()
{
	return shape.getGlobalBounds();
	//경계선의 크기 위치반환
}