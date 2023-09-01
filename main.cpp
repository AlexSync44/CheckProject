#include <iostream>
#include <sstream>
#include "View.h"
#include "CharacterClasses.h"

bool startGame();
void gameRunning();

int main()
{
	setlocale(LC_ALL, "rus");

	gameRunning();

    return 0;
}

void gameRunning()
{
	if (startGame())
	{
		gameRunning();
	}
}

bool startGame()
{

	sf::RenderWindow win(sf::VideoMode(1920, 1080), "Alterdude");

	view.reset(sf::FloatRect(0, 0, 1920, 1080));

	// работа с текстом
	sf::Font font;

	font.loadFromFile("20832.ttf");
	sf::Text textHealth("", font, 25);
	sf::Text textDamage("", font, 25);
	sf::Text textArmor("", font, 25);
	textHealth.setStyle(sf::Text::Bold);
	textDamage.setStyle(sf::Text::Bold);
	textArmor.setStyle(sf::Text::Bold);

	// объевление врагов
	Enemy enemy1("walk.png", 600, 800, 16.0, 16.0);
	Enemy enemy2("walk.png", 900, 1100, 16.0, 16.0);
	Enemy enemy3("walk.png", 1700, 1300, 16.0, 16.0);
	Enemy enemy4("walk.png", 1200, 500, 16.0, 16.0);
	Enemy enemy5("walk.png", 1700, 800, 16.0, 16.0);

	// текстуры карты
	sf::Image map_image;
	map_image.loadFromFile("images/map.png");

	sf::Texture map;
	map.loadFromImage(map_image);

	sf::Sprite spriteMap;
	spriteMap.setTexture(map);

	GamePerson person("mainHero.png", 150, 200, 48.0, 48.0);

	float currentFrame = 0;
	sf::Clock clock;

	while (win.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); // прошедшее время в микросекундах
		clock.restart();
		time /= 800; // скорость игры


		sf::Event ev;

		while (win.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				win.close();
			}
		}

		person.update(time);
		damageInMap(enemy1, person);
		damageInMap(enemy2, person);
		damageInMap(enemy3, person);
		damageInMap(enemy4, person);
		damageInMap(enemy5, person);
		person.movement(currentFrame, time);

		enemy1.update(time);
		enemy2.update(time);
		enemy3.update(time);
		enemy4.update(time);
		enemy5.update(time);

		win.setView(view); // установка камеры

		win.clear(sf::Color(128, 106, 89));

		// цикл для рисования карты
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  spriteMap.setTextureRect(sf::IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  spriteMap.setTextureRect(sf::IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) spriteMap.setTextureRect(sf::IntRect(64, 0, 32, 32));
				if ((TileMap[i][j] == 'd')) spriteMap.setTextureRect(sf::IntRect(96, 0, 32, 32));
				if ((TileMap[i][j] == 'h')) spriteMap.setTextureRect(sf::IntRect(128, 0, 32, 32));

				// позволяет рисовать не в 1 месте
				spriteMap.setPosition(j * 32, i * 32);

				win.draw(spriteMap);
			}
		}

		// ввод значений в строки
		std::ostringstream playerHealthStr, playerDamageStr, playerArmorStr;
		playerHealthStr << person.health;
		playerDamageStr << person.damage;
		playerArmorStr << person.armor;
		textHealth.setString("Health: " + playerHealthStr.str());
		textDamage.setString("Damage: " + playerDamageStr.str());
		textArmor.setString("Armor: " + playerArmorStr.str());
		// вывод текста на экран
		textHealth.setPosition(view.getCenter().x - 950, view.getCenter().y - 515);
		textDamage.setPosition(view.getCenter().x - 950, view.getCenter().y - 498);
		textArmor.setPosition(view.getCenter().x - 950, view.getCenter().y - 480);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { return true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return false; }

		// отписовка всего
		win.draw(enemy1.spriteEnemy);
		win.draw(enemy2.spriteEnemy);
		win.draw(enemy3.spriteEnemy);
		win.draw(enemy4.spriteEnemy);
		win.draw(enemy5.spriteEnemy);
		win.draw(textHealth);
		win.draw(textDamage);
		win.draw(textArmor);
		win.draw(person.sprite);
		win.display();
	}
}