//
// Created by Anna on 10/5/2025.
//

//
// Created by Anna on 9/11/2025.
//

#ifndef TODOLIST_H
#define TODOLIST_H
#include "Task.h"
#include <vector>
using namespace std;

class ToDoList
{
private:
    vector<Task> tasks;

public:
    // Constructor
    ToDoList();
    // getter
    Task getTask(int index) const;

    // Add/remove tasks
    void addTask(Task t);
    void removeTask(int index);

    // Display
    void displayAll() const;
    void displayByPriority(Priority p) const;
    void displayIncomplete() const;
    void displayOverdue(string today) const;
    void displayBeforeDate(string date) const;
    void displayByCategory(string categoryName) const;

    // Modify tasks
    void markTaskComplete(int index);
    bool isTaskComplete(int index) const;
    bool saveToFile(const string &filename) const;

    // Find size of ToDoList
    int size() const;
};

#endif // TODOLIST_H
