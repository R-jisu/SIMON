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
	
	void recall(RenderWindow& _window);
	void recall_update();
	void upscore();
	void update();

	void recalldraw(RenderWindow& _window);
	void draw(RenderWindow& _window);
	void checkHit(FloatRect _rect);
};