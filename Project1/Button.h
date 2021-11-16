#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button
{
private:
	//button x, y��ǥ, ����üũ��ȣ
	int x;  int y;
	float w; float h;
	int check;
	//button rect�� ����
	RectangleShape rect;
public:
	Clock clock;
	Clock clock1;
	float time = 0;
	float time1 = 0;
	int line_period;
	bool checkit = false;
	bool recallcheck= false;

	bool blink(bool _blink);

	Button(float _w, float _h, int _x, int _y, int _check);
	void update();
	void recallUpdate();
	void draw(RenderWindow& _window);
	FloatRect getArea();
	int id();
};
