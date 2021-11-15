#include "Button.h"
#include <iostream>
Button::Button(float _w, float _h, int _x, int _y, int _check) : w(_w), h(_h), x(_x), y(_y), check(_check)
{
	line_period =300.0f;
	rect = RectangleShape(Vector2f(_w, _h));
	rect.setFillColor(Color::Red);
	rect.setPosition(_x, _y);
	check = _check;
	rect.setOutlineThickness(5);
	rect.setOutlineColor(Color::Black);
	bool checkit = false;
}

void Button::recalltoMagenta()
{
	if (checkit == true)
	{
		rect.setOutlineColor(Color::Cyan);
		checkit = false;
		clock.restart();
	}

	time = clock.getElapsedTime().asMilliseconds();

	if (time >= line_period)
	{
		//cout << "time : " << time << endl;
		rect.setOutlineColor(Color::Black);
	}
}

void Button::recalltoBlack()
{
	rect.setOutlineColor(Color::Black);
}

void Button::update()
{
	//처음부터 vector 확인 button _check시 테두리 on
	//마우스x,y좌표가 해당하면 테두리

	if (checkit == true)
	{
		rect.setFillColor(Color::Magenta);
		checkit = false;
		clock.restart();
	}

	time = clock.getElapsedTime().asMilliseconds();

	if (time >= line_period)
	{
		//cout << "time : " << time << endl;
		rect.setFillColor(Color::Red);
	}
}

void Button::draw(RenderWindow& _window)
{
	_window.draw(rect);
}

//똥의 크기를 받아올 함수입니다.
// getGlobalBound를 사용하면 경계상자의 크기 위치를 반환해줍니다
FloatRect Button::getArea()
{
	return rect.getGlobalBounds();
	//경계선의 크기 위치반환
}

int Button::id()
{
	return check;
}