#include <iostream>
 
using namespace std;
 
class String  {
private:
    char *pStr;
    int _size;
public:
    String()  {						//конструктор
        pStr = NULL;
        _size = 0;
    }

	~String()  {					//деструктор
        delete []pStr;
    }
	
    int size()  {
        return _size;
    }

	char get(int i)	{
	return pStr[i];
	}

	void set(int i)	{
	pStr[i] = //.....
	}
	
	void print	{
	for(int i=0; i<strlen(pStr); i++)
	cout<<pStr[i];
	}

};
 
int main()  
{
    String str("Blablabla");
    String.print(str);
    return 0;
}
