// Example program
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct node{
    int elem;
    node *next;
};

class queue{
    private:
        node *top;
        node *end;
        int size;
    public:
        queue(int newEl){
            node *temp = new node;
            temp->elem = newEl;
            top = end = temp;
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
            if(size != 0){
                end->next = temp;
                end = temp;
            }
            else{
                top = end = temp;
            }
            size++;
        }
};


int main()
{
	map <string, int> commands;			//list of commands
	commands["queue"]=1;
	commands["end"]=2;
	commands["push"]=3;
	commands["pop"]=4;

	string s;
	queue A(0);					//creating an empty queue
							// this zero will be popped in "queue"-case of input

	do{						//command handler

		cin>>s;

        	int temp;

		switch ( commands[s] ){

			case 1:				// input "queue" - creating the first element of queue:
        						// deleting temporal zero from queue
                		cin>>temp;		// and create first element from input
		                A.pop();
                		A.push(temp);
             			break;

			case 2: 			// input - "end" - ending of inputting
				break;

            		case 3:        			// input "push" - reading element for pushing to queue from input
		                cin>>temp;
                		A.push(temp);
		                break;

            		case 4:   		     	// input "pop" - writing popped from queue element to output
                		cout<<A.pop()<<endl;
                		break;
        	}
  	}
	while (s!="end");

	return 0;
}
