#include <iostream>
using namespace std;
class number{
    int a;
    int b;
    public:
    number(int i=0,int j=0):a(i),b(j){}
    void display(){
        cout<<"a: "<<a<<endl;
        cout<<"b: "<<b<<endl;
    }
    number operator+(int a){
        number temp;
        temp.a=this->a+a;
        temp.b=this->b+a;
        return temp;

    }
};


int main(){
    number n1(1,2),n2;
    n1.display();
    n2=n1+2;
    n2.display();
    return 0;
}