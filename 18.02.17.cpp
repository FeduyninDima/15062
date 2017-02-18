#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Vect{
    private:
    int s;
    public:
    double *val;

    Vect(int sz){
        s = sz;
        val = (double *)malloc(sizeof(double)*s);
    }

    Vect(int sz, double v){
        s = sz;
        val = (double *)malloc(sizeof(double)*s);
        for(int i=0;i<s;i++)
            val[i] = v;
    }

    void append(int begp, double el){
        val = (double *)realloc(val, sizeof(val)+sizeof(double));
        s++;
        double buf, temp;
        for(int i=0;i<s;i++){
            if(i == begp){
                buf = val[i];
                val[i] = el;
            }
            if(i > begp){
                temp = val[i];
                val[i] = buf;
                buf = temp;
            }
        }
    }
    void append(double el){
        val = (double *)realloc(val, sizeof(val)+sizeof(double));
        val[++s] = el;
    }

    void rresize(int sz){
        val = (double *)realloc(val, sizeof(double)*sz);
    }

    void rresize(int sz, double v){
        val = (double *)realloc(val, sizeof(double)*sz);
        for(int i=0;i<s;i++)
            val[i] = v;
    }

    double top(){
        return val[0];
    }

    double tail(){
        return val[s-1];
    }

    double& operator[](int index){
        return val[index];
    }

    ~Vect(){
        free(val);
    }
};

int main()
{
    Vect v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    cout << v[3];
    return 0;
}
