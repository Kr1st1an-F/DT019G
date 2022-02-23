/*
Kristian Fatohi
2021-10-15
DT019G
Betyg C
Maze Projekt
*/


//Checka srand()

#include "maze.h"
#include "menu.h"

/*
    Operator== overloading
*/
bool operator==(Maze::coordinate &lhs, Maze::coordinate &rhs) {
    if((lhs.x == rhs.x) && (lhs.y == rhs.y)){
        return true;
    }
    return false;
}

//Default Constructor
Maze::Maze(){
    Length = 11;
    Width = 11;
}

//Constructor With Parametres, To Input
Maze::Maze(int Length, int Width) {
    this->Length = Length;
    this->Width = Width;
}

//Generating Functions
void Maze::InsertNode() {
    for(int i = 0; i < GetWidth(); i++){
        std::vector<node> BodyRow;
        for(int j = 0; j < GetLength(); j++){
            BodyRow.push_back(node());
        }
        Body.push_back(BodyRow);
    }
}
void Maze::DFSGenerate() {
    srand(time(NULL));
    std::stack<coordinate> s;
    std::vector<coordinate> neighbours;
    coordinate n;
    SetStart();
    n.x = randomX();
    n.y = randomY();

    Body[n.x][n.y].visited = true;

    s.push(n);
    while (!s.empty())
    {
        n = s.top();
        neighbours = SelectNeighbours(n.x, n.y);
        if(!neighbours.empty()){
            int randomNeighbour = rand() % neighbours.size();
            coordinate randomN = neighbours[randomNeighbour];

            if (n.y != randomN.y) //A chech to see which direction the neighbour is in
            {
                if (n.y < randomN.y)
                {
                    Body[n.x][n.y+1].visited = true;

                }else
                {
                    Body[n.x][n.y-1].visited = true;
                }  
            }else
            {
                if (n.x < randomN.x)
                {
                    Body[n.x+1][n.y].visited = true; 

                }else
                {
                    Body[n.x-1][n.y].visited = true;
                } 
            }
            Body[randomN.x][randomN.y].visited = true;
            s.push(randomN);

        }else {
            s.pop();
        }
    }
    SetEnd();
    ChangeSymbol(); //To Make Paths Of The Visited Nodes
    print();
    std::cout << "\n\n";
}

//Solving Functions
void Maze::DFSSolve() {
    srand(time(NULL));
    VisitWalls(); //Visit Walls
    UnvisitVisitedNode(); //Unvisit nodes
    std::stack<coordinate> S; 
    std::vector<coordinate> V;

    coordinate N; //Node that will travel from Start -> End
    coordinate Start; //Declare Start Node
    Start.x = GetWidth()-2;
    Start.y = GetStartY();

    coordinate End; //Declare End Node
    End.x =  1;
    End.y = GetEndY();

    S.push(Start); //Push Start Node

    while (!S.empty())
    {
        N = S.top();
        Body[N.x][N.y].visited = true;

        V = UnvisitNeighbour(N.x, N.y); //Get the unvisited neighbours from node N

        if (N == End){
            std::cout << std::endl;
            S.push(N); //Push Last Node In Stack, You're Done.
            break;
        }
        if (!V.empty()){
            for(int i = 0; i < V.size(); i++){
                S.push(V[i]); //Push All Neighbours To Stack
            }
            Body[N.x][N.y].symbol = '/';
        }
        else{ // Backtracking When An End Has Been Hit
            Body[N.x][N.y].symbol = ' ';
            S.pop();
        }      
    }

    Body[N.x][N.y].symbol = '/';

    print();
    if (S.empty()) //:(
    {
        std::cout << "No solution found for this Maze!" << std::endl;
    } 

}

//Set Functions
void Maze::SetEnd() {
    int tempcord = 1 + rand() % (GetLength() - 2); //1-(1-EndWall)
    while(tempcord % 2 == 0){
        tempcord = 1 + rand() % (GetLength() - 2);
    }
    Body[0][tempcord].symbol = 'E';
    Body[0][tempcord].visited = true;

}
void Maze::SetStart() {
    int tempcord = 1 + rand() % (GetLength() - 2); //1-(1-EndWall)
    
    while(tempcord % 2 == 0){
        tempcord = 1 + rand() % (GetLength() - 2);
    }

    Body[GetWidth() - 1][tempcord].symbol = 'S';
    Body[GetWidth() - 1][tempcord].visited = true;

}
void Maze::VisitWalls() {
    for(int i = 0; i < GetWidth(); i++){
        for(int j = 0; j < GetLength(); j++){
            if (Body[i][j].symbol == '*') //Make Walls Visited
            {
                Body[i][j].visited = true;
            }  
        }
    }
}
int Maze::randomX() {
    int r = rand() % (GetWidth() - 2) +1;
    while (r % 2 == 0)
    {
        r = rand() % (GetWidth() - 2) +1; //Random X Coordinate, Not Even
    }
    
    return r;
}
int Maze::randomY() {
    int r = rand() % (GetLength() - 2) +1;
    while (r % 2 == 0)
    {
        r = rand() % (GetLength() - 2) +1;  //Random Y Coordinate, Not Even
    }
    
    return r;
}

//Get Functions
int Maze::GetWidth() {
    return this->Width;
}
int Maze::GetLength() {
    return this->Length;
}
int Maze::GetStartY() {
    int y;

    for(y = 1; y < GetLength(); y++){ //Try To Find Start Y Coordinate
        if(Body[GetWidth() - 1][y].symbol == 'S'){
            break;
        }
    }
    return y;
}
int Maze::GetEndY() {
    int y;
    for(y = 1; y < GetLength(); y++){ //Tru To Find End Y Coordinate
        if(Body[0][y].symbol == 'E'){
            break;
        }
    }
    return y;
}

//Print Functions
void Maze::print() {
    for(int i = 0; i < GetWidth(); i++){
        for(int j = 0; j < GetLength(); j++){
            std::cout << Body[i][j].symbol;
        }
        std::cout << std::endl;
    }
}
void Maze::ChangeSymbol() {
    for(int i = 0; i < GetWidth(); i++){
        for(int j = 0; j < GetLength(); j++){
            if(Body[i][j].visited == true && Body[i][j].symbol == '*'){
                Body[i][j].symbol = ' ';
            }   
        }
    }
}
void Maze::printCellSymbol() {
    for(int i = 0; i < GetWidth(); i++){
        for(int j = 0; j < GetLength(); j++){
            if (Body[i][j].visited == false)
            {
                std::cout << "(" << i << "," << j << ") is not visited" << std::endl;
            }else
            {
                std::cout << "(" << i << "," << j << ") is visited" << std::endl;
            }
        }
    }    
}
void Maze::printStack(std::stack<Maze::coordinate> S) {
    if (S.empty())
    {
        return;
    }

    coordinate N = S.top();

    S.pop();

    printStack(S);

    std::cout << "(" << N.x << " , " << N.y << ")" << std::endl;

    S.push(N);
    
}

//Check Functions
void Maze::UnvisitVisitedNode() {
    for(int i = 0; i < GetWidth(); i++){
        for(int j = 0; j < GetLength(); j++){ //Makes Paths And Start/End Nodes Unvisited, FOR Solving
            if(Body[i][j].symbol == ' '){
                Body[i][j].visited = false;
            }
        }
    }
}
bool Maze::IsInsideBody(int x, int y) {
    if(x <= 0 || x >= (GetWidth()-1) || y <= 0 || y >= (GetLength()-1)){//Is Node Inside Walls????
        return false;

    }
    return true;
}
bool Maze::IsNotVisited(int x, int y) {
    if(Body[x][y].visited == true){
        return false;
    }
    return true;
}

//Vector Functions
std::vector<Maze::coordinate> Maze::UnvisitNeighbour(int x, int y) {
    std::vector<coordinate> neighbour; //Return This Container

    if(IsInsideBody(x, y - 1) && IsNotVisited(x, y - 1)){ //Is Visited(Unvisited) "Neighbour" Valid?
        neighbour.push_back({x, y - 1});
    }
    if(IsInsideBody(x, y + 1) && IsNotVisited(x, y + 1)){
        neighbour.push_back({x, y + 1});
    }
    if(IsInsideBody(x - 1, y) && IsNotVisited(x - 1, y)){
        neighbour.push_back({x - 1, y});
    }
    if(IsInsideBody(x + 1, y) && IsNotVisited(x + 1, y)){
        neighbour.push_back({x + 1, y});
    }
    
    return neighbour;
}
std::vector<Maze::coordinate> Maze::SelectNeighbours(int x, int y) {
    
    std::vector<coordinate> neighbours; //Returning this vector

    if(IsInsideBody(x, y - 2) && IsNotVisited(x, y - 2) ){ //Is Neighbour Valid?
        neighbours.push_back({x, y-2});
    }
    if(IsInsideBody(x, y + 2) && IsNotVisited(x, y + 2)){
        neighbours.push_back({x, y +2});
    }
    if(IsInsideBody(x - 2, y) && IsNotVisited(x - 2, y)){
        neighbours.push_back({x - 2, y});
    }
    if(IsInsideBody(x + 2, y) && IsNotVisited(x + 2, y)){
        neighbours.push_back({x + 2, y});
    }

    return neighbours;
}

//Constructor
Maze::node::node() {
    visited = false;
    symbol = '*';
    coord.x = 0;
    coord.y = 0;
}