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

/*
void Did::updateElement(Element& element)
{

}

void Did::deleteElement(Element& element)
{

}

void Did::isHaveaAnyElement(void)
{

}

void Did::randomElement(void)
{

}
*/