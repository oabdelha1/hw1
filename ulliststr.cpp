
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_front(const std::string& val){

  if(empty()){
    head_ = tail_=new Item();
    head_->last = ARRSIZE;
    head_->first = ARRSIZE;
  }
  else if (head_->first == 0){
    Item* temp = new Item();
    temp->next = head_;
    head_->prev = temp;
    head_=temp;
    head_->first = head_->last = ARRSIZE;
  }

  head_->val[head_->first -1] = val;
  size_++;
  head_->first --;

}

void ULListStr::push_back(const std::string& val){

  if(empty()){
    head_ = tail_ = new Item();
  } 
  else if (tail_->last == ARRSIZE){
    Item* temp = new Item();
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_front(){
  head_->val[head_->first] = '\0';
  head_->first++;
  size_--;
  if(head_->first == head_->last){
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
  }
}


void ULListStr::pop_back(){
  
  if (tail_==nullptr){}
  else if(tail_->last - tail_->first > 1){
    tail_->last--;
    size_--;
  }
  else{
    if (head_ == tail_){
      head_ = nullptr;
      delete tail_;
      tail_ = nullptr;
    }
    else{
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
      tail_->next = nullptr;
    }
    size_ --;
  }

  /*
  tail_->last--;
  size_--;

  if (size_==0){
    delete tail_;
  }
  else if(tail_->last == 0){
    Item* temp = tail_->prev;
    temp->next = nullptr;
    delete tail_;
    tail_ = temp;
  }
  */
}


std::string const & ULListStr::back() const{
  return (tail_->val[tail_->last - 1]);
}

std::string const & ULListStr::front() const{
  return (head_->val[head_->first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const{

  if (loc > size_){
    return nullptr;
  }
  
  int currfirst = head_->first;
  Item* temp = head_;
  string* spot;

  for(size_t i = 0; i < loc + 1; i++){
    if(currfirst == ARRSIZE){
      currfirst = 0;
      temp = temp->next;
    }

    spot = &(temp->val[currfirst]);
    currfirst++;
  }

  return spot;
}

//End

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  //cout << "test" << endl;
  std::string* ptr = getValAtLoc(loc);
  //cout << "test " << ptr << endl;
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
