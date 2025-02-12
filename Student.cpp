#include "Student.h"
#include <sstream>
#include <stdexcept>

// 構造函數（int perm, std::string lastName, std::string firstAndMiddleNames）
Student::Student(int perm, std::string lastName, std::string firstAndMiddleNames)
    : perm(perm), lastName(lastName), firstAndMiddleNames(firstAndMiddleNames) {}

// 透過 CSV 字串初始化 Student
Student::Student(std::string csvString) {
    std::stringstream ss(csvString);
    std::string permStr;

    // 讀取並解析 CSV
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

// 取得學生編號
int Student::getPerm() const {
    return perm;
}

// 取得姓氏
std::string Student::getLastName() const {
    return lastName;
}

// 取得名字（含中間名）
std::string Student::getFirstAndMiddleNames() const {
    return firstAndMiddleNames;
}

// 取得全名
std::string Student::getFullName() const {
    return firstAndMiddleNames + " " + lastName;
}

// 轉換為字串格式
std::string Student::toString() const {
    return "[" + std::to_string(perm) + "," + lastName + "," + firstAndMiddleNames + "]";
}

