#include <iostream>
#include <cstring>

using namespace std;
 
class String  {
private:
    char *pStr;
    int _size;
public:
    String()  {
        pStr = NULL;
        _size = 0;
    }
    String(char *str)  {
        _size = strlen(str) + 1;
        pStr = new char[_size];
        strcpy(pStr, str);
    }
    int size()  {
        return _size;
    }
    ~String()  {
        delete []pStr;
    }
	
	void print()
	{	
	for(int i=0; i<_size; i++)
		cout<<pStr[i];
	}

	char get(int i)
	{
	return pStr[i];
	}

	void set(int i, char c)
	{
	pStr[i] = c;
	}

	int find(String str)
	{
	bool ch = false;
	int index;
	int ind1=0;
	for(int i = 0; i < _size; i++)
		{
			if (!ch)
			{
				if(pStr[i] == str.get(0))
				ch = true;
				index = i;
				ind1 = 1;
			}
				else
			if (ch)
			{
				if (!pStr[i] == str.get(ind1))
					{
					ch = false; 
					index = 0; 
					ind1 = 0;
					}
			}
		}
	return index;
	}

	void Concat(String s)
	{
     _size += s.size();
     char* tmp = new char[_size + 1];
     ::strcpy(tmp, pStr);
     ::strcat(tmp, s.pStr);
     delete [] pStr;
     pStr = tmp;
	}

	
};
 



int main()  {
	String str1("kekekek.");
    String str("Blablabla");
	str.Concat(str1);
	cout<<str.find("abl")<<endl;
	str.print();
	cout<<'.';

	return 0;
}
