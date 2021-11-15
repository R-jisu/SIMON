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
	float time = 0;
	int line_period;
	bool checkit = false;
	Button(float _w, float _h, int _x, int _y, int _check);
	void update();
	void recalltoMagenta();
	void recalltoBlack();
	void draw(RenderWindow& _window);
	FloatRect getArea();
	int id();
};
