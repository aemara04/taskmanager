from flask import Flask, jsonify, request
import subprocess
import json

app = Flask(__name__)

@app.route('/tasks', methods=['GET'])
def get_tasks():
    # Run your C++ program to get the list of tasks
    result = subprocess.run(["./backend/task_manager", "--list"], capture_output=True, text=True)
    try:
        tasks = json.loads(result.stdout)
    except json.JSONDecodeError:
        tasks = []
    return jsonify(tasks)

@app.route('/tasks', methods=['POST'])
def add_task():
    data = request.get_json()
    name = data.get("name")
    subprocess.run(["./backend/task_manager", "--add", name])
    return jsonify({"message": "Task added!"})

@app.route('/tasks/<task_id>', methods=['DELETE'])
def delete_task(task_id):
    subprocess.run(["./backend/task_manager", "--remove", task_id])
    return jsonify({"message": "Task removed!"})

if __name__ == "__main__":
    app.run(debug=True)
