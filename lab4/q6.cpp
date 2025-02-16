/*Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
(default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
available balance.
4. Display account details including account number, owner’s name, and current balance.
Your task is to implement a C++ program that fulfills these requirements.*/

#include<iostream>
using namespace std;
class bank{

    private:
    int accNum;
    string OwnerName;
    double balance;

    public:
    bank ():balance(0.0){};
    bank(int accNum, string OwnerName,double balance){
        this->accNum=accNum;
        this->OwnerName=OwnerName;
        this->balance=balance;
    }
    void depositMoney(double ammount){
      balance+=ammount;
    }
    void withdraw(double ammount){
        if(ammount<0||ammount>balance){
            cout<<"sorry! can not withdraw ammount"<<endl;
        }
        else{
            balance-=ammount;
            cout<<"Transaction Successful! You have withdrawn $"<<ammount<<". Your remaining balance is $1,500."<<balance<<endl;
        }

    }
    void displayDetails(){
        cout<<"Account Number: "<<this->accNum<<endl;
        cout<<"Oner Name: "<<this->OwnerName<<endl;
        cout<<"Available balance: "<<balance<<endl;
        cout<<"-----------------------"<<endl<<endl;
     }
};

int main(){
    bank customer1(1001, "Abbas", 50000.0);
    bank customer2(512, "Manahil", 3100.0);

    customer1.displayDetails();
    customer2.displayDetails();

    customer1.depositMoney(15000);
    customer2.withdraw(1500);

    cout << "After Transactions: " << endl;
    customer1.displayDetails();
    customer2.displayDetails();

    return 0;
}