#include "Functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

/*
    Converts all chars in a string to an uppercase
*/
void convert (std::string& small) 
{

    for(int a = 0; a< small.length(); a++){
        small[a] = toupper(small[a]);
    }

}

/*
    To test if a string is correct formitted
*/
std::string namn_fel(std::string& namn)
{
    char c;
    // Iterate through the string one letter at a time.
    for (int i = 0; i < namn.length(); i++) 
    {    
        c = namn.at(i);         // Get a char from string

            // if it's NOT within these bounds, then it's not a character
        if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ))) 
        {

            std::cout << "Du har matat in annat än bokstäver. Prova igen: ";
            std::cin >> namn;
            namn_fel(namn);
            
        }
        else
        {
            continue;
        }
    }
    for(int k = 0; k < 1; k++){ //Converts the first char into a uppercase
        namn[k] = toupper(namn[k]);
    }

    return namn;        
}

/*
    To test if a string is correct formitted
*/
std::string city_fel(std::string stad)
{
    char c;
    // Iterate through the string one letter at a time.
    for (int i = 0; i < stad.length(); i++) 
    {    
        c = stad.at(i);         // Get a char from string

            // if it's NOT within these bounds, then it's not a character
        if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || (c == ' '))) 
        {

            std::cout << "Du har matat in siffror. Prova igen: ";
            std::cin >> stad;
            city_fel(stad);
        }
        else
        {
            continue;
        }
    }
    return stad;        
}

int menu()
{
    /*
        DEN FINA MENYN.
    */
    char val;


    std::cout << "****************************************\n";
    std::cout << "*   Välkommen till din egna sökmotor   *\n";
    std::cout << "*       1. Skriv in Personnummer.      *\n";
    std::cout << "*       2. Skriv in Stad.              *\n";
    std::cout << "*       3. Avsluta.                    *\n";
    std::cout << "****************************************\n\n";
    std::cout << "Mata in ditt alternativ: ";
    std::cin >> val;
    std::cout << "\n\n";

    return val; //returnar valet man matat in.
}

