#pragma once
#include <SFML/Graphics.hpp>

sf::View view; // класс камеры
void getPlayerCoordinateForView(float x, float y) // передача координат для камеры
{
	//view.setCenter(x + 100, y);
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	if (x > 1285) tempX = 1285; // правая
	if (x < 960) tempX = 960; // левая
	if (y < 540) tempY = 540; // верхняя
	if (y > 810) tempY = 810; // нижняя

	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
}
