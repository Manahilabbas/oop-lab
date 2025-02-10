/*You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
 `studentID` (int)
 `name` (string)
 `age` (int)
 `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.

4. Add methods:
 `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
 `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
 `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods. */
#include<iostream>
using namespace std;
class student{
    private:
    int studentID;
    string name;
    int age;
    char grade;

    public:
    student(){
        grade='N';

    }
    student(int studentID,string name,int age, char grade){
        this->studentID=studentID;
        this->name=name;
        this->age=age;
        this->grade=grade;

    }
    void promotestudent(){
        if (grade !='A')
        grade=grade-1;
    }
    bool isEligibleForScholarship(){
        if (grade=='A')
        {
            return true;
        }
        else {
            
            return false;

        }
    }
    void displayDetails(){
       cout<<"Name: "<<name<<endl;
       cout<<"student ID: "<<studentID<<endl;
       cout<<"Age: "<<age<<endl;
       cout<<"grade "<<grade<<endl;
       promotestudent();
       cout<<"grade after upgration: "<<grade<<endl; 
       if(isEligibleForScholarship()){
        cout<<"student is eligible for scholarship"<<endl;

       }
       else cout<< "student is not eligible for scholarship"<<endl;
    }


};
int main(){
    student s1(812,"Laiba",17,'A');
    student s2(1026, "manahil",19,'C');
    student s3(688,"simal",19,'B');
    s1.displayDetails();
    s2.displayDetails();
    return 0;
}