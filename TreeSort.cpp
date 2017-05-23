#include <iostream>
using namespace std;

class knot{
private:
	long long leight;
public:
	knot *parent;
	knot *right;
	knot *left;
	bool was;

	knot(long long nu){
		leight = nu;
		parent = NULL;
		right = NULL;
		left = NULL;
		was = false;
	}


	~knot(){

		leight = NULL;
		parent = NULL;
		right = NULL;
		left = NULL;

	}



	long long getLeight(){
		return leight;
	}

	int printSelf(){
		return leight;
	}

};

class BinaryTree{
private:
	knot*root;
	int*Arr;
	int i = 0;
	void addToTree(long long NewNum, knot*temp){
		if ((temp->getLeight()) > NewNum){
			if (temp->left != NULL)
				addToTree(NewNum, temp->left);
			else{
				temp->left = new knot(NewNum);
				temp->left->parent = temp;
			}
		}
		else{
			if (temp->right != NULL)
				addToTree(NewNum, temp->right);
			else{
				temp->right = new knot(NewNum);
				temp->right->parent = temp;
			}
		}

	}

	void Sort(knot*temp){
		if (temp!=NULL){
			temp = FindSmallest(temp);
			if (!(temp->was)){
				Arr[i]=temp->printSelf();
				temp->was = true;
				i++;
			}
			if ((temp->right != NULL))
			{
				if (!(temp->right->was))
					Sort(temp->right);
				else
					if (temp->parent != NULL)
						Sort(temp->parent);
			}
			else
				if (temp->parent != NULL)
					Sort(temp->parent);
		}
	}

	knot* FindSmallest(knot*del){
		if ((del->left == NULL) || (del->left->was))
			return del;
		else{
			return FindSmallest(del->left);
		}

	}



public:
	BinaryTree(int n){
		root = NULL;
		Arr = new int[n];
	}

	~BinaryTree(){
		root = NULL;
	}

	void add(long long NewNum){
		if (root == NULL){
			root = new knot(NewNum);
		}
		else{
			addToTree(NewNum, root);
					

		}
	}
	
	int* Sort(){
		Sort(root);
		return Arr;
	}
};

void TreeSort(int*Arr, int n){
	BinaryTree G(n);
	for (int i = 0; i < n; i++){
		G.add(Arr[i]);
	}
	for (int i = 0; i < n; i++){
		Arr[i] = G.Sort()[i];
	}
}



int main(){
	int n;
	cin >> n;
	int*Arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	TreeSort(Arr, n);
	for (int i = 0; i < n; i++)
		cout << Arr[i]<<" ";
	system("pause");
	return 0;
}