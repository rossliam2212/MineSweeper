# Simple Mine Sweeper Console Game

### Sample Game:
##### Note: There is color while playing in the console to make things easier to read.

```
Enter your name: 
>Liam

===== Welcome to Mine Sweeper Liam =====

Here are the game modes:
	- One Bomb
	- Three Bombs
	- Five Bombs
	- Ten Bombs
	- Twenty Bombs
	- Thirty Five Bombs

Which would you like to play? (1/3/5/10/20/35)
>10

Game mode chosen: Ten Bombs

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

=== Game Started ===

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

Positions Opened: 0 | Positions Remaining: 36 | Number of Bombs: 10 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>1 1
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  1 | █ | █ | █ | █ | █ 
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

Positions Opened: 1 | Positions Remaining: 35 | Number of Bombs: 10 | Score: 0

Enter the position you want to reveal.
Make sure to enter in the format - [Row] [Space] [Column]
>1 4
    1 | 2 | 3 | 4 | 5 | 6 
                          
1|  1 | X | X | X | X | █ 
   ---+---+---+---+---+---
2|  █ | █ | █ | █ | █ | X 
   ---+---+---+---+---+---
3|  █ | █ | █ | █ | █ | X 
   ---+---+---+---+---+---
4|  █ | █ | █ | █ | █ | █ 
   ---+---+---+---+---+---
5|  █ | █ | █ | █ | █ | X 
   ---+---+---+---+---+---
6|  █ | X | █ | X | █ | X 

Hard luck you've just exploded! Game Over!

```
