#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.h"

void loadStudents(std::vector<Student*>& students, const std::string& filename);
void printStudents(const std::vector<Student*>& students);
void showStudentNames(const std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

int main(){
    std::vector<Student*> students;
    std::string filename = "students.csv";
    loadStudents(students, filename);
    std::string choice;
    while ((choice = menu()) != "0") {
        if (choice == "1"){
            showStudentNames(students);
        }
        else if (choice == "2"){
            printStudents(students);
        }
        else if (choice == "3"){
            findStudent(students);
        }
        else{
            std::cout << "Invalid choice, please select 0-6." << std::endl;
        }
    }
    delStudents(students);
    return 0;
}

void loadStudents(std::vector<Student*>& students, const std::string& filename){
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)){
        Student* student = new Student(line);
        students.push_back(student);
    }
    file.close();
}
void printStudents(const std::vector<Student*>& students){
    for (const auto& student : students){
        student->printStudent();
        std::cout << "____________________________________" << std::endl;
    }
}

void showStudentNames(const std::vector<Student*>& students){
    for (const auto& student : students){
        std::cout << student->getLastFirst() << std::endl;
    }
}

void findStudent(std::vector<Student*>& students){
    std::string target;
    bool notFound = true;
    std::cout << "last name of student: ";
    getline(std::cin, target);
    for (Student* s : students){
        std::string lName = s->getLastName();
        if (lName.find(target) != std::string::npos){
            s->printStudent();
            notFound = false;
        }
    }
    if (notFound){
        std::cout << "Student " << target << " not found" << std::endl;
    }
}

void delStudents(std::vector<Student*>& students){
    for (Student* student : students) {
        delete student;
    }
    students.clear();
}

std::string menu(){
    std::string choice;
    std::cout << "0) quit\n";
    std::cout << "1) print all student names\n";
    std::cout << "2) print all student data\n";
    std::cout << "3) find a student\n";
    std::cout << "please choose 0-3: ";
    getline(std::cin, choice);
    return choice;
}
