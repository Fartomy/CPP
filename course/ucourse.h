#pragma once

// ucourse.h

#ifndef UCOURSE_H
#define UCOURSE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string surname;
    int stuID;
    int finalGrade;
    int midtermGrade;
    int THE1, THE2, THE3, THE4;
    string letter;
};

class ucourse {
public:
    ucourse();

    int readFile(string);
    void addStudent(Student);
    Student findByID(int);
    vector<Student> findBySurname(string);
    void updateByID(int);
    void deleteByID(int);
    void sortByID();
    void displayLetterGradeFile();
    void generateLetterGradeFile(string);

private:
    vector<Student> database;
};

vector<string> splitUltra(const string& str, char delimiter);
string trim(const string& str);
string calcLetterGrade(Student& stu);
bool isNumber(string nbr);

#endif // UCOURSE_H
