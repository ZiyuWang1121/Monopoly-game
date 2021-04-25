Project proposal

Game type: Monopoly 
Team Member: WANG Ziyu (my groupmate dropped the class so I'm now the only member)
UID: 3035777547

Compilation and execution instructions:
(1) The SSH Client, Command Prompt, introduced in module 0 is recommanded for playing the game
(2) Sever used for testing: academy11 server
(3) To compile and run the new monopoly program, we need to input command:
$ g++ -pedantic-errors -std=c++11 monopoly_main.cpp select_round.cpp rule.cpp -o monopoly
$ ./monopoly

Problem statement:
I chose this topic because it is both challenging and too interesting for me to give up. A monopoly game appears that it will made with many programming knowledge involved, which can furthely cultivate my understanding in this couse. Meanwhile, I used to play monopoly in my childhood and I'm familiar with it. It feels fun to make a similar game appears in the screen.

Game concept:
Monopoly here is a text-based game, which only requires an individual player to trigger events and make choices. Contestants gain setup money in the game, and by chance and trading strategies to buy land and upgrade it to earn toll. There are now three game endings for player to explore.

Description of the game (game story): 
You have been chosen by the richest person to enter his investment contest! He will give you and another candidate (the computer) a sum of money. Then whoever wins the game will inherit the richest person's fortune!
  
Game rules: 
(1) The palyer should enter a specific number + press the enter key to conduct certain actions. For example, there're the statements in the game:  
  
             (1) Continue  (2) Pause   -- '(1)': enter 1 + press the enter key           
                                       -- '(2)': enter 2 + press the enter key           
             (3) Check the assets details                                                
                                       -- '(3)': enter 3 + press the enter key           
 
Other places needed input from the player but don't appear in this form will come with instruction measages. 
(2) In this game, the player can roll a die, draw cards, purchase land, and upgrade it (start with 0, The maximum level of land is 2). Meanwhile, the computer's action will be automatically conducted by the program.
(3) The palyer can check the assets details for him/her and the computer at his/her turn by enter 3 + press the enter key.
(4) The palyer can check the game description and game rules in the pause page at his/her turn.
(5) The player's chess in the map is 'A' and computer's chess is 'B'.
(6) If you are at a computer-owned land, you will have to pay a toll, and vice versa.
(7) The amount of toll will be 0.1 * current land value. You can upgrade the land to increase its value and get more toll (charge for leveling up: 0.3 * current land value). 
(8) The game ends after certain months (rounds) chosen by you. 3 options are provided in the begining of a new game: 12 months, 24 months, 36 months.
(9) Meanwhile, the computer's action will be automatically conducted by the program.
(10) Wining conditions (Achieving any of the following terms is considered a victory): 
    1. Having the most assets (cash + value of housing properties) when there's no time left (i.e. Months = 0). 
    2. If one goes bankrupt (i.e. cash own < 0), the other wins outright.  

Game features implemented:
(1) The player can choose to start a new game or continue the last saved game.
(2) The player/ the computer can roll dice, draw fate cards (random events). The event occur will be indentified and implemented.
(3) Calculate and store the cashes for both the player and the computer.
(4) Calculate and store the information of the lands (including the lands' serial codes, name of the lands, level of the lands, owner of the lands, and the value of the lands)  for both the player and the computer.
(5) The palyer can check the assets details for him/her and the computer at his/her turn.
(6) At the player's turn, the player can also save and quit the current game, quit the game directly, continue the game, or check the game description and game rules in the pause page.
(7) Visualization of: 1. the map, 2. the movement of pieces, 3. the purchase and upgrade of land
(8) Player's piece cannot overlap with computer's piece (prevent confusion of position).
(9) Capacity to determine the position of piece
(10) Capacity to determine the time left
(11) Ability to purchase and upgrade land (the computer's decision will be randomly and automatically generated)
(12) Enabling the player and the computer to pay tolls when they pass another's lands. The tolls will be determined according to the condition of the land.
(13) Calculate and compare the total assets (cash and the value of lands) of the player and the computer at the end of the game (if no time left).
(14) The basic function of judging the outcome of the battle (Success conditon: (1) the computer goes bankrupt (cash is 0) during the game; (2) the player has the highest total assets at the end of the game.)
(15) Distinguish the player and the computer's turn by using different colors for them (black: player, purple: computer).
(16) Player can select the game mode at the start of a new game. 3 options are provided in the begining of a new game: 12 months, 24 months, 36 months.

The roles of supported coding elements:
Element 1: Generation of random game sets or events
Features it supports: feauture 2 and 11
How: There're random functions to generate random events (using things like srand(), the random number generator (RNG) rand() with the current time as the seed); Set specific numbers to label the events geneated and latter use if statements/ switch statements to identify and execute the result.

Element 2: Data structures for storing game status
Features it supports: feauture 2, 3, 4, 5, 7, 9, 10, 11, 12, 13, and 14
How: After the input from the file "map.txt"/"save.txt", the map and assets related informaion are stored using struct and dynamic arrays (e.g.the cash array stores the set up the same amunt of starting fund for both computer and player if this is a new game). There're latter modifications on them as the game process (like encounter a random event, buy land, and pay toll). For example, if the player roll the dice, the result will be processed in array position. The chess piece will then move,; it can disapper in the previous block and appear in the new block. Another example: If a land is bought/upgraded, its information will be recored/changed in the buyer's column in the check assets detail page. And when a land is upgraded, its level and value will increase. Changes like that are shown in the map page or check assets detail page using cout. Also, if either computer or player step in others' houses, the fee is deducted from their cash array. A while loop are monitoring the time left and cash left to continue the game. There are other arrays like total_assets[2], which will store the calculation result for the total assets (the cash and the value of the lands) at the end of the game, then if-else statements are used to decide and output the corresponding ends. 

Element 3: Dynamic memory management 
Features it supports: 2, 3, 5, 7, 9, 10, 11, 12, 13, and 14
How: Employing dynamic arrays like position, round, cash, and len to make the system data storage flexible, then free them at the end of the code, prompting the efficiency of allocating system resources.

Element 4: File input/output:
Features it supports: feature 1, 6
How: Depending on the player's choice, the map and assets related informaion are read and store from the text file (Start a new game: "map.txt"; continue the last game: "save.txt", if there is an archive). The player can choose to save and quit the game in the pause page. The player quit the game, but the data are saved. The current map and assets related information are read from the data structures and store in the file "save.txt" (create a new one if there's none, shroud the previous one if the file already exists). 

Element 5: Program codes in multiple files
Features it supports: feature 6, 16
How: The function "select_round" and "rule" are displayed in other files other than the main file to improve clarity and construction of the program. As the game rules shown and the mode selected have to be updated oftently, it's nice to put it in a seperate file and later link all the program codes together in the compilation. That way we don't accidentally delete other important code. 
