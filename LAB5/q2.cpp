#include <iostream>
using namespace std;

class LoanHelper {
    const float interestRate;  
    float amountOfLoan;     
    double amountPerMonth; 
    int amountOfMonths;  

public:
    LoanHelper(const float rate = 0, float amountOfLoan = 0, int numMonths = 0) 
        : interestRate(rate), amountOfLoan(amountOfLoan), amountOfMonths(numMonths) {}

    void calcLoan() {
        amountPerMonth = amountOfLoan / amountOfMonths;  
        amountPerMonth += amountPerMonth * (interestRate / 100); }

    double getAmountPerMonth() { return amountPerMonth; }

    int getNumMonths() { return amountOfMonths; }
};

int main() {
    cout << "Enter interest rate (between 0 and 0.5): ";
    float rate;
    cin >> rate;

    if (rate >= 0 && rate <= 0.5) {
        float loan;
        int month;

        cout << "Enter the amount of loan: ";
        cin >> loan;

        cout << "Enter number of months to repay the loan: ";
        cin >> month;

        if (loan > 0 && month > 0) {
            LoanHelper loanHelper(rate, loan, month);
            loanHelper.calcLoan();

            cout << "You have to pay " << loanHelper.getAmountPerMonth() 
                 << " every month for " << loanHelper.getNumMonths() 
                 << " months to repay your loan." << endl;
        } else {
            cout << "Loan amount and months must be greater than zero!" << endl;
        }
    } else {
        cout << "Interest rate must be between 0 and 0.5!" << endl;
    }

    return 0;
}
