# Simple Mine Sweeper Console Game

#### Note: 
- There is color while playing in the console to make things easier to read.
- If the unicode characters/colors don't show correctly in the console, try changing how the file is being encoded in your IDE/editor.

### Sample Game:
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
>20

Game mode chosen: Twenty Bombs

=== Game Instructions ===
- When you select the game mode, the bombs will be added to the board and it will be displayed like below.
- When the game starts, each position will contains a "█", which indicates an unopened position.
- You will then be asked to enter the position you would like to reveal. To enter a position, you have to enter the row number 
  followed by a space, followed by the column number.
- For example, to reveal the very first position on the board, which is the first row and the first column, you would enter: 1 1.
- When you reveal a position, you will see either an "X", which indicates a bomb, or a number from 1 -> 8 , depending on whether 
  there was a bomb in that position or not.
- If the position you reveal contains a number, these means that there are that many bombs touching that position. For example, 
  if you reveal a 3, this tells you that there are currently 3 bombs touching that position and can be anywhere in the eight 
  positions (three if it's a corner, five if it's a side, eight otherwise) around the position you opened.
- You must use the numbers you reveal to your advantage to navigate your way around the board.
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

Positions Opened: 0 | Positions Remaining: 36 | Number of Bombs: 20 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>1 2
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | 3 | █ | █ | █ | █ 
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

Positions Opened: 1 | Positions Remaining: 35 | Number of Bombs: 20 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>1 3
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | 3 | 2 | █ | █ | █ 
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

Positions Opened: 2 | Positions Remaining: 34 | Number of Bombs: 20 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>2 2
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | 3 | 2 | █ | █ | █ 
   ---+---+---+---+---+---
2|  █ | 5 | █ | █ | █ | █ 
   ---+---+---+---+---+---
3|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
4|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
5|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
6|  █ | █ | █ | █ | █ | █ 

Positions Opened: 3 | Positions Remaining: 33 | Number of Bombs: 20 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>1 5
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  █ | 3 | 2 | █ | 3 | █ 
   ---+---+---+---+---+---
2|  █ | 5 | █ | █ | █ | █ 
   ---+---+---+---+---+---
3|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
4|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
5|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
6|  █ | █ | █ | █ | █ | █ 

Positions Opened: 4 | Positions Remaining: 32 | Number of Bombs: 20 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>3 4
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  X | 3 | 2 | X | 3 | X 
   ---+---+---+---+---+---
2|  X | 5 | X | █ | X | █ 
   ---+---+---+---+---+---
3|  █ | X | X | X | X | █ 
   ---+---+---+---+---+---
4|  X | X | X | X | X | █ 
   ---+---+---+---+---+---
5|  █ | X | █ | X | X | █ 
   ---+---+---+---+---+---
6|  █ | █ | █ | X | █ | X 

Hard luck Liam you've just exploded! Game Over!
Score: 0

Would you like to play again Liam? (y/n)
>n

Thanks for playing Liam!
```
