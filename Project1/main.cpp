#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <string>
#include <iostream>
#include "Button_GEN.h"
#include "Button.h"
#include "levelgen.h"

using namespace sf;
using namespace std;
int Buttonnumber;


FloatRect getArea(CircleShape mouse)
{
	return mouse.getGlobalBounds();
}

int main()
{
	Clock clock;
	float time = 0;
	int level_period = 500.0f;

	RenderWindow window_l(VideoMode(600, 400), "level");

	level_GEN levels;

	CircleShape mouse;
	mouse = CircleShape(5.0f);

	while (window_l.isOpen())
	{
		Event event;
		while (window_l.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window_l.close();
				break;
			case Event::MouseButtonPressed:
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i pos = Mouse::getPosition(window_l);
					mouse.setPosition(pos.x, pos.y);
					Buttonnumber = levels.checkHit(getArea(mouse));
					window_l.close();
				}
			}
			default:
				break;
			}

		}
		window_l.clear(Color(0, 0, 0));
		levels.draw(window_l);
		window_l.display();
	}

	RenderWindow window(VideoMode(620, 615), "SIMON");
	window.setFramerateLimit(60);
	int flag = 1;
	Button_GEN buttons(Buttonnumber);
	int i = -1;
	int lv = 0;
	int cur_lv = 0;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i pos = Mouse::getPosition(window);
					mouse.setPosition(pos.x, pos.y);
					buttons.checkHit(getArea(mouse));
					i++;
						if (buttons.simonbutton.at(i) == buttons.mybutton.at(i))
						{
							if (buttons.mybutton == buttons.simonbutton)
							{
								cout << "good" << endl;
								buttons.upscore();
								buttons.mybutton.clear();
								
								i = -1;
							}
						}
						else
						{
							window.close();
						}
				}
		
			}
			
			default:
				break;
			}

		}
	
		window.clear(Color(0, 0, 0));
		buttons.update();
		buttons.draw(window);
		window.display();
	}


	return 0;
}