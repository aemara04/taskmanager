//
// Created by Anna on 10/5/2025.
//

#ifndef RECURRINGTASK_H
#define RECURRINGTASK_H

#include "Task.h"
#include <string>
using namespace std;

class RecurringTask : public Task {
private:
    int recurrenceDays;  // Number of days between each recurrence

public:
    // Constructors
    RecurringTask();
    RecurringTask(string desc, string date, Priority p, bool status, Category c, int recurDays);

    // Getter and Setter
    int getRecurrenceDays() const;
    void setRecurrenceDays(int days);

    // Override isOverdue to include recurring logic
    bool isOverdue(string today) const;

    // Friend function to print recurring task info
    friend ostream& operator<<(ostream& outs, const RecurringTask& rtask);
};

#endif // RECURRINGTASK_H

