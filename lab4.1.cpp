#include<iostream>
using namespace std;
class Node
{public:
// data store
int data;
//pointer to movve to next node
Node* next;
//initializes next pointer as NULL
Node()
{next = NULL;}
};
class LinkedList
{public:
//pointer to store starting  node
Node* head;
//pointer to point to the last node
Node *tail;
//initializes head as NULL
LinkedList()
{head = NULL;
tail = NULL;
}
void insert(int value)
{//create new node temp
Node *temp = new Node;
//set value as data of the node
temp->data = value;
if(head==NULL)
{// head;
head = temp;}
else
{//link last element to new node
tail->next = temp;}
// tail
tail = temp;
cout<<endl;
}

//Deletion
void deletion()
{//store the tail in temp
Node *temp = tail;
//node before tail has to point to NULL
// to use head
Node *current = head;
//objective is to stop current upto node just before tail
while(current->next != tail)
{current = current->next;}
//this will be the last node now so that the next node can be deleted
current->next = NULL;
//tail
tail = current;
//delete temp//the next node gets deleted
//the next node gets deleted
delete temp;
cout<<endl;
}

//inserts node at a specific place and not in the last necessarily
void insertAt(int pos,int value)
{//To add node at the position of the header
if(pos == 1)
{//create a new node
Node *temp = new Node;
//assign the entered value as data
temp->data = value;
//link the new node to head
temp->next = head;
// head
head = temp;
}
else
{//Reach the place before the position
Node *current = head;
int i = 1;
while(i<pos-1)
{i++;
//now current points to the node just before the position
current = current->next;
}
//counter variable to count
int count = 0;
//declare present pointer to initially point to head
Node *present = head;
//increment count upto last element
while(present!=NULL)
{count++;
present = present->next;
}
if(pos>count)
{cout<<"The linked list doesn't have that many elements\n";}
else
{//Create the node
Node *temp = new Node;
temp->data = value;
//Moving pointers like magic
//link established between new node and the next node
temp->next = current->next;
//current should be linked to the new node
current->next = temp;}
}
cout<<endl;
}
//Deletes element of linked list from a specific position
void deletionAt(int pos)
{if(pos == 1)
{   //set node to be deleted as temp
Node *temp = new Node;
temp = head;
head = head->next;
//delete temp
delete temp;
}
else
{//reach the position just before the node to be deleted
Node *current = head;
int i = 1;
while(i<pos-1)
{i++;
current = current->next;
}
//Create the node temp and set it as the node to be deleted
Node *temp = new Node;
temp = current->next;
//linking nodes
current->next = temp->next;
//delete temp
delete temp;
}
cout<<endl;
	}
//Display
void display()
{   Node *current = head;
//prints till current reaches last node
while(current != NULL)
{cout<<current->data<<"->";
current = current->next;}
cout<<"NULL";
}
//Counts number of items
int countItems()
{//set a counter variable
int count = 0;
//move pointer from 1st element till the last and increment it everytime it moves
Node *current = head;
while(current !=NULL)
{count++;
current = current->next;
}
//return counter
return count;
}
};
//stacking
class StackLL
{   public:
Node *top;
LinkedList l1;
StackLL()
{top = NULL;
//initializes top pointer as NULL
}
//pushes on top
void push(int value)
{l1.insertAt(1,value);
//update top
top = l1.head;
}
//pops from top
void pop()
{l1.deletionAt(1);
//update top
top = l1.head;}
//checks if the stack is empty
bool isEmpty()
{if(top == NULL)
return true;
return false;}
//returns size
int size()
{return l1.countItems();}
//displays value stored in top pointer
void topDisplay()
{cout<<"Value in top pointer: "<<top->data<<endl;}
//displays the contents of the stack
void display()
{l1.display();}
};
//implements linked list to create a queue
class QueueLL
{   public:
Node *front;
Node *end;
LinkedList l2;
//initializes front and end to NULL
QueueLL()
{front = NULL;
end = NULL;}
//adds element at the start
void enqueue(int value)
{l2.insertAt(1,value);
//update front and end pointers
front = l2.tail;
end = l2.head;
}
//removes element from the end
void dequeue()
{l2.deletionAt(l2.countItems());
//update front and end pointers
front = l2.tail;
end = l2.head;}
//returns size of the queue
int size()
{return l2.countItems();}
//checks if the queue is empty
bool isEmpty()
{if(front == NULL)
return true;
return false;
}
//displays the data in front and end pointers
void frontendDisplay()
{cout<<"Front pointer data: "<<front->data<<endl;
cout<<"End pointer data: "<<end->data<<endl;
}
//displays the contents
void display()
{l2.display();}
};
class StackArr
{    public:
//variable that stores index value of starting element
int top;
int arr[30];
//initialize top as -1
StackArr()
{top = -1;}
//pushes new element into stack
void push(int value)
{ //increment top
top++;
//add value to array
arr[top] = value;
}
//pops element from stack
void pop()
{//decrement top
top--;}
//returns the size of the stack
int size()
{if(top == -1)
return 0;
//stores the no. of elements
int count = 0;
for(int i=0;arr[i]!=arr[top];i++)
{count++;}
return count;
}
//checks if the stack is empty
bool isEmpty()
{if(top == -1)
return true;
return false;}
//displays the contents of the stack
void display()
{for(int i=0;arr[i]!=arr[top];i++)
{cout<<arr[i]<<"->";}
cout<<arr[top]<<endl;}
};
class QueueArr
{public:
    //variables that store indices for first and last element of the array
	int front,end;
	int arr[30];
    //initialize both front and end as -1
 	QueueArr()
	{front = -1;
    end = -1;}
    //inserts element at the end
	void enqueue(int value)
	{//increment end
		end++;
		//insert element
		arr[end] = value;}
     //deletes element from the front
	void dequeue()
	{if(front == end)
		{front = -1;
          end = -1;}
        //increment front
        front++;}
     //returns size of the queue
	int size()
	{if(end == -1)
    return 0;
    int count = 0;
    for(int i=0;arr[i]!=arr[end];i++)
    count++;
    return count;
	}
    //checks if the queue is empty
	bool isEmpty()
	{if(end == -1)
    return true;
    return false;
	}
    //displays the contents of the queue
	void display()
	{//has to display contents between front and end
     int i=front+1;
     while(i>front && i<end)
   		{cout<<arr[i]<<"->";
        i++;}
		cout<<arr[end]<<endl;
	}
};
//main function
int main()
{   /Implementation of stack using linked list
	cout<<"Stack using LL: "<<endl;
	StackLL s1;
	for(int i=1;i<6;i++){s1.push(i);}
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	cout<<endl<<endl;
    //Implementation of queue using linked list
	cout<<"Queue using LL: "<<endl;
	QueueLL q1;
	for(int j=1;j<6;j++)
	{q1.enqueue(j);}
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	cout<<endl;
    //Implementation of stack using arrays
	cout<<"Stack using array: "<<endl;
	StackArr s2;
	for(int k=1;k<6;k++)
		s2.push(k);
    s2.display();
	s2.pop();
	s2.display();
	s2.pop();
	s2.display();
    //Implementation of queue using arrays
	cout<<"Queue using array: "<<endl;
	QueueArr q2;
	for(int l=1;l<6;l++)
		q2.enqueue(l);
    q2.display();
	q2.dequeue();
	q2.display();
	q2.dequeue();
	q2.display();
    //return statement
	return 0;
}
