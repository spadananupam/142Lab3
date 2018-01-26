#include<iostream>
using namespace std;
//structure of the node with data, and a next pointer
class node{
	public:
	int data;
	node *next;
	node *prev;
	//node initialization
	node(){
		node *next=NULL;}
};

class clist{
	private:
	node *head, *tail;
	public:
	dlist(){
		head=NULL;
		tail=NULL;

		
	}
	void insert();//adds at end
	void insertAt();//adds at a position
	void deletenode();//deletes the end element
	void deleteAt();//deletes at given position
	void countItems();
	void display();
	
};

void clist::insert(){
	node *temp = new node;//temp node
	cout << "Please enter the data you want to enter ";
	cin >> temp->data;
	temp->next= NULL;
	temp->prev= NULL;
	if (head==NULL){
		head=temp;//temp is the new head
		tail=head;
		head->prev = tail;
		tail->next = head;
	}
	else if (head==tail){
		head->next=temp;
		temp->prev=head;
		tail=temp;
		tail->next=head;
		head->prev=tail;
		}//temp is the new tail
	else { tail->next=temp;
		temp->prev=tail;
		tail=temp;
		tail->next=head;
		head->prev=tail;//tail to temp then temp is the new tail
	}
}

void clist::insertAt(){
	node *temp1= new node;
	temp1->next=NULL;
	int pos;
	cout<<"Please insert the position at which you want to enter the data ";
	cin>>pos;//insert here
	int t=1;
	temp1=head;
	while (t<pos-1){
		temp1=temp1->next;//taking a temp1 to the prev position
		t++;
	}

	node *temp2=new node;
	cout<<"Please enter the data";
	cin>>temp2->data;//node to be inserted
	temp2->prev=temp1;
	temp2->next=temp1->next;
	temp1->next=temp2;//previous to new, that to the next
	cout<<"done";
}
	
void clist::deletenode(){
	node *temp;
	temp=tail->prev;//we have prev and next, so we go to the previous and delete the next
	temp->next=head;
	head->prev=temp;
	delete tail;
	tail=temp;
}

void clist::deleteAt(){
	node *temp;
	node *temp1;
	int pos;
	cout<<"Please enter the node position you want to delete";
	cin>> pos;
	temp=head;//initial position 
	int i=1;
	while (i<pos-1){
		temp=temp->next;//going till reaching the previous node
		i++;
	}
	temp1=temp->next;//new pointer to node to be deleted
	temp->next=temp1->next;//precious of target node to after of the target
	delete temp1;}


void clist::display(){
	node *tempo=new node;
	tempo = head;
	while (tempo->next!=head){
	cout << tempo->data<< "->";//going to each node, going to next. couting everything
	tempo=tempo->next;}
	cout << tail->data<<"-> back to head"<<endl;
	cout << "That was your list\n";
}

void clist::countItems(){
	node *temp=new node;
	int t=0;
	temp=head;
	while (temp!=NULL){
		temp=temp->next;//going upto tail, after which tail points tto null
		t++;
	}
	cout<<"The number of elements is "<<t<<endl;
}

int main(){
	int num;
	clist obj;
	//declared object in linked list class
	cout << "How many data points do you want to enter? ";
	cin >> num;
	int i=0;
	while (i<num)
	{obj.insert();
	i++;}
	cout<<"Now press 1 if you want to insert anything in between, 2 if you want to delete from end, 3 if you want to delete at a position, 4 if you want to count number of items.";
	int j;
	cin >>j;
	//using switch case for allowing people choices
	switch (j){
	case 1:
	     obj.insertAt();
	     cout<<"done"<<endl;
	     break;
	case 2:
	     obj.deletenode();
	     cout<<"done"<<endl;
	     break;
	case 3:
	     obj.deleteAt();
	     cout<<"done"<<endl;
	     break;
	case 4:
	     obj.countItems();
	     cout<<"done"<<endl;
	     break;
	}
	cout<<"Your final list is ";
	obj.display();
	cout<<endl;
	return 0;
}
