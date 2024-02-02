#include <iostream>
#include "Wallet.h"
#include "Expense.h"
#include "FinanceManager.h"

int main() {
    
    Wallet wallet("Main Wallet", 1000.0);
    FinanceManager manager;

   
    Expense expense1(50.0, "Food");
    Expense expense2(30.0, "Transportation");
    manager.addExpense(expense1);
    manager.addExpense(expense2);

    
    std::cout << "Weekly Expense: $" << manager.calculateWeeklyExpense() << std::endl;
    std::cout << "Monthly Expense: $" << manager.calculateMonthlyExpense() << std::endl;

    
    manager.saveReportsToFile("finance_reports.txt");

    return 0;
}
