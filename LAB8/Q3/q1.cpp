#include <iostream>
using namespace std;
class number{
    int a;
    int b;
    public:
    number(int i,int j):a(i),b(j){}
    void display(){
        cout<<"a: "<<a<<endl;
        cout<<"b: "<<b<<endl;
    }
    friend void operator+=(number& n, number&b);
};
void operator+=(number& n, number&m){
    n.a+=m.a;
    n.b+=m.b;
}
int main(){
    number n1(1,2),n2(2,3);
    n1.display();
    n2.display();
    n1+=n2;
    n1.display();
    return 0;
}