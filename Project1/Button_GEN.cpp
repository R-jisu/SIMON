#include "Button_GEN.h"
#include <random>
#include <iostream>
using namespace std;
using namespace sf;
//버튼 n개 생성
Button_GEN::Button_GEN(int level_num)
{
	recall_period = 500.0f;
	Buttonnumber = level_num;
	if (Buttonnumber == 4)
	{
		Button B1(290, 285,10, 25, 0);
		Button B2(290, 285 ,315, 25, 1);
		Button B3(290, 285, 10, 320, 2);
		Button B4(290, 285, 315, 320, 3);
		buttons.push_back(B1);buttons.push_back(B2);
		buttons.push_back(B3);buttons.push_back(B4);
	}
	else if (Buttonnumber == 5)
	{
		Button B1(195, 287.5, 10, 25, 0);
		Button B2(195, 287.5, 215, 25, 1);
		Button B3(195, 287.5, 420, 25, 2);
		Button B4(195, 287.5, 107, 323, 3);
		Button B5(195, 287.5, 312, 323, 4);
		buttons.push_back(B1);buttons.push_back(B2);buttons.push_back(B3);
		buttons.push_back(B4);buttons.push_back(B5);
	}
	else if (Buttonnumber == 6)
	{
		Button B1(195, 287.5, 10, 25, 0);
		Button B2(195, 287.5, 215, 25, 1);
		Button B3(195, 287.5, 420, 25, 2);
		Button B4(195, 287.5, 10, 323, 3);
		Button B5(195, 287.5, 215, 323, 4);
		Button B6(195, 287.5, 420, 323, 5);
		buttons.push_back(B1);buttons.push_back(B2);buttons.push_back(B3);
		buttons.push_back(B4);buttons.push_back(B5);buttons.push_back(B6);
	}
	else if (Buttonnumber == 7)
	{
		Button B1(145, 287.5, 5, 25, 0);
		Button B2(145, 287.5, 160, 25, 1);
		Button B3(145, 287.5, 315, 25, 2);
		Button B4(145, 287.5, 470, 25, 3);
		Button B5(145, 287.5, 92, 323, 4);
		Button B6(145, 287.5, 247, 323, 5);
		Button B7(145, 287.5, 402, 323, 6);
		buttons.push_back(B1);buttons.push_back(B2);
		buttons.push_back(B3);buttons.push_back(B4);
		buttons.push_back(B5);buttons.push_back(B6);
		buttons.push_back(B7);
	}
	else if (Buttonnumber == 8)
	{
		Button B1(145, 287.5, 5, 25, 0);
		Button B2(145, 287.5, 160, 25, 1);
		Button B3(145, 287.5, 315, 25, 2);
		Button B4(145, 287.5, 470, 25, 3);
		Button B5(145, 287.5, 5, 323, 4);
		Button B6(145, 287.5, 160, 323, 5);
		Button B7(145, 287.5, 315, 323, 6);
		Button B8(145, 287.5, 470, 323, 7);
		buttons.push_back(B1);buttons.push_back(B2);buttons.push_back(B3);buttons.push_back(B4);
		buttons.push_back(B5);buttons.push_back(B6);buttons.push_back(B7);buttons.push_back(B8);
	}
	else if (Buttonnumber == 9)
	{
		Button B1(195, 188, 10, 25, 0);
		Button B2(195, 188, 215, 25, 1);
		Button B3(195, 188, 420, 25, 2);
		Button B4(195, 188, 10, 223, 3);
		Button B5(195, 188, 215, 223, 4);
		Button B6(195, 188, 420, 223, 5);
		Button B7(195, 188, 10, 421, 6);
		Button B8(195, 188, 215, 421, 7);
		Button B9(195, 188, 420, 421, 8);
		buttons.push_back(B1);buttons.push_back(B2);buttons.push_back(B3);
		buttons.push_back(B4);buttons.push_back(B5);buttons.push_back(B6);
		buttons.push_back(B7);buttons.push_back(B8);buttons.push_back(B9);
	}
	else if (Buttonnumber == 10)
	{
		Button B1(114, 285, 5, 25, 0);
		Button B2(114, 285, 129, 25, 1);
		Button B3(114, 285, 253, 25, 2);
		Button B4(114, 285, 377, 25, 3);
		Button B5(114, 285, 501, 25, 4);
		Button B6(114, 285, 5, 320, 5);
		Button B7(114, 285, 129, 320, 6);
		Button B8(114, 285, 253, 320, 7);
		Button B9(114, 285, 377, 320, 8);
		Button B10(114, 285, 501, 320, 9);
		buttons.push_back(B1);buttons.push_back(B2);buttons.push_back(B3);buttons.push_back(B4);
		buttons.push_back(B5);buttons.push_back(B6);buttons.push_back(B7);buttons.push_back(B8);
		buttons.push_back(B9);buttons.push_back(B10);
	}
	simonbutton.push_back(0);
}

void Button_GEN::upscore()
{
	auto _b = buttons[rand() % Buttonnumber];
	int rand_n = _b.id();

	cout << "push back new pattern : " << rand_n << endl;

	simonbutton.push_back(rand_n);

}

void Button_GEN::recall()
{
	//simonbuttons에 있는 id 값 출력 시간 간격을 두고 
	//int j = 0;

	//while (j != simonbutton.size())
	//{
	//		time = clock.getElapsedTime().asMilliseconds();
	//		auto  _e = buttons.at(simonbutton.at(j));


	//		if (time <= recall_period)
	//		{
	//			cout << "time :" << time << endl;
	//			_e.recalltoMagenta();
	//		
	//		}

	//		cout << "recall e_id : " << _e.id() << endl;
	//		_e.recalltoBlack();
	//		j++;
	//		cout << j << endl;
	//		clock.restart();
	//}
	//cout << "recall end" << endl;


}

// vector 안에 넣기 
void Button_GEN::update()
{
	for (auto& _E : buttons)
	{
			_E.update();
	}
}

void Button_GEN::draw(RenderWindow& _window)
{
	for (auto& _e : buttons)
	{
		_e.draw(_window);
	}
}

void Button_GEN::checkHit(FloatRect mouse)
{
;	for (auto& _e : buttons)
	{
		if (mouse.intersects(_e.getArea()) == true)
		{
			_e.checkit = true;
			mybutton.push_back(_e.id());
			return;
		}
	}
	return;
}


//random으로 vector 안에 넣기 checkit = true;