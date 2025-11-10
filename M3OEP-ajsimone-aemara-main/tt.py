import matplotlib.pyplot as plt

def read_tasks(filename="tasks.txt"):
   tasks = []
   with open(filename) as f:
       for line in f:
           if line.strip():
               description = line.split("|")[0].split(". ",1)[1]
               status = line.split("|")[2].strip()
               priority = line.split("|")[4].strip()
               tasks.append((description, status, priority))
   return tasks

def visualize_tasks(tasks):
   names = [t[0] for t in tasks]
   colors = []
   for t in tasks:
       if t[1] == "Complete":
           colors.append("green")
       else:
           colors.append("red")

   priorities = []
   for t in tasks:
       if t[2] == "0":  # LOW
           priorities.append(1)
       elif t[2] == "1":  # MEDIUM
           priorities.append(2)
       else:  # HIGH
           priorities.append(3)

   plt.figure(figsize=(10,5))
   plt.bar(names, priorities, color=colors)
   plt.xticks(rotation=45, ha="right")
   plt.ylabel("Priority (1=LOW, 2=MEDIUM, 3=HIGH)")
   plt.title("Task Visualization (green=complete, red=incomplete)")
   plt.tight_layout()
   plt.show()

if __name__ == "__main__":
   tasks = read_tasks()
   visualize_tasks(tasks)