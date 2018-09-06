#include <stdio.h>

// Hold a string
class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as;
  }
};

struct List {
private:

// ListNode represents each 
// node of the list
  class ListNode {
  public:
    Item item; // data in the list
    ListNode *next;	
  public:
    ListNode(Item a, ListNode *n=NULL) 
    { 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext() 
    { 
      return next; 
    }
    void setNext(ListNode *n) 
    { 
      next = n; 
    }
    Item& getItem() 
    { 
      return item; 
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public:
  List();
  void push_back (Item a);  
  Item get (int n);
  int length ();
  Item remove_front();    
  bool empty(); 
  };

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void List::push_back (Item a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

Item List::get (int n)
{
  ListNode *tmp = head;
  int i=0;
  Item value;
  while (i<=n)
    {
      tmp=tmp->next;
      calue=tmp->getItem();
      i++;
    }
  return value;
}

int
List::length ()			//Get the number of items in the list
{
  ListNode *tmp = head;
  int total = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      total++;
    }
  return total;
}

Item List::remove_front ()		
{
  if (!empty ())		
    {
      copy = head->getItem ();	
      ListNode *tmp = head->getNext ();
      delete head;		
      head = tmp;	
      if (tmp == NULL)		
	    tail = NULL;
      return copy;
    }
  else
    {
      return NULL;
    }
}

bool List::empty()
{
  return head==NULL;
}

List::~List ()			
{
  while (!empty ())		
    remove_front ();		
}



int main()
{
  List l;

  l.push_back(Item("milk"));
  l.push_back(Item("eggs"));
  l.push_back(Item("bread"));
  l.push_back(Item("potato chips"));
  l.push_back(Item("toothpaste"));


  while(!l.end())
    {
      Item copy;
      l.remove(copy);
      
      printf("Next thing in list: %s\n",copy.str);

      l.increment();
    }

  return 0;
}
