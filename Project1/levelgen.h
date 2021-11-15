#pragma once
#include "level.h"
#include <vector>
#include <random>

using namespace std;
using namespace sf;

class level_GEN
{
private:
	vector<level> levels;
public:
	level_GEN();
	int id();
	void draw(RenderWindow& _window);
	int checkHit(FloatRect _rect);
};