//
// Created by Anna on 10/5/2025.
//


#include "RecurringTask.h"
#include <iostream>
using namespace std;

// Default constructor
RecurringTask::RecurringTask() : Task(), recurrenceDays(0) {}

// Parameterized constructor
RecurringTask::RecurringTask(string desc, string date, Priority p, bool status, Category c, int recurDays)
        : Task(desc, date, p, status, c), recurrenceDays(recurDays) {}

// Getter
int RecurringTask::getRecurrenceDays() const {
    return recurrenceDays;
}

// Setter
void RecurringTask::setRecurrenceDays(int days) {
    recurrenceDays = days;
}

/*
 * Determines whether a recurring task is overdue.
 */
bool RecurringTask::isOverdue(string today) const {
    return !isComplete() && getDueDate() < today;
}

// Output operator overload
ostream& operator<<(ostream& outs, const RecurringTask& rtask) {
    outs << static_cast<const Task&>(rtask)  // Call base Task's operator<<
         << " | Recurs every " << rtask.recurrenceDays << " day(s)";
    return outs;
}

