#include "ucourse.h"

vector<string> splitUltra(const string& str, char delimiter)
{
    vector<string> tokens;
    string token;
    string::size_type start = 0;
    string::size_type end = str.find(delimiter);

    while (end != string::npos)
    {
        token = str.substr(start, end - start + 1);
        tokens.push_back(token);
        start = end + 1;
        end = str.find(delimiter, start);
    }

    token = str.substr(start);
    tokens.push_back(token);

    return tokens;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

string calcLetterGrade(Student& stu)
{
    double wea, theOvr, endGrd;

    if(stu.finalGrade < 25)
        return "F";
    wea = ((stu.finalGrade * 0.45) + (stu.midtermGrade * 0.35)) / 0.8;
    if(wea < 35)
        return "F";
    if(stu.THE1 > 1.6 * wea)
        stu.THE1 = 1.6 * wea;
    if(stu.THE2 > 1.6 * wea)
        stu.THE2 = 1.6 * wea;
    if(stu.THE3 > 1.6 * wea)
        stu.THE3 = 1.6 * wea;
    if(stu.THE4 > 1.6 * wea)
        stu.THE4 = 1.6 * wea;

    theOvr = (stu.THE1 + stu.THE2 + stu.THE3 + stu.THE4) * 0.05;
    endGrd = (stu.finalGrade * 0.45) + (stu.midtermGrade *.35) + theOvr;

    if(endGrd >= 89)
        return "A";
    if(endGrd >= 83 && endGrd < 89)
        return "A-";
    if(endGrd >= 77 && endGrd < 83)
        return "B+";
    if(endGrd >= 71 && endGrd < 77)
        return "B";
    if(endGrd >= 65 && endGrd < 71)
        return "B-";
    if(endGrd >= 59 && endGrd < 65)
        return "C+";
    if(endGrd >= 53 && endGrd < 59)
        return "C";
    if(endGrd >= 47 && endGrd < 53)
        return "C-";
    if(endGrd >= 41 && endGrd < 47)
        return "D+";
    if(endGrd >= 35 && endGrd < 41)
        return "D";
    return "F";
}

bool isNumber(string nbr)
{
	int i = -1;
	while (nbr[++i])
	{
		if(!isdigit(nbr[i]))
			return (false);
	}
	return (true);
}