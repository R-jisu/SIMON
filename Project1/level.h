#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class level
{
private:
	RectangleShape shape;
	float x;
	float y;
	int checkid;
public:
	level(float _x, float _y, int _id);
	int id();
	void update();
	void draw(RenderWindow& _window);
	FloatRect getArea();
};
