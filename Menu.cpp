#include"Menu.h"
Menu::Menu(float Width, float Height)
{
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	Thunder.loadFromFile("Fonts/Thunder.ttf");

	MainMenuImage.loadFromFile("Backgrounds/WorldCup.jpg");
	MenuBackgrounImage.setSize(Vector2f(820, 650));
	MenuBackgrounImage.setTexture(&MainMenuImage);
	MenuBackgrounImage.setPosition(Vector2f(125, 0));

	MenuHeading.setFont(Algerian);
	MenuHeading.setString("");
	MenuHeading.setFillColor(Color(204, 0, 153));
	MenuHeading.setCharacterSize(50);
	MenuHeading.setOutlineThickness(1);
	MenuHeading.setOutlineColor(Color(255, 255, 255));
	MenuHeading.setPosition(Vector2f(120, 10));
	BlueShade.setSize(Vector2f(1100, 650));
	BlueShade.setFillColor(Color(14, 58, 83, 500));

	MainOptionsProvided[0].setFont(MilkShake);
	MainOptionsProvided[0].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[0].setString("Login\n  ID");
	MainOptionsProvided[0].setCharacterSize(25);
	MainOptionsProvided[0].setOutlineColor(Color::Cyan);
	MainOptionsProvided[0].setOutlineThickness(3);
	MainOptionsProvided[0].setPosition(Vector2f(20, 100));

	MainOptionsProvided[1].setFont(MilkShake);
	MainOptionsProvided[1].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[1].setString("Display\n Teams");
	MainOptionsProvided[1].setCharacterSize(25);
	MainOptionsProvided[1].setOutlineColor(Color::Cyan);
	MainOptionsProvided[1].setOutlineThickness(3);
	MainOptionsProvided[1].setPosition(Vector2f(20,250));

	MainOptionsProvided[2].setFont(MilkShake);
	MainOptionsProvided[2].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[2].setString("  Recent\nMatches");
	MainOptionsProvided[2].setCharacterSize(25);
	MainOptionsProvided[2].setOutlineColor(Color::Cyan);
	MainOptionsProvided[2].setOutlineThickness(3);
	MainOptionsProvided[2].setPosition(Vector2f(20,400));


	MainOptionsProvided[3].setFont(MilkShake);
	MainOptionsProvided[3].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[3].setString("UpComing\n  Matches");
	MainOptionsProvided[3].setCharacterSize(25);
	MainOptionsProvided[3].setOutlineColor(Color::Cyan);
	MainOptionsProvided[3].setOutlineThickness(3);
	MainOptionsProvided[3].setPosition(Vector2f(970,100));

	
	
	MainOptionsProvided[4].setFont(MilkShake);
	MainOptionsProvided[4].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[4].setString("News");
	MainOptionsProvided[4].setCharacterSize(35);
	MainOptionsProvided[4].setOutlineColor(Color::Cyan);
	MainOptionsProvided[4].setOutlineThickness(3);
	MainOptionsProvided[4].setPosition(Vector2f(985, 275));

	

	MainOptionsProvided[5].setFont(MilkShake);
	MainOptionsProvided[5].setFillColor(Color(105, 105, 105));
	MainOptionsProvided[5].setString("Exit");
	MainOptionsProvided[5].setCharacterSize(40);
	MainOptionsProvided[5].setOutlineColor(Color::Cyan);
	MainOptionsProvided[5].setOutlineThickness(3);
	MainOptionsProvided[5].setPosition(Vector2f(980, 420));


	MenuOptionSelected = 0;
}
void Menu::Draw(RenderWindow& Windows)
{
	Windows.draw(BlueShade);
	Windows.draw(MenuBackgrounImage);
	for (int i = 0; i < MAxMenuOptions; i++)
	{
		Windows.draw(MainOptionsProvided[i]);
	}
}
void Menu::MoveUp()
{
	if (MenuOptionSelected - 1 >= 0)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
		MenuOptionSelected--;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color::Black);
	}
}
void Menu::MoveDown()
{
	if (MenuOptionSelected + 1 < MAxMenuOptions)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
		MenuOptionSelected++;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color::Black);
	}
}
int Menu::get_SelectedOption()
{
	return MenuOptionSelected;
}