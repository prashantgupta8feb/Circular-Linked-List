//circular linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
node *AddEmpty(node *last ,int data){
	if(last != NULL) 
	return last ;
	node *newnode = new node();
	newnode->data =   data;
	last = newnode;
	last->next = newnode;
}

node *AddHead(node *last,int data){
	if(last == NULL){
		return AddEmpty(last,data);
	}
	node *newnode = new node();
	newnode->data =data;
	newnode->next = last->next;
	last->next = newnode;
	return last;
}
node *AddAfter(node *last ,int data,int item){
	if(last == NULL) 
	return NULL;
	node *prev = last->next;
	while(prev != last->next){
		if(prev->next->data == item){
			node *newnode = new node();
			newnode->data = data;
			newnode->next = prev->next->next;
			prev->next = newnode;
			if(prev == last)
			last = newnode;
			return last;
		}
		prev = prev->next;
	} 
	cout<<item<<" not found!\n";
}
node *Append(node *last, int data){
	if(last == NULL) 
	return NULL;
	node *newnode = new node();
	newnode->data = data;
	newnode->next = last->next;
	last->next = newnode;
	last = newnode;
}
void print(node *head){
	node *ptr = head;
   while(ptr != NULL){
   cout<<" "<<ptr->data<<"I am running!";
   head = ptr->next;
   cout<<"\n";
	}
	
}
int main()
{
	node* head = NULL;
   //AddEmpty AddHead AddAfter Append
   AddEmpty(head,2);AddEmpty(head,4);AddEmpty(head,6);
   AddEmpty(head,8);AddEmpty(head,10);AddEmpty(head,12);
   print(head);
   AddHead(head,22); AddAfter(head,2000,6);Append(head,40);
   print(head);

	
}
  
