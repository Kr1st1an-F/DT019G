#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "L2.h"

void print_list(linked_list l){
    l.print_list();
}

linked_list merge(linked_list& l, linked_list& l2){
    linked_list mergedlist;
    while (!l.is_empty() && !l2.is_empty())
    {
        if (l.front() <= l2.front())
        {
            mergedlist.push_back(l.pop_front());
            
        }else
        {
            mergedlist.push_back(l2.pop_front());
        }
        
    }

    while (!l2.is_empty())
    {
        mergedlist.push_back(l2.pop_front());
    }
    

    while (!l.is_empty())
    {
        mergedlist.push_back(l.pop_front());
    }
    

    return mergedlist;
}

bool isSorted(linked_list& l){
    for(int i =0; i < (l.size()-1);i++){
        if(l.at(i) > l.at(i + 1)){
            return false;
        }
    }
    return true;
}

int main(){
    linked_list first;
    linked_list second;
    linked_list third;
    linked_list fourth;

    //1
    int randomNumber = 0;
    int randomNumber2 = 0;
    for(int i = 0; i < 50; i++){
        int limit, limit2;
        limit = std::rand()%5;
        limit2 = std::rand()%5;
        first.push_back(randomNumber); 
        second.push_back(randomNumber2);
        randomNumber += limit;
        randomNumber2 += limit2;
    }

    
    
    //2
    if(first.at(24) > second.at(24)){
        std::cout << "First list har den största talet lagrat på 25:te platsen och är nu en node mindre" << std::endl;
        first.remove(24); 
    }else if(first.at(24) < second.at(24)){
        std::cout << "Second list har den största talet lagrat på 25:te platsen och är nu en node mindre" << std::endl;
        second.remove(24);
    }else
    {
        std::cout << "First och Second har lika stort värde på talet lagrat på 25:te platsen så jag väljer att ta bort en node från First listan" << std::endl;
        first.remove(24);
    }
   
    //3 
    if (first.size() < second.size())
    {
        std::cout << "Third listan blir deklarerad av First listan då den är mindre." << std::endl;  
        third = first;
    }else
    {
        std::cout << "Third listan blir deklarerad av Second listan då den är mindre." << std::endl;
        third = second;
    } 
    
    //4 
    if (first.size() < second.size())
    {
        std::cout << "Vi tar bort vartannat element från Second list då den fortfarande har 50 element" << std::endl;
        for(int i = 0; i < 25; i++){
            second.pop_back();
            second.push_front(second.pop_back());
        }
    }else
    {
        std::cout << "Vi tar bort vartannat element från First list då den fortfarande har 50 element" << std::endl;
        for(int i = 0; i < 25; i++){
            first.pop_back();
            first.push_front(first.pop_back());
        }
    }

    //5
    if (first.size() < second.size())
    {
        std::cout << "Listan som skrivs ut är den halverade listan, i detta fall är det First" << std::endl;
        print_list(first);
    }else
    {
        std::cout << "Listan som skrivs ut är den halverade listan, i detta fall är det Second" << std::endl;
        print_list(second);
    }
    
    //6
    fourth = merge(first, second);

    //7
    if(isSorted(fourth) == true){
        std::cout << "Mergade filen är sorterad" << std::endl;
    }else
    {
        std::cout << "Mergade filen är ej sorterad" << std::endl;
    }
 
    return 0;
}