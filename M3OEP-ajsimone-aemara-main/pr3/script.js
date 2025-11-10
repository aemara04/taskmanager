document.addEventListener('DOMContentLoaded', async function () {
    const taskList = document.getElementById('task-list');
    const taskModal = document.getElementById('taskModal');
    const taskNameInput = document.getElementById('taskName');

    async function loadTasks() {
        const response = await fetch('/tasks');
        const tasks = await response.json();

        taskList.innerHTML = '';
        if (tasks.length === 0) {
            taskList.innerHTML = '<p>No tasks yet!</p>';
        }

        tasks.forEach(task => {
            const card = document.createElement('div');
            card.classList.add('machine-card');
            card.innerHTML = `
        <h3>${task.name}</h3>
        <button class="ok-button" onclick="deleteTask('${task.id}')">Delete</button>
      `;
            taskList.appendChild(card);
        });
    }

    window.showAddModal = function () {
        taskModal.style.display = 'flex';
    }

    window.closeModal = function () {
        taskModal.style.display = 'none';
        taskNameInput.value = '';
    }

    window.addTask = async function () {
        const name = taskNameInput.value.trim();
        if (!name) return alert("Please enter a task name.");

        await fetch('/tasks', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ name })
        });

        closeModal();
        loadTasks();
    }

    window.deleteTask = async function (id) {
        await fetch(`/tasks/${id}`, { method: 'DELETE' });
        loadTasks();
    }

    loadTasks();
});
