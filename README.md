<h1 align="center">Quarter Monkey Game · IUT de Paris - Rives de Seine</h1>

The "Quarter Monkey Game" GitHub project is a software that allows a group of players to play a game of Quarter Monkey. The application ensures adherence to the game's rules and manages the entire progression of the game until the announcement of the loser.

> [!IMPORTANT]  
> The project has been developed exclusively in a professional context, with the specific aim of promoting learning. It is carried out as a project for the University of Paris.

<p align="center">
  <img src="https://github.com/Corentin-Lcs/iut-quarter-monkey-game/blob/main/Quart_De_Singe.png" alt="Quart_De_Singe.png"/>
</p>

## Game Rules

Players take turns announcing a letter that completes a word. A player who gives a letter that ends an existing word (of more than two letters) loses the round and is rewarded with a quarter monkey. The current player having to announce a letter may prefer to ask the previous player which word they have in mind. If the previous player is unable to provide an existing word that is coherent with the letters already announced, he loses the round. Otherwise, it is the player who asked the question who loses the round. The first player to collect four quarters monkeys loses the game.

## Description

The application allows a minimum of two players to play a complete game. In order for a single player to practice, the application implements robot players who play automatically. The letters played by this type of player are not entered but displayed. They have access to the dictionary and are programmed to play optimally.

In the displays, players are designated by their order number (1, 2, etc.) and their nature (`H` for humans and `R` for robots). At each game turn, the current player's number, nature, and the letters already announced are displayed (e.g., `1H (ABAC) >`). The player enters either a letter of the alphabet (unaccented and in upper or lower case) to continue the letter chain, the character `?` to ask the previous player which word they have in mind, or the character `!` to give up the round (and receive a quarter monkey).

At the end of each round, the number of quarter monkeys for each player is displayed (e.g., `1H: 0.25; 2R: 0; 3H: 0.75; 4R: 0`). If no player has received four monkey quarters, the player who lost the last round starts the next one. Otherwise, the application displays "The game is over".

> To better understand the conditions and progress of a game, please consult the manual for the subject by clicking [here](https://github.com/Corentin-Lcs/iut-quarter-monkey-game/blob/main/Sujet.pdf).

## Usage

To compile the `*.cpp` files from the command prompt, run the following command :

```
g++ [source_code_name].cpp -o [executable_name]
g++ *.cpp -o singe
```

> For more details about the concept of compilation and compilers, here are some useful links :
>
> Link 1 : <https://perso.univ-lyon1.fr/jean-claude.iehl/Public/educ/gcc.html> [FR]
> 
> Link 2 : <https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html> [EN]
>          
> Link 3 : <https://www.cyberciti.biz/faq/compiling-c-program-and-creating-executable-file/> [EN]
>
> Link 4 : <https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052> [EN]
> 
> Link 5 : <https://gcc.gnu.org> [EN]

To launch the program from the command prompt, type the following command with the correct syntax :

```
singe.exe <H|R>...
```

To illustrate the execution, here are some examples :

```bash
singe.exe HH            # 2 Humans
singe.exe RR            # 2 Robots
singe.exe HR            # 1 Human / 1 Robot
singe.exe HRH           # 2 Humans / 1 Robot
singe.exe HRHHHRRHR     # 5 Humans / 4 Robots
```

> The `singe.exe` and `ods4.txt` files must be in the same directory to work.

## Project's Structure

```
iut-quarter-monkey-game/
├─ README.md
├─ LICENSE
├─ Sujet.pdf
├─ Sujet.tex
├─ Quart_De_Singe.png
└─ src/
   ├─ main.cpp
   ├─ singe.exe
   ├─ ods4.txt
   ├─ Dictionary.cpp
   ├─ Dictionary.h
   ├─ Game.cpp
   ├─ Game.h
   ├─ Player.cpp
   ├─ Player.h
   ├─ playerList.cpp
   ├─ playerList.h
   ├─ termcolor.hpp
   └─ ComponentTest/
      ├─ testDictionary.cpp
      ├─ testGame.cpp
      ├─ testPlayer.cpp
      └─ testPlayerList.cpp
```

Named `Sujet.pdf` (Subject.pdf), the file contains the subject of the project and is the compiled version of `Sujet.tex` (Subject.tex).

Named `singe.exe` (monkey.exe), the file is the program executable.

Named `ods4.txt`, the file contains 369 085 French words. It acts as a dictionary.

## Meta

Created by [@Corentin-Lcs](https://github.com/Corentin-Lcs). Feel free to contact me !

Distributed under the GNU GPLv3 license. See [LICENSE](https://github.com/Corentin-Lcs/iut-quarter-monkey-game/blob/main/LICENSE) for more information.
