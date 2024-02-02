#include "FinanceManager.h"
#include <fstream>
#include <iostream>

void FinanceManager::addExpense(Expense expense) {
    expenses.push_back(expense);
}

double FinanceManager::calculateWeeklyExpense() const {
    double totalWeeklyExpense = 0.0;
    time_t currentTime;
    time(&currentTime);
    struct tm timeInfo;
    localtime_s(&timeInfo, &currentTime);
    int currentWeek = timeInfo.tm_wday;

    
    for (const auto& expense : expenses) {
        time_t expenseTime = expense.getTimestamp();
        struct tm expenseDate;
        localtime_s(&expenseDate, &expenseTime);
        int expenseWeek = expenseDate.tm_wday;

        if (currentWeek == expenseWeek) {
            totalWeeklyExpense += expense.getAmount();
        }
    }

    return totalWeeklyExpense;
}

double FinanceManager::calculateMonthlyExpense() const {
    double totalMonthlyExpense = 0.0;
    time_t currentTime;
    time(&currentTime);
    struct tm timeInfo;
    localtime_s(&timeInfo, &currentTime);
    int currentMonth = timeInfo.tm_mon; 

    
    for (const auto& expense : expenses) {
        time_t expenseTime = expense.getTimestamp();
        struct tm expenseDate;
        localtime_s(&expenseDate, &expenseTime);
        int expenseMonth = expenseDate.tm_mon;

        if (currentMonth == expenseMonth) {
            totalMonthlyExpense += expense.getAmount();
        }
    }

    return totalMonthlyExpense;
}

std::map<std::string, double> FinanceManager::getTop3WeeklyCategories() const {
    
    std::map<std::string, double> top3WeeklyCategories;
    time_t currentTime;
    time(&currentTime);
    struct tm timeInfo;
    localtime_s(&timeInfo, &currentTime);
    int currentWeek = timeInfo.tm_wday; 

    for (const auto& expense : expenses) {
        time_t expenseTime = expense.getTimestamp();
        struct tm expenseDate;
        localtime_s(&expenseDate, &expenseTime);
        int expenseWeek = expenseDate.tm_wday;

        if (currentWeek == expenseWeek) {
            std::string category = expense.getCategory();
            top3WeeklyCategories[category] += expense.getAmount();
        }
    }

    
    return top3WeeklyCategories;
}

std::map<std::string, double> FinanceManager::getTop3MonthlyCategories() const {
    
    std::map<std::string, double> top3MonthlyCategories;
    time_t currentTime;
    time(&currentTime);
    struct tm timeInfo;
    localtime_s(&timeInfo, &currentTime);
    int currentMonth = timeInfo.tm_mon; 

    for (const auto& expense : expenses) {
        time_t expenseTime = expense.getTimestamp();
        struct tm expenseDate;
        localtime_s(&expenseDate, &expenseTime);
        int expenseMonth = expenseDate.tm_mon;

        if (currentMonth == expenseMonth) {
            std::string category = expense.getCategory();
            top3MonthlyCategories[category] += expense.getAmount();
        }
    }

    
    return top3MonthlyCategories;
}

void FinanceManager::saveReportsToFile(std::string filename) const {
    std::ofstream file(filename);

    if (file.is_open()) {
        
        file << "Weekly Expense: $" << calculateWeeklyExpense() << std::endl;
        file << "Monthly Expense: $" << calculateMonthlyExpense() << std::endl;

        
        auto top3WeeklyCategories = getTop3WeeklyCategories();
        file << "Top 3 Weekly Categories:" << std::endl;
        for (const auto& pair : top3WeeklyCategories) {
            file << pair.first << ": $" << pair.second << std::endl;
        }

        
        auto top3MonthlyCategories = getTop3MonthlyCategories();
        file << "Top 3 Monthly Categories:" << std::endl;
        for (const auto& pair : top3MonthlyCategories) {
            file << pair.first << ": $" << pair.second << std::endl;
        }

        file.close();
        std::cout << "Reports saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
