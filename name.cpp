
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;


void textFunction() {

	cout << "Today, our gamble will be a bet that the magic spinner will land on your lucky number. \nFirst, you'll insert your lucky number. \nThen, you'll pick a number for the spinner to go up to. \nFinally, you'll put a money bet on whether the spinner will land on your number.\n\n";
}



class Spinner {
	private: 
		int spinnerMax;
		int luckyNumber;
		int randomNumber;
		int bet;
		int score = 0;
	public:
		int spinTheWheel();
		bool checkIfEqual();
		int getUsrInput();
		void displayResults();
		int trackScore(int bet);


};

int Spinner::spinTheWheel() {
	randomNumber = rand() % spinnerMax + 1;

	return randomNumber;
}


bool Spinner::checkIfEqual() {
	
	if (luckyNumber == randomNumber) {

		return true;
	}
	else {

		return false;

	}

}

int Spinner::getUsrInput() {
	cout << "What is your lucky number today?? \n\n";
	cin >> luckyNumber;
	cout << "How high would you like the spinner to go today?? \n\n";
	cin >> spinnerMax;
	while (spinnerMax < luckyNumber)
	{
		cout << "Re-enter a valid spinner max which is higher than your lucky number: \n\n";
		cin >> spinnerMax;
	}
	cout << "How much do you want to be that your number was chosen by the spinner?? \n\n$";
	cin >> bet;

	return luckyNumber, spinnerMax, bet;
}

void Spinner::displayResults() {


	if (checkIfEqual() == 0) {
		cout << "Sorry! The spinner landed on " << randomNumber << " not " << luckyNumber << ". You just lost " << bet << "$!!\n\n";
		bet = -bet;
		trackScore(bet);
	}
	else {
		cout << "Congratulations!! The spinner landed on your lucky number. You just won " << bet << "$!!\n\n";
		trackScore(bet);
	}

}

int Spinner::trackScore(int bet) {

	score = score + bet;
	cout << "You have " << score << "$ in your bank.\n\n";
	return score;

}


int main() {
	textFunction();
	Spinner spinner;
	string keepPlaying = "Yes";

	do {
		spinner.getUsrInput();
		spinner.spinTheWheel();
		spinner.displayResults();
		cout << "Play again? (yes/no) ";
		cin >> keepPlaying;
	} while (keepPlaying == "yes");
	return 0;

};