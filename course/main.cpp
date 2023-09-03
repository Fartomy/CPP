#include "ucourse.h"

void welcome(ucourse& obj)
{
    string cmd, inputFile;

    inputFile = "input.txt";
    cout << "Enter your choice: ";
    cin >> cmd;
    if(cmd == "1")
    {
        int i = obj.readFile(inputFile);
        if(i == 0)
            std::cerr << "File Error!" << endl;
    }
    else if(cmd == "2")
    {
        Student stu;

        obj.addStudent(stu);
    }
    else if(cmd == "3")
    {
        string str;
        while(1)
        {
            cout << "Enter 1 for ID, 2 for surname: ";
            cin >> str;
            if(str == "1")
            {
                Student stu;
                int id;

                cout << "Enter ID: ";
                cin >> str;
                while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	            {
		            cout << "Please type a number!\nEnter ID: ";
		            cin >> str;
	            }
                stu = obj.findByID(stoi(str));
                if(stu.surname.empty())
                {
                    std::cerr << "Student not found with ID: " << str << endl;
                    break;
                }
                cout << stu.name << " " << stu.surname << " " << stu.letter << endl;
                break;
            }
            if(str == "2")
            {
                vector<Student> res;

                cout << "Enter Surname: ";
                cin >> str;
                res = obj.findBySurname(str);
                if(res.size() < 1)
                {
                    std::cerr << "Student/Students not found with surname: "<< str << endl;
                    break;
                }
                for(auto rs : res)
                    cout << rs.name << " " << rs.surname << " " << rs.letter << endl;
                break;
            }
            else
                std::cerr << "Wrong Input!" << endl;
        }
    }
    else if(cmd == "4")
    {
        string str;

        cout << "Enter ID: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nEnter ID: ";
		    cin >> str;
	    }
        obj.updateByID(stoi(str));
    }
    else if(cmd == "5")
    {
        string str;

        cout << "Enter ID: ";
        cin >> str;
        while (!isNumber(str)) // Bu cikti istenmiyorsa bu donguyu silin.
	    {
		    cout << "Please type a number!\nEnter ID: ";
		    cin >> str;
	    }
        obj.deleteByID(stoi(str));
    }
    else if(cmd == "6")
    {
        obj.sortByID();
        obj.displayLetterGradeFile();
    }
    else if(cmd == "7")
    {
        string str;

        obj.sortByID();
        cout << "Enter the output filename: ";
        cin >> str;
        obj.generateLetterGradeFile(str);
    }
    else if(cmd == "8")
    {
        cout << "END OF THE PROGRAM!" << endl;
        exit(0);
    }
    else
        cout << "Invalid choice." << endl;

}

int main(void)
{
    ucourse obj;

    cout << "Welcome to UCourse!\nPlease select your action:" << endl <<
    "1. Read grades from a file" << endl <<
    "2. Enter a new student" << endl <<
    "3. Find a student" << endl <<
    "4. Update a student" << endl <<
    "5. Delete a student" << endl <<
    "6. Display grades" << endl <<
    "7. Generate letter grade file" << endl <<
    "8. Exit program" << endl;

    while(1)
        welcome(obj);
    return 0;
}