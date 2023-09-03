#include "ucourse.h"

ucourse::ucourse() {};

int ucourse::readFile(string filename)
{
    std::ifstream file(filename);
    
    if(file.is_open())
    {
        string line, str;
        vector<string> data, tmp;

        while (getline(file, line))
            str += line + "\n";
        file.close();
        data = splitUltra(str, '\n');
        data.pop_back();

        for (string dt : data)
        {
            tmp = splitUltra(dt, ' ');
            Student stu;

            stu.stuID = stoi(tmp[0]);
            stu.surname = trim(tmp[1]);
            stu.name = trim(tmp[2]);
            stu.finalGrade = stoi(tmp[3]);
            stu.midtermGrade = stoi(tmp[4]);
            stu.THE1 = stoi(tmp[5]);
            stu.THE2 = stoi(tmp[6]);
            stu.THE3 = stoi(tmp[7]);
            stu.THE4 = stoi(tmp[8]);
            addStudent(stu);
        }
        return 1;
    }
    return 0;
}

void ucourse::addStudent(Student newStu)
{
    if(newStu.surname.empty())
    {
        string str;

        cout << "Enter information of student;" << endl;
        cout << "Name: ";
        cin >> str;
        newStu.name = trim(str);
        cout << "Surname: ";
        cin >> str;
        newStu.surname = trim(str);
        cout << "ID: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nID: ";
		    cin >> str;
	    }
        newStu.stuID = stoi(str);
        cout << "Final Grade: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nFinal Grade: ";
		    cin >> str;
	    }
        newStu.finalGrade = stoi(str);
        cout << "Midterm Grade: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nMidterm Grade: ";
		    cin >> str;
	    }
        newStu.midtermGrade = stoi(str);
        cout << "THE1 Grade: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nTHE1 Grade: ";
		    cin >> str;
	    }
        newStu.THE1 = stoi(str);
        cout << "THE2 Grade: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nTHE2 Grade: ";
		    cin >> str;
	    }
        newStu.THE2 = stoi(str);
        cout << "THE3 Grade: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nTHE3 Grade: ";
		    cin >> str;
	    }
        newStu.THE3 = stoi(str);
        cout << "THE4 Grade: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nTHE4 Grade: ";
		    cin >> str;
	    }
        newStu.THE4 = stoi(str);
        newStu.letter = calcLetterGrade(newStu);
        database.push_back(newStu);
        return;
    }
    newStu.letter = calcLetterGrade(newStu);
    database.push_back(newStu);
}

Student ucourse::findByID(int ID)
{
    Student stu;
    for(auto dta : database)
    {
        if(dta.stuID == ID)
            return dta;
    }
    return stu;
}

vector<Student> ucourse::findBySurname(string surname)
{
    vector<Student> founds;
    for(auto dta : database)
    {
        if(dta.surname == surname)
            founds.push_back(dta);
    }
    return founds;
}

void ucourse::updateByID(int ID)
{
    Student* stu;
    int isFound = 0;
    int i = 0;

    for(auto dt : database)
    {
        if(dt.stuID == ID)
        {
            stu = &database[i];
            isFound = 1;
            break;
        }
        i++;
    }
    if(isFound)
    {
        string str;

        cout << "Updating grades for student with ID: " << ID <<
        "\nCurrent final grade: " << stu->finalGrade << 
        "\nCurrent midterm grade: " << stu->midtermGrade <<
        "\nCurrent THE1 grade: " << stu->THE1 <<
        "\nCurrent THE2 grade: " << stu->THE2 << 
        "\nCurrent THE3 grade: " << stu->THE3 << 
        "\nCurrent THE4 grade: " << stu->THE4 << 
        "\nWhich grade do you want to update?" << 
        "\n1: Final, 2: Midterm, 3: THE1, 4: THE2, 5: THE3, 6: THE4: ";
        while(1)
        {
            cin >> str;
            if(str == "1")
            {
                cout << "Enter new final grade: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter new final grade: ";
		            cin >> str;
	            }
                stu->finalGrade = stoi(str);
                stu->letter = calcLetterGrade(*stu);
                cout << "Grades updated successfully!" << endl;
                break;
            }
            else if(str == "2")
            {
                cout << "Enter new midterm grade: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter new midterm grade: ";
		            cin >> str;
	            }
                stu->midtermGrade = stoi(str);
                stu->letter = calcLetterGrade(*stu);
                cout << "Grades updated successfully!" << endl;
                break;
            }
            else if(str == "3")
            {
                cout << "Enter new THE1 grade: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter new THE1 grade: ";
		            cin >> str;
	            }
                stu->THE1 = stoi(str);
                stu->letter = calcLetterGrade(*stu);
                cout << "Grades updated successfully!" << endl;
                break;
            }
            else if(str == "4")
            {
                cout << "Enter new THE2 grade: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter new THE2 grade: ";
		            cin >> str;
	            }
                stu->THE2 = stoi(str);
                stu->letter = calcLetterGrade(*stu);
                cout << "Grades updated successfully!" << endl;
                break;
            }
            else if(str == "5")
            {
                cout << "Enter new THE3 grade: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter new THE3 grade: ";
		            cin >> str;
	            }
                stu->THE3 = stoi(str);
                stu->letter = calcLetterGrade(*stu);
                cout << "Grades updated successfully!" << endl;
                break;
            }
            else if(str == "6")
            {
                cout << "Enter new THE4 grade: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter new THE4 grade: ";
		            cin >> str;
	            }
                stu->THE4 = stoi(str);
                stu->letter = calcLetterGrade(*stu);
                cout << "Grades updated successfully!" << endl;
                break;
            }
            else
            {
                std::cerr << "Wrong choice!\nWhich grade do you want to update?\n" << 
                "1: Final, 2: Midterm, 3: THE1, 4: THE2, 5: THE3, 6: THE4: ";
            }
        }
    }
    else
        std::cerr << "Student not found with ID: " << ID << endl;
}

void ucourse::deleteByID(int ID)
{
    int i = 0;
    for(auto dt : database)
    {
        if(dt.stuID == ID)
        {
            database.erase(database.begin() + i);
            return;
        }
        i++;
    }
    std::cerr << "Student not found with ID: " << ID << endl;
}

void ucourse::sortByID()
{
    int n = database.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j)
        {
            if (database[j].stuID > database[j + 1].stuID)
            {
                swap(database[j], database[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void ucourse::displayLetterGradeFile()
{
    for(auto dt : database)
        cout << dt.stuID << " " << dt.surname << " " << dt.name << " " << dt.letter << endl;
}

void ucourse::generateLetterGradeFile(string filename)
{
    ofstream outputFile(filename);

    if(outputFile.is_open())
    {
        for(auto dt : database)
            outputFile << dt.stuID << " " << dt.surname << " " << dt.name << " " << dt.letter << endl;
        outputFile.close();
        cout << "Letter grade file generated successfully." << endl;
        return;
    }
    std::cerr << "Letter grade file generated failed!" << endl;
}
