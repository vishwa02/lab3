#include <iostream>
using namespace std;

  struct node // structure having variable for data section and a pointer for the next node. 
  {
    int data;
    node *next;
    node *prev;
  };	
  
   class linkedList //  class  containing the functions to handle the nodes
  {
    private:
    node *head, *tail; //Declaring two important pointers, i.e. head and tail
    public:
    linkedList() //The constructer will make them NULL to avoid any garbage value.
    {
      head=NULL;
      tail=NULL;
    }
    void insert(int value)
    {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
      	temp->prev=NULL;
            head=temp;
        
      }
      else
      {	
        tail->next=temp;
        temp->prev=tail;
      
      }
      
      tail=temp;
    }
    void insertAt(int pos,int value)// to insert element at a certain position
    {
    node *cur=new node;
    node *before=new node;
    node *temp= new node;
    cur= head;
    temp->data=value;
    if(pos<=countItems()) //To check if the list has that many elements
    {
    for(int i=1;i<pos;i++)
    { before= cur;
     cur=cur->next;	
    }
    before->next=temp;
    temp->prev=before;
    temp->next=cur;
    cur->prev=temp;	
    }
    else
    cout<<"Linkedlist does not have that many elements.\n";
    
    }
    
    void Delete()// delete element at the end of list
    {
    	node*cur=new node;
    	node *before=new node;
    	cur=head;
    	while(cur->next!=NULL)
    	{
    	before=cur;
    	cur=cur->next;
    	}
    	tail=before;
    	before->next=NULL;
    	delete cur;
    	cout<<"The last element is deleted.\n";
    }
    
    void deleteAt(int pos)// delete element at a certain position
    {
     node *cur=new node;
     node *before=new node;
     node *after=new node;
     cur=head;
     if(pos<=countItems()) //To check if the list has that many elements 
     {
     for(int i=1;i<pos; i++)
     {before=cur;
      cur=cur->next;
      after=cur->next;
     }
     before->next=after;
     after->prev=before;
     delete cur;
     }
     else
     cout<<"Linkedlist does not have that many elements\n.";
     cout<<"The "<<pos<<" th element is deleted\n";
    }
    
    int countItems() //To count the number of elements in the list
    {       int count=0;
    	node *temp=new node;
    	temp= head;
    	while(temp!=NULL)
    	{ temp=temp->next;
    	count++;
    	}
    	return count;
    }
   void display()// to display the elements
    {
    	node*temp= new node;
    	temp=head;
    	cout<<"\nThe list is:";
    	while(temp!=NULL)
    	{
    		cout<<temp->data<<"<->";
    		
    		temp=temp->next;
    	}
    cout<<"NULL"<<endl;
   }
    
  };	
int main() {
	cout<<"\nDOUBLY LINKED LIST";
	cout<<endl;
 linkedList l; // Declaring object of class linkedList
 l.insert(1);
 l.insert(2);
 l.display();
 cout<<"The total number of elements in the list is "<<l.countItems()<<endl;
 l.insertAt(2,3);
 l.display();
 l.Delete();
 l.display();
 l.insertAt(2,4);
 l.display();
  cout<<"The total number of elements in the list is "<<l.countItems()<<endl;
 l.deleteAt(2);
 l.display();
 l.insertAt(5,4);
 l.deleteAt(3);
 l.display();
	return 0;
}
