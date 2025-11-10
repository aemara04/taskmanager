//
// Created by Anna on 10/5/2025.
//

#ifndef TASK_H
#define TASK_H

#include "Category.h"
#include <string>
using namespace std;

enum Priority {LOW, MEDIUM, HIGH};

class Task {
private:
    string description;
    string dueDate;
    Priority priority;
    bool completed;
    // new has-a relationship
    Category category;

public:
    // Constructors
    Task();
    Task(string desc, string date, Priority p, bool status, Category c);

    // Getters
    string getDescription() const;
    string getDueDate() const;
    Priority getPriority() const;
    bool isComplete() const;
    Category getCategory() const;

    // Setters
    void setDescription(string desc);
    void setDueDate(string date);
    void setPriority(Priority p);
    void setComplete(bool status);
    void setCategory(Category c);

    // Additional methods
    bool isOverdue(string today) const;

    // Operator overloads
    friend bool operator==(const Task &lhs, const Task &rhs);
    friend bool operator!=(const Task &lhs, const Task &rhs);
    friend bool operator<(const Task &lhs, const Task &rhs);
    friend bool operator<=(const Task &lhs, const Task &rhs);
    friend bool operator>(const Task &lhs, const Task &rhs);
    friend bool operator>=(const Task &lhs, const Task &rhs);
    friend ostream& operator<<(ostream &outs, const Task &task);
};

#endif //TASK_H

