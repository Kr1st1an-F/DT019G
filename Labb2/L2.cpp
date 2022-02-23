#include "L2.h"
#include <iostream>

/*
    Creating an empty list
*/
linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}

/*
    Erases Objects
*/
linked_list::~linked_list(){
}

/*
    A check if a list is empty, by checking size() value
*/
bool linked_list::is_empty() const{
    if(size() == 0){
        return true;
    }

    return false;
}

/*
    Adding an element (value) to the end of a list
*/
void linked_list::push_back(double value){
    node* n = new node(value); //Pointer N points at value 
    if (head == nullptr) //A check when list is empty
    {
        head = n;
        tail = n;

    }else if ((head != nullptr) && (head->next == nullptr)) //A Check if list has one element
    {
        head->next = n;
        tail = n;
        tail->prev = head;
    }else
    {
        node* temp;
        for(temp = head; temp->next != nullptr; temp = temp->next){ ; } //Iterate to tail pointer
        temp->next = n;
        tail = n;
        tail->prev = temp;
    }
} 

/*
    Adding an element (value) to the front of a list
*/
void linked_list::push_front(double value){
    node* n = new node(value);
    if (head == nullptr)//A check when list is empty
    {
        head = n;
        tail = n;
    }else if ((head != nullptr) && (head->next == nullptr))//A check when list has one element
    {
        tail->prev = n;
        head = n;
        head->prev = nullptr;
        head->next = tail;
    }else
    {
        head->prev = n;
        n->next = head;
        head = n;
    }  
}

/*
    Prints out a list
*/
void linked_list::print_list(){
    for(node* pt = head; pt != nullptr; pt = pt->next){ //Iterate from head to tail
        std::cout << pt->value << std::endl;
    }
}

/*
    Prints out a list in reverse
*/
void linked_list::print_reverse() const{
    for(node* pt = tail; pt != nullptr; pt = pt->prev){ //Iterate from tail to head
        std::cout << pt->value << std::endl;
    }
}

/*
    Creating a new node
*/
linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

/*
    Return the value in which position it lays in
*/
double linked_list::at(size_t pos) const{
    double counter = 0;
    node* temp = head;
    for(temp = head; counter < pos; temp = temp->next){//Iterate from head to the desired pos
        counter++;
    }
    return temp->value;
}

/*
    Removes the value in which position it lays in
*/
void linked_list::remove(size_t pos){
    double counter = 0;
    node* temp = head;
    for(temp = head; counter < pos; temp = temp->next){//Iterate from head to desired pos
        counter++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

/*
    To make an already created list to match another list by using =
*/
linked_list& linked_list::operator=(const linked_list &rhs){
    if(this == &rhs){ //avoiding self-assignment , To check if both list is already the same
        return *this;
    }
    while (!is_empty()) //Make the list empty
    {
        pop_back();
    }

    return *this += rhs; //Add every element to this from rhs list
}

/*
    Erasing last element in list
*/
double linked_list::pop_back(){
    
    double z = tail->value;
    if(head == nullptr){ //A check when list is empty
        return false; //Nothing to pop
    }else if ((head != nullptr) && (head->next == nullptr)) //A check when list has one element
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

 
    return z;
}

/*
    Erasing the first element in list
*/
double linked_list::pop_front(){

    
    if(head == nullptr){ //A check if the list is empty
        return false;
    }
    
    double z = head->value;
    if ((head != nullptr) && (head->next == nullptr)) //A check if the list has one element
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

 
    return z;
}

/*
    Returns size of a list
*/
size_t linked_list::size() const{
    int counter = 0;
    
    for(node* pt = head; pt != nullptr; pt = pt->next){
        counter++;
    }

    return counter;
}

/*
    Returns value of head
*/
double linked_list::front() const{
    return head->value;
}

/*
    Returns value of tail
*/
double linked_list::back() const{
    return tail->value;
}

/*
    To make two list into one using +=
*/
linked_list& linked_list::operator+=(const linked_list& rhs) {

    for(node* pt = rhs.head; pt != nullptr; pt = pt->next){ //Iterera through rhs list
        this->push_back(pt->value); //Push back value to lhs list
    }

    return *this;  
}

/*
    Takes a position to insert a new value to a list
*/
void linked_list::insert(double value, size_t pos){
    int counter = 0;
    node* n = new node(value);
    node* pt;
    for(pt = head; counter < pos; pt = pt->next){    
    }
    pt->prev = n;
    pt->prev->next = pt;

}

/*
    Makes a deep copy from a list
*/
linked_list::linked_list(const linked_list& src) {
    head = nullptr;
    tail = nullptr;
    
    for(int i= 0; i< src.size(); i++){ //iterate through src
        push_back(src.at(i)); //push_back value from every element in src
    }
} 
