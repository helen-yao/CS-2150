#include <iostream>
#include "List.h"
#include "ListItr.h"

using namespace std;

List::List(){
    head = new ListNode();
    tail = new ListNode();
    count = 0;
    head->next = tail;
    tail->previous = head;
  }

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

void  List::insertAtTail(int x){
      ListNode* end = new ListNode();
      end->value = x;
      end->previous = tail->previous;
      end->next = tail;
      tail->previous->next = end;
      tail->previous = end;
      count++;
    }

ListItr List::first(){
      ListItr first(head->next);
      return first;
    }

ListItr List::last(){
      ListItr last(tail->previous);
      return last;
}
    
int List::size()const{
      return count;
    }

void printList(List& source, bool forward){
  ListItr point;
      if(forward){
	point = source.first();
	while(!point.isPastEnd()){
	  cout<< point.retrieve();
	  point.moveForward();
	}
      }
      else{
	point = source.last();
	while(!point.isPastBeginning()){
	  cout<< point.retrieve();
	  point.moveBackward();
	}
      }
      source.remove(point.retrieve());
    }

List::~List(){
  makeEmpty();
  delete head;
  delete tail;
  
}
      
ListItr List::find(int x){
  ListItr itr (tail->previous);
  while (!itr.isPastBeginning()){
    if(itr.current->value == x){
      return itr;
    }
    else{
      itr.moveBackward();
    }
  }
  return itr;
}

void List::insertBefore(int x, ListItr position){
  ListNode* temp = new ListNode();
  temp -> value = x;
  temp -> previous = position.current -> previous;
  position.current -> previous -> next = temp;
  temp -> next = position.current;
  position.current -> previous = temp;
}

void List:: insertAfter(int x, ListItr position){
  ListNode* temp = new ListNode();
  temp -> value = x;
  temp -> next = position.current -> next;
  temp -> previous = position.current;
  position.current->next->previous = temp;
  position.current->next = temp;
 
}

void List:: remove(int x){
  if(find(x).current != tail){
      ListItr pos = find(x);
      pos.current->next->previous = pos.current -> previous;
      pos.current -> previous -> next = pos.current ->next;
      delete pos.current;
    }
  count--;
}

void List:: makeEmpty(){
  ListItr itr (head->next);
  while (!itr.isPastEnd()){
    itr.current=itr.current->next;
    delete itr.current->previous;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

