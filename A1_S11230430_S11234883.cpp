#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 20;

struct Student{
	string id;
	double coursework;
	double finalExam;
	double totalMark;
	
	void printDetails()
	{
		cout << left << setw(20) << "ID" << setw(20) << "Coursework" << setw(20) << "Final Exam" << setw(20) << "Total" << endl;
        cout << setw(20) << id << setw(20) << coursework << setw(20) << finalExam << setw(20) << totalMark << endl;
    }
};

void printAverageMarks(Student students[], int size)
{
    double totalMarks = 0.0;

    for (int i = 0; i < size; i++)
    {
        students[i].totalMark = students[i].coursework + students[i].finalExam;
        totalMarks += students[i].totalMark;
    }

    double averageMarks = totalMarks / size;

    cout << "\nThe average marks for the class are: " << fixed << setprecision(2) << averageMarks << endl;
}

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
            cout << "ERROR! Invalid option detected." << endl;
            cout << "Please enter a number." << endl;
        }
		else if (input < lowerLimit || input > upperLimit)
		{
            cin.clear();
            cout << "ERROR! Your choice is not in range." << endl;
            cout << "Please enter a number between " << lowerLimit << " and " << upperLimit << endl;
        }
        cin >> input;
    }
    return input;
}

void printWelcomeMessage()
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

void displayMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Print Entire List with Grades" << endl;
	cout << "2. Update Student's Marks" << endl;
	cout << "3. Print Average marks" << endl;
	cout << "4. Print Pass Rate" << endl;
	cout << "5. Print the Highest Scorer's Details" << endl;
	cout << "6. Exit Program" << endl;
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
        cout << "ERROR! Invalid input detected." << endl;
        cout << "Please enter either \"S\" or \"Q\" only." << endl;
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
	ifstream readFile(fileName.c_str());
	
	if (!readFile)
	{
		cout << "ERROR! File could not be found." << endl;
		exit(1); // Exiting as the file is not found
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

void printEntireList(Student students[], int size)
{
	cout << "\nThe Entire List of Students with Grades:" << endl;
	cout << left << setw(20) << "ID" << setw(20) << "Coursework" << setw(20) << "Final Exam" << setw(20) << "Grade" << endl;
	
	for (int i = 0; i < size; i++)
	{
		students[i].totalMark = students[i].coursework + students[i].finalExam;
		string studentGrade = determineGrade(students[i].totalMark);
		
		cout << left << setw(20) << students[i].id << setw(20) << students[i].coursework << setw(20) << students[i].finalExam << setw(20) << studentGrade << endl;
	}
}

void updateMark(Student students[], int size)
{
	string searchId;
	bool found = false;
	
	cout << "Please enter the ID number you would like to search. Example: S122243" << endl;
	cin >> searchId;
	while(cin.fail())
	{
		cin.clear();
		string dummy;
		cin >> dummy;
		cout << "ERROR! Invalid Input Detected." << endl;
		cout << "Please enter letter \"S\" in uppercase followed by numbers only." << endl;
		cin >> searchId;
	}
	
	for (int i = 0; i < size; i++)
	{
		if (students[i].id == searchId)
		{
			found = true;
			cout << "Enter the new coursework mark: ";
			cin >> students[i].coursework;
			
			cout << "Enter the new final exam mark: ";
			cin >> students[i].finalExam;
			
			students[i].totalMark = students[i].coursework + students[i].finalExam;
			
			cout << "Marks Updated Successfully!" << endl;
			students[i].printDetails();
			break;
		}
	}
	
	if (!found)
	{
		cout << "No student was found with the ID# " << searchId << endl;
	}
}

int main()
{
	Student students[SIZE];
	int size = 0;
	int rows = 0;
	int choice;
	bool continueExecuting = true;
	
	ifstream readFile("studentData.txt");
	
	cout << fixed << setprecision(2) << endl;
	
	printWelcomeMessage();
	
	programStartQuit(continueExecuting);
	
	while (continueExecuting)
	{
		rows = 0;
		
		fillArray("studentData.txt", rows, students);
		
		cout << endl;
		displayMenu();
		choice = validateInput(1,6);
		
		if (choice == 1)
		{
			printEntireList(students, rows);
		}
		else if (choice == 2)
		{
			updateMark(students, rows);
		}
		else if (choice == 3)
		{
		    printAverageMarks(students, rows);
		}
		else if (choice == 6)
		{
			endProgram(continueExecuting);
		}
	}
	
	return 0;
}