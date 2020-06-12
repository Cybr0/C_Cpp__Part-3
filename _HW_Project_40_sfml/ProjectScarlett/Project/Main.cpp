#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "USER.h"
#include "FLIGHT.h"
#include "DATA.h"


#include "Textbox.h"
#include "Button.h"
#include "Menu.h"


//enum MenuRights
//{
//	m_main = 1,
//	m_admin,
//	m_cashier
//
//};

int main()
{
	setlocale(LC_ALL, "RUS");
	Data data;
	std::ifstream in;
	in >> data;
	accessRights access = ar_default;
	std::string login;
	


	sf::RenderWindow window(sf::VideoMode(640, 480), "AirProject 0.0.3"); //увеличили для удобства размер окна

	sf::Font font;						//-----------------------шрифт 
	if (!font.loadFromFile("font/CyrilicOld.TTF")) {
		std::cout << "error" << std::endl;
	}
	AuthorizationMenu background(font);

	/*sf::Text text("", font, 20);
	text.setFillColor(sf::Color::Red);
	text.setString("Менять собственный пароль");//задает строку тексту
	text.setPosition(280, 140); */             //задаем позицию текста, центр камеры


	sf::Text coutText("", font, 20);
	coutText.setFillColor(sf::Color::Red);
	coutText.setPosition(280, 140);

	Textbox cinText(20, sf::Color::Red, true);
	cinText.setFont(font);
	cinText.setPosition({ 400, 200 });

	AdministrationMenu administration(font);
	int administrationCase = 79;  //79 стартовое значение
	CashierMenu cashier(font);


	


	int n = 1; // переменная чтобы переключаться между Textbox--mainMenu

	// -------------------------  ИВЕНТЫ --------------------------------------
	while (window.isOpen())
	{
		
		background.moveCloud();
		sf::Event Event;
		 
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			if (access == ar_default) {
				background.getMenuTextbox()[0].setSelected(true);				//-----------------------Textbox--mainMenu
				background.getMenuTextbox()[1].setSelected(true);				//-----------------------Textbox--mainMenu
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			if (access == ar_default) {
				background.getMenuTextbox()[0].setSelected(false);				//-----------------------Textbox--mainMenu
				background.getMenuTextbox()[1].setSelected(false);				//-----------------------Textbox--mainMenu
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			if (access == ar_default) {
				if (n == 1) {
					background.getMenuTextbox()[0].setSelected(false);				//-----------------------Textbox--mainMenu
					background.getMenuTextbox()[1].setSelected(true);
					n = 2;
				}
				else if (n == 2) {
					background.getMenuTextbox()[1].setSelected(false);				//-----------------------Textbox--mainMenu
					background.getMenuTextbox()[0].setSelected(true);
					n = 1;
				}
			}
		}
		while (window.pollEvent(Event)) {
			switch (Event.type) {
			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				if (access == ar_default) {
					if (n == 1) {
						background.getMenuTextbox()[0].typedOn(Event);			//-----------------------Textbox--mainMenu
						background.getMenuButton()[0].setText("Login: " + background.getMenuTextbox()[0].getText());
					}
					if (n == 2) {
						background.getMenuTextbox()[1].typedOn(Event);			//-----------------------Textbox--mainMenu
						background.getMenuButton()[1].setText("Password: " + background.getMenuTextbox()[1].getText());
					}
				}
				else if (access == ar_admin) {
					switch (administrationCase) {
					case 0:
						cinText.typedOn(Event);
						break;
					}
				}
				break;
			case sf::Event::MouseMoved:
				if (access == ar_default) {
					if (background.getMenuButton()[2].isMouseOver(window)) {
						background.getMenuButton()[2].setBackColor(sf::Color(87, 184, 208, 30)); //-----------------------Button--mainMenu
					}
					else if (background.getMenuButton()[0].isMouseOver(window)) {
						background.getMenuButton()[0].setBackColor(sf::Color(87, 184, 208, 30)); //-----------------------Button--mainMenu
					}
					else if (background.getMenuButton()[1].isMouseOver(window)) {
						background.getMenuButton()[1].setBackColor(sf::Color(87, 184, 208, 30)); //-----------------------Button--mainMenu
					}
					else {
						background.getMenuButton()[2].setBackColor(sf::Color(153, 218, 234, 30)); //-----------------------Button--mainMenu
						background.getMenuButton()[0].setBackColor(sf::Color(153, 218, 234, 30)); //-----------------------Button--mainMenu
						background.getMenuButton()[1].setBackColor(sf::Color(153, 218, 234, 30)); //-----------------------Button--mainMenu
					}
				}
				else if (access == ar_admin) {
					switch (administrationCase)
					{
					case (79):
						for (size_t i = 0; i < administration.getBtnAdmin().size(); i++)
						{
							if (administration.getBtnAdmin()[i].isMouseOver(window)) {
								administration.getBtnAdmin()[i].setBackColor(sf::Color::Red);
							}
							else
							{
								administration.getBtnAdmin()[i].setBackColor(sf::Color(255, 255, 255, 100));
							}
						}
						break;
					default:
						break;
					}
					
					
				}
				else if (access == ar_cashier) {
					for (size_t i = 0; i < cashier.getBtnCashier().size(); i++)
					{
						if (cashier.getBtnCashier()[i].isMouseOver(window)) {
							cashier.getBtnCashier()[i].setBackColor(sf::Color::Red);
						}
						else
						{
							cashier.getBtnCashier()[i].setBackColor(sf::Color(255, 255, 255, 100));
						}
					}

				}
				break;
			case sf::Event::MouseButtonPressed: //-----------------------Button--mainMenu
				if (access == ar_default) {
					if (background.getMenuButton()[2].isMouseOver(window)) {
						for (size_t i = 0; i < data.getUser().size(); i++) {
							if (background.getMenuTextbox()[0].getText() == data.getUser()[i].getLogin() && background.getMenuTextbox()[1].getText() == data.getUser()[i].getPassword()) {
								if (data.getUser()[i].getRights() == ar_admin) {
									login = data.getUser()[i].getLogin();
									access = ar_admin; break;
								}
								else {
									access = ar_cashier; break;
								}
							}
						}
					}
					else if (background.getMenuButton()[0].isMouseOver(window)) {
						background.getMenuTextbox()[0].setSelected(true);
						background.getMenuTextbox()[1].setSelected(false);
						n = 1;
					}
					else if (background.getMenuButton()[1].isMouseOver(window)) {
						background.getMenuTextbox()[1].setSelected(true);
						background.getMenuTextbox()[0].setSelected(false);
						n = 2;
					}

				}
				else if (access == ar_admin) {
					switch (administrationCase)
					{
					case (79):
						for (size_t i = 0; i < administration.getBtnAdmin().size(); i++)
						{
							if (administration.getBtnAdmin()[i].isMouseOver(window)) {
								//administration.getBtnAdmin()[i].setBackColor(sf::Color::Red);
								administrationCase = i;
								std::cout << "BtnAdmin pressed\n";
								switch (i)
								{
								case 0://Изменение собственного Пароля
									coutText.setString("Изменение Пароля\nПотвердите старый пароль: ");
									//data.changePassword(login, cinText);
									/*window.clear();
									cinText.typedOn(Event);
									cinText.drawTo(window);*/
									break;
								case 1://Добавить Кассира
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 2://Удалить Кассира
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 3://Изменение Информации Кассиров
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 4://Поиск по Рейсам
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 5://Добавить Рейс
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 6://Удалить Рейс
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 7://Изменение Информации Рейсов
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 8://Отчёты по Продажам
									administrationCase = 79; // временно пока не готовы кнопки
									break;
								case 9://Назад
									background.getMenuTextbox()[0].setText("");
									background.getMenuTextbox()[1].setText("");
									background.getMenuButton()[0].setText("Login: " + background.getMenuTextbox()[0].getText());
									background.getMenuButton()[1].setText("Password: " + background.getMenuTextbox()[1].getText());
									access = ar_default;
									administrationCase = 79;
									std::cout << "BtnAdmin pressed -> ar_default\n";
									break;
								default:
									break;
								}
							}
						}
						break;
					default:
						break;
					}
					
				}
				else if (access == ar_cashier) {
					for (size_t i = 0; i < cashier.getBtnCashier().size(); i++)
					{
						if (cashier.getBtnCashier()[i].isMouseOver(window)) {
							//cashier.getBtnCashier()[i].setBackColor(sf::Color::Red);
							std::cout << "BtnCashier pressed\n";
							switch (i)
							{
							case 0://Доступные Рейсы
								break;
							case 1://Поиск по Рейсам
								break;
							case 2://Продажа Билетов
								break;
							case 3://Отмена Билетов
								break;
							case 4://Назад
								background.getMenuTextbox()[0].setText("");
								background.getMenuTextbox()[1].setText("");
								background.getMenuButton()[0].setText("Login: " + background.getMenuTextbox()[0].getText());
								background.getMenuButton()[1].setText("Password: " + background.getMenuTextbox()[1].getText());
								access = ar_default;
								std::cout << "BtnCashier pressed -> ar_default\n";
								break;
							default:
								break;
							}
						}
					}

				}
				break;
			}
		}
			
		//------------  ВЫВОД НА ЭКРАН -------------//
		background.drawTo(window);//выводим спрайт на экран
		switch (access)
		{
		case ar_default:
		//textboxLogin.drawTo(window); //-----------------------Textbox--mainMenu
			background.getMenuButton()[2].drawTo(window);	//-----------------------Button--mainMenu
			background.getMenuButton()[0].drawTo(window);
			background.getMenuButton()[1].drawTo(window);
			break;
		case ar_admin:
			
			switch (administrationCase)
			{
			
			case 0:
				window.draw(coutText);
				cinText.drawTo(window);
				break;
			case (79):
				for (auto& i : administration.getBtnAdmin()) {
					i.drawTo(window);
				}
				break;
			default:
				break;
			}
			
			break;
		case ar_cashier:
			for (auto& i : cashier.getBtnCashier()) {
				i.drawTo(window);
			}
			break;
		default:
			break;
		}
		
		window.display();
	}

	return 0;
}

