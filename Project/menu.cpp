/*
Kristian Fatohi
2021-10-15
DT019G
Betyg C
Maze Projekt
*/

#include "menu.h"
#include "maze.h"

//Menu Functions
char StartingMenu() {
    char choice;

    std::cout << "****************************************\n";
    std::cout << "*     Welcome to your own maze game    *\n";
    std::cout << "*       1. Generate a random maze.     *\n";
    std::cout << "*       2. Solve Maze with DFS         *\n";
    std::cout << "*       3. Exit.                       *\n";
    std::cout << "****************************************\n\n";
    std::cout << "Choose one option: ";
    std::cin >> choice;
    std::cout << "\n";
    choice = OptionCheck(choice);

    return choice;
}
char GenerateMenu() {
    char choice;

    std::cout << "****************************************\n";
    std::cout << "*            Generate Maze             *\n";
    std::cout << "*     1. Generate By User Size.        *\n";
    std::cout << "*     2. Generate By Default Size.     *\n";
    std::cout << "*     3. Go Back.                      *\n";
    std::cout << "****************************************\n\n";
    std::cout << "Choose one option: ";
    std::cin >> choice;
    std::cout << "\n";
    choice = OptionCheck(choice);

    return choice;

}
char SolveMenu() {
    char choice;

    std::cout << "****************************************\n";
    std::cout << "*             Solve Maze               *\n";
    std::cout << "*     1. Generate Maze By User Size.   *\n";
    std::cout << "*     2. Generate Maze By Default Size.*\n";
    std::cout << "*     3. Go Back.                      *\n";
    std::cout << "****************************************\n\n";
    std::cout << "Choose one option: ";
    std::cin >> choice;
    std::cout << "\n";
    choice = OptionCheck(choice);

    return choice;
}
char EndMenu() {
    char choice;

    std::cout << "***************************************\n";
    std::cout << "*              End Menu               *\n";
    std::cout << "*      1. Generate A New Maze.        *\n";
    std::cout << "*      2. Solve A New Maze.           *\n";
    std::cout << "*      3. Return To Start Menu.       *\n";
    std::cout << "***************************************\n\n";
    std::cout << "Choose one option: ";
    std::cin >> choice;
    std::cout << std::endl;
    choice = OptionCheck(choice);

    return choice;
}

//Options Functions
void StartingOption(char choice) {
    if(choice == '1'){
        char option = GenerateMenu();
        GenerateOption(option);

    }else if(choice == '2'){
        char choice = SolveMenu();
        SolveOption(choice);
    }else if(choice == '3')
    {
        std::cout << "Bye Bye\n";
        exit(1);
    }else
    {
        std::cout << "Error" << std::endl;
    }
}
void GenerateOption(char choice) {
    if (choice == '1')
    {
        int x,y;
        std::cout << "Your Maze Can Not Be In An Even Dimensional!";
        std::cout << "\nMaze Length: ";
        std::cin >> x;
        std::cout << "\nMaze Width: ";
        std::cin >> y;
        std::cout << std::endl;
        SizeCheck(x, y);
        std::cout << "Maze Size == " << x << "x" << y << std::endl;
        CreateMaze(x, y);

    }else if(choice == '2'){
        std::cout << "Maze Size == 11x11\n";
        CreateMaze(11, 11);

    }else if (choice == '3')
    {
        char option = StartingMenu();
        StartingOption(option);    
    }else
    {
        std::cout << "Error" << std::endl;
    }
    
    
}
void SolveOption(char choice) {
    if (choice == '1')
    {
        int x,y;
        std::cout << "Your Maze Can Not Be In An Even Dimensional!";
        std::cout << "\nMaze Width: ";
        std::cin >> x;
        std::cout << "\nMaze Length: ";
        std::cin >> y;
        std::cout << std::endl;
        SizeCheck(x, y);
        std::cout << "Maze Size == " << x << "x" << y << std::endl;
        SolveMaze(x, y);

    }else if(choice == '2'){
        std::cout << "Maze Size == 11x11\n";
        SolveMaze(11, 11);

    }else if(choice == '3'){
        char option = StartingMenu();
        StartingOption(option);
    }else
    {
        std::cout << "Error" << std::endl;
    }
}
void EndOption(char choice) {
    if(choice == '1'){
        char option = GenerateMenu();
        GenerateOption(option);
    }else if(choice == '2')
    {
        char option1 = SolveMenu();
        SolveOption(option1);
    }else
    {
        char option2 = StartingMenu();
        StartingOption(option2);    
    } 
}

//Input Check Functions
char OptionCheck(char choice) {
    int check = 0;
    
    while(check == 0){

        if(choice == '1' || choice == '2' || choice == '3'){
            break;
        }else
        {
            std::cout << "You have typed the wrong option, Try Again: ";
            std::cin >> choice;
        }
    }
    return choice;
}
void SizeCheck(int &Width, int &Length) {
    if(Width % 2 == 0 || Width <= 1 || Length % 2 == 0 || Length <= 1){
        std::cout << "Wrong Size for your maze, Try Again: " << std::endl << "Maze Width: ";
        std::cin >> Width;
        std::cout << "\nMaze Length: ";
        std::cin >> Length;
        SizeCheck(Width, Length);
    }
}

//Run Functions
void CreateMaze(int x, int y) {
    Maze first(x,y);
    char go;

    first.InsertNode();
    first.DFSGenerate();

    std::cout << "\n\n";
    std::cout << "Press 1 to continue: ";
    std::cin >> go;

    while(go != '1'){
        std::cout << "Wrong! Try again. Press 1 to continue: ";
        std::cin >> go;
    }

    char choice = EndMenu();
    EndOption(choice);
}
void SolveMaze(int x, int y) {
    Maze second(x,y);
    char go;

    second.InsertNode();
    std::cout << "\nMaze Before Being Solved With DFS\n";
    second.DFSGenerate();
    std::cout << "Maze After Being Solved With DFS\n";
    second.DFSSolve();
    
    std::cout << "\n\n";
    std::cout << "Press 1 to continue: ";
    std::cin >> go;

    while(go != '1'){
        std::cout << "Wrong! Try again. Press 1 to continue: ";
        std::cin >> go;
    }
    
    char choice = EndMenu();
    EndOption(choice);
}