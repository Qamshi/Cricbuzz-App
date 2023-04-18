#include <SFML/Graphics.hpp>
#include"Menu.h"
#include<iostream>
#include<windows.h>
using namespace sf;
using namespace std;
Team myTeam;   // ===========================>> Globally creating object of class Team <<===========================
Match Game;    // ===========================>> Globally creating object of class Match <<===========================
Font Algerian, Milkshake, Timenewroman, Thunder;    // ===========================>> Globally creating object of Fonts <<===========================
void SubMenu() // ===========================>> Declaring Function For Sub Menu Which comes After login <<===========================
{
    int option;
    bool BreakMenu = false;
    do
    {
        system("color 4F");
        cout << "\n\tPlease Select Option!"
            << "\n\tPress 1  ===>> Add Player"
            << "\n\tPress 2  ===>> Remove Player"
            << "\n\tPress 3  ===>> Search Player"
            << "\n\tPress 4  ===>> Update Player"
            << "\n\tPress 5  ===>> Update Captan"
            << "\n\tPress 6  ===>> Update Coach"
            << "\n\tPress 7  ===>> Schedule Match"
            << "\n\tPress 8  ===>> Conduct Match"
            << "\n\tPress 9  ===>> Update Player Ranking"
            << "\n\tPress 10 ===>> Update Team Ranking"
            << "\n\tPress 11 ===>> Update World Records"
            << "\n\tPress 12 ===>> Back to Main\n\t";
        cin >> option;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\t====>> Enter Again Valid Input ";
            cin >> option;
        }
        system("cls");
        switch (option)
        {
        case 1:
            system("Color 1F");
            myTeam.addPlayer();
            break;
        case 2:
            system("Color 2F");
            myTeam.removePlayer();
            break;
        case 3:
            system("Color 3F");
            myTeam.searchPlayer();
            break;
        case 4:
            system("Color 5F");
            myTeam.updatePlayer();
            break;
        case 5:
            system("Color 8F");
            myTeam.updateCaptain();
            break;
        case 6:
            system("Color 9F");
            myTeam.updateCoach();
            break;
        case 7:
            system("Color 1F");
            Game.scheduleMatch();
            break;
        case 8:
            system("Color 2F");
            Game.conductMatch();
            break;
        case 9:
            system("Color 3F");
            Game.updatePlayerRanking();
            break;
        case 10:
            system("Color 5F");
            Game.updateTeamRanking();
            break;
        case 11:
            system("Color 6F");
            Game.updateWorldRecords();
            break;
        case 12:
            BreakMenu = true;
            break;
        default:
            cout << "\n\tPlease Select Valid Option!\n";
            break;
        }
        cout << "\n\n\t";
        system("pause");
        system("cls");
    } while (BreakMenu == false);
}  
void credential()  // ===========================>> Declaring Function of Login Page <<===========================
{
    
    system("color 9F");
    bool matchFound = false;
    Texture  LoginImage;  
    RectangleShape LoginImageBackground;
    string username = "\0", password="\0";
    Text LoginName, LoginKey;
    string temp_user, temp_pass; //temporary variable 
    ifstream Admin("admin.txt"); //opening credentials file (username, password)
    if (!Admin.is_open()) //if not opened
    {
        cout << "File is not opened\n";
    }
    else
    {
        Admin >> temp_user; //input username from file
        Admin >> temp_pass; //input password from file
    }
    Admin.close(); //closing file
   // return access; //return access
    LoginImage.loadFromFile("Backgrounds/Security.jpeg");
    LoginImageBackground.setSize(Vector2f(1000, 650));
    LoginImageBackground.setTexture(&LoginImage);

    RenderWindow Login(VideoMode(1000, 650), "\t\tLogin ID!");
    while (Login.isOpen())
    {
        LoginName.setFont(Timenewroman);
        LoginName.setString(username);
        LoginName.setFillColor(Color::Black);
        LoginName.setOutlineThickness(3);
        LoginName.setOutlineColor(Color::White);
        LoginName.setPosition(Vector2f(235, 255));

        LoginKey.setFont(Timenewroman);
        LoginKey.setString(password);
        LoginKey.setFillColor(Color::Black);
        LoginKey.setOutlineThickness(3);
        LoginKey.setOutlineColor(Color::White);
        LoginKey.setPosition(Vector2f(235, 320));
        Event evnt;
        while (Login.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed() || evnt.key.code == Mouse::isButtonPressed(Mouse::Left))
            {
                Login.close();

            }
            if (evnt.type == Event::KeyPressed)
                Login.close();
        }
        Login.clear();
        Login.draw(LoginImageBackground);
        Login.draw(LoginName);
        Login.draw(LoginKey);
        Login.display();
        if (matchFound == false)
        {
           cout << "\n\t\n\t================================================================================================"
                << "\n\t\n\t================================================================================================"
                << "\n\t\n\t                                 =========>> LOGIN PAGE <<=========                             "
                << "\n\t\n\t================================================================================================"
                << "\n\t\n\t================================================================================================"
                << "\n\n\n\n\n\t==========>> Enter Username : ";
            cin >> username;
            cout << "\n\n\t==========>> Enter Password : ";
            cin >> password;
            if (temp_user == username && temp_pass == password)
            {
                matchFound = true;
            }
            else
            {
                cout << "\a";
            }
            system("cls");
        }
    }  

}
void MainMenu(RenderWindow& Windows) // ===========================>> It is main menu function of SFML <<===========================
{
    bool breakmenu = false;
    do
    {
        system("cls");
        system("color 5F");
        Menu MenuScreen(1100, 650);
        while (Windows.isOpen())
        {
            Event evnt;
            while (Windows.pollEvent(evnt))
            {
                if (evnt.type == Event::KeyReleased)
                {
                    if (evnt.key.code == Keyboard::Up)
                    {
                        MenuScreen.MoveUp();
                    }
                    else if (evnt.key.code == Keyboard::Down)
                    {
                        MenuScreen.MoveDown();
                    }
                    else if (evnt.key.code == Keyboard::Return)
                    {
                        switch (MenuScreen.get_SelectedOption())
                        {
                        case 0:
                            credential();
                            SubMenu();
                            break;
                        case 1:
                            myTeam.displayTeam();
                            break;
                        case 2:
                            Game.displayRecentMatches();
                            break;
                        case 3:
                            Game.displayUpcomingMatches();
                            break;
                        case 4:
                            Game.News();
                            break;
                        case 5:
                            Windows.close();
                            break;
                        case 6:
                            breakmenu = true;
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            if (evnt.type == Event::Closed())
            {
                Windows.close();
            }
            Windows.clear();
            MenuScreen.Draw(Windows);
            Windows.display();
        }
    } while (breakmenu == false);
}
void Introduction()
{
    
    Texture WindowImage,WindowImage1;
    RectangleShape BackgroundImage;
    CircleShape BackgroundImage1;

    WindowImage.loadFromFile("Backgrounds/Main.jpg");
    BackgroundImage.setSize(Vector2f(1000,650));
    BackgroundImage.setTexture(&WindowImage);
    WindowImage1.loadFromFile("Backgrounds/Cricbuzz.png");
    BackgroundImage1.setRadius(75);
    BackgroundImage1.setTexture(&WindowImage1);
    BackgroundImage1.setPosition(800, 20);
    
    Text Heading, Qamrosh, Haseeb;
    Heading.setFont(Algerian);
    Heading.setString("WELCOME TO \n   CRICBUZZ");
    Heading.setFillColor(Color(204, 0, 153));
    Heading.setOutlineThickness(2);
    Heading.setOutlineColor(Color(255, 255, 255));
    Heading.setCharacterSize(50);
    Heading.setPosition(100, 125);

    Qamrosh.setFont(Thunder);
    Qamrosh.setString("QAMROSH MAQSOOD \n\n 20F-0276");
    Qamrosh.setFillColor(Color(204, 0, 153));
    Qamrosh.setOutlineThickness(2);
    Qamrosh.setOutlineColor(Color(255, 255, 255));
    Qamrosh.setCharacterSize(25);
    Qamrosh.setPosition(30, 350);

    Haseeb.setFont(Thunder);
    Haseeb.setString("HASEEB USMANI \n\n 20F-0276");
    Haseeb.setFillColor(Color(204, 0, 153));
    Haseeb.setOutlineThickness(2);
    Haseeb.setOutlineColor(Color(255, 255, 255));
    Haseeb.setCharacterSize(25);
    Haseeb.setPosition(220, 500);

    
    
    RenderWindow window(VideoMode(1000,650), "INTRODUCTION ", Style::Resize | Style::Close);

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case  Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                switch (evnt.key.code)
                {
                case Mouse::Left:
                    window.close();
                    break;
                }
            case Event::LostFocus:
                break;
            }
        }
        window.clear(Color());
        window.draw(BackgroundImage);
        window.draw(BackgroundImage1);
        window.draw(Heading);
        window.draw(Qamrosh);
        window.draw(Haseeb);
        window.display();
    }
}
int main()
{   
    Algerian.loadFromFile("Fonts/Algerian.ttf");
    Milkshake.loadFromFile("Fonts/Milkshake.ttf");
    Thunder.loadFromFile("Fonts/Thunder.ttf");
    Timenewroman.loadFromFile("Fonts/TimesNewRoman.ttf");
    Introduction();
    
    RenderWindow window(VideoMode(1100, 650), "CRIC-BUZZ APP",Style::Close);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        MainMenu(window);
        window.clear();
        window.display();
    }
    return 0;
}