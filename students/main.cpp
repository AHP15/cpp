#include <iostream>
#include <vector>
#include <algorithm>

int getStudentNumber() {
    int input { 0 };
    do {
        std::cout << "Enter the number of students you want store: ";
        std::cin >> input;
    } while(input <= 0 || std::cin.fail());
    return input;
}

struct Student {
    std::string name {};
    float grade {};
};

using Students = std::vector<Student>;

Student getStudent(int studentNumber) {
    Student student {};
    do {
        std::cout << "Enter student " << studentNumber << " name: ";
        std::cin >> student.name;
    } while(std::cin.fail());

    do {
        std::cout << "Enter student " << studentNumber << " grade: ";
        std::cin >> student.grade;
    } while(std::cin.fail());

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

int main() {

    Students students { getStudents() };
    std::sort(students.begin(), students.end(), compareStudents);

    for(auto& student: students) {
        std::cout << student.name << " has a grade of: " << student.grade << '\n';
    };
    return 0;
}