#include <iostream>
#include <cstring>

using namespace std;

const int MAX_TASKS = 100;

// Task structure
struct Task {
    string description;
    bool completed;

    Task() : completed(false) {}
};

// Function prototypes
void displayMenu();
void addTask(Task tasks[], int& taskCount);
void viewTasks(const Task tasks[], int taskCount);
void markCompleted(Task tasks[], int taskCount);
void deleteTask(Task tasks[], int& taskCount);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markCompleted(tasks, taskCount);
                break;
            case 4:
                deleteTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n======= To-Do List Manager =======\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

void addTask(Task tasks[], int& taskCount) {
    if (taskCount < MAX_TASKS) {
        cout << "Enter the task description: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, tasks[taskCount].description);
        taskCount++;
        cout << "Task added successfully!\n";
    } else {
        cout << "Task list is full. Cannot add more tasks.\n";
    }
}

void viewTasks(const Task tasks[], int taskCount) {
    cout << "\n======= Task List =======\n";
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << tasks[i].description << " - "
             << (tasks[i].completed ? "Completed" : "Pending") << "\n";
    }
}

void markCompleted(Task tasks[], int taskCount) {
    viewTasks(tasks, taskCount);

    if (taskCount > 0) {
        int index;
        cout << "Enter the number of the task to mark as completed: ";
        cin >> index;

        if (index > 0 && index <= taskCount) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number. Please try again.\n";
        }
    }
}

void deleteTask(Task tasks[], int& taskCount) {
    viewTasks(tasks, taskCount);

    if (taskCount > 0) {
        int index;
        cout << "Enter the number of the task to remove: ";
        cin >> index;

        if (index > 0 && index <= taskCount) {
            for (int i = index - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task number. Please try again.\n";
        }
    }
}

