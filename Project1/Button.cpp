#include "Button.h"
#include <iostream>
Button::Button(float _w, float _h, int _x, int _y, int _check) : w(_w), h(_h), x(_x), y(_y), check(_check)
{
	line_period =500.0f;
	rect = RectangleShape(Vector2f(_w, _h));
	rect.setFillColor(Color::Blue);
	rect.setPosition(_x, _y);
	check = _check;
	rect.setOutlineThickness(5);
	rect.setOutlineColor(Color::Black);
	recallcheck = false;
	bool checkit = false;
}

void Button::recallUpdate()
{
	if (recallcheck == true)
	{
		rect.setOutlineColor(Color::Magenta);
		recallcheck = false;
		clock1.restart();
	}
	
	time1 = clock1.getElapsedTime().asMilliseconds();

	if (time1 >= line_period)
	{
		rect.setOutlineColor(Color::Black);
	}
}


void Button::update()
{
	//ó������ vector Ȯ�� button _check�� �׵θ� on
	//���콺x,y��ǥ�� �ش��ϸ� �׵θ�

	if (checkit == true)
	{
		rect.setFillColor(Color::Red);
		checkit = false;
		clock.restart();
	}

	time = clock.getElapsedTime().asMilliseconds();

	if (time >= line_period)
	{
		rect.setFillColor(Color::Blue);
		//rect.setOutlineColor(Color::Black);

	}
}

void Button::draw(RenderWindow& _window)
{
	_window.draw(rect);
}

FloatRect Button::getArea()
{
	return rect.getGlobalBounds();
	//��輱�� ũ�� ��ġ��ȯ
}

int Button::id()
{
	return check;
}