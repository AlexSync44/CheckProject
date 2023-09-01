#pragma once
#include <SFML/Graphics.hpp>

sf::View view; // ����� ������
void getPlayerCoordinateForView(float x, float y) // �������� ��������� ��� ������
{
	//view.setCenter(x + 100, y);
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����

	if (x > 1285) tempX = 1285; // ������
	if (x < 960) tempX = 960; // �����
	if (y < 540) tempY = 540; // �������
	if (y > 810) tempY = 810; // ������

	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 
}
