//
// Created by Anna on 10/2/2025.

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ToDoList.h"
#include "RecurringTask.h"
using namespace std;

int getValidInt(string message, int minVal, int maxVal);
string getValidDate();

int main()
{
  ToDoList toDo;
  int choice = 0;

  while (choice != 12)
  {
    cout << "----- To Do List Menu ----" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Remove Task" << endl;
    cout << "3. Display All Tasks" << endl;
    cout << "4. Display Tasks by Priority" << endl;
    cout << "5. Display Incomplete Tasks" << endl;
    cout << "6. Display Overdue Tasks" << endl;
    cout << "7. Display Tasks Before a Date" << endl;
    cout << "8. Display Tasks by Category" << endl;
    cout << "9. Mark Task as Complete" << endl;
    cout << "10. Add Recurring Task" << endl;
    cout << "11. Write to a file" << endl;
    cout << "12. Exit" << endl;

    choice = getValidInt("Enter Choice (1-12): ", 1, 12);

    // Implementing the menu
    switch (choice)
    {
      // Add a task
    case 1:
    {
      string desc;
      cout << "Enter Task Description: ";
      getline(cin, desc);

      string date = getValidDate();
      int priorityChoice = getValidInt("Enter Priority (1 = LOW, 2 = MEDIUM, 3 = HIGH): ", 1, 3);
      Priority priority;
      if (priorityChoice == 1)
      {
        priority = LOW;
      }
      else if (priorityChoice == 2)
      {
        priority = MEDIUM;
      }
      else
      {
        priority = HIGH;
      }
      string categoryName;
      cout << "Enter Task Category Name: ";
      getline(cin, categoryName);

      Task newTask(desc, date, priority, false, Category(categoryName));
      toDo.addTask(newTask);
      break;
    }
      // Remove a task
    case 2:
    {
      // Check to see if ToDoList is empty
      if (toDo.size() == 0)
      {
        cout << "No tasks to remove." << endl;
        break;
      }
      else
      {
        int taskNumber = getValidInt("Enter Task Number: ", 1, toDo.size());
        int index = taskNumber - 1;
        toDo.removeTask(index);
        break;
      }
    }
      // Display all tasks
    case 3:
    {
      toDo.displayAll();
      break;
    }
      // Display task by priority
    case 4:
    {
      int priorityChoice = getValidInt("Enter priority (1 = LOW, 2 = MEDIUM, 3 = HIGH): ", 1, 3);
      Priority priority;
      if (priorityChoice == 1)
      {
        priority = LOW;
      }
      else if (priorityChoice == 2)
      {
        priority = MEDIUM;
      }
      else
      {
        priority = HIGH;
      }
      toDo.displayByPriority(priority);
      break;
    }
      // Display incomplete tasks
    case 5:
    {
      toDo.displayIncomplete();
      break;
    }
    // Display overdue tasks
    case 6:
    {
      string today;
      cout << "Enter today's date: ";
      today = getValidDate();
      toDo.displayOverdue(today);
      break;
    }
    // Display tasks due before a certain date
    case 7:
    {
      string cutoff = getValidDate();
      toDo.displayBeforeDate(cutoff);
      break;
    }

    // Display tasks by Category
    case 8:
    {
      string categoryName;
      cout << "Enter Category name: ";
      getline(cin, categoryName);
      toDo.displayByCategory(categoryName);
      break;
    }

      // Mark task as complete
    case 9:
    {
      if (toDo.size() == 0)
      {
        cout << "No tasks to mark complete." << endl;
        break;
      }
      else
      {
        int taskNumber = getValidInt("Enter a task number to mark complete: ", 1, toDo.size());
        int index = taskNumber - 1;
        toDo.markTaskComplete(index);
        break;
      }
    }
    case 10:
    {
      string desc;
      cout << "Enter Recurring Task Description: ";
      getline(cin, desc);

      string date = getValidDate();
      int priorityChoice = getValidInt("Enter Priority (1 = LOW, 2 = MEDIUM, 3 = HIGH): ", 1, 3);
      Priority priority;
      if (priorityChoice == 1)
      {
        priority = LOW;
      }
      else if (priorityChoice == 2)
      {
        priority = MEDIUM;
      }
      else
      {
        priority = HIGH;
      }

      int recurDays = getValidInt("Enter recurrence interval (in days): ", 1, 365);
      RecurringTask newTask(desc, date, priority, false, Category(), recurDays);

      toDo.addTask(newTask);
      break;
    }
    case 11:
    {
      string filename;
      cout << "Enter filename to save to (e.g., todolist.txt): ";
      getline(cin, filename);

      if (toDo.saveToFile(filename))
      {
        cout << "To-Do List saved to " << filename << endl;
      }
      else
      {
        cout << "Error saving file." << endl;
      }
      break;
    }
      // Exit
    case 12:
    {
      cout << "Goodbye!" << endl;
      break;
    }
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  ofstream out("tasks.txt");
  for (int i = 0; i < toDo.size(); i++)
  {
    out << toDo.getTask(i).getDescription() << endl;
  }
  out.close();

  return 0;
}

/*
 * Prompts the user for an integer within a specified range
 * Repeatedly asks user for input until a valid integer is entered.
 * @param message The prompt message displayed to the user
 * @param minVal The minimum acceptable integer value
 * @param maxVal The maximum acceptable integer value
 * @return A valid integer entered by the user
 */
int getValidInt(string message, int minVal, int maxVal)
{
  string input;
  int num;

  while (true)
  {
    cout << message;
    getline(cin, input);
    if (input.length() == 0)
    {
      cout << "No input. " << message;
    }
    else
    {
      stringstream ss(input);
      ss >> num;

      if (!ss.fail())
      {
        string leftover;
        if (ss >> leftover)
        {
          cout << "Invalid input. " << message << endl;
        }
        else if (num < minVal || num > maxVal)
        {
          cout << "Number out of range (" << minVal << "-" << maxVal << "). " << endl;
        }
        else
        {
          return num;
        }
      }
      else
      {
        cout << "Invalid input. " << message << endl;
      }
    }
  }
}

/*
 * Prompts the user for a valid date
 * Uses getValidInt to validate the integers in date
 * @return a date in the format "MM/DD/YYYY"
 */
string getValidDate()
{
  int month, day, year;
  // Get month from user
  month = getValidInt("Enter a month (1-12): ", 1, 12);
  // Use month to determine valid day
  int daysInMonth;
  if (month == 2)
  {
    daysInMonth = 28;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    daysInMonth = 30;
  }
  else
  {
    daysInMonth = 31;
  }
  // Get day from user
  day = getValidInt("Enter a day (1-" + to_string(daysInMonth) + "): ", 1, daysInMonth);
  // Get year from user
  year = getValidInt("Enter year: ", 2024, 9999);
  // Format the values to a string to compare
  string date;
  // Format month
  if (month < 10)
  {
    date += "0" + to_string(month) + "/";
  }
  else
  {
    date += to_string(month) + "/";
  }
  // Format day
  if (day < 10)
  {
    date += "0" + to_string(day) + "/";
  }
  else
  {
    date += to_string(day) + "/";
  }
  // Format year
  date += to_string(year);
  return date;
}
#include <fstream>
