
#include <iostream>
using namespace std;

  struct node // structure having variable for data section and a pointer for the next node. 
  {
    int data;
    node *next;
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
    { cout<<value<<" is added at the end of the list.\n";
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        
      }
      else
      { temp->next=head;	
        tail->next=temp;
        
      }
      tail=temp;
      
     
    }
    void insertAt(int pos,int value)// to insert element at a certain position
    {
    node *cur=new node;
    node *prev=new node;
    node *temp= new node;
    cur= head;
    temp->data=value;
    if(pos<=countItems()) //To check if the list has that many elements
    {
    for(int i=1;i<pos;i++)
    { prev= cur;
     cur=cur->next;	
    }
    prev->next=temp;
    temp->next=cur;
     cout<<value<<" is added at "<< pos <<" th position\n";	
    }
    else
    {       cout<<value<<" can not be added at "<<pos<<" th position.\n";
    	cout<<"Linkedlist does not have that many elements.\n";}
   
    
    }
    
    void Delete()// delete element at the end of list
    {
    	node*cur=new node;
    	node*prev=new node;
    	cur=head;
    	while(cur->next!=head)
    	{
    	prev=cur;
    	cur=cur->next;
    	}
    	tail=prev;
    	prev->next=head;
    	delete cur;
    	cout<<"The last element is deleted.\n";
    }
    
    void deleteAt(int pos)// delete element at a certain position
    {
     node *cur=new node;
     node *prev=new node;
     node *after=new node;
     cur=head;
     if(pos<=countItems()) //To check if the list has that many elements 
     {
     for(int i=1;i<pos; i++)
     {prev=cur;
      cur=cur->next;
      after=cur->next;
     }
     prev->next=after;
     delete cur;
     cout<<"\nThe "<<pos<<" th element is deleted\n";
     }
     else
     cout<<" \nData from " <<pos<< " th position can not be deleted.\n";
     cout<<"Linkedlist does not have that many elements\n.";
     
    }
    
    int countItems() //To count the number of elements in the list
    {       int count=0;
    	node *temp=new node;
    	temp= head;
    do	
    	{ temp=temp->next;
    	count++;
    	}
    	
    while(temp!=head);
    	return count;
    }
   void display()// to display the elements
    {
    	node*temp= new node;
    	temp=head;
    	cout<<"The list is: ";
    	 do 
    	 
    	{
    	     	cout<<temp->data<<"->";
    	           temp=temp->next;
    	}
    while(temp!=head);
    
    cout<<endl;
   }
    
  };	
int main() {
	cout<<"\nCIRCULAR SINGLY LINKED LIST\n";
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

   
