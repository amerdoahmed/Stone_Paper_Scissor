#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enumeration: enGameChoice
enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };

// Enumeration: enWinner
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// Structure : stRoundInfo
struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

// Structure : stGameResults
struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

// Function: RandomNumbe
int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

// Function: GetComputerChoice
enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

// Function: WhoWonTheRound
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;
	// Determine the winner based on game rules.
	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
	case enGameChoice::Paper:
		return (RoundInfo.ComputerChoice == enGameChoice::Scissor) ? enWinner::Computer : enWinner::Player1;
	case enGameChoice::Scissor:
		return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
	}
}

// Function: WhoWonTheGame
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes) return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes) return enWinner::Computer;
	else return enWinner::Draw;
}

// Function: ChoiceName
string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone", "Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

// Function SetWinnerScreenColor
void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 20"); //turn screen to Green
		break;
	case enWinner::Computer:
		system("color 40"); //turn screen to Red
		cout << "\a";
		break;
	default:
		system("color 60"); //turn screen to Yellow
		break;
	}
	cout << "\n\t\t\t\t_________________________________________________________\n";
}

// Function: WinnerName
string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
	return arrWinnerName[Winner - 1];
}

// Function: ReadPlayer1Choice
enGameChoice ReadPlyer1Choice()
{
	short Choice;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissor? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);
	return (enGameChoice)Choice;
}

// Function: PrintRoundResults
void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
	cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
	if (RoundInfo.Winner == Player1)
	{
		system("color 20");  // Green for player
	}
	else if (RoundInfo.Winner == Computer)
	{
		system("color 40");  // Red for computer
		cout << "\a";  // Bell sound
	}
	else
	{
		system("color 60");  // Yellow for no winner
	}

	cout << endl;
	cout << "_________________________________________\n" << endl;
}

// Function FillGameResults
stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

// Function: PlayGame
stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound[" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlyer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\n";
		cout << t;
	}
	return t;
}

// Function ShowFinalGameResults
void ShowFinalGameResults(stGameResults GameResults)
{

	cout << "\n\t\t\t\t_________________________________________________________\n\n";
	cout << "\t\t\t\t\t\t +++ G A M E  O V E R +++ \n";
	cout << "\t\t\t\t_________________________________________________________\n";
	cout << "\t\t\t\t_______________________[Game Result]_____________________";
	cout << "\n\t\t\t\tGame Rounds          : " << GameResults.GameRounds;
	cout << "\n\t\t\t\tPlayer won times     : " << GameResults.Player1WinTimes;
	cout << "\n\t\t\t\tComputer won times   : " << GameResults.ComputerWinTimes;
	cout << "\n\t\t\t\tDraw times           : " << GameResults.DrawTimes;
	cout << "\n\t\t\t\tFinal Winner         : " << GameResults.WinnerName;

	if (GameResults.WinnerName == "Player1")
	{
		system("color 20");
	}
	else if (GameResults.WinnerName == "Computer")
	{
		system("color 40");
		cout << "\a";
	}
	else
	{
		system("color 60");
	}

	cout << "\n\t\t\t\t_________________________________________________________\n";
}

// Function ReadHowManyRounds
short ReadHowManyRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

//Function ResetScreen
void ResetScreen()
{
	system("cls");
	system("color 07");
}

// Function: StartGame
void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();

		stGameResults GameResults = PlayGame(ReadHowManyRounds());

		ShowFinalGameResults(GameResults);

		cout << endl<< Tabs(3) << "\nDo you want to play again? (Y/N): ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// Main Function
int main()
{
	srand((unsigned)time(NULL));  // Seed random number generator.
	StartGame();  // Start the game.
	return 0;  
}
