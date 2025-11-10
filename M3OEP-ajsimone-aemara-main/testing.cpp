//
// Created by Anne on 10/5/2025.
//

#include <iostream>
#include <sstream>
#include "Task.h"
#include "RecurringTask.h"
#include "ToDoList.h"
using namespace std;

bool test_task_class();
bool test_recurring_task();
bool test_todolist();

int main() {
    bool allPassed = true;

    if (!test_task_class()) {
        allPassed = false;
        cout << "Task class tests failed." << endl;
    }

    if (!test_recurring_task()) {
        allPassed = false;
        cout << "RecurringTask tests failed." << endl;
    }

    if (!test_todolist()) {
        allPassed = false;
        cout << "ToDoList tests failed." << endl;
    }

    if (allPassed) {
        cout << "Passed all test cases!" << endl;
    } else {
        cout << "Some test cases failed." << endl;
    }

    return 0;
}

// -------------------------
// Test Task class
// -------------------------
bool test_task_class() {
    bool passed = true;

    Task t1("Do homework", "10/06/2025", HIGH, false, Category("School"));

    if (t1.getDescription() != "Do homework") {
        cout << "FAILED: Task description getter" << endl;
        passed = false;
    }
    if (t1.getDueDate() != "10/06/2025") {
        cout << "FAILED: Task due date getter" << endl;
        passed = false;
    }
    if (t1.getPriority() != HIGH) {
        cout << "FAILED: Task priority getter" << endl;
        passed = false;
    }
    if (t1.isComplete() != false) {
        cout << "FAILED: Task complete status getter" << endl;
        passed = false;
    }

    // Test setters
    t1.setDescription("Do dishes");
    t1.setDueDate("10/10/2025");
    t1.setPriority(MEDIUM);
    t1.setComplete(true);

    if (t1.getDescription() != "Do dishes") {
        cout << "FAILED: setDescription" << endl;
        passed = false;
    }
    if (t1.getDueDate() != "10/10/2025") {
        cout << "FAILED: setDueDate" << endl;
        passed = false;
    }
    if (t1.getPriority() != MEDIUM) {
        cout << "FAILED: setPriority" << endl;
        passed = false;
    }
    if (!t1.isComplete()) {
        cout << "FAILED: setComplete" << endl;
        passed = false;
    }

    return passed;
}

// -------------------------
// Test RecurringTask class
// -------------------------
bool test_recurring_task() {
    bool passed = true;

    RecurringTask r1("Workout", "10/07/2025", LOW, false, Category(), 7);

    if (r1.getRecurrenceDays() != 7) {
        cout << "FAILED: RecurringTask getRecurrenceDays" << endl;
        passed = false;
    }

    r1.setRecurrenceDays(14);
    if (r1.getRecurrenceDays() != 14) {
        cout << "FAILED: RecurringTask setRecurrenceDays" << endl;
        passed = false;
    }

    // Test output stream (toString)
    stringstream ss;
    ss << r1;
    string out = ss.str();
    if (out.find("Recurs every") == string::npos) {
        cout << "FAILED: RecurringTask operator<< output missing recurrence info" << endl;
        passed = false;
    }

    return passed;
}

// -------------------------
// Test ToDoList class
// -------------------------
bool test_todolist() {
    bool passed = true;
    ToDoList list;

    Task t1("Buy milk", "10/06/2025", LOW, false, Category("Grocery"));
    Task t2("Study", "10/07/2025", HIGH, false, Category("School"));

    // Test addTask
    list.addTask(t1);
    if (list.size() != 1) {
        cout << "FAILED: addTask didn't add correctly" << endl;
        passed = false;
    }

    // Test duplicate prevention
    list.addTask(t1);
    if (list.size() != 1) {
        cout << "FAILED: addTask allowed duplicate" << endl;
        passed = false;
    }

    // Add second task
    list.addTask(t2);
    if (list.size() != 2) {
        cout << "FAILED: addTask didn't add second task" << endl;
        passed = false;
    }

    // Test markTaskComplete
    list.markTaskComplete(0);
    if (!list.isTaskComplete(0)) {
        cout << "FAILED: markTaskComplete didn't mark as complete" << endl;
        passed = false;
    }


    // Test removeTask
    list.removeTask(1);
    if (list.size() != 1) {
        cout << "FAILED: removeTask didn't remove task" << endl;
        passed = false;
    }

    return passed;
}
