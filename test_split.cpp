/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using std::cout;
using std::endl;

void checker(Node* temp){
    int counter = 1;
    while (temp != nullptr){
        cout << counter << ": " << temp->value << endl;
        counter++;
        temp = temp->next;
    }
}

int main(int argc, char* argv[])
{
    //Using a very basic LL implementation just to test

    //Setting up LL values
    Node* head;
    Node* first = new Node(4, nullptr);
    Node* second = new Node(5, nullptr);
    Node* third = new Node(6, nullptr);
    Node* fourth = new Node(7, nullptr);

    head = first;
    first->next = second;
    second -> next = third;
    third ->next = fourth;

    Node* evs = nullptr;
    Node* odd = nullptr;



    cout << "Testing the LL implementation" << endl;

    Node* tempmain = head;
    Node* tempeven = evs;
    Node* tempodd = odd;

    cout << "Checking main list: " << endl;
    checker(tempmain);

    split (head, odd, evs);

    /*
    cout << "Checking evens: " << endl;
    cout << evs->value << endl;
    checker(evs);
    cout << "Checking odds: " << endl;
    cout << odd->value << endl;
    checker(odd); 
    */

    return 0;
}
