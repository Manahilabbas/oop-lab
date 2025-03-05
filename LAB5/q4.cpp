/*Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.*/
#include <iostream>
using namespace std;
class BankAccount{
    string accountNumber;
    string accountHolderName;
    double balance;
    public: 
    BankAccount(string accnum="123",string accholdername="abc",double balance=0):accountNumber(accnum),accountHolderName(accholdername),balance(balance){}
    void deposit(double amount){
        if(amount>0)
        balance+=amount;
        cout<<"unsufficient ammount"<<endl;
    }
     void withdraw(double amount){
        if(amount>0&&amount<balance)
        balance-=amount;
        else
        cout<<"unsufficient ammount"<<endl;
     }
   
    void display(){
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"Account Holdr Name: "<<accountHolderName<<endl;
    cout<<"Balance: "<<balance<<endl;
}
    
};
int main(){
    BankAccount accounts[3]{{"012234","Manahil Abbas",10000},{"022345","Ayesha",20000},{"123456","Ahsan",5000}};
    for(int i=0;i<3;i++){
        accounts[i].display();
        accounts[i].deposit(500.0);
        accounts[i].withdraw(200.0);
        accounts[i].display();

    }
    return 0;
}