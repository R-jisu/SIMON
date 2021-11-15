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

	Font font;
	if (!font.loadFromFile("C:\\Users\\WCL\\Desktop\\project2\\arial.ttf"))
	{
		cout << "font error" << endl;
	}

	Text text;
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setPosition(0.0f, 0.0f);
	text.setCharacterSize(15);

	Text level_txt;
	level_txt.setFont(font);
	level_txt.setFillColor(Color::White);
	level_txt.setPosition(0.0f, 0.0f);
	level_txt.setCharacterSize(15);

	Text lv_text;
	lv_text.setFont(font);
	lv_text.setFillColor(Color::Black);
	lv_text.setPosition(300.0f, 0.0f);
	lv_text.setCharacterSize(15);

	Text level_4;	Text level_5;	Text level_6;	Text level_7;	Text level_8;	Text level_9;	Text level_10;

	level_4.setFont(font);level_4.setFillColor(Color::Black);level_4.setPosition(60.0f, 60.0f);level_4.setCharacterSize(70);
	level_5.setFont(font); level_5.setFillColor(Color::Black); level_5.setPosition(210.0f, 60.0f); level_5.setCharacterSize(70);
	level_6.setFont(font); level_6.setFillColor(Color::Black); level_6.setPosition(360.0f, 60.0f); level_6.setCharacterSize(70);
	level_7.setFont(font); level_7.setFillColor(Color::Black); level_7.setPosition(510.0f, 60.0f); level_7.setCharacterSize(70);
	level_8.setFont(font); level_8.setFillColor(Color::Black); level_8.setPosition(60.0f, 260.0f); level_8.setCharacterSize(70);
	level_9.setFont(font); level_9.setFillColor(Color::Black); level_9.setPosition(210.0f, 260.0f); level_9.setCharacterSize(70);
	level_10.setFont(font); level_10.setFillColor(Color::Black); level_10.setPosition(340.0f, 260.0f); level_10.setCharacterSize(70);


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

		level_txt.setString("Select button number");
		window_l.draw(level_txt);

		level_4.setString("4");window_l.draw(level_4);
		level_5.setString("5");window_l.draw(level_5);
		level_6.setString("6");window_l.draw(level_6);
		level_7.setString("7");window_l.draw(level_7);
		level_8.setString("8");window_l.draw(level_8);
		level_9.setString("9");window_l.draw(level_9);
		level_10.setString("10");window_l.draw(level_10);
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

			if (Buttonnumber == 0)
			{
				window.close();
			}

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
								lv++;
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
	
		window.clear(Color::White);
		buttons.update();
		buttons.draw(window);

		text.setString("Start When you click First Button      LV: ");
		window.draw(text);
		cur_lv = lv;
		lv_text.setString(to_string(cur_lv));
		window.draw(lv_text);

		window.display();
	}


	return 0;
}