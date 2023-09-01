#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "View.h"

struct GamePerson
{
private:
	float x, y;
public:
	std::string nameHero;
	float widthSprite, heightSprite, dx, dy, speed = 0;
	int dir = 0, health = 0, armor = 10, damage = 25;
	bool life;
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	GamePerson(sf::String File, int X, int Y, float w, float h)
	{
		health = 150;
		life = true;
		this->File = File;
		x = X;
		y = Y;
		widthSprite = w;
		heightSprite = h;
		image.loadFromFile("images/" + this->File);
		//image.createMaskFromColor(sf::Color(41, 33, 59));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, widthSprite, heightSprite));
	}

	float getPlayerCoordinateX()
	{
		return x;
	}

	float getPlayerCoordinateY()
	{
		return y;
	}

	void movement(float& currentFrame, float time)
	{
		if (life == true)
		{
			image.loadFromFile("images/mainHero.png");
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setTextureRect(sf::IntRect(48, 0, 48, 48));
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				dir = 4;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 144, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				speed = 0;
				currentFrame += 0.008 * time;

				if (currentFrame > 7) currentFrame -= 7;
				{
					image.loadFromFile("images/animationsHero.png");
					texture.loadFromImage(image);
					sprite.setTexture(texture);
					sprite.setTextureRect(sf::IntRect(64 * int(currentFrame), 0, 64, 64));
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				speed = 0;
				currentFrame += 0.008 * time;

				if (currentFrame > 7) currentFrame -= 7;
				{
					image.loadFromFile("images/animationsHero.png");
					texture.loadFromImage(image);
					sprite.setTexture(texture);
					sprite.setTextureRect(sf::IntRect(64 * int(currentFrame), 0, -64, 64));
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				dir = 5;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 144, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				dir = 6;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 0, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				dir = 7;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 0, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				dir = 1;
				speed = 0.1255;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 48, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				dir = 0;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 96, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				dir = 2;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 0, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				dir = 3;
				speed = 0.125;
				currentFrame += 0.005 * time;
				if (currentFrame > 3) currentFrame -= 3;
				sprite.setTextureRect(sf::IntRect(48 * int(currentFrame), 144, 48, 48));
				getPlayerCoordinateForView(getPlayerCoordinateX(), getPlayerCoordinateY());
			}
		}
		else
		{
			image.loadFromFile("images/animationsHero.png");
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setTextureRect(sf::IntRect(384, 256, 64, 64));
		}
	}

	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		case 4: dx = speed; dy = -speed; break;
		case 5: dx = -speed; dy = -speed; break;
		case 6: dx = -speed; dy = speed; break;
		case 7: dx = speed; dy = speed; break;
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
		interactionWithMap();

		health > 0 ? life = true : life = false;
	}

	void interactionWithMap()
	{
		for (size_t i = y / 32; i < (y + heightSprite) / 32; i++)
		{
			for (size_t j = x / 32; j < (x + widthSprite) / 32; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if (dy > 0)
					{
						y = i * 32 - heightSprite;
					}
					if (dy < 0)
					{
						y = i * 32 + 32;
					}
					if (dx > 0)
					{
						x = j * 32 - widthSprite;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}
				}

				if (TileMap[i][j] == 'h' && health < 150)
				{
					health += 80;
					if (health > 150)
					{
						health = 150;
					}

					TileMap[i][j] = ' ';
				}

				if (TileMap[i][j] == 'd')
				{
					damage += 10;
					TileMap[i][j] = ' ';
				}

				if (TileMap[i][j] == 's')
				{
					armor += 3;
					TileMap[i][j] = ' ';
				}
			}
		}

	}
};

struct Enemy
{
private:
	float x, y;
public:
	float widthSprite, heightSprite, dx, dy, speed = 0, damTime, damX, damY;
	int dir = 0, health = 0, armor = 13, damage = 37;
	bool life;
	sf::String fileEnemy;
	sf::Image imageEnemy;
	sf::Texture textureEnemy;
	sf::Sprite spriteEnemy;

	Enemy(sf::String File, int X, int Y, float w, float h)
	{
		health = 75;
		life = true;
		this->fileEnemy = File;
		x = X;
		y = Y;
		widthSprite = w;
		heightSprite = h;
		imageEnemy.loadFromFile("images/enemy/" + this->fileEnemy);
		//image.createMaskFromColor(sf::Color(41, 33, 59));
		textureEnemy.loadFromImage(imageEnemy);
		spriteEnemy.setTexture(textureEnemy);
		spriteEnemy.setTextureRect(sf::IntRect(0, 0, widthSprite, heightSprite));
	}

	void update(float time)
	{
		damTime += time;
		spriteEnemy.setPosition(x + widthSprite / 2, y + heightSprite / 2);
		damX = x;
		damY = y;

		health > 0 ? life = true : life = false;

		if (life == false)
			spriteEnemy.setPosition(6000, 6000);
	}
};

inline void damageInMap(Enemy enemy, GamePerson person)
{
	float difX, difY;
	difX = person.dx - enemy.dx;
	difY = person.dy - enemy.dy;
	if (difX < 20 && difY < 20)
	{
		enemy.health -= person.damage - (enemy.armor / 2);
		person.health -= enemy.damage - (person.armor / 2);
	}
}