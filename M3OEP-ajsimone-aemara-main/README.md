# M2OEP-ajsimone-aemara
Anna Simonelli and Anne Mara

We built off of Anna's module 1 project, which was a To Do List. The project is made up of the following classes:

Task class:
- Represents a single task. Stores its description (string), due date (string in the format MM/DD/YYYY), priority
(enumerated type), completion status (boolean), and a Category (of type Category)
- The class includes methods to update its features, mark it as complete, or mark it as overdue
- The class implements overloaded operators to compare tasks equality (check for duplicates) and inequalities 
(compare by due date)
- Overloaded operators create a clear output for the tasks

Category class:
- A task has-a Category
- A category is a string to describe each Task's type. Examples include, School, Work, Grocery, Personal, etc

RecurringTask class:
- A RecurringTask is a Task that repeats. For example, I have had weekly notes due for many of my classes. For this type of Task, the user can enter how often the task recurs (whether its every 7 days for a weekly task, or 30 for a monthly) and they won't have to enter it each period

ToDoList class:
- Manages a collection of Task objects in a vector. This is a has-a relationship.
- A ToDoList can add a new task to the vector, remove a task by index, display all tasks, display tasks by priority, display by category 
- display incomplete tasks, display overdue tasks, display tasks by category, and mark tasks as complete

Testing class:
- Tests all of the planned methods for functionality


The main program provides an interactive menu for the user to implement the methods of a ToDo list and contains input 
validation.


Input is validated through a getValidInt function, which validates integers in a specified range, and a 
getValidDate function which calls getValidInt to get the numeric components of a date, then converts them to a string 
in the format "MM/DD/YYYY"

During our collaboration, we had trouble with both of our programming running on both machines at the same time. We would pull and each of our programs would not always show the entirety of what was in git. All of the work we completed showed up in git, but after some last minute changes to write our ToDoList to an output file, it no longer sucessfully ran.

Future work would be ensuring that our program is bug-free. We would need to take more time for the collaboration process. We could also include improving date handling, maybe by making it a Date class. Additionally, we could 
add sorting options (such as by priority or by date). 

We did not use any code outside of this class. 

Using the rubric here is the grade we think we deserve: 

Main program complexity and usability:
- Based on the rubric I think our program earns 5 points. It is buggy on our end. Though the code we need does all appear in git and not on our own personal computers, so this issue may be resolved.


Has-A ToDoList
- Has a Task
- This is the fundamental part of our program. This was working from the getgo
- We think this deserves 20 points


Has-A Category
- This offers an additional way to sort our Tasks on the ToDoList
- While it is very simple, it has a strong functionality
- We think this deserves 10 points

Is-A RecurringTask
- I think its very common to have recurring tasks, especially for school
- It isn't implemented as strong as we would have liked
- We think it earns 10 points

File output
- As we last ran it, this had bugs
- In concept, this adds a lot of depth to our program, we just didn't end up sucessfully executing it
- We think it earns 3 points



Loss of points:
- Contributions are all made within 72 hours (-10)
- No vide (-10)

Estimated points: 28
