#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;
};
class TodoList {
private:
    vector<Task> tasks;
public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task '" << description << "' added successfully!" << endl;
    }
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                const Task& task = tasks[i];
                string status = task.completed ? "Completed" : "Pending";
                cout << i + 1 << ". " << task.description << " - " << status << endl;
            }
        }
    }
    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
    void removeTask(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            string removedDescription = tasks[taskIndex].description;
            tasks.erase(tasks.begin() + taskIndex);
            cout << "Task '" << removedDescription << "' removed successfully." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};
int main() {
    TodoList todoList;
    while (true) {
        cout << "\nTodo List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); 
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex - 1); 
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex - 1); 
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
