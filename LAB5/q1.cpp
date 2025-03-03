/*Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.*/
#include <iostream>
using namespace std;
class Square{
private:
float sidelenght;
float area;
static float allarea;
public:
Square(){
    sidelenght=0;
    area=0;
}
Square(float sidelenght){
    this->sidelenght=sidelenght;
}
void calc_area(){
    area=sidelenght*sidelenght;
    allarea+=area;
}
float getsidelenght(){return sidelenght;}
float getarea(){return area;}
static float getallarea();
void setsidelenght (float lenght){this->sidelenght=lenght;}
};
float Square::allarea = 0;
float Square::getallarea(){return allarea;}
int main(){
    Square s1(5),s2(10),s3(30);
    s1.calc_area();
    s2.calc_area();
    s3.calc_area();

    cout<<"area of square 1 is :"<<s1.getarea()<<endl;
    cout<<"area of square 2 is :"<<s2.getarea()<<endl;
    cout<<"area of square 3 is :"<<s3.getarea()<<endl;
    cout<<"all area: "<<Square::getallarea();
    return 0;
}