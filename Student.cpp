#include "Student.h"
#include <sstream>
#include <stdexcept>

Student::Student(int perm, std::string lastName, std::string firstAndMiddleNames)
    : perm(perm), lastName(lastName), firstAndMiddleNames(firstAndMiddleNames) {}

Student::Student(std::string csvString) {
    std::stringstream ss(csvString);
    std::string permStr;

    if (!std::getline(ss, permStr, ',') ||
        !std::getline(ss, lastName, ',') ||
        !std::getline(ss, firstAndMiddleNames, ',')) {
        throw std::invalid_argument("Invalid CSV format: " + csvString);
    }

    try {
        perm = std::stoi(permStr);
    } catch (std::exception &e) {
        throw std::invalid_argument("Invalid perm value: " + permStr);
    }
}

int Student::getPerm() const {
    return perm;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getFirstAndMiddleNames() const {
    return firstAndMiddleNames;
}

std::string Student::getFullName() const {
    return firstAndMiddleNames + " " + lastName;
}

std::string Student::toString() const {
    return "[" + std::to_string(perm) + "," + lastName + "," + firstAndMiddleNames + "]";
}

