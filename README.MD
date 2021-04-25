Project proposal

Game type: Monopoly 
Team Member: WANG Ziyu (my groupmate dropped the class so I'm now the only member)
UID: 3035777547

Description of the game (game story): 
You have been chosen by the richest person to enter his investment contest! He will give you and another candidate (the computer) a sum of money. Then whoever wins the game will inherit the richest person's fortune!
  
Game rules: 
(1) The palyer should enter a specific number + press the enter key to conduct certain actions. For example, there're the statements in the game:  
  
             (1) Continue  (2) Pause   -- '(1)': enter 1 + press the enter key           
                                       -- '(2)': enter 2 + press the enter key           
             (3) Check the assets details                                                
                                       -- '(3)': enter 3 + press the enter key           
                                                                                         
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
    2. If one goes bankrupt (i.e. cash own = 0), the other wins outright.  

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

The roles of supported coding elements (as only half of the code requirements are expected for a group of 1 member, you might mainly look at element 1, 2, and 4):
Element 1: Generation of random game sets or events
Features it supports: feauture 2 and 11
How: There're random functions to generate random events (using things like srand(), the random number generator (RNG) rand() with the current time as the seed); Set specific numbers to label the events geneated and latter use if statements/ switch statements to identify and execute the result.

Element 2: Data structures for storing game status
Features it supports: feauture 4, 5, 6, 7, 9, 12
How: 
s: · Employ "int Bank[2]" array to add up the cash and the value of the houses. · Adopt "int cash[2]" array, which can set up the same amunt of starting fund for both computer and player and will be updated during the game. · Employ if-else statement that if either computer or player step in others' houses, the fee is deducted from their cash array. Once there's no cash, the program will check the condition of the holding of lands. The property right of lands own could be sold to the bank in exchange of cash. · Employ for loop to continue the game when j<=n (n is the rounds of the game). When the deadline comes, the total assets will be calculated, then use an if-else statement to decide and output the winner. · Employ if-else statement to automatically add one block if player and computer overlap. · Use the add statement in the array and move the player and computer. Where they stand authomatically cout '1'.

Element 3: Dynamic memory management 
Features it supports: flexible allocation of space
How: Employing dynamic arrays like position, round, cash, and len to make the system data storage flexible, then free them at the end of the code, prompting the efficiency of allocating system resources.

Element 4: File input/output:
Features it supports: 
-input： · Using if-else statement to ask the player about his/her decision (want to purchase land, build house, or upgrade it). · Employ while loop, if the player press "Pause", then the game ends but the record of bank[2] and cash[2] and houses remains. when the player press "restart" then game starts again.

-output： · (1) Using cout or printf print the maps and setup in the screen; (2) when the piece move, it disapper in the previous block and appear in the new block; (3) If a land is bought, * (to represent the player) or # (to represent the computer) will be printed next to the related place's name. Also, if an house is upgraded, the number of * or # will increase. For example, if the player bought hku before, the display of the block is currently hku*. Then if the player decide to buid a house here, the display will be hku**. Furthely, if the player upgraded the house, the display will be hku***, which reaches the limit of developing the land.

Element 5: Program codes in multiple files
· Set different functions for example getting random chance card or moving steps into different files to improve clarity and construction of the program.
