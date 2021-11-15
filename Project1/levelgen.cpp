#include "levelgen.h"
#include <random>
#include <iostream>
using namespace std;
using namespace sf;
//버튼 n개 생성

level_GEN::level_GEN()
{
	level n4(30,50,4);
	level n5(180,50,5);
	level n6(330, 50,6);
	level n7(480, 50,7);
	level n8(30,250,8);
	level n9(180, 250,9);
	level n10(330, 250,10);

	levels.push_back(n4);
	levels.push_back(n5);
	levels.push_back(n6);
	levels.push_back(n7);
	levels.push_back(n8);
	levels.push_back(n9);
	levels.push_back(n10);
}

void level_GEN::draw(RenderWindow& _window)
{
	for (auto& _e : levels)
	{
		_e.draw(_window);
	}
}

int level_GEN::checkHit(FloatRect mouse)
{
	;	for (auto& _e : levels)
	{
		if (mouse.intersects(_e.getArea()) == true)
		{
			cout << "level : " << _e.id() << endl;
			return	_e.id();
		}
	}

	return 0;
}

