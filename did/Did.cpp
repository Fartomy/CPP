#include "Did.hpp"

Did::Did(){};

Element Did::generateNewElement(string elementName)
{
    Element element;

    for(auto &elm : elements)
    {
        if(elm.name == elementName)
            return element;
    }
    element.name = elementName;
    cout << "[Menu-1] Enter the name of the material (at least 1)\nFor example: 'e-book' to 'Reading' element"
            "\nTo exit please type 'end'"
         << endl;
    while (1)
    {
        cout << "[Menu-1] Enter Material: ";
        getline(cin, elementName);
        if (elementName == "end" && element.materials.size() > 0)
            break;
        if (elementName != "end")
            element.materials.insert(std::pair<string, bool>(elementName, false));
    }
    return element;
}

void Did::addElement(const Element &element)
{
    if(element.name.empty())
    {
        cout << "This element already exists!" << endl;
        return;
    }
    else
    {
        elements.push_back(element);
        Save(*this);
    }
}

void Did::listElements(void)
{
    int i = 0;
    string input;
    if (elements.empty())
    {
        cout << "[Menu-4] You don't have any elements yet!" << endl;
        return;
    }
    cout << "[Menu-4] The elements:" << endl;
    for (auto element : elements)
    {
        cout << i + 1 << "- " << element.name << " | status: " << boolalpha << element.isCompleted << noboolalpha << endl;
        i++;
    }
    cout << "[Menu-4] Enter the name of the element to see the materials\nFor example: 'Reading'"
            " or 'end' to exit"
         << endl;
    while (1)
    {
        cout << "[Menu-4] Enter element name: ";
        getline(cin, input);
        int i = 0;
        for (auto element : elements)
        {
            if (element.name == input)
            {
                cout << "[Menu-4] Materials of [" << element.name << "]:" << endl;
                for (auto material : element.materials)
                {
                    cout << i + 1 << "- " << material.first << " | status: " << boolalpha << material.second << noboolalpha << endl;
                    i++;
                }
            }
        }
        if (input == "end")
            break;
        else if (i == 0)
            cout << "[Menu-4] Wrong input!" << endl;
    }
}

void Did::randomHaveGetTask(void)
{
    if (elements.empty() || isHaveaTask)
    {
        cout << "[Menu-2] You don't have any elements yet or you have a already task!" << endl;
        return;
    }
    vector<Element> falseElements;
    vector<string> falseMaterials;

    for (const auto &element : elements)
    {
        if (element.isCompleted == false)
            falseElements.push_back(element);
    }
    if (falseElements.empty())
    {
        cout << R"(
[Menu-2]
 ██████╗ ██████╗ ███╗   ██╗ ██████╗  ██████╗ ██████╗  █████╗ ████████╗██╗   ██╗██╗      █████╗ ████████╗██╗ ██████╗ ███╗   ██╗███████╗██╗
██╔════╝██╔═══██╗████╗  ██║██╔════╝ ██╔═══██╗██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██║     ██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝██║
██║     ██║   ██║██╔██╗ ██║██║  ███╗██║   ██║██████╔╝███████║   ██║   ██║   ██║██║     ███████║   ██║   ██║██║   ██║██╔██╗ ██║███████╗██║
██║     ██║   ██║██║╚██╗██║██║   ██║██║   ██║██╔══██╗██╔══██║   ██║   ██║   ██║██║     ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║╚════██║╚═╝
╚██████╗╚██████╔╝██║ ╚████║╚██████╔╝╚██████╔╝██║  ██║██║  ██║   ██║   ╚██████╔╝███████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║███████║██╗
 ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝

All tasks are completed!
Whole elements are resetting..
            )"
             << endl;
        progressBarEffc();
        for (int i = 0; i < elements.size(); i++)
        {
            elements[i].isCompleted = false;
            for (auto it = elements[i].materials.begin(); it != elements[i].materials.end(); ++it)
                it->second = false;
        }
        Save(*this);
        return;
    }
    else if (falseElements.size() == 1)
    {
        currentTask = falseElements[0];
        isHaveaTask = true;
        for (const auto &material : currentTask.materials)
        {
            if (material.second == false)
                falseMaterials.push_back(material.first);
        }
        if (falseMaterials.size() == 1)
            currentTaskMat = falseMaterials[0];
        else
        {
            srand(time(NULL));
            int randomElement = rand() % falseMaterials.size();
            currentTaskMat = falseMaterials[randomElement];
        }
        diceRollEffc();
        cout << "[Menu-2] Result:" << endl;
        cout << "[Menu-2] Your task is: " << currentTask.name << " -> " << currentTaskMat << endl;
        Save(*this);
        return;
    }
    else
    {
        srand(time(NULL));
        int randomElement = rand() % falseElements.size();
        currentTask = falseElements[randomElement];
        isHaveaTask = true;
        for (const auto &material : currentTask.materials)
        {
            if (material.second == false)
                falseMaterials.push_back(material.first);
        }
        if (falseMaterials.size() == 1)
            currentTaskMat = falseMaterials[0];
        else
        {
            srand(time(NULL));
            int randomElement = rand() % falseMaterials.size();
            currentTaskMat = falseMaterials[randomElement];
        }
        diceRollEffc();
        cout << "[Menu-2] Result:" << endl;
        cout << "[Menu-2] Your task is: " << currentTask.name << " -> " << currentTaskMat << endl;
        Save(*this);
        return;
    }
}

void Did::completeTask(void)
{
    if (elements.empty() || !isHaveaTask)
    {
        cout << "You don't have any elements yet or you have not a task!" << endl;
        return;
    }
    string input;
    cout << "Are you sure? (y/n): ";
    getline(cin, input);
    if (input == "y")
    {
        for (auto &element : elements)
        {
            if (element.name == currentTask.name)
            {
                for (auto &material : element.materials)
                {
                    if (material.first == currentTaskMat)
                    {
                        material.second = true;
                        break;
                    }
                }
                break;
            }
        }
        for (auto &element : elements)
        {
            if (element.name == currentTask.name)
            {
                bool isAllCompleted = true;
                for (auto &material : element.materials)
                {
                    if (material.second == false)
                    {
                        isAllCompleted = false;
                        break;
                    }
                }
                if (isAllCompleted)
                {
                    element.isCompleted = true;
                    isHaveaTask = false;
                    currentTaskMat.clear();
                    currentTask.name.clear();
                    cout << R"(
╦ ╦╔═╗╔╗╔╔╦╗╔═╗╦═╗╔═╗╦ ╦╦  
║║║║ ║║║║ ║║║╣ ╠╦╝╠╣ ║ ║║  
╚╩╝╚═╝╝╚╝═╩╝╚═╝╩╚═╚  ╚═╝╩═╝o
You have completed all material!
                )" << endl;
                    Save(*this);
                    return;
                }
                else
                {
                    isHaveaTask = false;
                    currentTaskMat.clear();
                    currentTask.name.clear();
                    cout << R"(
╦ ╦╔═╗╔╗╔╔╦╗╔═╗╦═╗╔═╗╦ ╦╦  
║║║║ ║║║║ ║║║╣ ╠╦╝╠╣ ║ ║║  
╚╩╝╚═╝╝╚╝═╩╝╚═╝╩╚═╚  ╚═╝╩═╝o
You have completed the material!
                )" << endl;
                    Save(*this);
                    return;
                }
            }
        }
    }
    else
    {
        cout << "Canceled!" << endl;
        return;
    }
}

void Did::displayCurrentTask(void)
{
    if (elements.empty() || !isHaveaTask)
    {
        cout << "[Menu-6] You don't have any elements yet or you have not a task!" << endl;
        return;
    }
    cout << R"(
[Menu-6]
 ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄    ▄ 
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌
 ▀▀▀▀█░█▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀       ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌ ▐░▌ 
     ▐░▌     ▐░▌       ▐░▌▐░▌                    ▐░▌     ▐░▌       ▐░▌▐░▌          ▐░▌▐░▌  
     ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄           ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌░▌   
     ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌          ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌    
     ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀           ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░▌░▌   
     ▐░▌     ▐░▌       ▐░▌▐░▌                    ▐░▌     ▐░▌       ▐░▌          ▐░▌▐░▌▐░▌  
     ▐░▌     ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄           ▐░▌     ▐░▌       ▐░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░▌ ▐░▌ 
     ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌          ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌
      ▀       ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀            ▀       ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀    ▀ 

    )" << endl;
    cout << "[Menu-6] [" << currentTask.name << " -> " << currentTaskMat << "]" << endl;
}

void Did::editElement(string elementName)
{
    if (elements.empty())
    {
        cout << "[Menu-3.1] You don't have any elements yet!" << endl;
        return;
    }

    string input;
    cout << "[Menu-3.1.1] Select to edit option\n1- Edit element name\n2- Edit material name\n"
            "To exit please type 'end'"
         << endl;

    while (1)
    {
        cout << "[Menu-3.1.1] Enter choice: ";
        getline(cin, input);
        if (input == "1")
        {
            bool isFound = false;
            for (auto &element : elements)
            {
                if (element.name == elementName)
                {
                    isFound = true;
                    cout << "[Menu-3.1.1.1] Enter a new element name for [" << element.name << "]: ";
                    getline(cin, input);
                    element.name = input;
                    if (currentTask.name == elementName)
                        currentTask.name = input;
                    break;
                }
            }
            if (isFound)
            {
                cout << "[Menu-3.1.1.1] Element name changed!" << endl;
                Save(*this);
            }
            else
                cout << "[Menu-3.1.1.1] Element not found!" << endl;
            input.clear();
            break;
        }
        else if (input == "2")
        {
            cout << "[Menu-3.1.1.2] Enter the name of the material of [" << elementName << "]: ";
            getline(cin, input);
            bool isFound = false;
            for (auto &element : elements)
            {
                if (element.name == elementName)
                {
                    isFound = true;
                    auto it = element.materials.find(input);
                    if (it != element.materials.end())
                    {
                        bool valueStat = it->second;
                        element.materials.erase(it);
                        cout << "[Menu-3.1.1.2] Enter a new material name: ";
                        getline(cin, input);
                        element.materials[input] = valueStat;
                        if (currentTask.name == elementName && currentTaskMat == input)
                            currentTaskMat = input;
                    }
                    else
                        cout << "[Menu-3.1.1.2] Material not found!" << endl;
                    break;
                }
            }
            if (!isFound)
                cout << "[Menu-3.1.1.2] Material name is not changed because element not found!" << endl;
            else
            {
                cout << "[Menu-3.1.1.2] Material name changed!" << endl;
                Save(*this);
            }
            input.clear();
            break;
        }
        else if (input == "end")
            break;
        else
        {
            cout << "[Menu-3.1.1] Wrong input!" << endl;
            input.clear();
        }
    }
}

void Did::addElementMaterial(string elementName, string materialName)
{
    if (elements.empty())
    {
        cout << "[Menu-3.1.2] You don't have any elements yet!" << endl;
        return;
    }
    bool isFound = false;
    for (auto &element : elements)
    {
        if (element.name == elementName)
        {
            isFound = true;
            element.materials.insert(std::pair<string, bool>(materialName, false));
            break;
        }
    }
    if (isFound)
    {
        cout << "[Menu-3.1.2] Material added!" << endl;
        Save(*this);
    }
    else
        cout << "[Menu-3.1.2] Element not found!" << endl;
}

void Did::deleteElement(string elementName)
{
    if (elements.empty())
    {
        cout << "[Menu-5] You don't have any elements yet!" << endl;
        return;
    }
    else if (currentTask.name == elementName)
    {
        cout << "[Menu-5] You can't delete the element because you have a task!" << endl;
        return;
    }
    string input;
    cout << "[Menu-5.1] Are you sure? (y/n): ";
    getline(cin, input);
    if (input == "y")
    {
        bool isFound = false;
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (it->name == elementName)
            {
                isFound = true;
                elements.erase(it);
                break;
            }
        }
        if (isFound)
        {
            cout << "[Menu-5.1] Element deleted! [" << elementName << "]"<< endl;
            Save(*this);
        }
        else
            cout << "[Menu-5.1] Element not found!" << endl;
    }
    else
        cout << "[Menu-5.1] Canceled!" << endl;
}

void Did::deleteElementMaterial(string elementName, string matName)
{
    if (elements.empty())
    {
        cout << "[Menu-5] You don't have any elements yet!" << endl;
        return;
    }
    else if(currentTaskMat == matName && currentTask.name == elementName)
    {
        cout << "[Menu-5] You can't delete the material because you have a task!" << endl;
        return;
    }
    string input;
    cout << "[Menu-5.2] Are you sure? (y/n): ";
    getline(cin, input);
    if (input == "y")
    {
        bool isFound = false;
        for (auto &element : elements)
        {
            if (element.name == elementName)
            {
                isFound = true;
                auto it = element.materials.find(matName);
                if (it != element.materials.end())
                {
                    element.materials.erase(it);
                    break;
                }
                else
                {
                    cout << "[Menu-5.2] Material not found!" << endl;
                    return;
                }
            }
        }
        if (isFound)
        {
            cout << "[Menu-5.2] Material deleted! [" << matName << "]" << endl;
            Save(*this);
        }
        else
            cout << "[Menu-5.2] Material not deleted because element not found!" << endl;
    }
    else
        cout << "[Menu-5.2] Canceled!" << endl;
}
