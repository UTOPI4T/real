#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile() {
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    ofstream file(fileName);

    if (!file) {
        cerr << "Error creating file!" << endl;
        return;
    }

    cout << "File created successfully." << endl;
    file.close();
}

void deleteFile() {
    string fileName;
    cout << "Enter file name to delete: ";
    cin >> fileName;

    if (remove(fileName.c_str()) != 0) {
        cerr << "Error deleting file!" << endl;
        return;
    }

    cout << "File deleted successfully." << endl;
}

int main() {
    int choice;
    cout << "File Management System" << endl;
    cout << "1. Create File" << endl;
    cout << "2. Delete File" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            createFile();
            break;
        case 2:
            deleteFile();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Exiting program." << endl;
            break;
    }

    return 0;
}
