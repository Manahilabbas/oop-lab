/*You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
1. Attributes:
 `employeeID` (int)
 `name` (string)
 `department` (string)
 `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
 `isManager()`: Returns `true` if the employee's department is "Management".
 `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/

#include<iostream>
using namespace std;
class employee{
    private:
    int employeeID;
    string name;
    string department;
    double salary;

    public:
    employee():salary(0.0){}
    employee(int employeeID,string name,string department,double salary){
        this->employeeID=employeeID;
        this->name=name;
        this->salary=salary;
        this->department=department;

    }
    void giveBonus(double ammount){
        salary+=ammount;
        cout<<"bonus added"<<endl;
    }
    bool isManager(){
        if (this->department=="Management"){
            return true;
        }
        else 
        return false;
    }
 void displayDetails(){
    cout<<"Empoyee ID: "<<this->employeeID<<endl;
    cout<<"Name: "<<this->name<<endl;
    cout<<"Department: "<<department<<endl;
    cout<<"salary: "<<this->salary<<endl;
    cout<<"-----------------------"<<endl<<endl;
 }

};

int main(){
    employee emp[3]{{565,"Manan","Management",120000},{562,"Fatima","IT",10000},{522,"Ayesha","IT",110000}};
    for(int i=0;i<3;i++){
    if (emp[i].isManager())
    emp[i].giveBonus(12000);}

    for(int i=0;i<3;i++){
        emp[i].displayDetails();
    }
    return 0;
}