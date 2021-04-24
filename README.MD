Project proposal

Game type: Monopoly Team Member: WANG Ziyu (UID: 3035777547)

Description of the game: You have been chosen by the richest person to enter his investment contest! He will give you and another candidate (the computer) a sum of money. Then whoever has the most assets by the deadline will inherit the richest person's fortune! Also, if one goes bankrupt, the other wins outright.

The player's main action in Monopoly is to roll a die, draw cards, purchase land, build houses, and upgrade houses. The game ends after certain months (rounds) chosen by the player (2 options provided: 12 months, 24 months). Meanwhile, the computer's action will be automatically conducted by the program.

Features plan to implement:

Rolling dice, drawing fate and chance cards (random event), identify the event occur, and implement them.
Calculate and compare the total assets (cash and the value of houses) of the player and the computer at the end of the game (if no one goes bankrupt).
Calculate and store the player's cash and the computer's cash.
Visualization of (1) the map, (2) the movement of pieces, (3) the purchase of land, setup of the house, and the upgrade of house.
Player's piece cannot overlap with computer's piece (prevent confusion of position).
The tolls will be determined according to the condition of the land.
The basic function of judging the outcome of the battle (Success conditon: (1) the computer goes bankrupt (total assets is 0) during the game; (2) the player has the highest total assets at the end of the game.)
Ability to pause and to restart the game
Capacity to determine the position of piece
Ability to purchase land, build house, and upgrade it
The roles of supported coding elements (1 to 5 listed under the coding requirements):

Generation of random game sets or events: · Random functions to conduct random events (srand(), the random number generator (RNG) rand()); The seed might be the value of the time that the system returns for the current time. Set specific numbers to label the events within if and random statements and execute the result.

Data structures for storing game status: · Employ "int Bank[2]" array to add up the cash and the value of the houses. · Adopt "int cash[2]" array, which can set up the same amunt of starting fund for both computer and player and will be updated during the game. · Employ if-else statement that if either computer or player step in others' houses, the fee is deducted from their cash array. Once there's no cash, the program will check the condition of the holding of lands. The property right of lands own could be sold to the bank in exchange of cash. · Employ for loop to continue the game when j<=n (n is the rounds of the game). When the deadline comes, the total assets will be calculated, then use an if-else statement to decide and output the winner. · Employ if-else statement to automatically add one block if player and computer overlap. · Use the add statement in the array and move the player and computer. Where they stand authomatically cout '1'.

Dynamic memory management: . Employ dynamic 2D arrays to make the system data storage flexible, prompting the efficiency of allowcating system resources.

File input/output: -input： · Using if-else statement to ask the player about his/her decision (want to purchase land, build house, or upgrade it). · Employ while loop, if the player press "Pause", then the game ends but the record of bank[2] and cash[2] and houses remains. when the player press "restart" then game starts again.

-output： · (1) Using cout or printf print the maps and setup in the screen; (2) when the piece move, it disapper in the previous block and appear in the new block; (3) If a land is bought, * (to represent the player) or # (to represent the computer) will be printed next to the related place's name. Also, if an house is upgraded, the number of * or # will increase. For example, if the player bought hku before, the display of the block is currently hku*. Then if the player decide to buid a house here, the display will be hku**. Furthely, if the player upgraded the house, the display will be hku***, which reaches the limit of developing the land.

Program codes in multiple files: · Set different functions for example getting random chance card or moving steps into different files to improve clarity and construction of the program.