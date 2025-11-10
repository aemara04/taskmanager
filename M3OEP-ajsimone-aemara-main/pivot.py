import turtle

# Read task durations from a file (format: "task_name, duration_in_minutes")
tasks = []
with open("tasks.txt") as f:
    for line in f:
        parts = line.strip().split(",")
        if len(parts) == 2 and parts[1].isdigit():
            tasks.append((parts[0], int(parts[1])))

# Setup turtle screen
turtle.setup(width=800, height=400)
turtle.bgcolor("white")
turtle.title("Task Duration Visualizer")

pen = turtle.Turtle()
pen.speed(0)
pen.penup()
pen.goto(-350, 0)
pen.pendown()

# Draw color bars based on duration
for task, duration in tasks:
    if duration < 30:
        color = "green"
    elif duration < 60:
        color = "yellow"
    else:
        color = "red"

    pen.fillcolor(color)
    pen.begin_fill()
    for _ in range(2):
        pen.forward(duration * 3)  # scale width
        pen.right(90)
        pen.forward(40)
        pen.right(90)
    pen.end_fill()
    
    # Label the bar
    pen.penup()
    pen.forward(10)
    pen.setheading(90)
    pen.forward(10)
    pen.write(task, align="left", font=("Arial", 10, "bold"))
    pen.setheading(0)
    pen.backward(10)
    pen.right(90)
    pen.forward(50)
    pen.pendown()

turtle.done()
