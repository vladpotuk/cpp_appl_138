#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <ctime>

class Expense {
private:
    double amount;
    std::string category;
    time_t timestamp;

public:
    Expense(double amount, std::string category);
    double getAmount() const;
    std::string getCategory() const;
    time_t getTimestamp() const;
};

#endif 
