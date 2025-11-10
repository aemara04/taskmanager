
//
// Created by Anna on 9/11/2025.
//

#include "ToDoList.h"
#include <iostream>
#include <fstream>
using namespace std;

ToDoList::ToDoList()
{
}

/*
 * Adds a Task to the ToDoList
 * @param t Task to be added to list
 */
void ToDoList::addTask(Task t)
{
  for (const Task &existing : tasks)
  {
    if (existing == t)
    {
      cout << "Task already exists." << endl;
      return;
    }
  }
  tasks.push_back(t);
  cout << "Task added." << endl;
}

/*
 * Removes a Task from the ToDoList
 * @param index Index of Task to be removed from ToDoList
 */
Task ToDoList::getTask(int index) const
{
  if (index >= 0 && index < tasks.size())
  {
    return tasks[index];
  }
  // Return a default Task if the index is invalid
  return Task();
}

void ToDoList::removeTask(int index)
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to remove." << endl;
    return;
  }
  if (index >= 0 && index < tasks.size())
  {
    tasks.erase(tasks.begin() + index);
    cout << "Task removed" << endl;
  }
  else
  {
    cout << "Invalid index. No task removed" << endl;
  }
}

/*
 * Displays all Tasks
 */
void ToDoList::displayAll() const
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to display." << endl;
    return;
  }
  else
  {
    for (int i = 0; i < tasks.size(); i++)
    {
      cout << i + 1 << ". " << tasks[i] << endl;
    }
  }
}

/*
 * Displays Tasks by Priority
 * @param p Priority level of Tasks of display
 */
void ToDoList::displayByPriority(Priority p) const
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to display." << endl;
    return;
  }
  bool found = false;
  for (int i = 0; i < tasks.size(); i++)
  {
    if (tasks[i].getPriority() == p)
    {
      cout << i + 1 << ". " << tasks[i] << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No tasks found with that priority." << endl;
  }
}

/*
 * Displays incomplete Tasks
 */
void ToDoList::displayIncomplete() const
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to display." << endl;
    return;
  }
  bool found = false;
  for (int i = 0; i < tasks.size(); i++)
  {
    if (!tasks[i].isComplete())
    {
      cout << i + 1 << ". " << tasks[i] << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No incomplete tasks." << endl;
  }
}

/*
 * Display overdue Tasks
 * @param today The current date in "MM/DD/YYYY" format
 */
void ToDoList::displayOverdue(string today) const
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to display." << endl;
    return;
  }
  bool found = false;
  for (int i = 0; i < tasks.size(); i++)
  {
    if (tasks[i].isOverdue(today))
    {
      cout << i + 1 << ". " << tasks[i] << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No overdue tasks." << endl;
  }
}

/*
 * Displays all Tasks before a specific due date
 * @param date The specified date in "MM/DD/YYYY" format
 */
void ToDoList::displayBeforeDate(string date) const
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to check." << endl;
    return;
  }
  bool found = false;
  // Make a temporary Task with the given date
  Task temp("temp", date, LOW, false, Category());

  for (const Task &t : tasks)
  {
    if (t < temp)
    {
      cout << t << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No tasks due before " << date << "." << endl;
  }
}

/*
 * Marks a Task as complete
 * @param index The index of the Task to mark as complete
 */
void ToDoList::markTaskComplete(int index)
{
  if (tasks.size() == 0)
  {
    cout << "No tasks to mark complete." << endl;
    return;
  }
  if (index >= 0 && index < tasks.size())
  {
    tasks[index].setComplete(true);
    cout << "Task marked complete." << endl;
  }
  else
  {
    cout << "Invalid task number." << endl;
  }
}
bool ToDoList::isTaskComplete(int index) const
{
  if (index >= 0 && index < tasks.size())
  {
    return tasks[index].isComplete();
  }
  else
  {
    cout << "Invalid Index." << endl;
    return false;
  }
}

/*
 * Displays Tasks by Category name
 * @param string categoryName
 */
void ToDoList::displayByCategory(string categoryName) const
{
  if (tasks.empty())
  {
    cout << "No tasks to display." << endl;
    return;
  }

  bool found = false;
  for (int i = 0; i < tasks.size(); i++)
  {
    if (tasks[i].getCategory().getName() == categoryName)
    {
      cout << i + 1 << ". " << tasks[i] << endl;
      found = true;
    }
  }

  if (!found)
  {
    cout << "No tasks found in category \"" << categoryName << "\"." << endl;
  }
}

bool ToDoList::saveToFile(const string &filename) const
{
  ofstream out(filename);
  if (!out.is_open())
    return false;

  for (size_t i = 0; i < tasks.size(); i++)
  {
    out << (i + 1) << ". "
        << tasks[i].getDescription() << " | "
        << tasks[i].getDueDate() << " | "
        << (tasks[i].isComplete() ? "Complete" : "Incomplete") << " | "
        << tasks[i].getCategory().getName() << " | "
        << tasks[i].getPriority()
        << endl;
  }

  out.close();
  return true;
}

/*
 * Returns the size of the ToDoList
 * @return size The number of Tasks in the ToDoList
 */
int ToDoList::size() const
{
  return tasks.size();
}