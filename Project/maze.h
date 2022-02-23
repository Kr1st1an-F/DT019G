/*
Kristian Fatohi
2021-10-15
DT019G
Betyg C
Maze Projekt
*/

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>

class Maze{

public:

    //Constructor
    Maze();
    Maze(int Width,int Length);

    //Generate Funcitons
    void InsertNode();
    void DFSGenerate();

    //Solve Functions  
    void DFSSolve();

    //Check Functions
    bool IsInsideBody(int x, int y);
    bool IsNotVisited(int x, int y);

    //Print Functions
    void print();
    void printCellSymbol();

    //Getters
    int GetWidth();
    int GetLength();
    int GetStartY();
    int GetEndY();

private:

    int Width;
    int Length;

    struct coordinate{ //Coordinates for nodes
        int x;
        int y;
    };


    struct node{
        node();
        bool visited;
        char symbol;
        coordinate coord; //Coordinates of previous visited cell
    };

    friend bool operator==(coordinate &rhs, coordinate &lhs); //Operator overload

    void UnvisitVisitedNode();

    //Setters
    void SetStart();
    void SetEnd();
    void VisitWalls();
    int randomX();
    int randomY();

    void ChangeSymbol();

    void CheckDirection(coordinate x, coordinate y); //Checks to see what direction the neighbour is placed

    void printStack(std::stack<coordinate> S); //PrintAStack

    std::vector<coordinate> UnvisitNeighbour(int x, int y); //Unvisit the neighbours
    std::vector<coordinate> SelectNeighbours(int x, int y); //Returns a vector for a nodes neighbour:
    
    std::vector<std::vector<node>> Body; //2d vector to contain all nodes

};




#endif