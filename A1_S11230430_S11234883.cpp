#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 20;

struct Student{
	string id;
	string grade;
	double coursework;
	double finalExam;
	double totalMark;
	
	void printAllDetails()
	{
        cout << setw(20) << id << setw(20) << coursework << setw(20) << totalMark << setw(20) << grade << endl;
    }
};

int validateInput(int lowerLimit, int upperLimit)
{
    int input;
    cin >> input;
    
    while(input < lowerLimit || input > upperLimit || cin.fail())
	{
        if (cin.fail())
		{
            cin.clear();
            string dummy;
            cin >> dummy;
            cout << "ERROR!. Invalid option was detected" << endl;
            cout << "Kindly enter a number" << endl;
        }
		else if (input < lowerLimit || input > upperLimit)
		{
            cin.clear();
            cout << "ERROR!. Your choice is not in range" << endl;
            cout << "Kindly enter a number between " << lowerLimit << " and " << upperLimit << endl;
        }
        cin >> input;
    }
    return input;
}

void welcomeMessage()
{
    cout << "+-------------------------------------------------+\n";
    cout << "|   WELCOME TO THE STUDENT MARKS SORTING PROGRAM  |\n";
    cout << "+-------------------------------------------------+\n";
}

void endProgram(bool& continueExecuting)
{
    continueExecuting = false;

    cout << endl;
    cout << "+-------------------------------------+\n";
    cout << "|  Thank you for using this program!  |\n";
    cout << "+-------------------------------------+\n";
}

void programStartQuit(bool& continueExecuting)
{
    char userDecision;
    cout << "Enter S to start or Q to quit" << endl;
    cin >> userDecision;
    
    while(userDecision != 'S' && userDecision != 's' && userDecision != 'Q' && userDecision != 'q') {
        cin.clear();
        string dummy;
        cin >> dummy;
        cout << "ERROR!, invalid input was detected" << endl;
        cout << "Please enter either \"S\" or \"Q\" only" << endl;
        cin >> userDecision;
    }
    
    if (userDecision == 'S' || userDecision == 's')
	{
		continueExecuting = true;
	}
	
	else if (userDecision == 'Q' || userDecision == 'q')
	{
		continueExecuting = false;
	}
}

void fillArray(string fileName, int& rows, Student students[])
{
	string readHeader;
	ifstream readFile;
	readFile.open(fileName.c_str());
	
	if (!readFile)
	{
		cout << "ERROR!. This file could not be found" << endl;
	}
	else 
	{
		getline(readFile, readHeader);
		
		while (readFile >> students[rows].id >> students[rows].coursework >> students[rows].finalExam)
		{
			rows++;
		}
	}
}

void calculateTotal(Student students[], int size)
{
	for (int i = 0; i < size; i++)
	{
		students[i].totalMark = students[i].coursework + students[i].finalExam;
	}
}

string determineGrade(double totalMark)
{
	if (totalMark >= 85)
	{
		return "A+";
	}
	else if (totalMark >= 78)
	{
		return "A";
	}
	else if (totalMark >= 71)
	{
		return "B+";
	}
	else if (totalMark >= 64)
	{
		return "B";
	}
	else if (totalMark >= 57)
	{
		return "C+";
	}
	else if (totalMark >= 50)
	{
		return "C";
	}
	else if (totalMark >= 40)
	{
		return "D";
	}
	else 
	{
		return "E";
	}
}

void printAllDetails(Student students[], int size)
{
	cout << "\nThe Entire List of Students with Grade:" << endl;
	cout << left << setw(20) << "ID" << setw(20) << "Coursework" << setw(20) << "Final Exam" << setw(20) << "Grade" << endl;
	
	for (int i = 0; i < size; i++)
	{
		students[i].totalMark = students[i].coursework + students[i].finalExam;
		string studentGrade = determineGrade(students[i].totalMark);
		students[i].grade = studentGrade;
		
		cout << left << setw(20) << students[i].id << setw(20) << students[i].coursework << setw(20) << students[i].finalExam << setw(20) << students[i].grade << endl;
	}
}



int main()
{
	Student students[SIZE];
	int size = 0;
	int rows = 0;
	int choice;
	bool continueExecuting = true;
	
	ifstream readFile;
	readFile.open("studentData.txt");
	
	welcomeMessage();
	
	programStartQuit(continueExecuting);
	
	while (continueExecuting)
	{
		rows = 0;
		
		fillArray("studentData.txt", rows, students);
		
		cout << endl;
		cout << "Menu:" << endl;
		cout << "1. Print Entire List with Grades" << endl;
		cout << "2. Update student's marks" << endl;
		cout << "3. Print Average marks" << endl;
		cout << "4. Print Pass Rate" << endl;
		cout << "5. Print the Highest Scorer's Details" << endl;
		cout << "6. Exit Program" << endl;
		choice = validateInput(1,6);
		
		if (choice == 1)
		{
			printAllDetails(students, rows);
		}
	}
	
	return 0;
}
