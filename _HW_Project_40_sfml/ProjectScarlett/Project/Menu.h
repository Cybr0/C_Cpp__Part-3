#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Textbox.h"
#include "Button.h"

class AuthorizationMenu
{
public:
	AuthorizationMenu(sf::Font& font) {
		texture_back_ground.loadFromFile("images/back_ground.png");//��������� ��������
		texture_cloud.loadFromFile("images/c1.png");


		sprite_back_ground.setTexture(texture_back_ground);//������� � ���� ������ Texture (��������)
		sprite_back_ground.setPosition(0, 0);//������ ��������� ���������� ��������� �������
		sprite_cloud.setTexture(texture_cloud);//������� � ���� ������ Texture (��������)


		targetSize.x = 840.0f;
		targetSize.y = 680.0f;  //(840.0f, 680.0f);
		sprite_cloud.setScale(targetSize.x / sprite_cloud.getLocalBounds().width, targetSize.y / sprite_cloud.getLocalBounds().height);
		sprite_cloud.setPosition(0, -100);//������ ��������� ���������� ��������� �������


		// ����� ����� �������� ����  ------------------------------------------------//
		menuTextbox.push_back(Textbox(15, sf::Color::White, false));
		menuTextbox[0].setFont(font);
		menuTextbox[0].setLimit(true, 10);


		menuTextbox.push_back(Textbox(15, sf::Color::White, false));
		menuTextbox[1].setFont(font);
		menuTextbox[1].setLimit(true, 10);
		
		// ������ �������� ����   ------------------------------------------------//
		for (size_t i = 0; i < 3; i++)
		{
			
			menuButton.push_back(Button("", { 200,50 }, 20, sf::Color(153, 218, 234, 30), sf::Color::Black));
		}
		


		menuButton[0].setButtonText("Login"); 
		menuButton[0].setPosition({ 220, 130 });
		menuButton[0].setFont(font);

		menuButton[1].setButtonText("Password");
		menuButton[1].setPosition({ 220, 200 });
		menuButton[1].setFont(font);

		menuButton[2].setButtonText("Sign in"); 
		menuButton[2].setPosition({ 220, 300 });
		menuButton[2].setFont(font);

	}

	void moveCloud() {

		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 5000; //�������� ����
		//std::cout << time << std::endl;

		cloud_restart += time;
		if (cloud_restart > 5000) {
			sprite_cloud.setPosition(0, -100);
			cloud_restart = 0;
		}

		sprite_cloud.move(0.1 * time, 0.0);
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(sprite_back_ground);
		window.draw(sprite_cloud);
	}

	std::vector<Textbox> & getMenuTextbox() {
		return menuTextbox;
	}
	std::vector<Button>& getMenuButton() {
		return menuButton;
	}
private:
	sf::Texture texture_back_ground, texture_cloud;//������� ������ Texture (��������)
	sf::Sprite sprite_back_ground, sprite_cloud;//������� ������ Sprite(������)
	sf::Vector2f targetSize; //������� ������

	float cloud_restart = 0;
	sf::Clock clock;

	std::vector<Textbox> menuTextbox;
	std::vector<Button> menuButton;

};

class AdministrationMenu {
public:
	AdministrationMenu(sf::Font& font) {
		btnAdmin.push_back(Button("��������� ������������ ������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("�������� �������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("������� �������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("��������� ���������� ��������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("����� �� ������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("�������� ����", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("������� ����", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("��������� ���������� ������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("������ �� ��������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnAdmin.push_back(Button("�����", { 200,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));

		float yPos = 20;
		for (auto& i : btnAdmin) {
			i.setFont(font);
			i.setPosition({ 220, yPos });
			yPos += 50;
		}
		btnAdmin[9].setPosition({ 20, 400 });
	}

	void drawTo(sf::RenderWindow& window) {
		for (size_t i = 0; i < btnAdmin.size(); i++)
		{
			btnAdmin[i].drawTo(window);
		}
		
		
	}

	std::vector<Button>& getBtnAdmin() {
		return btnAdmin;
	}
private:
	std::vector<Button> btnAdmin;
};

class CashierMenu {
public:
	CashierMenu(sf::Font& font) {
		btnCashier.push_back(Button("��������� �����", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnCashier.push_back(Button("����� �� ������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnCashier.push_back(Button("������� �������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnCashier.push_back(Button("������ �������", { 320,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));
		btnCashier.push_back(Button("�����", { 200,50 }, 20, sf::Color(255, 255, 255, 100), sf::Color::Black));

		float yPos = 20;
		for (auto& i : btnCashier) {
			i.setFont(font);
			i.setPosition({ 220, yPos });
			yPos += 50;
		}
		btnCashier[4].setPosition({ 20, 400 });
	}

	void drawTo(sf::RenderWindow& window) {
		for (size_t i = 0; i < btnCashier.size(); i++)
		{
			btnCashier[i].drawTo(window);
		}


	}

	std::vector<Button>& getBtnCashier() {
		return btnCashier;
	}
private:
	std::vector<Button> btnCashier;
};