/*
Kristian Fatohi
2021-10-15
DT019G
Betyg C
Maze Projekt
*/

#ifndef MENU_H
#define MENU_H

#include "maze.h"
#include <iostream>
#include <string>
#include <stdlib.h>


//Menu Functions
char StartingMenu();
char GenerateMenu();
char SolveMenu();
char EndMenu();

//Option Functions
void StartingOption(char choice);
void GenerateOption(char choice);
void SolveOption(char choice);
void EndOption(char choice);

//Input Check Funtions
char OptionCheck(char choice);
void SizeCheck(int &Width, int &Length);

//Run Functions
void SolveMaze(int x, int y);
void CreateMaze(int x, int y);

#endif