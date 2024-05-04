#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "1. Add Task\n";
    cout << "2. Remove Task\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. List Tasks\n";
    cout << "5. Exit\n";
}

void saveTasksToFile(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt");
    if (outFile.is_open()) {
        for (const auto& task : tasks) {
            outFile << task.description << "," << task.completed << "\n";
        }
        outFile.close();
    } else {
        cout << "Unable to save tasks to file.\n";
    }
}

void loadTasksFromFile(vector<Task>& tasks) {
    ifstream inFile("tasks.txt");
    if (inFile.is_open()) {
        Task task;
        while (getline(inFile, task.description, ',')) {
            inFile >> task.completed;
            tasks.push_back(task);
            inFile.ignore();
        }
        inFile.close();
    } else {
        cout << "No tasks found.\n";
    }
}

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Task newTask;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, newTask.description);
                newTask.completed = false;
                tasks.push_back(newTask);
                break;
            }
            // Implement other menu options (2-5) here
        }

        saveTasksToFile(tasks);
    } while (choice != 5);

    return 0;
}
