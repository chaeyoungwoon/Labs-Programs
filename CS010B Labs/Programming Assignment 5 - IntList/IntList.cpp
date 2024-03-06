#include <iostream>
#include "IntList.h"

using namespace std;

//default constructor 
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

//deconstructor that utilizes clear()
IntList::~IntList(){
    clear();
}

//clear() will delete all nodes by looping as long as there are nodes in the list
void IntList::clear(){
    while (head != nullptr) { 
        //creates temp node to ensure a reference to the next node before deleting the current one
        //if we don't do this, then we lose info on the next node making it impossible to keep going in the list
        IntNode *temp = head->next; 
        delete head; 

        //head points to the next node
        head = temp;  
    }
    tail = nullptr;
}

//push_front will add a new node to the front of the list
void IntList::push_front(int newNode){
    IntNode* temp = new IntNode(newNode); 
    
    //pointer of next node = current head in the list (because current head will be the second node after)
    temp->next = head; 
    
    //update the head to point to new node
    head = temp; 

    if (tail == nullptr){
        tail = temp;
    }
}

/* 
fixed this
void IntList::pop_front(){
    if (head != nullptr){ 
        IntNode* temp = head; //store next node into temp
        delete head; //delete current head
        head = temp; //assign head with stored node
    }

    if (head == nullptr){
        tail = nullptr;
    }
}
*/

//pop_front will remove the front node in the list as long as it isn't empty
void IntList::pop_front(){
    if (head != nullptr){ 
        IntNode* temp = head; //store head into temp
        head = head->next; //reassign head before deletion
        delete temp; //delete current head 
    }

    if (head == nullptr){
        tail = nullptr;
    }
}

//checks if list is empty and returns corresponding bool
bool IntList::empty() const{
    if (head == nullptr){
        return true;
    }
    else {
        return false;
    }
}

//returns value pointed to by head
const int & IntList::front() const{
    return head->value;
}

//returns value pointed to by tail
const int & IntList::back() const{
    return tail->value;
}

//overloaded operator to output the list
ostream & operator<<(ostream &out, const IntList &newList){
    IntNode* current = newList.head; //begin from the head of the new list
    
    while (current != nullptr){ //loop until the end of the list
        out << current->value; //output current value of the node
        current = current->next; //traverses the node by 1 until current == nullptr
        if (current != nullptr){ 
            out << " ";
        }
    }
    return out;
}

//deep copy constructor
//use push_back (go back and add after finishing push_back)
IntList::IntList(const IntList &cpy){
    head = nullptr;
    tail = nullptr;

    IntNode *currNode = cpy.head; //create pointer to traverse the list starting from the head

    while(currNode != nullptr){
        push_back(currNode->value); //adding new nodes with given values as we go along
        currNode = currNode->next; //traverse 
    }
}

//overloaded operator
//performs deep copy on the rhs of the = 
IntList & IntList::operator=(const IntList &rhs){
    //self assignment check
    //current object
    if (this == &rhs){
        return *this;
    }
    //check if rhs is empty
    else if (rhs.empty()){
        head = nullptr;
        tail = nullptr;
    }
    else {
        clear(); //avoid memory leaks
        IntNode* currNode = rhs.head;
        while (currNode != nullptr){
            push_back(currNode->value); //add the values from the rhs list to  current list
            currNode = currNode->next; //move to the next node in the rhs list
        }
    }
    return *this;
}

//push_back
void IntList::push_back(int value){
    IntNode* temp = new IntNode(value);
    if (empty()){
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

/*
void IntList::selection_sort(){
    IntNode* currNode = head;
    while(currNode != nullptr){
        IntNode* minNode = currNode;   
        IntNode* tempNode = currNode->next;
        while (tempNode != nullptr){
            if (currNode->value < minNode->value){
                minNode = tempNode;
            }
            int tempVal = currNode->value;
            currNode->value = minNode->value;
            minNode->value = tempVal;

            currNode = currNode->next;
        }
        int tempVal = currNode->value;
        currNode->value  = minNode->value;
        minNode->value = tempVal;
        currNode = currNode->next;
    }

}
*/

//select sort - use nested for loop
void IntList::selection_sort(){
    //start from the head, iterate until i is null
    for(IntNode *i = head; i != nullptr; i = i->next){
	    int minVal = i->value; //default
	    // nested loop compares all other indexes to first loop.
	    for(IntNode *j = i->next; j != nullptr; j = j->next){
		    //sorts in ascending order
		    if(j->value < minVal){
		        minVal = j->value;
			    j->value = i->value;
			    i->value = minVal;
		    }   
	    }
    }
}

/*

void IntList::insert_ordered(int value){
    IntNode* newNode = new IntNode(value);
    if (head == nullptr || head->value >= newNode->value){
            newNode->next = head;
            head = newNode;
        if (tail == nullptr){
            tail = newNode;
        }
    }
    else{
        IntNode* currNode = head;
        while (currNode->next !=nullptr && currNode->next->value < value){
        currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
        if (currNode == tail){
            tail = newNode;
        }
    }
}
*/

//insert value at certain spot
void IntList::insert_ordered(int value){
    //if empty, insert that value as the only one in the list
	if (empty()){
        push_front(value);
    }
    //check the value of the first node and insert accordingly
    else if (value <= head->value){
        push_front(value);
    }
    //check value of the last node and insert accordingly
    else if (value >= tail->value){
        push_back(value);
    }
    else {
        IntNode* prevNode = head; //pointer to previous node
        IntNode* currNode = head->next; //pointer to current node
        IntNode* temp = new IntNode(value); //new node with given value
        //loop through current list until if finds the correct pos for new value, then inserts it
        while(currNode != nullptr){
            //order
            if (value < currNode->value){
                prevNode->next = temp; //update the next pointer of the previous node to point to the new node
                temp->next = currNode; //update the next pointer of the new node to point to the current node
                return;
            }
            prevNode = prevNode->next; //update accordingly
            currNode = currNode->next;
        }
    }
}

/*
IntNode* currNode = head;
while (currNode!=nullptr && currNode->next !=nullptr){
    IntNode* tempNode = currNode;

}

*/
void IntList::remove_duplicates(){
    //check if there is anything to remove
    if (empty() || head == tail){
        return;
    }
    else {
        //for later use
        IntNode* prevNode = nullptr;

        //iterate over each node in the list
        for (IntNode* i = head; i != nullptr; i = i->next){
            prevNode = i;
            //starting from head node, iterate
            for (IntNode* j = i->next; j != nullptr; j = prevNode->next){
                if (i->value == j->value){ //checking for identical values
                    if (j == tail){
                        delete j;
                        tail = prevNode;
                        tail->next = nullptr;
                        //checks if head and tail are the same node
                        if (head == tail){
                            return;
                        }
                    }
                    else {
                        prevNode->next = j->next;
                        delete j;
                    }
                }
                else {
                    prevNode = prevNode->next;
                }
            }
        }
    }
}



