#ifndef DID_HPP
#define DID_HPP

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <thread>

using std::cout;
using std::cin;
using std::cerr;

using std::string;
using std::endl;

using std::map;
using std::vector;

using std::boolalpha;
using std::noboolalpha;

struct Element
{
    string name;
    bool isCompleted = false;
    map<string, bool> materials;
};

class Did
{
public:
    Did();

    Element generateNewElement(string elementName);
    void addElement(const Element& element);
    void listElements(void);
    void randomElement(void);
/*
    void isHaveaAnyTask(void);
    void updateElement(Element& element);
    void deleteElement(Element& element);
    void Save(void);
    void Load(void);
*/

private:
    vector<Element> elements;
    bool isHaveaTask = false;
};

void welcome(Did& did);
int theMenu(Did& did);
void progressBar(void);

#endif