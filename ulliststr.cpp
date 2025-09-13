#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

// push_back: add value to end of list
  void ULListStr::push_back(const std::string& val) {
    // case 1: list empty
      if (empty()) { 
        // add a first node and update pointers
        Item* newNode = new Item();
        tail_ = newNode;
        head_ = tail_;
      }
    
    // case 2: list is full
      else if (tail_->last == ARRSIZE) {
        // add a new node and update pointers
        Item* newNode = new Item();
        newNode->prev = tail_;
        tail_->next = newNode;
        tail_ = newNode; 
      }

    // case 3: list has room
      // add new element to list
      tail_->val[tail_->last] = val;
      tail_->last++;

      size_++; // update size
    return;
  }

// push_front: add element to front of list
  void ULListStr::push_front(const std::string& val) {
    // case 1: list empty
    if (empty()) {
      // allocate first node and update pointers
      Item* newNode = new Item();
      head_ = newNode;
      tail_ = head_;

      // start filling in from the last slot
      head_->first = ARRSIZE; 
      head_->last  = ARRSIZE;
    }

    // case 2: list is full at the front
    else if (head_->first == 0) {
      Item* newNode = new Item();
      newNode->next = head_;
      head_->prev = newNode;
      head_ = newNode;

      // start filling in from the last slot
      head_->first = ARRSIZE; 
      head_->last  = ARRSIZE;
    }

    // case 3: room at front
      // add value to the list
      head_->first--;
      head_->val[head_->first] = val;

      size_++; // update size
    return;
  }
  

// pop_back: remove element from end of list
void ULListStr::pop_back() {
  // case 1: empty list - nothing to remove
  if (empty()){
    return; 
  }

  // case 2: nonempty list 
    // remove the last element from tail
    tail_->last--;
    size_--;
  
  // if there was only 1 node in list
  if (tail_->first == tail_->last) { 
    //  separate old empty tail node
    Item* old = tail_;
    tail_ = tail_->prev;

    // update head or tail if necessary
    if (tail_){ 
    tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
    }    
    delete old; // delete old tail node
  }  

}
// pop_front: remove element from front of list
void ULListStr::pop_front() {
  // case 1: empty list - nothing to remove
  if (empty()){
    return;
  }

  // case 2: nonempty list
    // remove the 1st element from the head 
    head_->first++;  
    size_--;         

  // if this head node is now empty
  if (head_->first == head_->last) {
    // separate old head node
    Item* old = head_;       
    head_ = head_->next;     

    // update head or tail if necessary
    if (head_) {
      head_->prev = nullptr; 
    } else {
      tail_ = nullptr;      
    }

    delete old; // delete old head node
  }
}


// front return value at the front of the list
std::string const & ULListStr::front() const {
  size_t firstIdx = head_->first;
  return head_->val[firstIdx];
}

// back: return value at end of the list
std::string const & ULListStr::back() const {
  size_t lastIdx = tail_->last - 1;
  return tail_->val[lastIdx];
}


// getValAtLoc: return ptr to the i-th element in the array 
std::string* ULListStr::getValAtLoc(size_t loc) const {
  // case 1: non-existent location provided
  if (loc >= size_) {
    return NULL;
  }

  // case 2: valid location
  size_t idx = loc;
  Item* temp = head_;

  while (temp != nullptr) {

    // number of elements in this node
    size_t cnt = temp->last - temp->first;

    if (idx < cnt) {
      // the element is inside this node
      return &temp->val[temp->first + idx];
    }

    // skip this node and reduce the index accordingly
    idx -= cnt;
    temp = temp->next;
  }
  return NULL;
}

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
  std::string* ptr = getValAtLoc(loc);
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

