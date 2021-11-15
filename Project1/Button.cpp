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
	//처음부터 vector 확인 button _check시 테두리 on
	//마우스x,y좌표가 해당하면 테두리

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
	//경계선의 크기 위치반환
}

int Button::id()
{
	return check;
}