#include "Did.hpp"

Did::Did(){};

Element Did::generateNewElement(string elementName)
{
    Element element;

    element.name = elementName;
    cout << "Enter the name of the material(at least 1)\nFor example: 'e-book' to 'Reading' element"
            "\nTo exit please type 'end'" << endl;
    while(1)
    {
        cout << "Enter Material: ";
        getline(cin, elementName);
        if(elementName == "end" && element.materials.size() > 0)
            break;
        if(elementName != "end")
            element.materials.insert(std::pair<string, bool>(elementName, false));
    }
    return element;
}

void Did::addElement(const Element& element)
{
    elements.push_back(element);
}

void Did::listElements(void)
{
    int i = 0;
    string input;
    if(elements.empty())
    {
        cout << "You don't have any elements yet!" << endl;
        return;
    }
    cout << "The elements:" << endl;
    for(auto element : elements)
    {
        cout << i + 1 << "- "<< element.name << endl;
        i++;
    }
    cout << "Enter the name of the element to see the materials\nFor example: 'Reading'" 
    " or 'end' to exit" << endl;
    while(1)
    {
        cout << "Enter element name: ";
        getline(cin, input);
        int i = 0;
        for(auto element : elements)
        {
            if(element.name == input)
            {
                cout << "Materials of [" << element.name << "]:" << endl;
                for(auto material : element.materials)
                {
                    cout << i + 1 << "- name: " << material.first << " | status: " << 
                    boolalpha << material.second << noboolalpha << endl;
                    i++;
                }
            }
        }
        if(input == "end")
            break;
        else if(i == 0)
            cout << "Wrong input!" << endl;
    }
}

void Did::randomHaveGetTask(void)
{
    if(elements.empty() || isHaveaTask)
    {
        cout << "You don't have any elements yet or you have a already task!" << endl;
        return;
    }
    vector<Element> falseElements;
    vector<string> falseMaterials;

    for(const auto& element : elements)
    {
        if(element.isCompleted == false)
            falseElements.push_back(element);
    }
    if(falseElements.empty())
    {
        cout << R"(

 ██████╗ ██████╗ ███╗   ██╗ ██████╗  ██████╗ ██████╗  █████╗ ████████╗██╗   ██╗██╗      █████╗ ████████╗██╗ ██████╗ ███╗   ██╗███████╗██╗
██╔════╝██╔═══██╗████╗  ██║██╔════╝ ██╔═══██╗██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██║     ██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝██║
██║     ██║   ██║██╔██╗ ██║██║  ███╗██║   ██║██████╔╝███████║   ██║   ██║   ██║██║     ███████║   ██║   ██║██║   ██║██╔██╗ ██║███████╗██║
██║     ██║   ██║██║╚██╗██║██║   ██║██║   ██║██╔══██╗██╔══██║   ██║   ██║   ██║██║     ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║╚════██║╚═╝
╚██████╗╚██████╔╝██║ ╚████║╚██████╔╝╚██████╔╝██║  ██║██║  ██║   ██║   ╚██████╔╝███████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║███████║██╗
 ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝

All tasks are completed!
Whole elements are resetting..
            )" << endl;
        progressBarEffc();
        for(int i = 0; i < elements.size(); i++)
        {
            elements[i].isCompleted = false;
            for(auto it = elements[i].materials.begin(); it != elements[i].materials.end(); ++it)
                it->second = false;
        }
        return;
    }
    else if(falseElements.size() == 1)
    {
        currentTask = falseElements[0];
        isHaveaTask = true;
        for(const auto& material : currentTask.materials)
        {
            if(material.second == false)
                falseMaterials.push_back(material.first);
        }
        if(falseMaterials.size() == 1)
            currentTaskMat = falseMaterials[0];
        else
        {
            srand(time(NULL));
            int randomElement = rand() % falseMaterials.size();
            currentTaskMat = falseMaterials[randomElement];
        }
        diceRollEffc();
        cout << "Result:" << endl;
        cout << "Your task is: " << currentTask.name << " -> " << currentTaskMat << endl;
        return;
    }
    else
    {
        srand(time(NULL));
        int randomElement = rand() % falseElements.size();
        currentTask = falseElements[randomElement];
        isHaveaTask = true;
        for(const auto& material : currentTask.materials)
        {
            if(material.second == false)
                falseMaterials.push_back(material.first);
        }
        if(falseMaterials.size() == 1)
            currentTaskMat = falseMaterials[0];
        else
        {
            srand(time(NULL));
            int randomElement = rand() % falseMaterials.size();
            currentTaskMat = falseMaterials[randomElement];
        }
        diceRollEffc();
        cout << "Result:" << endl;
        cout << "Your task is: " << currentTask.name << " -> " << currentTaskMat << endl;
        return;
    }
}

/*
void Did::displayCurrentTas(void)
{
    
}

void Did::updateElement(Element& element)
{

}

void Did::deleteElement(Element& element)
{

}

void Did::isHaveaAnyElement(void)
{

}

// Friend Functions
void getRandomMaterial(const Did& obj)
{
    
}

*/

