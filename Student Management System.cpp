#include"Student Management System.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    int choice = 1;
    char ch = '1';
    file.open("Semester.txt", ios::in);
    if (file)
    {
        cout << "File Opened" << endl;
        Ses = in();
        Year = stringtoint();
        ch = file.peek();
        while (ch != '=')
        {
            semester* read = new semester;
            read->semesterread();
            if (semHead == NULL)
            {
                semHead = read;
                semHead->semnptr = NULL;
            }
            else
            {
                semester* p = semHead;
                while (p->semnptr != NULL)
                    p = p->semnptr;
                p->semnptr = read;
                read->semnptr = NULL;
            }
            ch = file.peek();
        }


    }

    file.close();
    ch = '9';
    file.open("Faculty.txt", ios::in);
    if (file)
    {
        ch = file.peek();
        while (ch != '=')
        {
            faculty* readfac = new faculty;
            readfac->facultyread();
            if (FacHead == NULL)
            {
                FacHead = readfac;
                FacHead->nptr = NULL;
            }
            else
            {
                faculty* p = FacHead;
                while (p->nptr != NULL)
                    p = p->nptr;
                p->nptr = readfac;
                readfac->nptr = NULL;
            }
            ch = file.peek();
        }
    }

    file.close();
    ch = '2';
    file.open("Student.txt", ios::in);
    if (file)
    {
        ch = file.peek();
        while (ch != '=')
        {
            student* readstudent = new student;
            readstudent->studentwrite();
            if (StuHead == NULL)
            {
                StuHead = readstudent;
                StuHead->next = NULL;
            }
            else
            {
                student* curr = StuHead;
                while (curr->next != NULL)
                    curr = curr->next;
                readstudent->next = NULL;
                curr->next = readstudent;
            }
            ch = file.peek();
        }
    }
    file.close();
    student S;
    while (choice != 4)
    {

        cout << "=============================================" << endl;
        cout << "|                  MAIN MENU                |" << endl;
        cout << "=============================================" << endl;

        cout << "Login As" << endl;
        cout << "     1. Admin" << endl;
        cout << "     2. Student" << endl;
        cout << "     3. Faculty" << endl;
        cout << "     4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 2:
            if (studentlogin())
            {
                int choice2 = 9;
                while (choice2 != 4)
                {
                    cout << "---------------------------------------------" << endl;
                    cout << "   LOGGED IN AS STUDENT: " << studenttoset->getname() << endl;
                    cout << "---------------------------------------------" << endl;

                    cout << "1. Course Enrollment" << endl;
                    cout << "2. View Attendance" << endl;
                    cout << "3. View Grades" << endl;
                    cout << "4. Generate Fee Challan" << endl;
                    cout << "5. Exit" << endl;

                    cin >> choice2;
                    choice2--;
                    switch (choice2)
                    {
                    case 0:
                        studenttoset->enrollmentinstudent();
                        break;
                    case 1:
                        studenttoset->showattendance();
                        break;
                    case 2:
                        studenttoset->coursemarksdisplay();
                        break;
                    case 3:
                        studenttoset->generatechallan();
                        break;

                    }
                }

            }
            break;
        case 3:
            if (facultylogin())
            {
                int c = 9;
                while (c != 4)
                {
                    cout << "---------------------------------------------" << endl;
                    cout << "   LOGGED IN AS FACULTY MEMBER: " << facultytoset->getname() << endl;
                    cout << "---------------------------------------------" << endl;

                    cout << "1. Quizzes and Marks" << endl;
                    cout << "2. Grading" << endl;
                    cout << "3. Attendance" << endl;
                    cout << "4. Exit" << endl;
                    cout << "Enter Your Preference: "; cin >> c;
                    switch (c)
                    {
                    case 1:
                        facultytoset->setmarksandattendance();
                        break;
                    case 2:
                        facultytoset->grade();
                        break;
                    case 3:
                        facultytoset->attendance();
                        break;

                    }
                }
            }
            break;
        case 1:
            if (A.login())
            {

                int ch = 9;
                while (ch != 7)
                {
                    cout << "---------------------------------------------" << endl;
                    cout << "             LOGGED IN AS ADMIN" << endl;
                    cout << "---------------------------------------------" << endl;

                    cout << "1. Register Student" << endl;
                    cout << "2. Register Faculty Member" << endl;
                    cout << "3. Offer Semester and Courses" << endl;
                    cout << "4. Display All Courses" << endl;
                    cout << "5. Display All Students" << endl;
                    cout << "6. Display All Faculty Members" << endl;
                    cout << "7. Exit" << endl;
                    cin >> ch;
                    switch (ch)
                    {
                    case 1:
                        studentregistration();
                        break;
                    case 2:
                        registerfaculty();
                        break;
                    case 3:
                        A.OfferSemester();
                        A.displaysemester();
                        A.displayfaculty();
                    case 4:
                        A.displaysemester();
                        break;
                    case 5:
                        A.displaystudents();
                        break;
                    case 6:
                        A.displayfaculty();
                        break;
                    }
                }



            }



        }
        system("Pause");
        system("CLS");
    }
    file.open("Semester.txt", ios::out);
    file << Ses << endl << Year << endl;
    semester* write = semHead;
    while (write != NULL)
    {
        write->semesterwrite();
        write = write->semnptr;
    }
    file
        << "=";
    file.close();
    file.open("Faculty.txt", ios::out);
    faculty* writefaculty = FacHead;
    while (writefaculty != NULL)
    {
        writefaculty->facultywrite();
        writefaculty = writefaculty->nptr;
    }
    file << "=";

    file.close();
    file.open("Student.txt", ios::out);
    student* writestudent = StuHead;
    while (writestudent != NULL)
    {
        writestudent->studentwrite();
        writestudent = writestudent->next;
    }
    file << "=";

    file.close();
}