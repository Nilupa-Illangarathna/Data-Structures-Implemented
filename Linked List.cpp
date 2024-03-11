#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
	
struct Data
{
	string Name;
	int Age;
	void Datainput(string name="", int age=0)
	{
		Name=name;
		Age=age;
	}
	void print()
	{
		cout<<"\t\t\t\t"<<Name<<" is "<<Age<<" years old"<<endl;
	}
	string NAme()
	{
		return Name;
	}
};

struct Node
{
	Node *Previous;
	Data data;
	Node *Next;	
};

class Linkedlist
{
	private:
		Node *START=NULL;
	public:
		void print()
		{
			Node *pointer=START;
			while(pointer!=NULL)
			{
				pointer->data.print();
				pointer=pointer->Next;
			}
		}
		void insertBeg(string name, int age)
		{
			Node *New_Node=new Node;
			New_Node->data.Datainput(name, age);
			
			if(START==NULL)
			{
				New_Node->Next=NULL;
				New_Node->Previous=NULL;
				START=New_Node;
			}
			else
			{
				New_Node->Previous=NULL;
				New_Node->Next=START;
				START->Previous=New_Node;
				START=New_Node;
			}
		}	
		void insertEnd(string name, int age)
		{
			Node *New_Node=new Node;
			New_Node->data.Datainput(name,age);
			New_Node->Next=NULL;
			if(START==NULL)
			{
				New_Node->Previous=NULL;
				START=New_Node;
			}
			else
			{
				Node *pointer=START;
				while(pointer->Next!=NULL)
				{
					pointer=pointer->Next;
				}
				New_Node->Previous=pointer;
				pointer->Next=New_Node;
			}
		}
		void insertName(string Name, string name,int age)
		{
			Node *pointer=START;
			Node *preptr=pointer;
			
			while(pointer->data.NAme()!=Name)
			{
				if(pointer->Next==NULL)
				{
					cout<<"The name doesn't exist in the List";
					break;
				}
				preptr=pointer;
				pointer=pointer->Next;
				
			}
			
			Node *New_Node = new Node;
			New_Node->data.Datainput(name,age);
			
			New_Node->Previous=preptr;
			New_Node->Next=pointer;
			preptr->Next=New_Node;
			pointer->Previous=New_Node;
		}
		void deleteBeg()
		{
			if(START==NULL)
			{
				cout<<"There is nothing to delete"<<endl;
			}
			else
			{
				Node *pointer=START;
				START=START->Next;
				START->Previous=NULL;
				
				free(pointer);
			}
		}
		
		void deleteEnd()
		{
			if(START==NULL)
			{
				cout<<"There is nothing to delete"<<endl;
			}
			else if(START!=NULL&&START->Next==NULL)
			{
				START=NULL;
			}
			else
			{
				Node *Pointer=START;
				Node *preptr=Pointer;
				while(Pointer->Next!=NULL)
				{
					preptr=Pointer;
					Pointer=Pointer->Next;
				}
				Pointer->Previous=NULL;
				Pointer->Next=NULL;
				delete Pointer;
				
				preptr->Next=NULL;
				
			}
		}
		
		
};




int main()
{
	Linkedlist OBJECT;
	
	int input=100;
	
	do
	{
		system("cls");
		cout<<"Enter 1 to insert a new value to Begining    :"<<endl;
		cout<<"Enter 2 to insert a new value to End         :"<<endl;
		cout<<"Enter 3 to insert a new value before NAME    :"<<endl;
		cout<<"Enter 4 to delete a value from Begining      :"<<endl;
		cout<<"Enter 5 to delete a value from End           :"<<endl;


		
		
		
		cout<<"\t\t\t\t\t\t";
		
		
		
		cin>>input;
		
		
		if(input==1)
		{
			cout<<"Enter the name : ";
			string name;
			cin>>name;
			cout<<"Enter the age : ";
			int age;
			cin>>age;
			OBJECT.insertBeg(name,age);
		}
		else if(input==2)
		{
			cout<<"Enter the name : ";
			string name;
			cin>>name;
			cout<<"Enter the age : ";
			int age;
			cin>>age;
			OBJECT.insertEnd(name,age);	
		}
		else if(input==3)
		{
			cout<<"Enter the previous name";
			string Name;
			cin>>Name;
			cout<<"Enter the adding name";
			string name;
			cin>>name;
			cout<<"Enter the age";
			int age;
			cin>>age;
			OBJECT.insertName(Name,name,age);
		}
		else if(input==4)
		{
			OBJECT.deleteBeg();
		}
		else if(input==5)
		{
			OBJECT.deleteEnd();
		}
		
		
		
		
		cout<<"\n\n";
			OBJECT.print();
		cout<<"\n\n";
		
		getch();
		
	}while(input!=0);
	
	return 0;
}
