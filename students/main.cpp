#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getStudentNumber() {
    int input { 0 };
    while(true) {
        std::cout << "Enter the number of students you want store: ";
        std::cin >> input;
    
        if (!std::cin.fail()) return input;

        std::cin.clear();
        ignoreLine(); 
    }
}

struct Student {
    std::string name {};
    float grade {};
};

using Students = std::vector<Student>;

Student getStudent(int studentNumber) {
    Student student {};
    while(true) {
        std::cout << "Enter student " << studentNumber << " name: ";
        std::cin >> student.name;

        if (!std::cin.fail()) break;

        std::cin.clear();
        ignoreLine(); 
    }
    while(true) {
        std::cout << "Enter student " << studentNumber << " grade: ";
        std::cin >> student.grade;

        if (!std::cin.fail()) break;

        std::cin.clear();
        ignoreLine(); 
    }

    return student;
};

Students getStudents() {
    int numberOfStudents { getStudentNumber() };
    Students students(static_cast<Students::size_type>(numberOfStudents));

    int studentNumber { 1 };
    for(auto& student: students) {
        student = getStudent(studentNumber);
        ++studentNumber;
    };

    return students;
};

bool compareStudents(Student s1, Student s2) {
    return s1.grade > s2.grade;
};

void printByCharecter(const char* str) {
    // While we haven't encountered a null terminator
  while (*str != '\0') {
    // print the current character
    std::cout << *str;

    // and point str at the next character
    ++str;
  }
};

int main() {

    printByCharecter("Hello world!");
    Students students { getStudents() };
    std::sort(students.begin(), students.end(), compareStudents);

    for(auto& student: students) {
        std::cout << student.name << " has a grade of: " << student.grade << '\n';
    };
    return 0;
}