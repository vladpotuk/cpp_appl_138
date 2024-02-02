#include "Expense.h"

Expense::Expense(double amount, std::string category) : amount(amount), category(category) {
    timestamp = time(nullptr);
}

double Expense::getAmount() const {
    return amount;
}

std::string Expense::getCategory() const {
    return category;
}

time_t Expense::getTimestamp() const {
    return timestamp;
}
