/* 
Kristian Fatohi
2021-04-03
ObjektBaserad Programmering
L1
*/
#include "Functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


struct address {
    std::string street;
    int zip;
    std::string city;
};

struct person {
    std::string name;
    std::string id;
    address location;
};

// operatoröverlagring
std::istream& operator>>(std::istream& in, person& p){
    std::getline(in, p.name);
    std::getline(in, p.id);
    std::string a, b, c;
    std::getline(in, a);
    int hitta = a.find(','); //Find the index where , is located and store it in integral variable
    p.location.street = a.substr(0, hitta); //substring that only gets the start of line til it finds ,
    b = a.substr((hitta + 2), (a.length()-1)); // Substring that only gets zip code
    c = b;
    b.erase(remove_if(b.begin(), b.end(), isspace), b.end()); //Removes spaces
    p.location.zip = std::stoi(b); // String to int
    p.location.city = c.substr(8, (c.length()-1));

    return in;
}

std::ostream& operator<<(std::ostream& os, person n){


    os << n.id << ", " << n.name << ", " << n.location.city << std::endl;

    return os;
}

std::vector<person> read_file(std::string);
size_t find_in_names(std::vector<person>, std::string);
std::vector<person> find_person_from_city(std::vector <person>);

int main()
{
    std::vector<person> haystack;
    std::string sok;
    char alternativ;
    do
    {
        
        alternativ = menu();
        switch (alternativ)
        {
        case '1': 
            std::cout << "Mata in namnet: ";
            std::cin >> sok;
            namn_fel(sok);
            find_in_names(read_file("names.txt"), sok);
            break;
        case '2': find_person_from_city(read_file("names.txt"));
            break;
        case '3':     
            exit(1);
        default: 
            std::cout << alternativ << " är ej ett alternativ!\n\n\n";
            main();
        }
    } while (false);

    return 0;

}

std::vector<person> read_file(std::string filename)
{
    std::vector<person> listOfP;
    std::ifstream infil(filename);
    person b;
    std::string sok;
    while (!infil.eof()) //Iterate trough the infile and push_back from operatoröverlagringen
    {
        infil >> b;
        listOfP.push_back(b);
    }

    return listOfP;
}

size_t find_in_names(std::vector<person> haystack, std::string name_part)
{
    static const size_t npos =-1; //define an undefined variable
    int antal = 0;
    int val = 0; 
    std::string sok;
    for(person look: haystack){ //iterate through the vector haystack
        if (look.name.find(name_part) != npos)
        {
            std::cout << look << std::endl;
            antal++;
        }
    }
    std::cout << antal << " antal matchningar hittades\n\n";

    while(val == 0) // 
    {
        std::cout << "Skulle du vilja söka efter fler?, 1. Ja 2. Nej: ";
        std::cin >> val;
        if (val == 1)
        {
            std::cout << "Mata in namnet: ";
            std::cin >> sok;
            namn_fel(sok);
            find_in_names(read_file("names.txt"), sok); 
        }
        else if (val == 2)
        {
            std::cout << std::endl;
            main();
        }
        else
        {
            std::cout << "Du har matat in fel alternativ. Prova igen\n";
            val = 0;
            continue;
        }
    }
    
    
     
    
    return 0;
}

std::vector<person> find_person_from_city(std::vector <person> haystack)
{
    int val;
    std::string sok, sok2, stad;
    std::cout << "Mata in staden: ";
    std:: cin >> sok >> sok2;
    stad = sok + " " + sok2;
    city_fel(stad);
    convert(stad);

    for(person state: haystack){ //iterate through the vector haystack
        if(state.location.city == stad)
        {
            std::cout << state;
            std::cout << "\n";
        }else
        {
            continue;
        }
        
    }

    while(val == 0)
    {
        std::cout << "Skulle du vilja söka efter fler?, 1. Ja 2. Nej: ";
        std::cin.ignore();
        std::cin >> val;
        if (val == 1)
        {
            find_person_from_city(read_file("names.txt")); 
        }
        else if (val == 2)
        {
            std::cout << std::endl;
            main();
        }
        else
        {
            std::cout << "Du har matat in fel alternativ. Prova igen\n";
            val = 0;
            continue;
        }
    }

    return std::vector<person>();
}
