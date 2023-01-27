/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using std::cout;
using std::endl;


/* Add a prototype for a helper function here if you need */
//void addEven(Node*& in, Node*& evens);
//void addOdd(Node*& in, Node*& odds);
void add(Node*& in, Node*& list);

void split(Node*& in, Node*& odds, Node*& evens)
{
  //cout << "running split" << endl;


  //Attempt 3
  if (in!=nullptr){
    Node* temp = in->next;
    if (in->value % 2 == 0){
      add(in, evens);
    }
    else if (in->value % 2 == 1){
      add(in, odds);
    }
    split (temp, odds, evens);
  }
  in = nullptr;

  //Attempt 2
  /*
  if (in!=nullptr){
    if (in->value % 2 ==0) {addEven(in, evens);}
    else if (in->value %2 == 1) {addOdd (in, odds);}

    Node* temp = in->next;
    delete in;
    in = NULL;
    split(temp, odds, evens);
    
  }
  */

  //Attempt 1
  /*
  if (in == nullptr){
    cout << "Done!" << endl;
  }
  else if (in->next)
  

  if ((in->value) % 2 == 0){
    addEven(in, evens);
  }
  else if ((in->value) % 2 == 1){
    addOdd (in, odds);
  }

  if (in->next != nullptr){
    split(in->next, odds, evens);
  }
  */
}

/* If you needed a helper function, write it here */




void add(Node*& in, Node*& list){
  if (list == nullptr){
    list = in;
    in->next = nullptr;
    //cout << "Just made with " << in->value << endl;
  }
  else if (list->next == nullptr){
    list->next = in;
    in->next = nullptr;
    //cout << "Just added  " << in->value << endl;
  } else {
    //cout << "stepping forward" << endl;
    add(in, list->next);
  }
}

/*
void addEven(Node*& in, Node*& evens){

  cout << "running even " << in->value << endl;

  if (evens == nullptr){
    //cout<< "1"<< endl;
    evens = new Node(in->value, nullptr);
  }
  else if (evens->next == nullptr){
    //cout<< "2"<< endl;
    Node* temp = new Node(in->value, nullptr);

    evens->next = temp;
  }
  else{
    //cout<< "3"<< endl;
    addEven(in->next, evens);
  }

}

void addOdd(Node*& in, Node*& odds){

  cout << "running odd " << in->value << endl;

  if (odds == nullptr){
   // cout<< "1"<< endl;
    odds = new Node(in->value, nullptr);
  }
  else if (odds->next == nullptr){
    //cout<< "2"<< endl;
    odds ->next = new Node(in->value, nullptr);
  }
  else{
    //cout<< "3"<< endl;
    addOdd(in, odds->next);
  }

}
*/

//Note in the morning: edit your functions to not use new or delete but just change pointers
//This should be possible start with evens and odds and then rewrite split
