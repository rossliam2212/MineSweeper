# Simple Mine Sweeper Console Game

### Sample Game:
#### Note: 
- There is color while playing in the console to make things easier to read.
- If the unicode characters/colors don't show correctly in the console, try changing how the file is being encoded in your editor.

```
Enter your name: 
>Liam

===== Welcome to Mine Sweeper Liam =====

What would you like to do?
	1 - Play Mine Sweeper
	2 - View previous game wins
2

-----------------------------
| Game Mode         |  Wins |
--------------------+--------
| One Bomb          |  0 |
| Three Bombs       |  0 |
| Five Bombs        |  0 |
| Ten Bombs         |  0 |
| Twenty Bombs      |  0 |
| Thirty Five Bombs |  0 |
-----------------------------

What would you like to do?
	1 - Play Mine Sweeper
	2 - View previous game wins
1

Here are the game modes:
	- One Bomb
	- Three Bombs
	- Five Bombs
	- Ten Bombs
	- Twenty Bombs
	- Thirty Five Bombs

Which would you like to play? (1/3/5/10/20/35)
>35

Game mode chosen: Thirty Five Bombs

=== Game Instructions ===
- When you select the game mode, the bombs will be added to the board and it will be displayed like below.
- When the game starts, each position will contains a "█", which indicates an unopened position.
- You will then be asked to enter the position you would like to reveal. To enter a position, you have to enter the row number 
  followed by a space, followed by the column number.
- For example, to reveal the very first position on the board, which is the first row and the first column, you would enter: 1 1.
- When you reveal a position, you will see either an "X", which indicates a bomb, or a number from 1 -> 9, depending on whether 
  there was a bomb in that position or not.
- If you reveal a bomb (X), the game is over!

    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
2|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
3|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
4|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
5|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
6|  █ | █ | █ | █ | █ | █ 

Ready to play? (y/n)
>y

=== Game Started. Good Luck! ===

    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
2|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
3|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
4|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
5|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
6|  █ | █ | █ | █ | █ | █ 

Positions Opened: 0 | Positions Remaining: 36 | Number of Bombs: 35 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>2 5
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
2|  █ | █ | █ | █ | 1 | █ 
   ---+---+---+---+---+---
3|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
4|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
5|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
6|  █ | █ | █ | █ | █ | █ 

Congratulations You Win Liam!!!
Score: 0

Here were the bomb positions:
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  X | X | X | X | X | X 
   ---+---+---+---+---+---
2|  X | X | X | X | 1 | X 
   ---+---+---+---+---+---
3|  X | X | X | X | X | X 
   ---+---+---+---+---+---
4|  X | X | X | X | X | X 
   ---+---+---+---+---+---
5|  X | X | X | X | X | X 
   ---+---+---+---+---+---
6|  X | X | X | X | X | X 

Would you like to play again Liam? (y/n)
>n

Thanks for playing Liam!

```
