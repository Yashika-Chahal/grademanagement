#include <iostream>
#include <string>
using namespace std;

// Structure to represent a student
struct Student {
    int id;
    string name;
    int marks[3]; // Array for storing marks in 3 subjects
    int totalMarks; // Total marks

    // Function to calculate total marks
    void calculateTotal() {
        totalMarks = marks[0] + marks[1] + marks[2];
    }
};

// Function to display student details
void displayStudent(Student s) {
    cout << "ID: " << s.id << "\tName: " << s.name << "\tMarks: ";
    for (int i = 0; i < 3; i++) {
        cout << s.marks[i] << " ";
    }
    cout << "\tTotal Marks: " << s.totalMarks << endl;
}

// Function to input student data
void inputStudent(Student &s) {
    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Student Name: ";
    cin >> s.name;
    cout << "Enter marks in 3 subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> s.marks[i];
    }
    s.calculateTotal();
}

// Function to display all students
void displayAllStudents(Student students[], int n) {
    cout << "\nStudent List:\n";
    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }
}

// Bubble Sort to sort students by total marks
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].totalMarks < students[j+1].totalMarks) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

// Binary Search by Student ID
int binarySearch(Student students[], int n, int targetID) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].id == targetID) {
            return mid;
        } else if (students[mid].id < targetID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // ID not found
}

// Main function
int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    
    Student students[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        inputStudent(students[i]);
    }

    // Display all students before sorting
    displayAllStudents(students, n);

    // Sort students by total marks
    bubbleSort(students, n);

    // Display sorted students
    cout << "\nStudents sorted by total marks:\n";
    displayAllStudents(students, n);

    // Search for a student by ID
    int searchID;
    cout << "\nEnter student ID to search: ";
    cin >> searchID;

    int result = binarySearch(students, n, searchID);
    if (result != -1) {
        cout << "\nStudent found:\n";
        displayStudent(students[result]);
    } else {
        cout << "\nStudent with ID " << searchID << " not found.\n";
    }

    return 0;
}
