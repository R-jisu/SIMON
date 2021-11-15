#pragma once
#include "Button.h"
#include <vector>
#include <random>

using namespace std;
using namespace sf;

class Button_GEN
{
private:
	vector<Button> buttons;
	int Buttonnumber;
public:
	Clock clock;
	float time = 0;
	int recall_period;

	vector<int> mybutton; //��
	vector<int> simonbutton; //��

	Button_GEN(int level_num);
	
	void recall();
	void upscore();
	void update();
	void draw(RenderWindow& _window);
	void checkHit(FloatRect _rect);
};