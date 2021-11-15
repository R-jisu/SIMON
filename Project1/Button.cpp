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
	//ó������ vector Ȯ�� button _check�� �׵θ� on
	//���콺x,y��ǥ�� �ش��ϸ� �׵θ�

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

//���� ũ�⸦ �޾ƿ� �Լ��Դϴ�.
// getGlobalBound�� ����ϸ� �������� ũ�� ��ġ�� ��ȯ���ݴϴ�
FloatRect Button::getArea()
{
	return rect.getGlobalBounds();
	//��輱�� ũ�� ��ġ��ȯ
}

int Button::id()
{
	return check;
}