#include "Roster.h"
#include <sstream>
#include <iostream>
#include <algorithm>

Roster::Roster() : numStudents(0) {}

int Roster::getNumStudents() const {
    return numStudents;
}

Student Roster::getStudentAt(int index) const {
    if (index >= 0 && index < numStudents) {
        return *students[index];
    }
    throw std::out_of_range("Index out of bounds");
}

void Roster::addStudentsFromStream(std::istream &is) {
    std::string line;
    bool firstLine = true;
    while (std::getline(is, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        if (numStudents < ROSTER_MAX) {
            students[numStudents] = new Student(line);
            numStudents++;
        } else {
            std::cerr << "Roster is full, cannot add more students!" << std::endl;
            break;
        }
    }
}

void Roster::resetRoster() {
    for (int i = 0; i < numStudents; i++) {
        delete students[i];
    }
    numStudents = 0;
}

int Roster::indexOfMaxPermAmongFirstKStudents(int k) const {
    int maxIndex = 0;
    for (int i = 1; i < k; i++) {
        if (students[i]->getPerm() > students[maxIndex]->getPerm()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void Roster::sortByPermHelper(int k) {
    int maxIndex = indexOfMaxPermAmongFirstKStudents(k);
    std::swap(students[maxIndex], students[k - 1]);
}

void Roster::sortByPerm() {
    for (int i = numStudents; i > 1; i--) {
        sortByPermHelper(i);
    }
}

std::string Roster::toString() const {
    std::stringstream ss;
    ss << "{\n";
    for (int i = 0; i < numStudents; i++) {
        ss << students[i]->toString();  // 直接輸出學生資訊
        if (i < numStudents - 1) {  // 只有在非最後一個元素時加上換行
            ss << ",\n";
        }
    }
    ss << "\n}";
    return ss.str();
}
