// Author: Wang Ziyu
// U. No.: 3035777547
// File name: MONOPOLY.cpp
// Description: A program for the player to player the monopoly game
// with the computer

#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>

#include "select_round.h"
#include "rule.h"

using namespace std;

// Data structure for storing the map related information
struct map {
  string number;
	string name;
  string owner;
  int level;
	int value;
};
map map[16];

// Function for counting the length of a number
// Input: a number; output: the length of this number
int length(int x) {
	int len = 0;
	while(x) {
		x /= 10;
		len++;
	}
	return len;
}

// Function for loading a new game
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: none/ print out error message
void input_mapinfo(int position[],int cash[],int round[],int len[]) {
  int i = 0,num;
  string input;
  char location[16] = "map.txt";         // "map.txt" is a document that
  ifstream fin;                          // consists of the initial setting
                                         // of the game
  fin.open(location);

  if (fin.fail()) {
    cout << "Error in file opening!"
      << endl;
    exit(1);
  }

  // Read rows with different information from file "map.txt"
  while (i < 17) {
    if (i == 0 || i == 4 || i == 8 || i == 12) {
      fin >> input;
      map[i].number = input;            // loading grid 01, 04, 08, and 12

      fin >> input;
      map[i].name = input;
    }
    else if (i == 16) {                 // loading basic information (chess
      fin >> num;                       // positon, cash own, round left, and
      position[0] = num;                // length of cash number

      fin >> num;
      position[1] = num;

      fin >> num;
      round[0] = num;

      fin >> num;
      round[1] = num;

      fin >> num;
      cash[0] = num;

      fin >> num;
      cash[1] = num;

      len[0] = length(cash[0]),len[1] = length(cash[1]);
    }
    else {                              // loading grid left
      fin >> input;
      map[i].number = input;

      fin >> input;
      map[i].name = input;

      fin >> input;
      map[i].owner = input;

      fin >> num;
      map[i].level = num;

      fin >> num;
      map[i].value = num;
    }
    i++;
  }
  fin.close();
}

// Function for loading the last saved game
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: none/ print out error message
void input_last_mapinfo(int position[],int cash[],int round[],int len[]) {
  int i = 0,num;
  string input;
  char location[16] = "save.txt";     // "save.txt" stores the last
  ifstream fin;                       // saved game status

  fin.open(location);

  if (fin.fail()) {
    cout << "You haven't store any game, please start a new one!"
      << endl;
    exit(1);
  }

  // Store rows with different information to the file "save.txt"
  while (i < 17) {
    if (i == 0 || i == 4 || i == 8 || i == 12) {
      fin >> input;
      map[i].number = input;               // Loading grid 01, 04, 08, and 12

      fin >> input;
      map[i].name = input;
    }
    else if (i == 16) {                    // Loading basic information (chess
      fin >> num;                          // positon, cash own, round left, and
      position[0] = num;                   // length of cash number

      fin >> num;
      position[1] = num;

      fin >> num;
      round[0] = num;

      fin >> num;
      round[1] = num;

      fin >> num;
      cash[0] = num;

      fin >> num;
      cash[1] = num;

      len[0] = length(cash[0]),len[1] = length(cash[1]);
    }
    else {                                 // Loading grid left
      fin >> input;
      map[i].number = input;

      fin >> input;
      map[i].name = input;

      fin >> input;
      map[i].owner = input;

      fin >> num;
      map[i].level = num;

      fin >> num;
      map[i].value = num;
    }
    i++;
  }
  fin.close();
}

// Function to print out the mainpage of the game and process
// the player's choice
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: print out the mainpage of the game and instruction messages
void mainpage(int position[],int cash[],int round[],int len[]) {
  int b;
  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                        MONOPOLY                                        |" << endl;
  cout << "|                                  Welcome To The Game                                   |" << '\n';
  cout << "|                               1. Start a new game                                      |" << '\n';
  cout << "|                               2. Continue the last game                                |" << '\n';
  cout << "|                               3. Check the game rules                                  |" << '\n';
  cout << "|                               4. Quit                                                  |" << '\n';
  cout << "|                                                                                        |" << endl;
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << "Enter a number (1 or 2 or 3 or 4) + press the enter key to continue...\n";

  cin >> b;

  while (b) {
    if (b == 1) {                                     // Start a new game
      input_mapinfo(position,cash,round,len);
      Select_round(round);
      rule();
      break;
    }
    else if (b == 2) {                               // Continue the last game
      input_last_mapinfo(position,cash,round,len);
      break;
    }
    else if (b == 3) {                               // Check the game rules
      rule();
      mainpage(position,cash,round,len);
      break;
    }
    else if (b == 4) {                               // Quit the game
      cout << "You quit the game.\n";
      exit(1);
    }
    else {
      cout << "Please input the correct number.\n";
      cin >> b;
    }
  }
}

// Function to list out the player's assets situation
// including cash and Housing properties own.
// Input: none;
// Output: print out the player's assets situation
void showplayer() {
  int total = 0,len = 0;

  cout << "| 2. Housing properties:                                                                 |" << '\n';

  for (int j = 0; j < 16;j++) {
    if (j == 0 || j == 4 || j == 8 || j == 12) {
      cout << "";
    }
    else {
      if (map[j].owner == "Player") {
        cout << "|    Number: " << map[j].number << ", Name: " << map[j].name
         << ", Acquired by: " << map[j].owner << ", Level: " << map[j].level
         << ", Value: " << map[j].value;
        total += map[j].value;
        len = 3 + map[j].name.length() + map[j].owner.length() +
        length(map[j].value);

        for (int i = 0;i < 35 - len;i++) {        // for formating the output
          cout << " ";
        }
        cout << "|" << '\n';
      }
    }
  }
}

// Function to list out the computer's assets situation
// including cash and Housing properties own.
// Input: none;
// Output: // Output: print out the computer's assets situation
void showcomputer() {
  int total = 0,len = 0;

  cout << "| 2. Housing properties:                                           ";
  cout << "                      |" << '\n';

  for (int j = 0; j < 16;j++) {
    if (j == 0 || j == 4 || j == 8 || j == 12) {
      cout << "";
    }
    else {
      if (map[j].owner == "Computer") {
        cout << "|    Number: " << map[j].number << ", Name: " << map[j].name
        << ", Acquired by: " << map[j].owner << ", Level: " << map[j].level;
        cout << ", Value: " << map[j].value;
        total += map[j].value;
        len = 3 + map[j].name.length() + map[j].owner.length() +
        length(map[j].value);

        for (int i = 0;i < 35 - len;i++) {      // for formating the output
          cout << " ";
        }
        cout << "|" << '\n';
      }
    }
  }
}

// Function to print out the chesses according to the positions
// Input: a string (the serial numbers of the land) and a array
// (the palyer and the computer's positions);
// Output: print out the chesses for the player and the computer
void printchess(string number,int position[]) {
  if (map[position[0]].number == number
    && map[position[1]].number != number) {
    cout << "A ";
  }
  else if (map[position[1]].number == number
    && map[position[0]].number != number) {
    cout << " B";
  }
  else if (map[position[1]].number == number
    && map[position[0]].number == number) {
    cout << "AB";
  }
  else {
    cout << "  ";                              // for formating the output
  }
}

// Function to print out the complete map
// Input: three arrays (the palyer and the computer's positions, cashes,
// and the lengths of the cashes);
// Output: print out the complete map
void PrintBoard(int cash[],int len[],int position[]) {

  system("clear");

  cout << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << '\n';
  cout << "| 01 The starting point  | 02 The Hanging Gardens | 03 Sydney Opera House  | 04 Eiffel Tower        | 05 Fate                |" << '\n';
  cout << "|        ----->          |                        |                        |                        |          !!!           |" << '\n';
  cout << "|           ";
	printchess("01",position);
	cout << "           |           ";
	printchess("02",position);
	cout << "           |           ";
	printchess("03",position);
	cout << "           |           ";
	printchess("04",position);
	cout << "           |           ";
	printchess("05",position);
	cout << "           |" << '\n';
  cout << "|    (Nothing happends)  | Level: " << map[1].level << "               | Level: " << map[2].level << "               | Level: " << map[3].level << "               |      (Encounter a      |" << '\n';
  cout << "|                        | Value: $" << map[1].value << "           | Value: $" << map[2].value << "           | Value: $" << map[3].value << "           |      random event)     |" << '\n';
	cout << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << '\n';
  cout << "| 16 Plaza de Espana     |                                                                          | 06 Statue of Liberty   |" << '\n';
  cout << "|                        |                                                                          |                        |" << '\n';
  cout << "|           ";
	printchess("16",position);
	cout << "           |                                                                          |           ";
	printchess("06",position);
	cout << "           |" << '\n';
  cout << "| Level: " << map[15].level << "               |                                                                          | Level: " << map[5].level << "               |" << '\n';
  cout << "| Value: $" << map[15].value << "           |                                                                          | Value: $" << map[5].value << "           |" << '\n';
  cout << "+------------------------+                                                                          +------------------------+" << '\n';
  cout << "| 15 Alcatraz            |                                                                          | 07 Great Wall of China |" << '\n';
  cout << "|                        |                                                                          |                        |" << '\n';
  cout << "|           ";
	printchess("15",position);
	cout << "           |                                                                          |           ";
	printchess("07",position);
	cout << "           |" << '\n';
  cout << "| Level: " << map[14].level << "               |                                                                          | Level: " << map[6].level << "               |" << '\n';
  cout << "| Value: $" << map[14].value << "           |                                                                          | Value: $" << map[6].value << "           |" << '\n';
  cout << "+------------------------+                                                                          +------------------------+" << '\n';
  cout << "| 14 Machu Picchu        |                                                                          | 08 Taj Mahal           |" << '\n';
  cout << "|                        |                                                                          |                        |" << '\n';
  cout << "|           ";
	printchess("14",position);
	cout << "           |                                                                          |           ";
	printchess("08",position);
	cout << "           |" << '\n';
  cout << "| Level: " << map[13].level << "               |                                                                          | Level: " << map[7].level << "               |" << '\n';
  cout << "| Value: $" << map[13].value << "           |                                                                          | Value: $" << map[7].value << "           |" << '\n';
  cout << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << '\n';
  cout << "| 13 Fate                | 12 Angkor Wat          | 11 Mount Fuji          | 10 Golden Gate Bridge  | 09 Maldives            |" << '\n';
  cout << "|          !!!           |                        |                        |                        |   Take a holiday here  |" << '\n';
  cout << "|           ";
	printchess("13",position);
	cout << "           |           ";
	printchess("12",position);
	cout << "           |           ";
	printchess("11",position);
	cout << "           |           ";
	printchess("10",position);
	cout << "           |           ";
	printchess("09",position);
	cout << "           |" << '\n';
  cout << "|      (Encounter a      | Level: " << map[11].level << "               | Level: " << map[10].level << "               | Level: " << map[9].level << "               |    (Nothing happends)  |" << '\n';
  cout << "|      random event)     | Value: $" << map[11].value << "           | Value: $" << map[10].value << "           | Value: $" << map[9].value << "           |                        |" << '\n';
  cout << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << '\n';

}

// Function to print out the assets details for both player and computer
// Input: two arrays (the palyer and the computer's cashes and the lengths
// of the cashes);
// Output: print out the assets details for both player and computer
void detail(int cash[],int len[]) {
  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                         Player                                         |" << endl;
  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "| 1. Cash: $" << cash[0];

  // for formating the output
  if (length (cash[0]) <= len[0]) {
    for (int i = 0;i < (5 - length (cash[0]) + 72);i++) {
      cout << " ";
    }
  }
  else if (length (cash[0]) > 5) {
    for (int i = 0;i < 72 + len[0] - (length (cash[0] - len[0]));i++) {
      cout << " ";
    }
  }
  cout << "|" << '\n';

  cout << "|                                                                                        |" << '\n';

  showplayer();

  cout << "|                                                                                        |" << '\n';

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                        Computer                                        |" << endl;
  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "| 1. Cash: $" << cash[1];

  // for formating the output
  if (length (cash[1]) <= len[1]) {
    for (int i = 0;i < (5 - length (cash[1]) + 72);i++) {
      cout << " ";
    }
  }
  else if (length (cash[1]) > 5) {
    for (int i = 0;i < 72 + len[1] - (length (cash[1] - len[1]));i++) {
      cout << " ";
    }
  }
  cout << "|" << '\n';
  cout << "|                                                                                        |" << '\n';

  showcomputer();

  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;
}

// Function to print out the pause pages and process
// the player's choice
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: print out the pause pages and instruction messages
void pause(int position[],int cash[],int round[],int len[]) {
  system("clear");

  int b;

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                        MONOPOLY                                        |" << endl;
  cout << "|                                     * GAME PAUSE *                                     |" << endl;
  cout << "|                               1. Continue                                              |" << '\n';
  cout << "|                               2. Check the game rules                                  |" << '\n';
  cout << "|                               3. Save and quit                                         |" << '\n';
  cout << "|                               4. Quit without save                                     |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cin >> b;

  while (b) {
    if (b == 1) {                                  // Continue the game
      cout << "";
      break;
    }
    else if (b == 2) {                            // Check the game rules
      rule();
      pause(position,cash,round,len);
      break;
    }
    else if (b == 3) {
      char av[16] = "save.txt";    // "save.txt" stores the last
                                   // saved game status
      ofstream fout;

      fout.open("save.txt");

      if (fout.fail()) {
        cout << "Error in file opening!"
          << endl;
        exit(1);
      }
      string line;

      // Store rows with different information to the file "save.txt"
      for (int j = 0; j < 17;j++) {
        if (j == 0 || j == 4 || j == 8 || j == 12) {
          fout << map[j].number << " " << map[j].name << '\n';
        }
        else if (j == 16) {
          fout << position[0] << " " << position[1] << " " << round[0]
          << " " << round[1] << " " << cash[0] << " " << cash[1] << '\n';
        }
        else {
          fout << map[j].number << " " << map[j].name << " " << map[j].owner
          << " " << map[j].level << " " << map[j].value << '\n';
        }
      }
      fout.close();

      cout << "You save and quit the game." << '\n';
      exit(1);
    }
    else if (b == 4) {
      cout << "You quit the game (data unsaved)." << '\n';
      exit(1);
    }
    else {
      cout << "Please input the correct number." << '\n';
      cin >> b;
    }
  }
}

// Function for player to roll dice
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: one array for storing the palyer and the computer's positions
// and  print out the instruction messages
int * dice(int position[],int cash[],int len[],int round[]) {
  srand(time(0));

  int b,a;
  int result;

  cin >> a;

  // process the player's choice
  while (a) {
    if (a == 1) {
      round[0]--;                               // throw the dice: round - 1
      result = rand() % 6 + 1;         // generate random number from 1 to 6
      position[0] += result;           // update the player's position

      cout << '\n';
      cout << "You roll a " << result << "." << '\n';
      cout << '\n';
      cout << "Enter any number + press the enter key to continue..." << '\n';

      cin >> b;

      if (position[0] >= 16) {                 // make sure the position
        position[0] -= 16;                     // is not greater than 16
      }
      PrintBoard(cash,len,position);

      return position;
    }
    else if (a == 2) {
      pause(position,cash,round,len);          // enter the pause page and
      PrintBoard(cash,len,position);           // return to the game page

      cout << "You Are Here: " << map[position[0]].number << " "
      << map[position[0]].name << '\n';
      cout << "Time Left: " << round[0] << " Months" << "\n";
      cout << '\n';
      cout << "Continue the game?" << '\n';
      cout << "(1) Continue  (2) Pause" << '\n';
      cout << "(3) Check the assets details" << '\n';

      cin >> a;
    }
    else if (a == 3) {
      detail(cash,len);                        // enter the page for checking
                                               // the assets details
      cout << '\n';
      cout << "Enter any number + press the enter key to continue the game..." << '\n';
      cin >> b;

      PrintBoard(cash,len,position);           // return to the game page

      cout << "You Are Here: " << map[position[0]].number << " "
      << map[position[0]].name << '\n';
      cout << "Time Left: " << round[0] << " Months" << "\n";
      cout << '\n';
      cout << "Continue the game?" << '\n';
      cout << "(1) Continue  (2) Pause" << '\n';
      cout << "(3) Check the assets details" << '\n';

      cin >> a;
    }
    else {
      cout << "Please input the correct number." << '\n';
      cin >> a;
    }
  }
  return 0;
}

// Function for computer to roll dice automatically
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: one array for storing the palyer and the computer's positions
// and  print out the instruction messages
int * autodice(int position[],int cash[],int len[],int round[]) {
  srand(time(0));

  int result,b;

  cout << "\033[1;35m";

  PrintBoard(cash,len,position);

  cout << '\n';
  cout << "It's your opponent's turn!!!" << '\n';

  round[1] --;                          // throw the dice: round - 1
  result = rand() % 6 + 1;              // generate random number from 1 to 6
  position[1] += result;                // update the player's position

  cout << '\n';
  cout << "He rolls a " << result << "." << '\n';
  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << '\n';

  cin >> b;

  if (position[1] >= 16) {              // make sure the position
    position[1] -= 16;                  // is not greater than 16
  }
  PrintBoard(cash,len,position);

  return position;
}

// Function to generate the computer's choice randomly
// Input: none;
// Output: a number (the randomly generated decision of the computer)
int Comchoice() {
  srand(time(0));
  int result = rand() % 20 + 1;         // the probability for computer to
                                        // give disaffirmative reply: 1/20
  return result;
}

// Function for player to draw fate card (generate a random event)
// Input: three arrays (the palyer and the computer's positions, cashes,
// and the lengths of the cashes);
// Output: print out the instruction messages
void fate(int cash[],int len[],int position[]) {
  srand(time(0));
  int result = rand() % 12 + 1,b;       // generate a random event

  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;

  PrintBoard(cash,len,position);

  cout << '\n';

  switch(result) {                      // apply the event
    case 1:   case 12:                  // biased probability
      cout << "You are fined $500 for creating noise!" << '\n';
      cash[0] -= 500;
      break;
    case 2:
      cout << "You are fined $1000 for illegal development of land!" << '\n';
      cash[0] -= 1000;
      break;
    case 3:
      cout << "You won $2000 in the lottery!" << '\n';
      cash[0] += 2000;
      break;
    case 4:
      cout << "You inherited $1000 by accident!" << '\n';
      cash[0] += 1000;
      break;
    case 5:   case 11:
      cout << "You received an additional grant of $300!" << '\n';
      cash[0] += 300;
      break;
    case 6:
      cout << "You are fined $2000 for alleged monopolistic conduct!" << '\n';
      cash[0] -= 2000;
      break;
    case 7:
      cout << "Your subordinate decided to resign (cash -$500)!" << '\n';
      cash[0] -= 500;
      break;
    case 8:
      cout << "Your partner suddenly lost his ambition (cash -$3000)!" << '\n';
      cash[0] -= 3000;
      break;
    case 9:   case 10:
      cout << "You made $1,000 in the stock market!" << '\n';
      cash[0] += 1000;
      break;
  }
}

// Function for computer to draw fate card automatically
// (generate a random event)
// Input: three arrays (the palyer and the computer's positions, cashes,
// and the lengths of the cashes);
// Output: print out the instruction messages
void comfate(int cash[],int len[],int position[]) {
  srand(time(0));
  int result = rand() % 12 + 1,b;             // generate a random event

  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;

  PrintBoard(cash,len,position);

  cout << '\n';

  switch(result) {                             // apply the event
    case 1:   case 12:                         // biased probability
      cout << "Your opponent are fined $500 for creating noise!" << '\n';
      cash[1] -= 500;
      break;
    case 2:
      cout << "Your opponent are fined $1000 for illegal development of land!" << '\n';
      cash[1] -= 1000;
      break;
    case 3:
      cout << "Your opponent won $2000 in the lottery!" << '\n';
      cash[1] += 2000;
      break;
    case 4:
      cout << "Your opponent inherited $1000 by accident!" << '\n';
      cash[1] += 1000;
      break;
    case 5:   case 11:
      cout << "Your opponent received an additional grant of $300!" << '\n';
      cash[1] += 300;
      break;
    case 6:
      cout << "Your opponent are fined $2000 for alleged monopolistic conduct!" << '\n';
      cash[1] -= 2000;
      break;
    case 7:
      cout << "Your opponent's subordinate decided to resign (cash -$500)!" << '\n';
      cash[1] -= 500;
      break;
    case 8:
      cout << "Your opponent's partner suddenly lost his ambition (cash -$3000)!" << '\n';
      cash[1] -= 3000;
      break;
    case 9:   case 10:
      cout << "Your opponent made $1,000 in the stock market!" << '\n';
      cash[1] += 1000;
      break;
  }
}

// Function mainly for printing out the current status and achieve
// functions like buy land, upgrade land, and pay toll for computer
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: print out the instruction messages
void askcom(int position[],int cash[],int len[],int round) {
  int buy,upgrade,b,a;

  cout << '\n';
  cout << "Your Opponent Is Here: " << map[position[1]].number << " "
  << map[position[1]].name << '\n';
  cout << "Time Left: " << round << " Months" << "\n";

  if (map[position[1]].number == "01") {
    cout << "";
  }
  else if (map[position[1]].number == "05" || map[position[1]].number == "13") {
    cout << '\n';
    cout << "Your opponent just draw a fate card!!! (Encounter a random event)" << '\n';
    comfate(cash,len,position);
  }
  else if (map[position[1]].number == "09") {
    cout << '\n';
    cout << "Your opponent take a holiday here (Nothing happends)." << '\n';
  }
  else {
    if (map[position[1]].owner == "NULL") {
      cout << '\n';
      cout << "This land has no owner." << '\n';

      cout << "Price: $" << map[position[1]].value << '\n';

      cout << '\n';
      cout << "Enter any number + press the enter key to continue..." << "\n";

      cin >> b;

      if (Comchoice() != 1) {
        if ((cash[0] - (map[position[1]].value)) >= 0) {
          cash[1] -= map[position[1]].value;
          PrintBoard(cash,len,position);
          map[position[1]].owner = "Computer";
          cout << '\n';
          cout << "Your opponent just purchased this land." << '\n';
        }
        else {
          PrintBoard(cash,len,position);
          cout << '\n';
          cout << "Your opponent doesn't have enough cash to buy the land." << '\n';
        }
      }
      else {
        cout << '\n';
        cout << "Your opponent did not purchase the land." << '\n';
      }
    }
    else if (map[position[1]].owner == "Computer") {
      cout << '\n';
      cout << "This is land belongs to your opponent." << '\n';

      if (map[position[1]].level < 2) {      // 2: maximum level of land
        cout << "This land can be upgraded." << '\n';
        cout << "Price: $" << map[position[1]].value * 0.3 << '\n';
        cout << "Value of the land after upgrade: $"
        << (map[position[1]].value + (map[position[1]].value * 0.3)) << '\n';

        cout << '\n';
        cout << "Enter any number + press the enter key to continue..." << "\n";

        cin >> b;

        if (Comchoice() != 1) {
          if ((cash[0] - (map[position[1]].value * 0.3)) >= 0) {
            cash[1] -= (map[position[1]].value * 0.3);
            map[position[1]].level++;
            map[position[1]].value += (map[position[1]].value * 0.3);
            PrintBoard(cash,len,position);
            cout << '\n';
            cout << "Your opponent just upgraded this land." << '\n';
            cout << "Current level: " << map[position[1]].level << '\n';
          }
          else {
            PrintBoard(cash,len,position);
            cout << '\n';
            cout << "Your opponent doesn't have enough cash to upgrade the land." << '\n';
          }
        }
        else {
          cout << '\n';
          cout << "Your opponent did not upgrade the land." << '\n';
          cout << "Current level: " << map[position[1]].level << '\n';
        }
      }
      else {
        cout << "Current level: " << map[position[1]].level << " (MAX)" << '\n';
        cout << "This land can't be upgraded any more!!!" << '\n';
      }
    }
    if (map[position[1]].owner == "Player") {
      cout << '\n';
      cout << "Lucky! This land is yours!" << '\n';
      int toll = 0.1 * map[position[1]].value;
      cout << "Your opponent has to pay you $"<< toll << " for the toll!" << '\n';
      cash[0] += toll;
      cash[1] -= toll;
    }
  }
  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;

  cout << "\033[0m";

  PrintBoard(cash,len,position);

  // when there's still time left + no one bankrupts ask the player's choice
  if (round != 1 && cash[0] > 0 && cash[1] > 0) {  
    cout << '\n';
    cout << "It's your turn!"<< '\n';
    cout << '\n';
    cout << "Continue the game?" << '\n';
    cout << "(1) Continue  (2) Pause" << '\n';
    cout << "(3) Check the assets details" << '\n';
  }
}

// Function mainly for printing out the current status and achieve
// functions like buy land, upgrade land, and pay toll for player
// Input: four arrays (the palyer and the computer's positions, cashes, rounds
// left, and the lengths of the cashes);
// Output: print out the instruction messages
void ask(int position[],int cash[],int len[],int round) {

  int buy,upgrade,b;

  cout << '\n';

  cout << "You Are Here: " << map[position[0]].number << " "
  << map[position[0]].name << '\n';
  cout << "Time Left: " << round << " Months" << "\n";

  if (map[position[0]].number == "01") {
    cout << "";
  }
  else if (map[position[0]].number == "05" || map[position[0]].number == "13") {
    cout << '\n';
    cout << "Time to draw a lucky fate card!!! (Encounter a random event)" << '\n';
    fate(cash,len,position);
  }
  else if (map[position[0]].number == "09") {
    cout << '\n';
    cout << "You take a holiday here (Nothing happends)." << '\n';
  }
  else {
    if (map[position[0]].owner == "NULL") {
      cout << '\n';
      cout << "This land has no owner." << '\n';
      cout << "Do you want to buy it?" << '\n';
      cout << "Price: $" << map[position[0]].value << '\n';
      cout << "(1) Yes (2) No" << '\n';

      cin >> buy;

      if (buy == 1) {
        if ((cash[0] - (map[position[0]].value)) >= 0) {
          cash[0] -= map[position[0]].value;
          PrintBoard(cash,len,position);
          map[position[0]].owner = "Player";
          cout << '\n';
          cout << "This land is now yours." << '\n';
        }
        else {
          PrintBoard(cash,len,position);
          cout << '\n';
          cout << "You don't have enough cash to buy the land." << '\n';
        }
      }
      else if (buy == 2) {
        cout << '\n';
        cout << "You did not purchase the land." << '\n';
      }
      else {
        cout << '\n';
        cout << "Please input the correct number." << '\n';
      }
    }
    else if (map[position[0]].owner == "Player") {
      cout << '\n';
      cout << "This is your land." << '\n';

      if (map[position[0]].level < 2) {      // 2: maximum level of land
        cout << "Do you want to upgrade it?" << '\n';
        cout << "Price: $" << map[position[0]].value * 0.3 << '\n';
        cout << "Value of the land after upgrade: $"
        << (map[position[0]].value + (map[position[0]].value * 0.3)) << '\n';
        cout << "(1) Yes (2) No" << '\n';

        cin >> upgrade;

        if (upgrade == 1) {
          if ((cash[0] - (map[position[0]].value * 0.3)) >= 0) {
            cash[0] -= (map[position[0]].value * 0.3);
            map[position[0]].level++;
            map[position[0]].value += (map[position[0]].value * 0.3);
            PrintBoard(cash,len,position);
            cout << '\n';
            cout << "Your land has been upgraded." << '\n';
            cout << "Current level: " << map[position[0]].level << '\n';
          }
          else {
            PrintBoard(cash,len,position);
            cout << '\n';
            cout << "You don't have enough cash to upgrade the land." << '\n';
          }
        }
        else if (upgrade == 2) {
          cout << '\n';
          cout << "You did not upgrade the land." << '\n';
          cout << "Current level: " << map[position[0]].level << '\n';
        }
        else {
          cout << '\n';
          cout << "Please input the correct number." << '\n';
        }
      }
      else {
        cout << "Current level: " << map[position[0]].level << " (MAX)" << '\n';
        cout << "You can't upgrade it any more!!!" << '\n';
      }
    }
    if (map[position[0]].owner == "Computer") {
      cout << '\n';
      cout << "Oops! This land is own by your opponent!" << '\n';
      int toll = 0.1 * map[position[0]].value;
      cout << "You have to pay $"<< toll << " for the toll!" << '\n';
      cash[0] -= toll;
      cash[1] += toll;
    }
  }
  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;
}

// Function for calculating the assets for the player and computer
// when the game ends. Then compare the assets to determine the
// corresponding ends
// Input: one array (the palyer and the computer's cashes);
// Output: a number (1 or 2 or 3)
int cal(int cash[]) {
  int total_assets[2],totalland[2];

  total_assets[0] = cash[0];
  total_assets[1] = cash[1];

  for (int j = 0; j < 17;j++) {
    if (map[j].owner == "Player") {
      total_assets[0] += map[j].value;
    }
    else if (map[j].owner == "Computer") {
      total_assets[1] += map[j].value;
    }
  }

  if (total_assets[0] > total_assets[1]) {
    return 1;
  }
  else if (total_assets[0] < total_assets[1]) {
    return 2;
  }
  else {
    return 3;
  }
}

// Function to print out the ending for wining
// Input: none
// Output: print out the ending for wining
void win() {
  int b;

  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                         MONOPOLY                                       |" << endl;
  cout << "|                                        *  WIN   *                                      |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                           Congradulation! You just win the game!                       |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;

  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                      *  GOOD END  *                                    |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|     You proved your excellence and competency to the richest man by your victory.      |" << '\n';
  cout << "|     The richest man then made good on his promise. You inherited his fortune and       |" << '\n';
  cout << "|     became the richest person in the world. You are happy, but sometimes you ask       |" << '\n';
  cout << "|     ask yourself: Is this really what you want?                                        |" << endl;
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << '\n';
  cout << "Enter any number + press the enter key to quit..." << "\n";

  cin >> b;
}

// Function to print out the ending for losing
// Input: none
// Output: print out the ending for losing
void lose() {
  int b;

  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                         MONOPOLY                                       |" << endl;
  cout << "|                                        *  LOSE  *                                      |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                  You just LOSE the game...                             |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;

  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                         BAD END                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|     The winner inherited the fortune and took over the business you own. You try to    |" << '\n';
  cout << "|     make a comeback, but the winner squelched your growth in the industry at every     |" << '\n';
  cout << "|     turn. It looks like you've passed the peak of your life and it's just downhill     |" << '\n';
  cout << "|     from here on out.                                                                  |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << '\n';
  cout << "Enter any number + press the enter key to quit..." << "\n";

  cin >> b;
}

// Function to print out the ending for a tie
// Input: none
// Output: print out the ending for a tie
void tie() {
  int b;

  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                         MONOPOLY                                       |" << endl;
  cout << "|                                        *  TIE   *                                      |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|             This is really an unexpected result. The game ended in a tie.              |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << '\n';
  cout << "Enter any number + press the enter key to continue..." << "\n";

  cin >> b;

  system("clear");

  cout << "+----------------------------------------------------------------------------------------+" << endl;
  cout << "|                                                                                        |" << endl;
  cout << "|                                      *  RARE END  *                                    |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "|      Although you didn't expect this ending, you and another candidate develop an      |" << '\n';
  cout << "|      appreciation for each other during the competition. Together, you inherited       |" << '\n';
  cout << "|      the richest man's fortune and business and continued to develop in the real       |" << '\n';
  cout << "|      estate industry.                                                                  |" << '\n';
  cout << "|                                                                                        |" << '\n';
  cout << "+----------------------------------------------------------------------------------------+" << endl;

  cout << '\n';
  cout << "Enter any number + press the enter key to quit..." << "\n";

  cin >> b;
}

int main() {
  int * position = new int [2];
  int * round = new int [2];
  int * cash = new int [2];
  int * len = new int [2];

  mainpage(position,cash,round,len);
  PrintBoard(cash,len,position);

  cout << '\n';
  cout << "You Are Here: " << map[position[0]].number << " ";
  cout << map[position[0]].name << '\n';
  cout << "Time Left: " << round[0] << " Months" << "\n";
  cout << '\n';
  cout << "Continue the game?" << '\n';
  cout << "(1) Continue  (2) Pause" << '\n';
  cout << "(3) Check the assets details" << '\n';

  // Continue the game unitll there's no time left or one goes bankruptcy
  while (round[0] != 0 && round[1] != 0 && cash[0] > 0 && cash[1] > 0) {
    ask(dice(position,cash,len,round),cash,len,round[0]);
    askcom(autodice(position,cash,len,round),cash,len,round[1]);
  }

  // Determine endings
  if (round[0] == 0 && round[1] == 0) {     // condition: no time left
    if (cal(cash) == 1) {
      win();
    }
    else if (cal(cash) == 2) {
      lose();
    }
    else {
      tie();
    }
  }
  else {                                    // there's still time left
    if (cash[0] >= 0 && cash[1] < 0) {     // but one/two goes bankruptcy
      win();
    }
    else if (cash[0] < 0 && cash[1] >= 0) {
      lose();
    }
    else {
      tie();
    }
  }

  delete [] position;                     // free the dynamic arrays
  delete [] round;
  delete [] cash;
  delete [] len;

	return 0;
}
