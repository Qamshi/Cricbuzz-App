#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
using namespace sf;
const int MAxMenuOptions = 6;
class Menu  // ===========================>> Class of Menu <<===========================
{
private:        // ===========================>> Data Members <<===========================
	int MenuOptionSelected;
	Text MenuHeading;
	RectangleShape MenuBackgrounImage, MenubackgroundShade, BlueShade;
	Texture MainMenuImage;
	Text MainOptionsProvided[MAxMenuOptions];
	Texture MainMenuImage1;
	RectangleShape MenuBackgrounImage1;
	
	//------------>> Objects of Fonts......
	Font Algerian, MilkShake, Thunder;
public:
	Menu(float Width, float Height);
	void MoveUp();
	void MoveDown();
	int get_SelectedOption();
	void Draw(RenderWindow& Windows);
	~Menu() {}
};
class Player // ===========================>> Player Class An abstract class <<===========================
{
protected:
	//member variables
	string name;
	int shirt_no;
	double average;
	int icc_rank_T20;
	int icc_rank_ODI;
	int icc_rank_test;
	int total_runs;
	int match_played;
	int total_wickets;
	string bat_style; //batting style of the player
	string bowl_style; //Bowling style of the player
public:
	// ===========================>> Pure Virtual Functions <<===========================
	virtual void addPlayer() = 0;
	virtual void removePlayer() = 0;
	virtual	void searchPlayer() = 0;
	virtual void updatePlayer() = 0;
};

class Team :public Player
{
protected:
	//member variables
	string t_name;
	string t_icc_ranking;
	int no_of_Players;
	int total_matches_won;
	int total_matches_lost;
	string team_Captain;
	string team_Coach;
	string Admin_Username;
	string Admin_Password;
	string team_nickname; //nicknames of teams
	int count_player;
	Font MilkShake, Algerian;
public:
	void addPlayer() // ===========================>> Function of add a Player <<===========================
	{
		char choice;
		int i = 0;
		ofstream player_data("Players Data.txt", ios::app); //using append to right after previous text 
		ofstream rank("Ranking.txt", ios::app);

		cout << "\n\t========================>> Welcome to Add Player Section <<========================\n\n";
		do
		{
			count_player++;
			//taking data
			cout << "\n\t===> Enter Player Name: ";
			cin.ignore();
			getline(cin, name);

			cout << "\n\t===> Enter Shirt No: ";
			cin >> shirt_no;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter Shirt No: ";
				cin >> shirt_no;
			}
			cout << "\n\t===> Enter Average: ";
			cin >> average;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter Average: ";
				cin >> average;
			}
			cout << "\n\t===> Enter ICC Ranking in T20 Format: ";
			cin >> icc_rank_T20;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter ICC Ranking in T20 Format: ";
				cin >> icc_rank_T20;
			}
			cout << "\n\t===> Enter ICC Ranking in ODI Format: ";
			cin >> icc_rank_ODI;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter ICC Ranking in ODI Format: ";
				cin >> icc_rank_ODI;
			}
			cout << "\n\t===> Enter ICC Ranking in Test Match Format: ";
			cin >> icc_rank_test;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter ICC Ranking in Test Match Format: ";
				cin >> icc_rank_test;
			}
			cout << "\n\t===> Enter Total Runs: ";
			cin >> total_runs;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter Total Runs: ";
				cin >> total_runs;
			}
			cout << "\n\t===> Enter Matches Played: ";
			cin >> match_played;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter Matches Played: ";
				cin >> match_played;
			}
			cout << "\n\t===> Enter Total Wickets: ";
			cin >> total_wickets;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t===> Enter Total Wickets: ";
				cin >> total_wickets;
			}
			cout << "\n\t===> Enter Bat style: ";
			cin >> bat_style;
			cout << "\n\t===> Enter Bowl style: ";
			cin >> bowl_style;

			if (rank.is_open()) //check for file opening
			{
				rank << name << endl << icc_rank_T20 << endl << icc_rank_ODI << endl << icc_rank_test << endl;
			}
			else
			{
				cout << "Ranking File is not opened!\n";
			}

			if (player_data.is_open())  //check for file opening
			{
				//storing data on file
				player_data << name << endl << shirt_no << endl << average << endl << icc_rank_T20 << endl;
				player_data << icc_rank_ODI << endl << icc_rank_test << endl << total_runs << endl;
				player_data << match_played << endl << total_wickets << endl << bat_style << endl << bowl_style << endl;
			}
			else
			{
				cout << "Unable to create Player file\n";
			}
			cout << "\n\t ==========>> Do you want to Add more player (Y/N): "; //choice to add more player
			cin >> choice;
			system("cls");

		} while (choice == 'Y' || choice == 'y');

		//closing files
		player_data.close();
		rank.close();
	}
	void removePlayer() // ===========================>> Function of Remove player <<===========================
	{
		int i = 0;
		string temp_name, compare_name;//storing user 
		cout << "\n\n\t ========================>> Welcome to Remove Player Section <<========================\n\n";
		cout << "\n\n\t=============>> Enter Player name: ";
		cin.ignore();
		getline(cin, temp_name); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream removePlayer("Players Data.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted

		while (!removePlayer.eof()) //loop to search player by name
		{
			getline(removePlayer, compare_name); //reading from file
			if (compare_name == temp_name)
			{
				while (count_line != 11) // loop to ignore search player data
				{
					count_line++;
					getline(removePlayer, compare_name);
				}
			}
			if (!removePlayer.eof()) //check for prevent duplicate entry
			{
				temp << compare_name << endl; //Writing on file
				
			}
			
		}
		cout << "\n\t\t********** Successfully Removed! **********" << endl;
		temp.close(); //closing temporary file
		removePlayer.close(); //closing original file

		remove("Players Data.txt"); //removing original file that contain all data
		rename("text.txt", "Players Data.txt"); //renaming file 

	}
	void searchPlayer()  // ===========================>> Functiom of Search Player <<===========================
	{
		string temp_name, compare_data;//storing user 
		cout << "\n\n\t==================>> Welcome to Search Player Section <<==================\n\n";
		cout << "\n\n\t\t========>> Enter Player name: ";
		cin.ignore();
		getline(cin, temp_name); //taking player name whom data will search
		ifstream removePlayer("Players Data.txt");
		int count_line = 0; //var to count line of record to be searched
		while (!removePlayer.eof()) //loop to search player by name
		{
			getline(removePlayer, compare_data); //reading from file
			if (compare_data == temp_name)
			{
				int i = 0;
				while (count_line != 10) // loop to ignore search player data
				{
					count_line++;
					if (i == 0)
					{
						cout << "\n====>>\t Name =                           " << compare_data << endl;
					}
					i++;
					getline(removePlayer, compare_data);

					if (i == 1)
					{
						cout << "====>>\t Shirt No =                        ";
					}
					else if (i == 2)
					{
						cout << "====>>\t Average =                         ";
					}
					else if (i == 3)
					{
						cout << "====>>\t ICC Ranking in T20 Format =       ";
					}
					else if (i == 4)
					{
						cout << "====>>\t ICC Ranking in ODI Format =       ";
					}
					else if (i == 5)
					{
						cout << "====>>\t ICC Ranking in Test Format =      ";
					}
					else if (i == 6)
					{
						cout << "====>>\t Total Runs =                      ";
					}
					else if (i == 7)
					{
						cout << "====>>\t Matches Played =                  ";
					}
					else if (i == 8)
					{
						cout << "====>>\t Total Wickets =                   ";
					}
					else if (i == 9)
					{
						cout << "====>>\t Bat Style =                       ";
					}
					else if (i == 10)
					{
						cout << "====>>\t Bowl Style =                      ";
					}
					cout << compare_data << endl;
				}
			}
		}
		removePlayer.close();
	}
	void updatePlayer()// ===========================>> Function Of updating player data <<===========================
	{
		int choice = 0;
		string temp_name, compare_name;//storing user 
		cout << "\n\n==================>> Welcome to Update Player Section<< ==================\n\n";
		cout << "\n\t=========>> Enter Player name: ";
		cin.ignore();
		getline(cin, temp_name); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream updatePlayer("Players Data.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted

		while (!updatePlayer.eof()) //loop to search player by name
		{
			getline(updatePlayer, compare_name); //reading from file
			if (compare_name == temp_name)
			{
				cout << "\n\tWhich Data you want to Edit:\n\n";
				cout << "\n\t=====>> Press 1 for Player Name\n\t=====>> Press 2 for Shirt No\n\t=====>> Press 3 for Average\n\t=====>> Press 4 for ICC Ranking in T20 Format";
				cout << "\n\t=====>> Press 5 for ICC Ranking in ODI Format\n\t=====>> Press 6 for ICC Ranking in Test Match Format\n\t=====>> Press 7 for Total Runs";
				cout << "\n\t=====>> Press 8 for Matches Played\n\t=====>> Press 9 for Total Wickets\n\t=====>> Press 10 for Bat style\n\t=====>> Press 11 for Bowl style\n\n\t=====>> Choice: ";
				cin >> choice;
				cout << endl;
				switch (choice)
				{
				case 1:
					cout << "\t=====>> Enter Player Name: ";
					cin.ignore();
					getline(cin, name);
					getline(updatePlayer, compare_name);
					temp << name << endl;
					count_line++;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}

					break;
				case 2:
					cout << "\t=====>> Enter Shirt No: ";
					cin >> shirt_no;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t===> Enter Shirt No: ";
						cin >> shirt_no;
					}
					temp << compare_name << endl;
					temp << shirt_no << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 3:
					cout << "\t=====>> Enter Average: ";
					cin >> average;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t===> Enter Average: ";
						cin >> average;
					}
					for (int i = 0; i < 2; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << average << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 4:
					cout << "\t=====>> Enter ICC Ranking in T20 Format: ";
					cin >> icc_rank_T20;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t===> Enter ICC Ranking in T20 Format: ";
						cin >> icc_rank_T20;
					}
					for (int i = 0; i < 3; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << icc_rank_T20 << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 5:
					cout << "\t=====>> Enter ICC Ranking in ODI Format: ";
					cin >> icc_rank_ODI;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t===> Enter ICC Ranking in ODI Format: ";
						cin >> icc_rank_ODI;
					}
					for (int i = 0; i < 4; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << icc_rank_ODI << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 6:
					cout << "\t=====>> Enter ICC Ranking in Test Match Format: ";
					cin >> icc_rank_test;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t===> Enter ICC Ranking in Test Format: ";
						cin >> icc_rank_test;
					}
					for (int i = 0; i < 5; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << icc_rank_test;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 7:
					cout << "\t=====>> Enter Total Runs: ";
					cin >> total_runs;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\t=====>> Enter Total Runs: ";
						cin >> icc_rank_T20;
					}
					for (int i = 0; i < 6; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << total_runs << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 8:
					cout << "\t=====>> Enter Matches Played: ";
					cin >> match_played;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\t=====>> Enter Matches Played: ";
						cin >> match_played;
					}
					for (int i = 0; i < 7; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << match_played << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 9:
					cout << "\t=====>> Enter Total Wickets: ";
					cin >> total_wickets;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\t=====>> Enter Total Wickets: ";
						cin >> total_wickets;
					}
					for (int i = 0; i < 8; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << total_wickets << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 10:
					cout << "\t=====>> Enter Bat style: ";
					cin >> bat_style;
					for (int i = 0; i < 9; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << bat_style << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				case 11:
					cout << "\t=====>> Enter Bowl style: ";
					cin >> bowl_style;
					for (int i = 0; i < 10; i++) //loop to write previous data till the data whom to be update
					{
						getline(updatePlayer, compare_name);
						temp << compare_name << endl;
					}
					temp << bowl_style << endl;
					for (int i = 0; i < 2; i++) //skipping data who is updated
					{
						getline(updatePlayer, compare_name);
					}
					break;
				default:
					break;
				}
			}
			if (!updatePlayer.eof()) //check for prevent duplicate entry
			{
				temp << compare_name << endl; //Writing on file
			}
		}
		temp.close(); //closing temporary file
		updatePlayer.close(); //closing original file

		remove("Players Data.txt"); //removing original file that contain all data
		rename("text.txt", "Players Data.txt"); //renaming file

	}
	void updateCaptain() // ===========================>> Function Of updating Captain data <<===========================
	{
		string temp_name;//storing user 

		cout << "\n\t\t=======================>> Welcome to Update Captain Section << =======================";
		cout << "\n\n\t=====>> Enter Current Captain name: ";
		cin.ignore();
		getline(cin, team_Captain); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream updatecap("captains.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted
		string new_cap;

		while (!updatecap.eof())
		{
			getline(updatecap, temp_name);

			if (temp_name == team_Captain)
			{
				cout << "\n\t====>> Enter New Captain: ";
				cin.ignore();
				getline(cin, new_cap);
				getline(updatecap, temp_name);
				temp << new_cap << endl;
				count_line++;
			}
			if (!updatecap.eof())
			{
				temp << temp_name << endl;
			}
		}
		temp.close(); //closing temporary file
		updatecap.close(); //closing original file
		if (count_line == 0) //if wrong input
			cout << "\n\t===>> No Result Found!\n";

		remove("captains.txt"); //removing original file that contain all data
		rename("text.txt", "captains.txt"); //renaming file
	}
	void updateCoach()  // ===========================>> Function Of updating Coach data <<===========================
	{
		string temp_name;//storing user 

		cout << "\n\t\t =========================>> Welcome to Update Coach Section <<=========================";
		cout << "\n\t====>> Enter Current Coach name: ";
		cin.ignore();
		getline(cin, team_Coach); //taking player name whom data will delete

		ofstream temp("text.txt"); //opening file
		ifstream updatecoach("coaches.txt"); //opening file
		int count_line = 0; //var to count line of record to be deleted
		string new_coach;

		while (!updatecoach.eof())
		{
			getline(updatecoach, temp_name);

			if (temp_name == team_Coach)
			{
				cout << "\n\t====>> Enter New Coach: ";
				cin.ignore();
				getline(cin, new_coach);
				getline(updatecoach, temp_name);
				temp << new_coach << endl;
				count_line++;
			}
			if (!updatecoach.eof())
			{
				temp << temp_name << endl;
			}
		}

		temp.close(); //closing temporary file
		updatecoach.close(); //closing original file

		if (count_line == 0) //if wrong input
			cout << "\n\t ====>> No Result Found!\n";

		remove("coaches.txt"); //removing original file that contain all data
		rename("text.txt", "coaches.txt"); //renaming file
	}
	void displayTeam() // ===========================>> Function Of Displaying Teams on SFML Window <<===========================
	{
		Algerian.loadFromFile("Fonts/Algerian.ttf");
		MilkShake.loadFromFile("Fonts/Milkshake.ttf");
		string temp_name;
		cout << "\n\t\t==============================>> Welcome to Display Teams Section <<==============================";
		cout << "\n\t====>> Enter Name of the team: ";
		cin>> t_name;
		ifstream team("teams.txt");
		string TeamMembers[15], TeamName;
		while (!team.eof() )
		{
			getline(team, temp_name);
			TeamName = temp_name;
			if (t_name == temp_name)
			{
				for (int i = 0; i < 15;i++) // loop to display team data
				{
					getline(team, temp_name);
					TeamMembers[i] = temp_name;
				}
				break;
			}
		}
		team.close();

		Text TeamNameHeading;
		Texture Screen;
		RectangleShape BackgroundScreen, ScreenShade;

		TeamNameHeading.setFont(Algerian);
		TeamNameHeading.setFillColor(Color(0, 0, 0));
		TeamNameHeading.setString(TeamName);
		TeamNameHeading.setCharacterSize(60);
		TeamNameHeading.setPosition(Vector2f(700, 200));
		TeamNameHeading.setOutlineColor(Color(255, 255, 255,100));
		TeamNameHeading.setOutlineThickness(3);

		ScreenShade.setSize(Vector2f(400, 600));
		ScreenShade.setFillColor(Color(0,0,0,100));
		ScreenShade.setPosition(Vector2f(100, 25));
		ScreenShade.setOutlineColor(Color(255,255,255,100));
		ScreenShade.setOutlineThickness(4);
		
		Text Squad[15];
		Squad[0].setFont(MilkShake);
		Squad[0].setString(TeamMembers[0]);
		Squad[0].setCharacterSize(30);
		Squad[0].setFillColor(Color(255,255,255));
		Squad[0].setOutlineColor(Color::Black);
		Squad[0].setOutlineThickness(2);
		Squad[0].setPosition(Vector2f(150, 35));

		Squad[1].setFont(MilkShake);
		Squad[1].setString(TeamMembers[1]);
		Squad[1].setCharacterSize(30);
		Squad[1].setFillColor(Color(255, 255, 255));
		Squad[1].setOutlineColor(Color::Black);
		Squad[1].setOutlineThickness(2);
		Squad[1].setPosition(Vector2f(150, 75));

		Squad[2].setFont(MilkShake);
		Squad[2].setString(TeamMembers[2]);
		Squad[2].setCharacterSize(30);
		Squad[2].setFillColor(Color(255, 255, 255));
		Squad[2].setOutlineColor(Color::Black);
		Squad[2].setOutlineThickness(2);
		Squad[2].setPosition(Vector2f(150, 115));

		Squad[3].setFont(MilkShake);
		Squad[3].setString(TeamMembers[3]);
		Squad[3].setCharacterSize(30);
		Squad[3].setFillColor(Color(255, 255, 255));
		Squad[3].setOutlineColor(Color::Black);
		Squad[3].setOutlineThickness(2);
		Squad[3].setPosition(Vector2f(150, 155));

		Squad[4].setFont(MilkShake);
		Squad[4].setString(TeamMembers[4]);
		Squad[4].setCharacterSize(30);
		Squad[4].setFillColor(Color(255, 255, 255));
		Squad[4].setOutlineColor(Color::Black);
		Squad[4].setOutlineThickness(2);
		Squad[4].setPosition(Vector2f(150, 195));

		Squad[5].setFont(MilkShake);
		Squad[5].setString(TeamMembers[5]);
		Squad[5].setCharacterSize(30);
		Squad[5].setFillColor(Color(255, 255, 255));
		Squad[5].setOutlineColor(Color::Black);
		Squad[5].setOutlineThickness(2);
		Squad[5].setPosition(Vector2f(150, 235));

		Squad[6].setFont(MilkShake);
		Squad[6].setString(TeamMembers[6]);
		Squad[6].setCharacterSize(30);
		Squad[6].setFillColor(Color(255, 255, 255));
		Squad[6].setOutlineColor(Color::Black);
		Squad[6].setOutlineThickness(2);
		Squad[6].setPosition(Vector2f(150, 275));

		Squad[7].setFont(MilkShake);
		Squad[7].setString(TeamMembers[7]);
		Squad[7].setCharacterSize(30);
		Squad[7].setFillColor(Color(255, 255, 255));
		Squad[7].setOutlineColor(Color::Black);
		Squad[7].setOutlineThickness(2);
		Squad[7].setPosition(Vector2f(150, 315));

		Squad[8].setFont(MilkShake);
		Squad[8].setString(TeamMembers[8]);
		Squad[8].setCharacterSize(30);
		Squad[8].setFillColor(Color(255, 255, 255));
		Squad[8].setOutlineColor(Color::Black);
		Squad[8].setOutlineThickness(2);
		Squad[8].setPosition(Vector2f(150, 355));

		Squad[9].setFont(MilkShake);
		Squad[9].setString(TeamMembers[9]);
		Squad[9].setCharacterSize(30);
		Squad[9].setFillColor(Color(255, 255, 255));
		Squad[9].setOutlineColor(Color::Black);
		Squad[9].setOutlineThickness(2);
		Squad[9].setPosition(Vector2f(150, 395));

		Squad[10].setFont(MilkShake);
		Squad[10].setString(TeamMembers[10]);
		Squad[10].setCharacterSize(30);
		Squad[10].setFillColor(Color(255, 255, 255));
		Squad[10].setOutlineColor(Color::Black);
		Squad[10].setOutlineThickness(2);
		Squad[10].setPosition(Vector2f(150, 435));

		Squad[11].setFont(MilkShake);
		Squad[11].setString(TeamMembers[11]);
		Squad[11].setCharacterSize(30);
		Squad[11].setFillColor(Color(255, 255, 255));
		Squad[11].setOutlineColor(Color::Black);
		Squad[11].setOutlineThickness(2);
		Squad[11].setPosition(Vector2f(150, 475));

		Squad[12].setFont(MilkShake);
		Squad[12].setString(TeamMembers[12]);
		Squad[12].setCharacterSize(30);
		Squad[12].setFillColor(Color(255, 255, 255));
		Squad[12].setOutlineColor(Color::Black);
		Squad[12].setOutlineThickness(2);
		Squad[12].setPosition(Vector2f(150, 515));

		Squad[13].setFont(MilkShake);
		Squad[13].setString(TeamMembers[13]);
		Squad[13].setCharacterSize(30);
		Squad[13].setFillColor(Color(255, 255, 255));
		Squad[13].setOutlineColor(Color::Black);
		Squad[13].setOutlineThickness(2);
		Squad[13].setPosition(Vector2f(150, 555));

		Squad[14].setFont(MilkShake);
		Squad[14].setString(TeamMembers[14]);
		Squad[14].setCharacterSize(30);
		Squad[14].setFillColor(Color(255, 255, 255));
		Squad[14].setOutlineColor(Color::Black);
		Squad[14].setOutlineThickness(2);
		Squad[14].setPosition(Vector2f(150, 585));


		Screen.loadFromFile("Backgrounds/Team1.jpg");
		BackgroundScreen.setSize(Vector2f(1100, 650));
		BackgroundScreen.setTexture(&Screen);
	
		RenderWindow TeamViewer(VideoMode(1100, 650), "\t\tTeam Veiwer!");
		while (TeamViewer.isOpen())
		{
			Event evnt;
			while (TeamViewer.pollEvent(evnt))
			{
				if (evnt.type == Event::Closed() || evnt.key.code == Mouse::isButtonPressed(Mouse::Left))
				{
					TeamViewer.close();
				}
				if (evnt.type == Event::KeyPressed)
					TeamViewer.close();
			}
			TeamViewer.clear();
			TeamViewer.draw(BackgroundScreen);
			TeamViewer.draw(TeamNameHeading);
			TeamViewer.draw(ScreenShade);
			for (int i = 0; i < 15; i++)
			{
				TeamViewer.draw(Squad[i]);
			}
			TeamViewer.display();
		}
		system("cls");
	}
	
};
class Match : public Team
{
protected:
	//member variables
	string team1;
	string team2;
	string date;
	string venue;
	int sitting_capacity; //stadium capacity
	string match_type;
	string tournament_Name;
	string commentators[2];
	string Umpires[3];
	string Match_status;
	string weather;  
public:
	void conductMatch()  // ===========================>> Function Of Conducting a Match <<===========================
	{
		int ch = 0, i = 0;
		int count_line = 0;
		bool br1 = false;
		do {
			cout << "\n\t=============>> Press 1 if you want to Conduct an already Schedule Match\n\t=============>> Press 2 if you want to schedule a new match\n\t=============>> Press 3 for back to main menu\n\n\t====>>Choice: ";
			cin >> ch;
			if (ch == 1)
			{
				ifstream conduct("upcoming.txt");

				cout << "\n\t====>> Upcoming Matches <<=====";
				string extract;


				while (!conduct.eof()) // loop to ignore search player data
				{
					getline(conduct, extract);
					count_line++;
					if (i == 0)
					{
						cout << " " << extract << endl;
					}
					else if (i == 1)
					{
						cout << "\n\t====>> 2nd Team:";
					}
					else if (i == 2)
					{
						cout << "\n\t====>> Date: ";
					}
					else if (i == 3)
					{
						cout << "\n\t====>> Venue: ";
					}
					else if (i == 4)
					{
						cout << "\n\t====>> Sitting Capacity: ";
					}
					else if (i == 5)
					{
						for (int i = 0; i < 2; i++)
						{
							cout << i + 1 << " \n\t====>> Commentator: ";
							getline(conduct, extract);
							cout << extract << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							cout << "\n\t====>> Enter " << i + 1 << " Umpires: ";
							getline(conduct, extract);
							cout << extract << endl;
						}
					}
					else if (i == 5)
					{
						cout << "\n\t====>> Weather: ";
					}

					cout << extract << endl;
				}
				conduct.close(); //closing file
			}
			else if (ch == 2)
			{
				scheduleMatch(); //func call
			}
			else if (ch == 3)
			{
				br1 == true;
				break;
			}
			else
			{
				cout << "\n\t====>> Invalid Choice!\n";
			}
		} while (br1 == false);

	}
	void scheduleMatch()  // ===========================>> Function Of Schedule Match <<===========================
	{
		int ch = 0;
		bool br = false;
		cout << "\n\t\t======================>> Welcome to Schedule Match Section <<======================\n\n";
		do {
			cout << "Press 1 for Single Match\nPress 2 for Tournament\nPress 3 for Back to main\n\nChoice: ";
			cin >> ch;

			string team[9] = { "===>> Pakistan","===>> India","===>> New Zealand","===>> South Africa","===>> Bangladesh","===>> Australia","===>> West Indies","===>> England","===>> Sri-lanka" };

			if (ch == 1)
			{
				cout << "\n\t===>> Enter Match Type(ODI, T20, Test)\n\n===>> Choice: ";
				cin >> match_type;

				if (match_type == "T20" || match_type == "t20")
				{
					cout << "\n\t========>> Available Teams For T20 <<========\n\n";
					int z = 0;

					if (z == 0) //loops for random teams
					{
						for (int i = 0; i < 5; i++)
						{
							cout << team[i] << endl;
						}
						z++;
					}
					else
					{
						for (int i = 9; i > 4; i--)
						{
							cout << team[i] << endl;
						}
						z = 0;
					}
					cout << "\n\t===>> Enter 1st Team  Name from above Menu: ";
					cin.ignore();
					getline(cin, team1);

					cout << "\n\t===>> Enter 2nd Team  Name from above Menu: ";
					getline(cin, team2);

					cout << "\n\t===>> Enter Date (DD-MM-YYYY): ";
					getline(cin, date);

					cout << "\n\t===>> Enter Venue: ";
					getline(cin, venue);

					cout << "\n\t===>>Enter Sitting Capacity: ";
					cin >> sitting_capacity;
					while (cin.fail())
					{
						cout << "\n\t===>> Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Enter Sitting Capacity: ";
						cin >> sitting_capacity;
					}

					for (int i = 0; i < 2; i++)
					{
						cout << "\n\t===>> Enter " << i + 1 << " Commentator: ";
						cin.ignore();
						getline(cin, commentators[i]);
					}

					for (int i = 0; i < 3; i++)
					{
						cout << "\n\t===>> Enter " << i + 1 << " Umpires: ";
						cin.ignore();
						getline(cin, Umpires[i]);
					}

					cout << "\n\t===>> Enter Match Status (Current/Recent): ";
					getline(cin, Match_status);

					cout << "\n\t===>> Weather: ";
					cin >> weather;

					ofstream M("ODI-Matches.txt", ios::app);
					ofstream recent("Recent.txt", ios::app);
					ofstream upcome("upcoming.txt", ios::app);

					if (M.is_open())
					{
						M << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							M << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							M << Umpires[i] << endl;
						}
						M << Match_status << endl << weather << endl;
					}
					if (Match_status == "Recent" || Match_status == "recent") //check for storing data in recent or upcoming
					{
						recent << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							recent << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							recent << Umpires[i] << endl;
						}
						recent << Match_status << endl << weather << endl;
					}
					else
					{
						upcome << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							upcome << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							upcome << Umpires[i] << endl;
						}
						upcome << Match_status << endl << weather << endl;
					}
					//closing files
					M.close();
					recent.close();
					upcome.close();
				}
				else if (match_type == "ODI")
				{
					cout << "\n\t============>> Available Teams For ODI <<============\n\n";
					int z = 0;

					if (z == 0) //loops for random teams
					{
						for (int i = 0; i < 5; i++)
						{
							cout << team[i] << endl;
						}
						z++;
					}
					else
					{
						for (int i = 9; i > 4; i--)
						{
							cout << team[i] << endl;
						}
						z = 0;
					}
					cout << "\n\t====>> Enter 1st Team  Name from above Menu: ";
					cin.ignore();
					getline(cin, team1);

					cout << "\n\t====>> Enter 2nd Team  Name from above Menu: ";
					getline(cin, team2);

					cout << "\n\t====>> Enter Date (DD-MM-YYYY): ";
					getline(cin, date);

					cout << "\n\t====>> Enter Venue: ";
					getline(cin, venue);

					cout << "\n\t====>> Enter Sitting Capacity: ";
					cin >> sitting_capacity;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t====>> Enter Sitting Capacity: ";
						cin >> sitting_capacity;
					}

					for (int i = 0; i < 2; i++)
					{
						cout << "\n\t====>> Enter " << i + 1 << " Commentator: ";
						cin.ignore();
						getline(cin, commentators[i]);
					}

					for (int i = 0; i < 3; i++)
					{
						cout << "\n\t====>> Enter " << i + 1 << " Umpires: ";
						cin.ignore();
						getline(cin, Umpires[i]);
					}

					cout << "\n\t====>> Enter Match Status (Current/Recent): ";
					getline(cin, Match_status);

					cout << "\n\t====>> Weather: ";
					cin >> weather;

					ofstream M("ODI-Matches.txt", ios::app);
					ofstream recent("Recent.txt", ios::app);
					ofstream upcome("upcoming.txt", ios::app);

					if (M.is_open())
					{
						M << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							M << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							M << Umpires[i] << endl;
						}
						M << Match_status << endl << weather << endl;
					}
					if (Match_status == "Recent" || Match_status == "recent") //check for storing data in recent or upcoming
					{
						recent << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							recent << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							recent << Umpires[i] << endl;
						}
						recent << Match_status << endl << weather << endl;
					}
					else
					{
						upcome << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							upcome << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							upcome << Umpires[i] << endl;
						}
						upcome << Match_status << endl << weather << endl;
					}
					//closing files
					M.close();
					recent.close();
					upcome.close();
				}
				else if (match_type == "Test")
				{
					cout << "\n\t---Available Teams For Test---\n\n";
					int z = 0;

					if (z == 0) //loops for random teams
					{
						for (int i = 0; i < 5; i++)
						{
							i * 2;
							cout << team[i] << endl;
						}
						z++;
					}
					else
					{
						for (int i = 9; i > 4; i--)
						{
							cout << team[i] << endl;
						}
						z = 0;
					}
					cout << "\n\t====>> Enter 1st Team  Name from above Menu: ";
					cin.ignore();
					getline(cin, team1);

					cout << "\n\t====>> Enter 2nd Team  Name from above Menu: ";
					getline(cin, team2);

					cout << "\n\t====>> Enter Date (DD-MM-YYYY): ";
					getline(cin, date);

					cout << "\n\t====>> Enter Venue: ";
					getline(cin, venue);

					cout << "\n\t====>> Enter Sitting Capacity: ";
					cin >> sitting_capacity;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t====>> Enter Sitting Capacity: ";
						cin >> sitting_capacity;
					}

					for (int i = 0; i < 2; i++)  //loop to take both commentators in file
					{
						cout << "\n\t====>> Enter " << i + 1 << " Commentator: ";
						cin.get();
						getline(cin, commentators[i]);
					}

					for (int i = 0; i < 3; i++) //loop to take all 3 umpires in file
					{
						cout << "\n\t====>> Enter " << i + 1 << " Umpires: ";
						cin.get();
						getline(cin, Umpires[i]);
					}

					cout << "\n\t====>> Enter Match Status (Current/Recent): ";
					getline(cin, Match_status);

					cout << "\n\t====>> Weather: ";
					cin >> weather;

					ofstream M("Test-Matches.txt", ios::app);
					ofstream recent("Recent.txt", ios::app);
					ofstream upcome("upcoming.txt", ios::app);

					if (M.is_open())
					{
						M << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++) //loop to add both commentators in file
						{
							M << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++) //loop to add all 3 umpires in file
						{
							M << Umpires[i] << endl;
						}
						M << Match_status << endl << weather << endl;
					}
					if (Match_status == "Recent" || Match_status == "recent") //check for storing data in recent or upcoming
					{
						recent << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							recent << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							recent << Umpires[i] << endl;
						}
						recent << Match_status << endl << weather << endl;
					}
					else
					{
						upcome << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++)
						{
							upcome << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++)
						{
							upcome << Umpires[i] << endl;
						}
						upcome << Match_status << endl << weather << endl;
					}
					//closing files
					M.close();
					recent.close();
					upcome.close();
				}
			}
			else if (ch == 2)
			{
				int opt = 0;
				cout << "Press 1 for PSL\nPress 2 for IPL\n\nChoice: ";
				cin >> opt;

				if (ch == 1)
				{
					tournament_Name = "PSL";
					string psl[6] = { "Lahore Qalandar","Karachi Kings","Quetta Qladiator","Multan Sultan","Peshawer Zalmi","Islamabad United" };

					cout << "\n\t====>> Team for PSL <<====";
					for (int i = 0; i < 6; i++)
					{
						cout << i + 1 << "====>> " << psl[i] << endl;
					}

					cout << "\n\t====>> Enter 1st Team  Name from above Menu: ";
					cin.ignore();
					getline(cin, team1);

					cout << "\n\t====>> Enter 2nd Team  Name from above Menu: ";
					getline(cin, team2);

					cout << "\n\t====>> Enter Date (DD-MM-YYYY): ";
					getline(cin, date);

					cout << "\n\t====>> Enter Venue: ";
					getline(cin, venue);

					cout << "\n\t====>> Enter Sitting Capacity: ";
					cin >> sitting_capacity;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t====>> Enter Sitting Capacity: ";
						cin >> sitting_capacity;
					}

					for (int i = 0; i < 2; i++)  //loop to take both commentators in file
					{
						cout << "\n\t====>> Enter " << i + 1 << " Commentator: ";
						cin.get();
						getline(cin, commentators[i]);
					}

					for (int i = 0; i < 3; i++) //loop to take all 3 umpires in file
					{
						cout << "\n\t====>> Enter " << i + 1 << " Umpires: ";
						cin.get();
						getline(cin, Umpires[i]);
					}
					cout << "\n\t====>> Weather: ";
					cin >> weather;

					ofstream P("PSL.txt", ios::app);
					ofstream upcome("upcoming.txt", ios::app);

					if (P.is_open()) //writing in psl file
					{
						P << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++) //loop to add both commentators in file
						{
							P << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++) //loop to add all 3 umpires in file
						{
							P << Umpires[i] << endl;
						}
						P << Match_status << endl << weather << endl;
					}
					//writing in upcoming file as well
					upcome << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
					for (int i = 0; i < 2; i++)
					{
						upcome << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						upcome << Umpires[i] << endl;
					}
					upcome << Match_status << endl << weather << endl;

					upcome.close();
					P.close();

				}
				else if (opt == 2)
				{
					tournament_Name = "IPL";
					string ipl[6] = { "Royal Challenger Banglore","Chennai Super Kings","Mumbai Indians","Sunrise Hyderabad","Kings XI Punjab","Delhi Daredevils" };

					cout << "\n\t====>> Team for PSL\n\t <<====";
					for (int i = 0; i < 6; i++)
					{
						cout << i + 1 << "====>> " << ipl[i] << endl;
					}

					cout << "\n\t====>> Enter 1st Team  Name from above Menu: ";
					cin.ignore();
					getline(cin, team1);

					cout << "\n\t====>> Enter 2nd Team  Name from above Menu: ";
					getline(cin, team2);

					cout << "\n\t====>> Enter Date (DD-MM-YYYY): ";
					getline(cin, date);

					cout << "\n\t====>> Enter Venue: ";
					getline(cin, venue);

					cout << "\n\t====>> Enter Sitting Capacity: ";
					cin >> sitting_capacity;
					while (cin.fail())
					{
						cout << "Invalid!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t====>> Enter Sitting Capacity: ";
						cin >> sitting_capacity;
					}

					for (int i = 0; i < 2; i++)  //loop to take both commentators in file
					{
						cout << "\n\t====>> Enter " << i + 1 << " Commentator: ";
						cin.get();
						getline(cin, commentators[i]);
					}

					for (int i = 0; i < 3; i++) //loop to take all 3 umpires in file
					{
						cout << "\n\t====>> Enter " << i + 1 << " Umpires: ";
						cin.get();
						getline(cin, Umpires[i]);
					}
					cout << "\n\t====>> Weather: ";
					cin >> weather;

					ofstream P("IPL.txt", ios::app);
					ofstream upcome("upcoming.txt", ios::app);

					if (P.is_open()) //writing in ipl file
					{
						P << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
						for (int i = 0; i < 2; i++) //loop to add both commentators in file
						{
							P << commentators[i] << endl;
						}
						for (int i = 0; i < 3; i++) //loop to add all 3 umpires in file
						{
							P << Umpires[i] << endl;
						}
						P << weather << endl;
					}
					//writing in upcoming file as well
					upcome << team1 << endl << team2 << endl << date << endl << venue << endl << sitting_capacity << endl;
					for (int i = 0; i < 2; i++)
					{
						upcome << commentators[i] << endl;
					}
					for (int i = 0; i < 3; i++)
					{
						upcome << Umpires[i] << endl;
					}
					upcome << weather << endl;

					upcome.close();
					P.close();

				}
				else
				{
					cout << "Invalid choice!\n";
				}
			}
			else if (ch == 3)
			{
				br = true;
			}
			else
			{
				cout << "Invalid Choice!\n";
			}
		}while (br == false);
	}
	void updateWorldRecords()   // ===========================>> Function of Update World Records <<===========================
	{
		int choice = 0;
		string temp_name, search_name;
		string player;
		bool br2 = false;
		char ch;

		cout << "\n\t\t=================>> Welcome to Update World Records Section <<=================";
		do {
			cout << "\n\n\t====>> Press 1 Most runs\n\t====>> Press 2 Highest score\n\t====>> Press 3 Most sixes\n\t====>> Press 4 Most fours\n\t====>> Press 5 Most centuries\n\t====>> Press 6 Highest batting average\n\t====>> Press 7 Best batting strike rate\n\t====>> Press 8 Most wickets\n\t====>> Press 9 Best bowling avg\n\t====>> Press 10 Best bowling avg\n\t====>> Press 11 for Back to main menu\n\t====>>Choice: ";
			cin >> choice;
			if (choice == 11) //check for exit
			{
				break;
			}

			ifstream team("WC-Record.txt"); //openning file
			ofstream temp("text.txt"); //openning file

			if (!team.is_open()) //if not opened
			{
				cout << "\n\t====>> Team Ranking File is not opened\n";
			}
			else
			{
				while (!team.eof())
				{
					switch (choice)
					{
					case 1:
						search_name = "Most runs";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 2:
						search_name = "Highest score";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 3:
						search_name = "Most sixes";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 4:
						search_name = "Most fours";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 5:
						search_name = "Most centuries";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 6:
						search_name = "Highest batting average";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 7:
						search_name = "Best batting strike rate";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 8:
						search_name = "Most wickets";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 9:
						search_name = "Best bowling avg";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;
					case 10:
						search_name = "Best bowling";

						if (temp_name == search_name)
						{
							cout << "\n\t====>> Previous " << temp_name << " : ";
							getline(team, temp_name);
							cout << temp_name << endl;
							cout << "\n\t====>> Update Record: ";
							cin.ignore();
							getline(cin, player);
							temp << player << endl;
						}
						break;

					default:
						cout << "\n\t====>> Invalid Choice!\n";
						break;
					}
					getline(team, temp_name);
					temp << temp_name << endl;
				}

				temp.close(); //closing temporary file
				team.close(); //closing original file

				remove("WC-Record.txt"); //removing original file that contain all data
				rename("text.txt", "WC-Record.txt"); //renaming file

				cout << "\n\t====>> Are you want to Update more records(Y/N): ";
				cin >> ch;

			}
		} while (ch == 'Y' || ch == 'y');
	}
	void updateTeamRanking()   // ===========================>> Function Of updating team Ranking data <<===========================
	{
		string temp_name, search_name;
		int choice = 0, R = 0;  //R=0 for storing new ranking
		cout << "\n\t\================================>> Welcome to Update Team Ranking Section <<================================\n\n";
		cout << "\n\t======>> Enter Team Name: ";
		cin.ignore();
		getline(cin, search_name);

		int count_line = 0;

		ifstream team("Team Ranking.txt"); //openning file
		ofstream temp("text.txt"); //openning file

		if (!team.is_open())
		{
			cout << "\n\t======>> Team Ranking File is not opened\n";
		}
		else
		{
			while (!team.eof())
			{
				getline(team, temp_name);

				if (temp_name == search_name)
				{
					temp << temp_name << endl;
					cout << "\n\n\t======>> Press 1 to update T20 Ranking\n\t======>> Press 2 to update ODI Ranking\n\t======>> Press 3 to update Test Ranking\n\t======>> Choice: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						getline(team, temp_name);
						cout << "\n\t======>> Previous T20 Ranking: " << temp_name << endl; //displaying previous ranking
						cout << "\n\t======>> Enter New Ranking: ";
						cin >> R; //taking ranking
						temp << R << endl;
						break;
					case 2:
						for (int i = 0; i < 2; i++) //loop to write data before updated one
						{
							getline(team, temp_name);
							if (i < 1)  //check for write data before updated one
							{
								temp << temp_name << endl;
							}
						}
						cout << "\n\t======>> Previous ODI Ranking: " << temp_name << endl; //displaying previous ranking
						cout << "\n\t======>> Enter New Ranking: ";
						cin >> R; //taking ranking
						temp << R << endl;
						break;
					case 3:
						for (int i = 0; i < 3; i++) //loop to write data before updated one
						{
							getline(team, temp_name);
							if (i < 2)  //check for write data before updated one
							{
								temp << temp_name << endl;
							}
						}
						cout << "\n\t======>> Previous Test Ranking: " << temp_name << endl; //displaying previous ranking
						cout << "\n\t======>> Enter New Ranking: ";
						cin >> R; //taking ranking
						temp << R << endl;
						break;
					default:
						cout << "\n\t======>> Invalid choice!\n";
						break;
					}
					getline(team, temp_name); //updated key!
					count_line++;
				}

				temp << temp_name << endl;
			}

			temp.close(); //closing temporary file
			team.close(); //closing original file

			if (count_line == 0) //if wrong input
				cout << "\n\t======>> No Result Found!\n";

			remove("Team Ranking.txt"); //removing original file that contain all data
			rename("text.txt", "Team Ranking.txt"); //renaming file
		}
	}
	void updatePlayerRanking()   // ===========================>> Function Of updating player Ranking <<===========================  
	{
		string search_name, temp_name;
		cout << "\n\t\t========================>> Welcome to Update Player Ranking Section <<========================";
		cout << "\n\t====>> Enter Player name: ";
		cin.ignore();
		getline(cin, search_name);

		ifstream rank("Ranking.txt"); //opening file
		ofstream temp("text.txt"); //opening temporary file

		int R = 0;
		int count_line = 0; //var to count line of record to be deleted
		int choice = 0;
		while (!rank.eof())
		{
			getline(rank, temp_name);

			if (temp_name == search_name)
			{
				temp << temp_name << endl;
				cout << "\n\n ====>> Press 1 to update T20 Ranking\n====>> Press 2 to update ODI Ranking\n====>> Press 3 to update Test Ranking\n===>> Choice: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					getline(rank, temp_name);
					cout << "\n\t====>> Previous T20 Ranking: " << temp_name << endl; //displaying previous ranking
					cout << "\n\t====>> Enter New Ranking: ";
					cin >> R; //taking ranking
					temp << R << endl;
					break;
				case 2:
					for (int i = 0; i < 2; i++) //loop to write data before updated one
					{
						getline(rank, temp_name);
						if (i < 1)  //check for write data before updated one
						{
							temp << temp_name << endl;
						}
					}
					cout << "\n\t====>> Previous ODI Ranking: " << temp_name << endl; //displaying previous ranking
					cout << "\n\t====>> Enter New Ranking: ";
					cin >> R; //taking ranking
					temp << R << endl;
					break;
				case 3:
					for (int i = 0; i < 3; i++) //loop to write data before updated one
					{
						getline(rank, temp_name);
						if (i < 2)  //check for write data before updated one
						{
							temp << temp_name << endl;
						}
					}
					cout << "\n\t====>> Previous Test Ranking: " << temp_name << endl; //displaying previous ranking
					cout << "\n\t====>> Enter New Ranking: ";
					cin >> R; //taking ranking
					temp << R << endl;
					break;
				default:
					cout << "\n\t====>> Invalid choice!\n";
					break;
				}
				getline(rank, temp_name); //updated key!
				count_line++;
			}

			temp << temp_name << endl;
		}

		temp.close(); //closing temporary file
		rank.close(); //closing original file

		if (count_line == 0) //if wrong input
			cout << "\n\t====>> No Result Found!\n";

		remove("Ranking.txt"); //removing original file that contain all data
		rename("text.txt", "Ranking.txt"); //renaming file
	}
	void displayUpcomingMatches()    // ===========================>> Function Of Displaying Upcoming Matches on SFML window <<===========================
	{
		ifstream recent("Upcoming.txt");
		const int NumberofMatches = 2, InfoProvided = 13;
		string RecentmatchInfo[NumberofMatches][InfoProvided];
		string extract;
		for (int i = 0; i < NumberofMatches; i++)
		{
			for (int j = 0; j < InfoProvided; j++)
			{
				getline(recent, extract);
				RecentmatchInfo[i][j] = extract;
			}
		}
		recent.close(); //closing file
		Algerian.loadFromFile("Fonts/Algerian.ttf");
		MilkShake.loadFromFile("Fonts/Milkshake.ttf");

		Text Match1, Match2;
		Texture Screen;
		RectangleShape BackgroundScreen, Match_1Shade, Match_2Shade;

		Match1.setFont(Algerian);
		Match1.setFillColor(Color(0, 0, 0));
		Match1.setString("Match 1");
		Match1.setCharacterSize(50);
		Match1.setPosition(Vector2f(150, 20));
		Match1.setOutlineColor(Color(255, 255, 255, 100));
		Match1.setOutlineThickness(3);


		Match2.setFont(Algerian);
		Match2.setFillColor(Color(255, 255, 255));
		Match2.setString("Match 2");
		Match2.setCharacterSize(50);
		Match2.setPosition(Vector2f(750, 20));
		Match2.setOutlineColor(Color(255, 255, 255, 100));
		Match2.setOutlineThickness(3);

		Match_1Shade.setSize(Vector2f(400, 600));
		Match_1Shade.setFillColor(Color(0, 0, 0, 100));
		Match_1Shade.setPosition(Vector2f(70, 25));
		Match_1Shade.setOutlineColor(Color(255, 255, 255, 100));
		Match_1Shade.setOutlineThickness(4);


		Match_2Shade.setSize(Vector2f(400, 600));
		Match_2Shade.setFillColor(Color(0, 0, 0, 100));
		Match_2Shade.setPosition(Vector2f(630, 25));
		Match_2Shade.setOutlineColor(Color(255, 255, 255, 100));
		Match_2Shade.setOutlineThickness(4);

		Text MatchHistory[NumberofMatches][InfoProvided];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				MatchHistory[i][j].setFont(MilkShake);
				MatchHistory[i][j].setString(RecentmatchInfo[i][j]);
				MatchHistory[i][j].setCharacterSize(30);
				MatchHistory[i][j].setFillColor(Color(255, 255, 255));
				MatchHistory[i][j].setOutlineColor(Color::Black);
				MatchHistory[i][j].setOutlineThickness(2);
			}
		}

		MatchHistory[0][0].setPosition(Vector2f(100, 85));

		MatchHistory[0][1].setPosition(Vector2f(100, 125));

		MatchHistory[0][2].setPosition(Vector2f(100, 165));

		MatchHistory[0][3].setPosition(Vector2f(100, 205));

		MatchHistory[0][4].setPosition(Vector2f(100, 245));

		MatchHistory[0][5].setPosition(Vector2f(100, 285));

		MatchHistory[0][6].setPosition(Vector2f(100, 325));

		MatchHistory[0][7].setPosition(Vector2f(100, 365));

		MatchHistory[0][8].setPosition(Vector2f(100, 405));

		MatchHistory[0][9].setPosition(Vector2f(100, 445));

		MatchHistory[0][10].setPosition(Vector2f(100, 485));

		MatchHistory[0][11].setPosition(Vector2f(100, 525));

		MatchHistory[0][12].setPosition(Vector2f(100, 565));

		MatchHistory[1][0].setPosition(Vector2f(660, 85));

		MatchHistory[1][1].setPosition(Vector2f(660, 125));

		MatchHistory[1][2].setPosition(Vector2f(660, 165));

		MatchHistory[1][3].setPosition(Vector2f(660, 205));

		MatchHistory[1][4].setPosition(Vector2f(660, 245));

		MatchHistory[1][5].setPosition(Vector2f(660, 285));

		MatchHistory[1][6].setPosition(Vector2f(660, 325));

		MatchHistory[1][7].setPosition(Vector2f(660, 365));

		MatchHistory[1][8].setPosition(Vector2f(660, 405));

		MatchHistory[1][9].setPosition(Vector2f(660, 445));

		MatchHistory[1][10].setPosition(Vector2f(660, 485));

		MatchHistory[1][11].setPosition(Vector2f(660, 525));

		MatchHistory[1][12].setPosition(Vector2f(660, 565));

		Screen.loadFromFile("Backgrounds/Bowl.jpg");
		BackgroundScreen.setSize(Vector2f(1100, 650));
		BackgroundScreen.setTexture(&Screen);

		RenderWindow TeamViewer(VideoMode(1100, 650), "\t\tTeam Veiwer!");
		while (TeamViewer.isOpen())
		{
			Event evnt;
			while (TeamViewer.pollEvent(evnt))
			{
				if (evnt.type == Event::Closed() || evnt.key.code == Mouse::isButtonPressed(Mouse::Left))
				{
					TeamViewer.close();

				}
				if (evnt.type == Event::KeyPressed)
					TeamViewer.close();
			}
			TeamViewer.clear();
			TeamViewer.draw(BackgroundScreen);
			TeamViewer.draw(Match_1Shade);
			TeamViewer.draw(Match_2Shade);
			TeamViewer.draw(Match1);
			TeamViewer.draw(Match2);

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					TeamViewer.draw(MatchHistory[i][j]);
				}
			}
			TeamViewer.display();
		}

	}
	void displayRecentMatches() // ===========================>> Function Of Displaying Upcoming Matches on SFML window <<===========================
	{
		ifstream recent("Recent.txt");
		const int NumberofMatches = 2, InfoProvided = 13;
		string RecentmatchInfo[NumberofMatches][InfoProvided];
		string extract;
		for (int i = 0; i < NumberofMatches; i++)
		{
			for (int j = 0; j < InfoProvided; j++)
			{
				getline(recent, extract);
				RecentmatchInfo[i][j] = extract;
			}
		}
		recent.close(); //closing file
		Algerian.loadFromFile("Fonts/Algerian.ttf");
		MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	
		Text Match1,Match2;
		Texture Screen;
		RectangleShape BackgroundScreen, Match_1Shade, Match_2Shade;

		Match1.setFont(Algerian);
		Match1.setFillColor(Color(0, 0, 0));
		Match1.setString("Match 1");
		Match1.setCharacterSize(50);
		Match1.setPosition(Vector2f(150, 20));
		Match1.setOutlineColor(Color(255, 255, 255, 100));
		Match1.setOutlineThickness(3);


		Match2.setFont(Algerian);
		Match2.setFillColor(Color(255,255,255));
		Match2.setString("Match 2");
		Match2.setCharacterSize(50);
		Match2.setPosition(Vector2f(750, 20));
		Match2.setOutlineColor(Color(255, 255, 255, 100));
		Match2.setOutlineThickness(3);

		Match_1Shade.setSize(Vector2f(400, 600));
		Match_1Shade.setFillColor(Color(0, 0, 0, 100));
		Match_1Shade.setPosition(Vector2f(70, 25));
		Match_1Shade.setOutlineColor(Color(255, 255, 255, 100));
		Match_1Shade.setOutlineThickness(4);


		Match_2Shade.setSize(Vector2f(400, 600));
		Match_2Shade.setFillColor(Color(0, 0, 0, 100));
		Match_2Shade.setPosition(Vector2f(630, 25));
		Match_2Shade.setOutlineColor(Color(255, 255, 255, 100));
		Match_2Shade.setOutlineThickness(4);

		Text MatchHistory[NumberofMatches][InfoProvided];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				MatchHistory[i][j].setFont(MilkShake);
				MatchHistory[i][j].setString(RecentmatchInfo[i][j]);
				MatchHistory[i][j].setCharacterSize(30);
				MatchHistory[i][j].setFillColor(Color(255, 255, 255));
				MatchHistory[i][j].setOutlineColor(Color::Black);
				MatchHistory[i][j].setOutlineThickness(2);
			}
		}
		
		MatchHistory[0][0].setPosition(Vector2f(100, 85));

		MatchHistory[0][1].setPosition(Vector2f(100, 125));

		MatchHistory[0][2].setPosition(Vector2f(100, 165));

		MatchHistory[0][3].setPosition(Vector2f(100, 205));

		MatchHistory[0][4].setPosition(Vector2f(100, 245));

		MatchHistory[0][5].setPosition(Vector2f(100, 285));

		MatchHistory[0][6].setPosition(Vector2f(100, 325));

		MatchHistory[0][7].setPosition(Vector2f(100, 365));

		MatchHistory[0][8].setPosition(Vector2f(100, 405));

		MatchHistory[0][9].setPosition(Vector2f(100, 445));

		MatchHistory[0][10].setPosition(Vector2f(100, 485));

		MatchHistory[0][11].setPosition(Vector2f(100, 525));

		MatchHistory[0][12].setPosition(Vector2f(100, 565));

		MatchHistory[1][0].setPosition(Vector2f(660, 85));

		MatchHistory[1][1].setPosition(Vector2f(660, 125));

		MatchHistory[1][2].setPosition(Vector2f(660, 165));

		MatchHistory[1][3].setPosition(Vector2f(660, 205));

		MatchHistory[1][4].setPosition(Vector2f(660, 245));

		MatchHistory[1][5].setPosition(Vector2f(660, 285));

		MatchHistory[1][6].setPosition(Vector2f(660, 325));

		MatchHistory[1][7].setPosition(Vector2f(660, 365));

		MatchHistory[1][8].setPosition(Vector2f(660, 405));

		MatchHistory[1][9].setPosition(Vector2f(660, 445));

		MatchHistory[1][10].setPosition(Vector2f(660, 485));

		MatchHistory[1][11].setPosition(Vector2f(660, 525));

		MatchHistory[1][12].setPosition(Vector2f(660, 565));
		
		Screen.loadFromFile("Backgrounds/Team1.jpg");
		BackgroundScreen.setSize(Vector2f(1100, 650));
		BackgroundScreen.setTexture(&Screen);

		RenderWindow TeamViewer(VideoMode(1100, 650), "\t\tTeam Veiwer!");
		while (TeamViewer.isOpen())
		{
			Event evnt;
			while (TeamViewer.pollEvent(evnt))
			{
				if (evnt.type == Event::Closed() || evnt.key.code == Mouse::isButtonPressed(Mouse::Left))
				{
					TeamViewer.close();
				}
				if (evnt.type == Event::KeyPressed)
					TeamViewer.close();
			}
			TeamViewer.clear();
			TeamViewer.draw(BackgroundScreen);
			TeamViewer.draw(Match_1Shade);
			TeamViewer.draw(Match_2Shade);
			TeamViewer.draw(Match1);
			TeamViewer.draw(Match2);
			
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					TeamViewer.draw(MatchHistory[i][j]);
				}
			}
			TeamViewer.display();
		}

	}
	void News() // ===========================>> Function Of Displaying News on SFML window <<===========================
	{
		Algerian.loadFromFile("Fonts/Algerian.ttf");
		MilkShake.loadFromFile("Fonts/Milkshake.ttf");

		Text Newstext, Newstext1, NewsHeading;
		Texture News, News1, News2;
		RectangleShape NewsImage, New, Newbackground, Newbackground1;

		

		News.loadFromFile("Backgrounds/News.jpg");
		NewsImage.setSize(Vector2f(1000, 650));
		NewsImage.setTexture(&News);

		New.setSize(Vector2f(400, 600));
		New.setFillColor(Color(0, 0, 0, 100));
		New.setPosition(Vector2f(70, 25));
		New.setOutlineColor(Color(255, 255, 255, 100));
		New.setOutlineThickness(4);

		News1.loadFromFile("Backgrounds/Billings.png");
		Newbackground.setSize(Vector2f(300, 200));
		Newbackground.setTexture(&News1);
		Newbackground.setFillColor(Color(255, 255, 255));
		Newbackground.setPosition(Vector2f(120, 30));

		Newstext.setFont(Algerian);
		Newstext.setFillColor(Color(255, 255, 255));
		Newstext.setString("England's Sam Billings is bowled by Sri Lanka's \nNiroshan Dickwella during the second T20\ninternational cricket match between England\nand Sri Lanka in Cardiff, Wales ");
		Newstext.setCharacterSize(15);
		Newstext.setPosition(Vector2f(75, 235));
		Newstext.setOutlineColor(Color(0, 0, 0));
		Newstext.setOutlineThickness(3);

		NewsHeading.setFont(Algerian);
		NewsHeading.setFillColor(Color(255, 255, 255));
		NewsHeading.setString("LATEST NEWS");
		NewsHeading.setCharacterSize(50);
		NewsHeading.setPosition(Vector2f(600, 30));
		NewsHeading.setOutlineColor(Color(255, 255, 255, 100));
		NewsHeading.setOutlineThickness(3);

		News2.loadFromFile("Backgrounds/multan.png");
		Newbackground1.setSize(Vector2f(300, 200));
		Newbackground1.setTexture(&News2);
		Newbackground1.setPosition(Vector2f(120, 350));

		Newstext1.setFont(Algerian);
		Newstext1.setFillColor(Color(255, 255, 255));
		Newstext1.setString("Multan Sultans won their maiden title \non first attempt.");
		Newstext1.setCharacterSize(15);
		Newstext1.setPosition(Vector2f(75, 570));
		Newstext1.setOutlineColor(Color(0, 0, 0));
		Newstext1.setOutlineThickness(3);

	
		RenderWindow NewsWindow(VideoMode(1000, 650), "\t\tNews!");
		while (NewsWindow.isOpen())
		{
			Event evnt;
			while (NewsWindow.pollEvent(evnt))
			{
				if (evnt.type == Event::Closed() || evnt.key.code == Mouse::isButtonPressed(Mouse::Left))
				{
					NewsWindow.close();

				}
				if (evnt.type == Event::KeyPressed)
					NewsWindow.close();
			}
			NewsWindow.clear();
			NewsWindow.draw(NewsImage);
			NewsWindow.draw(New);
			NewsWindow.draw(Newbackground);
			NewsWindow.draw(Newstext);
			NewsWindow.draw(NewsHeading);
			NewsWindow.draw(Newbackground1);
			NewsWindow.draw(Newstext1);
			NewsWindow.display();
		}
	}
};



