// Example program
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct node{
    int elem;
    node *next;
};

class stack{
    private:
        node *top;
        int size;
    public:
        stack(int newEl){
            node *temp = new node;
            temp->elem = newEl;
            top = temp;
            size = 1;
        }
        int pop(){
            if(size != 0){
                size--;
                node *temp=top;
                top=top->next;
                int e = temp->elem;
                delete temp;
                return e;
            }
        }
        void push(int newEl){
            node *temp = new node;
            temp->elem = newEl;
            temp->next = top;
            top = temp;
            size++;
        }
};


int main()
{
	map <string, int> commands;			//list of commands
	commands["stack"]=1;
	commands["end"]=2;
	commands["push"]=3;
	commands["pop"]=4;

	string s;
	stack A(0);					//creating an empty stack
							// this zero will be popped in "stack"-case of input

	do{						//command handler

		cin>>s;

        	int temp;

		switch ( commands[s] ){

			case 1:				// input "stack" - creating the first element of stack:
        						// deleting temporal zero from stack
                		cin>>temp;		// and create first element from input
		                A.pop();
                		A.push(temp);
             			break;

			case 2: 			// input - "end" - ending of inputting
				break;

            		case 3:        			// input "push" - reading element for pushing to stack from input
		                cin>>temp;
                		A.push(temp);
		                break;

            		case 4:   		     	// input "pop" - writing popped element to output
                		cout<<A.pop()<<endl;
                		break;
        	}
  	}
	while (s!="end");

	return 0;
}
