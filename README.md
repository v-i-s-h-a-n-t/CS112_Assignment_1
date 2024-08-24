Student Performance Analysis & Reworking
Contributors
This project was completed by:

Rohan Nandan - S11234883
Vishant Kumar - S11230430
Files
A1_S11230430_S11234883.cpp: The main C++ source code file.
studentData.txt: The text file containing the student data.
Overview
This project is designed to analyze and process student performance data from a text file (studentData.txt). The program calculates and displays statistics related to students coursework and final exam scores.

Key Features
Data Input & Display: The program reads student marks data from a text file (studentData.txt) and display it to the user.
Updatable Marks: Student marks can be updated separately or together at once.
Average Calculation: It calculates the average mark for the class by adding every coursework and final exam mark then dividing by total number of students.
Pass Rate: It determines the percent of students that have passed based on thresholds.
Identification of Top Overall Scorer: The program identifies the student with the highest scores using the combination of coursework and final exam marks.
Option Execution
Depending on the option selected by the user, the following processes may occur:

Option 1: Calculate and Display All Marks with Grade

Process:
The program calculates the total scores for each student.
The program checks each student's scores against defined if..else statement thresholds to assignement each student a grade.
Output:
Student ID, coursework marks, final exam marks and grade for all students are printed and displayed to user.
Option 2: Update Student Marks

Process:
Entering a student ID, the program will search if that ID exists in database. If it does not then error message will be shown to user.
If student ID is found successfully then the user will have the option to update only coursework marks, only final exam marks or both.
All options have been input valided to avoid marks below 0 and above 50 to be entered.
New grade is calculated based on which marks were changed
Output:
ID of student with adjusted marks along with new grade if applicable will be printed and shown to user.
Option 3: Average For Class

Process:
The program calculates the total score for the class by adding all students coursework and final exam marks.
The total score is then divided by the total number of students in the database.
Output:
Displays and prints the class average to the user.
Option 4: Pass Rate

Process:
The program calculates the total for each student and checks it against the threshold of 50.
It then calculates the total number of students that have gotten equal to or greater than 50 and divides it by total students.
The final calculation is multiplied by 100 to be turned into a percentage.
Output:
Percent of students that have passed is displayed to user.
Option 5: Print Highest Scorer Details

Process:
The program calulcatesthe total for each student and identifies the student with the highest overall score.
Output:
Student ID, coursework, final exam marks and grade of highest scorer is displayed to user.
Option 6: Exit Program

Process:
The program leaves the loop and terminates.
Output:
End program message is displayed to user.
