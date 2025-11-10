//
// Created by Anna on 10/5/2025.
//

#include "Task.h"
#include <string>
#include <iostream>
using namespace std;

Task::Task() : description(""), dueDate(""), priority(LOW), completed(false), category(Category()) {}
Task::Task(string desc, string date, Priority p, bool status, Category c) : description(desc), dueDate(date), priority(p), completed(status), category(c) {}

// Returns Task description
string Task::getDescription() const {
  return description;
}

// Returns Task dueDate
string Task::getDueDate() const {
  return dueDate;
}

// Returns Task Priority
Priority Task::getPriority() const {
  return priority;
}

// Returns Task completed status
bool Task::isComplete() const {
  return completed;
}

// Returns Category
Category Task::getCategory() const {
  return category;
}

// Sets Task description
void Task::setDescription(string desc) {
  description = desc;
}

// Sets Task dueDate
void Task::setDueDate(string date) {
  dueDate = date;
}

// Sets Task priority
void Task::setPriority(Priority p) {
  priority = p;
}

// Sets Tasks completed status
void Task::setComplete(bool status) {
  completed = status;
}

// Sets Task Category
void Task::setCategory(Category c) {
  category = c;
}

/*
 * Determines whether the task is overdue
 * A task if considered overdue if it is not marked complete and
 * its due date is earlier than the provided current date
 * @param today The current date in "MM/DD/YYYY" format
 * @return true if the task is overdue, false otherwise
 */
bool Task::isOverdue(string today) const {
  return !completed && dueDate < today;
}


// Overloaded operators to compare tasks
bool operator == (const Task &lhs, const Task &rhs) {
  return lhs.description == rhs.description &&
         lhs.dueDate == rhs.dueDate &&
         lhs.priority == rhs.priority &&
         lhs.completed == rhs.completed;
}

bool operator != (const Task &lhs, const Task &rhs) {
  return !(lhs == rhs);
}

bool operator < (const Task &lhs, const Task &rhs) {
  return lhs.dueDate < rhs.dueDate;
}

bool operator > (const Task &lhs, const Task &rhs) {
  return rhs < lhs;
}

bool operator <= (const Task &lhs, const Task &rhs) {
  return !(rhs < lhs);
}

bool operator >= (const Task &lhs, const Task &rhs) {
  return !(lhs > rhs);
}

// Overloaded operator for Task output
ostream& operator<<(ostream& outs, const Task &task) {
  outs << "Description: " << task.description
     << " | Due: " << task.dueDate
     << " | Priority: ";
  switch (task.priority) {
  case LOW: outs << "LOW"; break;
  case MEDIUM: outs << "MEDIUM"; break;
  case HIGH: outs << "HIGH"; break;
  }
  outs << " | Category: " << task.category.getName();
  outs << " | Status: " << (task.completed ? "Complete" : "Incomplete");
  return outs;
}



