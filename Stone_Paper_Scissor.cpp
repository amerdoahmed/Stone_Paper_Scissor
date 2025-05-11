#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    // Function to generate a random number

    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

short int NumberOfRounds()
{
    short int Number;

    cout << "How Many Rounds 1 To 10 ?\n";
    cin >> Number;

    return Number;
}

enum SPC { Stone = 1, Paper = 2, Scissor = 3 };

int ComputerWinsTimes = 0;
int PlayerWinsTimes = 0;
int Draw = 0;
void CheckWinner(short int UserChoice, short int ComputerChoice)
{
    if (UserChoice == ComputerChoice)
    {
        system("Color 6F");
        cout << "No Winner!\n";
        Draw ++;
    }
    else if ((UserChoice == SPC::Paper && ComputerChoice == SPC::Stone) ||
        (UserChoice == SPC::Scissor && ComputerChoice == SPC::Paper) ||
        (UserChoice == SPC::Stone && ComputerChoice == SPC::Scissor))
    {
        system("color 2F");
        cout << "Player Wins\n";
        PlayerWinsTimes ++;
    }
    else
    {
        cout << "\a";
        system("color 4F");
        cout << "Computer Wins\n";
        ComputerWinsTimes ++;
    };
}


int TotalRounds = NumberOfRounds();
void Choices()
{
    
    short int UserChoice;
    short int ComputerChoice;
    for (int i = 0;i < TotalRounds;i++)
    {
        cout << "\nRound [" << i + 1 << "] begins :\n\n";
        cout << "Your choice : [1]:Stone , [2]:Paper, [3]Scissor ? ";
        cin >> UserChoice;
        ComputerChoice = RandomNumber(1, 3);
        cout << "\n____________Round [" << i + 1 << "]____________\n" << endl;
        cout << "Player1  Choice : " << UserChoice << endl;
        cout << "Computer Choice : " << ComputerChoice << endl;
        cout << "Round Winner    : ", CheckWinner(UserChoice, ComputerChoice);
        cout << "\n________________________________________________\n";

    }
}

void ShowResults()
{
    system("color 70");
    cout << "\n\n                    ________________________________________________________________________\n\n";
    cout << "                                         +++  G a m e  O v e r  +++           ";
    cout << "\n                    _________________________________________________________________________\n";
    cout << "\n                    ____________________[ Game Resuts ]______________________________________\n";
    cout << "                                        Game Rounds        :"<< TotalRounds << endl;
    cout << "                                        Player1 won times  :"<< PlayerWinsTimes << endl;
    cout << "                                        Computer won times :"<< ComputerWinsTimes << endl;
    cout << "                                        Draw Times         :" << Draw << endl;
    cout << "                                        Final Winner       :";
        if (PlayerWinsTimes > ComputerWinsTimes)
        cout << "Player" << endl;
        else if (ComputerWinsTimes > PlayerWinsTimes)
        cout << "Computer" << endl;
        else
        cout << "No Winner" << endl;
    cout << "                     _________________________________________________________________________\n";


}



int main()
{
    srand((unsigned)time(NULL));

    Choices();
    ShowResults();

    return 0;
}



