// rule.cpp
#include <iostream>
#include "rule.h"
using namespace std;


// Function to print out the game rules
// Input: none
// Output: print out the game rules and instruction messages
void rule() {
  int a;

  system("clear");

  cout << "+---------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                       |" << endl;
  cout << "|                                      GAME STORY:                                      |" << endl;
  cout << "|     You have been chosen by the richest person to enter his investment contest!       |" << endl;
  cout << "|     He will give you and another candidate (the computer) a sum of money. Then        |" << endl;
  cout << "|     whoever wins the game will inherit the richest person's fortune!                  |" << endl;
  cout << "|                                                                                       |" << endl;
  cout << "|                                      GAME RULES:                                      |" << endl;
  cout << "|     (1) You should enter a specific number + press the enter key to conduct           |" << endl;
  cout << "|         certain actions. For example, there're the statements in the game:            |" << endl;
  cout << "|                                                                                       |" << '\n';
  cout << "|           (1) Continue  (2) Pause   -- '(1)': enter 1 + press the enter key           |" << '\n';
  cout << "|                                     -- '(2)': enter 2 + press the enter key           |" << endl;
  cout << "|           (3) Check the assets details                                                |" << '\n';
  cout << "|                                     -- '(3)': enter 3 + press the enter key           |" << endl;
  cout << "|                                                                                       |" << endl;
  cout << "|         Other places needed input from the player but don't appear  in this form      |" << endl;
  cout << "|         will come with instruction measages.                                          |" << endl;
  cout << "|     (2) In this game, you can roll a die, draw cards, purchase land, and upgrade      |" << endl;
  cout << "|         it (start with 0, The maximum level of land is 2).                            |" << endl;
  cout << "|     (3) Your chess in the map is 'A' and computer's chess is 'B'.                     |" << endl;
  cout << "|     (4) If you are at a computer-owned land, you will have to pay a toll, and         |" << endl;
  cout << "|         vice versa.                                                                   |" << endl;
  cout << "|     (5) The amount of toll will be 0.1 * current land value. You can upgrade the      |" << endl;
  cout << "|         land to increase its value and get more toll (charge for leveling up:         |" << endl;
  cout << "|         0.3 * current land value).                                                    |" << endl;
  cout << "|     (6) The game ends after certain months (rounds) chosen by you. 3 options are      |" << endl;
  cout << "|         provided in the begining of a new game: 12 months, 24 months, 36 months.      |" << endl;
  cout << "|     (7) Meanwhile, the computer's action will be automatically conducted by the       |" << endl;
  cout << "|         program.                                                                      |" << endl;
  cout << "|                                                                                       |" << endl;
  cout << "|                                 WINNING CONDITIONS:                                   |" << endl;
  cout << "|            * Achieving any of the following terms is considered a victory *           |" << endl;
  cout << "|     (1) Having the most assets (cash + value of housing properties) when there's      |" << endl;
  cout << "|         no time left (i.e. Months = 0).                                               |" << endl;
  cout << "|     (2) If one goes bankrupt (i.e. cash own < 0), the other wins outright.            |" << endl;
  cout << "|                                                                                       |" << endl;
  cout << "|     Note: You can check these information in the pause page at your turn.             |" << endl;
  cout << "|                                                                                       |" << endl;
  cout << "+---------------------------------------------------------------------------------------+" << endl;

  cout << "Enter 1 + press the enter key to continue..." << '\n';

  cin >> a;

  switch (a) {
  case 1:
    break;
  default:
    cout << "Please input the correct number." << '\n';
    cin >> a;
  }
}
