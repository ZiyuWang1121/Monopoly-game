// select_round.cpp
#include <iostream>
#include "select_round.h"
using namespace std;

// Function for player to choose the mode of the game
// Input: one array (the palyer and the computer's rounds left)
// Output: print out the page for choose the mode of the game and instruction
// message
void Select_round(int round[]) {
  int choice;
  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                      SELECT MODE                                       |" << endl;
  cout << "|                                 1. Short  (12 months)                                  |" << '\n';
  cout << "|                                 2. Medium (24 months)                                  |" << '\n';
  cout << "|                                 3. Long   (36 months)                                  |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                Note: 1 month = 1 round                                 |" << '\n';
  cout << "|                                                                                        |" << endl;
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << "Enter a number (1 or 2 or 3) + press the enter key to continue..." << '\n';

  cin >> choice;

  // Set the round of the game up according to the player's choice
  while (choice) {
    if (choice == 1) {
      round[0] = 12;
      round[1] = 12;
      break;
    }
    else if (choice == 2) {
      round[0] = 24;
      round[1] = 24;
      break;
    }
    else if (choice == 3) {
      round[0] = 36;
      round[1] = 36;
      break;
    }
    else {
      cout << "Please input the correct number." << '\n';
      cin >> choice;
    }
  }
}
