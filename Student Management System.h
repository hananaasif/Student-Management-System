#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
fstream file;
int semarray[4];
bool sessionselected = 0;
string temppp;
int temm;
int stringtoint()
{
    getline(file, temppp);
    temm = stoi(temppp);
    return temm;
}
string in()
{
    getline(file, temppp);
    return temppp;
}

class semester;
semester* semHead = NULL;
class course;
course* coursesofallsem = NULL;
string Ses;
int Year;
class faculty;
faculty* facultytoset;
class student;
student* studenttoset;
student* StuHead;
class user
{
protected:
    string username, password;
public:
    user(string pass)
    {
        password = pass;
    }
    user()
    {

    }
    string getusername()
    {
        return username;
    }
    string getpassword()
    {
        return password;
    }
};

class num
{

};
class courselink
{
public:
    string name;
    courselink* nptr;
protected:

};
class faculty :public user
{
protected:
    string name;
    int phone, exten;
    courselink* head = NULL;
    int numofc = 0;
public:
    faculty* nptr;
    void facultywrite();
    void facultyread();

    void grade();
    void attendance();
    void setmarksandattendance();
    void setfaculty(string n, string m)
    {
        numofc = 1;
        name = n;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Extension: ";
        cin >> exten;
        cout << "Enter Id: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        courselink* ptr = new courselink;
        ptr->name = m;
        head = ptr;
        head->nptr = NULL;
    }
    void setfaculty(string n)
    {
        numofc = 0;
        name = n;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Extension: ";
        cin >> exten;
        cout << "Enter Id: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
    }
    void addcourse(string course)
    {
        numofc++;

        courselink* ptr = new courselink;
        ptr->name = course;
        if (head == NULL)
        {
            head = ptr;
            head->nptr == NULL;
        }
        else

        {
            courselink* cptr = head;
            while (cptr->nptr != NULL)
                cptr = cptr->nptr;
            cptr->nptr = ptr;
            ptr->nptr = NULL;
        }
    }
    faculty()
    {

    }
    string getname()
    {
        return name;
    }
    void facdis()
    {
        if (numofc != 0)
            cout << left << setw(20) << name << setw(20) << phone << setw(20) << exten << setw(20) << head->name << endl;
        else
            cout << left << setw(20) << name << setw(20) << phone << setw(20) << exten << setw(20) << "NA" << endl;
        if (head != NULL)
        {
            courselink* ptr = head->nptr;
            while (ptr != NULL)
            {
                if (numofc == 0)
                    cout << left << setw(20) << " " << setw(20) << " " << setw(20) << " " << setw(20) << ptr->name << endl;
                ptr = ptr->nptr;
            }
        }



    }
};
faculty* FacHead = NULL;
class semester;

class course
{
protected:
    string title, code, instructor;
    int credit, students = 0;
    int quizt = 0, assignt = 0, markst = 0, attendancet = 0;
    int quiz = 0, assign = 0, marks = 0, attendance = 0;
    int quizw = 0, assignw = 0, marksw = 0;
    string studentenrolled[100];
    bool marksset = 0;
    bool attendaceset = 0;
    bool marksuploaded = 0;
public:
    course* counptr;
    string temp;
    void coursewriteforsemester();
    void coursereadforsemester();

    void gradee();
    void courseattendance();
    void studenttocourseset()
    {
        if (marksuploaded == 0)
        {
            cout << "yahan 6" << endl;
            cout << "Enter Quiz Marks out of " << quizt << " : "; cin >> quiz;
            cout << "Enter Assignment Marks out of " << assignt << " : "; cin >> assign;
            cout << "Enter Sessional Marks out of " << markst << " : "; cin >> marks;

            marksuploaded = 1;
        }
        else
        {
            int choose;
            cout << "Marks already entered" << endl;
            cout << "Press 1 if you want to edit" << endl;
            cout << "Press 2 to view previously updated marks" << endl;
            cout << "Press any key to exit" << endl;
            cin >> choose;
            if (choose == 1)
            {
                cout << "Enter Quiz Marks out of " << quizt << " : "; cin >> quiz;
                cout << "Enter Assignment Marks out of " << assignt << " : "; cin >> assign;
                cout << "Enter Sessional Marks out of " << markst << " : "; cin >> marks;
                marksset = 1;
            }
            if (choose == 2)
            {
                cout << "Quiz Marks out of " << quizt << " : " << quiz << endl;
                cout << "Assignment Marks out of " << assignt << " : " << assign << endl;
                cout << "Sessional Marks out of " << markst << " : " << marks << endl;
            }
        }
    }
    void markattendance()
    {
        if (attendaceset == 0)
        {
            cout << "Course Title: " << title << endl;
            cout << "Presents out of " << attendancet << " : ";
            cin >> attendance;
            attendaceset = 1;
        }
        else
        {
            int choose;
            cout << "Marks already entered" << endl;
            cout << "Press 1 if you want to edit" << endl;
            cout << "Press 2 to view previously updated marks" << endl;
            cout << "Press any key to exit" << endl;
            cin >> choose;
            if (choose == 1)
            {
                cout << "Course Title: " << title << endl;
                cout << "Presents out of " << attendancet << " : ";
                cin >> attendance;
            }
            if (choose == 2)
            {
                viewattendane();
            }
        }
    }
    void showcourse()
    {
        course* ptr;
        cout << "Title: " << title << endl;
        cout << "Code: " << code << endl;
        cout << "Instructor: " << credit << endl;
        cout << "Students Enrolled: " << students << endl;
        cout << "Quiz Marks: " << quizt << endl;
        cout << "Quiz Weightage: " << quizw << endl;
        cout << "Assignment Marks: " << assignt << endl;
        cout << "Assignment Weightage: " << assignw << endl;
        cout << "Sessional Marks: " << markst << endl;
        marksw = 50 - quizw - marksw;
    }
    void showmarks()
    {
        if (marksuploaded == 1)
        {
            float a = 0;
            cout << endl;
            cout << "COURSE NAME: " << title << endl;
            cout << left << setw(12) << "Quizzes: " << quiz << "/" << quizt << endl;
            cout << left << setw(12) << "Assignments: " << assign << "/" << assignt << endl;
            cout << left << setw(12) << "Sessional: " << marks << "/" << markst << endl << endl;
            cout << quizw << assignw << marksw;
            cout << "ABSOLUTE MARKS:" << endl;
            float b = ceil((assign / assignt) * assignw);
            cout << left << setw(12) << "Quizzes: " << (float)(((float)quiz / (float)quizt) * (float)quizw) << "/" << quizw << endl;
            a = ceil((quiz / quizt) * quizw);
            cout << left << setw(12) << "Assignments: " << (float)(((float)assign / (float)assignt) * (float)assignw) << "/" << assignw << endl;
            a += ceil((assign / assignt) * assignw);
            cout << left << setw(12) << "Sessional: " << (float)(((float)marks / (float)markst) * (float)(marksw)) << "/" << 50 - quizw - assignw << endl << endl;
            a += (float)((float)(marks / (float)markst)) * (float)marksw;
            cout << setw(12) << "TOTAL MARKS: " << a / 50;



        }
        else
        {
            cout << "Marks not uploaded yet" << endl;
        }
    }
    string returntitle()
    {
        return title;
    }
    void copy(course& obj)
    {
        obj.title = title;
        obj.code = code;
        obj.instructor = instructor;
        obj.credit = credit;
        obj.quizt = quizt;
        obj.assignt = assignt;
        obj.markst = markst;
        obj.attendancet = attendancet;
    }
    string titlereturn()
    {
        return title;
    }
    void viewattendane()
    {

        if (attendaceset == 1)
        {
            float a;
            a = (attendance / attendancet) * 100;
            cout << setw(15) << "COURSE NAME: " << title << endl << endl;
            cout << setw(15) << "TOTAL WORKING DAYS: " << attendancet << endl;
            cout << setw(15) << "PRESENT: " << attendance << endl;
            cout << setw(15) << "ABSENTS: " << attendancet - attendance << endl;
            cout << setw(15) << "PERCENTAGE:" << a << endl;

        }
        else
        {
            cout << endl << "Attendance  of" << title << " not uploaded yet" << endl;
        }
    }
    void setmarks();

    string addstudent(int& credithours, string name, course taken[10], int& count)
    {
        static int sts = 0;
        credithours += credit;
        studentenrolled[sts] = name;
        sts++;
        students++;
        cout << "Successfully Enrolled in " << title << endl;
        taken[count].title = title;
        taken[count].code = code;
        taken[count].credit = credit;
        taken[count].instructor = instructor;
        return title;
    }
    string returnname()
    {
        return title;
    }
    void courseset()
    {
        cout << "Enter Course Title: ";
        cin.ignore(1);
        getline(cin, title);
        cout << "Enter Course Code: ";
        cin >> code;
        cout << "Enter Course Credit Hours: ";
        cin >> credit;
        cout << "Enter Faculty Member: ";
        cin.ignore(1);
        getline(cin, instructor);
        faculty* ch = FacHead;
        int a = 0;
        string ab;
        if (FacHead != NULL)
        {
            while (ch != NULL)
            {
                ab = ch->getname();
                if (ab == instructor)
                {
                    a = 1;
                    cout << endl << "FACULTY MEMBER REGISTERED" << endl;
                    ch->addcourse(title);
                    break;
                }
                ch = ch->nptr;
            }
        }

        if (a == 0)
        {
            cout << "Faculty Member not Registered" << endl << "Register Faculty Member" << endl;

            faculty* facptr = new faculty;
            facptr->setfaculty(instructor, title);
            if (FacHead == NULL)
            {
                FacHead = facptr;
                FacHead->nptr = NULL;
            }
            else
            {
                faculty* Fac = FacHead;
                while (Fac->nptr != NULL)
                    Fac = Fac->nptr;
                Fac->nptr = facptr;
                facptr->nptr = NULL;

            }
        }

    }
    void displaycourse()
    {
        if (marksset == 1)
        {
            if (marksuploaded == 1)
                cout << left << setw(20) << title << setw(20) << code << setw(20) << credit << setw(20) << instructor << setw(20) << "Yes" << setw(20) << "Yes" << endl;
            else
                cout << left << setw(20) << title << setw(20) << code << setw(20) << credit << setw(20) << instructor << setw(20) << "Yes" << setw(20) << "No" << endl;
        }

        else
            cout << left << setw(20) << title << setw(20) << code << setw(20) << credit << setw(20) << instructor << setw(20) << "No" << setw(20) << "No" << endl;


    }

};

class semester
{
protected:
    string sem;
    int num, yr, numc;

public:
    course* array;
    void semesterread();

    void semesterwrite();
    void addcourses(string name, int& credithours, string coursetaken[10], int& numof, course obj[10], int& count)
    {

        cout << "How many courses do you want to enroll in? ";
        cin >> numof;
        cout << "COURSES:" << endl;
        for (int i = 0; i < numc; i++)
        {
            cout << i + 1 << ". " << array[i].returnname() << endl;
        }
        int n;
        for (int i = 0; i < numof; i++)
        {
            cout << "Enter Your Preference(Number): ";
            cin >> n;
            coursetaken[i] = array[n - 1].addstudent(credithours, name, obj, count);
            cout << "semester:::Student: " << name << "Credit Hours: " << credithours << endl;
        }

    }
    void enrollcourses(int& nu, course Head[10], int& credit, string nameofstudent)
    {
        string strr;
        int coursenum;
        credit = 0;
        cout << "How many courses do you want to enroll? ";
        cout << numc << " courses available in  Semester " << num << endl;
    rec:
        cin >> nu;
        if (nu > numc)
        {
            cout << "Only " << numc << " courses available in  Semester " << num << endl;
            cout << "Enter valid number: ";
            goto rec;
        }
        cout << "COURSES AVAILABLE: " << endl;
        for (int i = 0; i < numc; i++)
        {
            cout << i + 1 << ". " << array[i].returnname() << endl;
        }
        for (int i = 0; i < nu; i++)
        {
            cout << "Course " << i + 1 << ": ";
        avail:
            cin >> coursenum;
            if (coursenum > numc)
            {
                cout << "Choose from available options:" << endl;
                goto avail;
            }
            course* ptr = new course(array[coursenum]);
            strr = array[coursenum].addstudent(credit, nameofstudent, Head, numc);
            array[coursenum].copy(array[coursenum]);
            cout << "Course Enrolled" << endl;
            if (Head == NULL)
            {
                Head = ptr;
                Head->counptr = NULL;
            }
            else
            {
                course* cp = Head;
                while (cp->counptr != NULL)
                    cp = cp->counptr;
                cp->counptr = ptr;
                ptr->counptr = NULL;
            }
        }

    }
    int returnnum()
    {
        return num;
    }
    int returnnumc()
    {
        return numc;
    }
    void enrolldisplay()
    {
        cout << "Semester " << num << " of " << sem << " " << yr << endl;
    }
    void set(string a, int b, int c, int d)
    {
        sem = a;
        yr = b;
        num = c;
        numc = d;
    }
    semester* semnptr;
    void courses(int num)
    {
        array = new course[num];
        for (int i = 0; i < num; i++)
        {
            cout << endl << "COURSE " << i + 1 << ": " << endl;
            array[i].courseset();
        }
    }
    void displayy()
    {
        cout << endl << "SEMESTER " << num << endl;
        cout << left << setw(20) << "COURSE TITLE" << setw(20) << "COURSE CODE" << setw(20) << "CREDIT HOURS" << setw(20) << "INSTRUCTOR" << setw(20) << "MARKS SET" << setw(20) << "GRADED" << endl;
        for (int i = 0; i < numc; i++)
        {
            array[i].displaycourse();
        }


    }
    void displayycou()
    {
        cout << left << setw(20) << "COURSE TITLE" << setw(20) << "COURSE CODE" << setw(20) << "CREDIT HOURS" << setw(20) << "INSTRUCTOR" << endl;
        for (int i = 0; i < numc; i++)
        {
            array[i].displaycourse();
        }

    }
};


void faculty::setmarksandattendance()
{
    string cours;
    courselink* cou = head;
    cours = cou->name;
    int a = 1;
    if (cou->nptr != NULL)
    {
        while (cou != NULL)
        {
            cout << a++ << ". " << cou->name << endl;
            cou = cou->nptr;
        }
        cout << "Select Course to Set Marks and Attendance:";
        cin >> a;
        cou = head;
        for (int i = 0; i < a; i++)
        {
            cours = cou->name;
            cou = cou->nptr;
        }
    }
    cout << "Name of Course: " << cours;
    semester* ptr = semHead;
    string name;
    int a1;
    while (ptr != NULL)
    {
        a1 = ptr->returnnumc();
        cout << "Number of courses: " << a1;
        for (int i = 0; i < a1; i++)
        {
            name = ptr->array[i].returnname();
            cout << i + 1 << ". " << name << endl;
            if (cours == name)
            {
                ptr->array[i].setmarks();
                break;
            }

        }
        ptr = ptr->semnptr;
    }

}
class student : public user
{
protected:
    string name, city;
    unsigned int roll, phone, sem;
    bool hostel = 0, transport = 0;
    int numc, credithours = 0;
    string coursestaken[10];
public:
    student* next;
    course coursetaken[10];
    void studentwrite();
    void studentread();

    void coursetostudentsetattendance(string coursename, int num)
    {
        string temp;
        for (int i = 0; i < numc; i++)
        {
            cout << "yahan 4" << endl;

            temp = coursetaken[i].returntitle();
            if (temp == coursename)
            {
                cout << "yahan 5" << endl;
                cout << "STUDENT " << i + 1 << " of " << num << " : " << name << endl;
                coursetaken[i].markattendance();
            }
        }
    }
    void coursetostudentset(string coursename, int num);
    void coursemarksdisplay()
    {
        if (numc == 0)
            cout << "No Courses Enrolled Yet" << endl << endl;
        else
            for (int i = 0; i < numc; i++)
            {
                coursetaken[i].showmarks();
            }
    }
    void showattendance()
    {
        for (int i = 0; i < numc; i++)
        {
            coursetaken[i].viewattendane();
            cout << endl;
        }

    }
    string getname()
    {
        return name;
    }

    int coursehetook = 0;
    void diplays()
    {
        if (sem == 0)
            cout << left << setw(20) << name << setw(20) << roll << setw(20) << city << setw(20) << phone << setw(20) << "Not Enrolled" << setw(20) << "No Courses Enrolled" << endl;
        else
            cout << left << setw(20) << name << setw(20) << roll << setw(20) << city << setw(20) << phone << setw(20) << sem << setw(20) << numc << endl;
    }
    int getnumc()
    {
        return numc;
    }
    void setstudent()
    {
        cin.ignore();
        int c;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter Phone: ";
        cin >> phone;
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        cout << "Do you want to avail university hostel?" << endl;
        cout << "1. Yes\n2. No" << endl;
    re:
        cin >> c;
        if (c == 1)
            hostel = 1;
        if (c != 2 && c != 1)
        {
            cout << "Choose from available options: ";
            goto re;
        }
        cout << "Do you want to avail transport facilty?" << endl;
        cout << "1. Yes\n2. No" << endl;
    re1:
        cin >> c;
        if (c == 1)
            transport = 1;
        if (c != 2 && c != 1)
        {
            cout << "Choose from available options: ";
            goto re1;
        }

    }
    void enrollmentinstudent()
    {
        cout << "Available Semesters" << endl;
        semester* enrollsem = semHead;
        int count = 1;
        while (enrollsem != NULL)
        {
            cout << count << ". "; enrollsem->enrolldisplay();
            enrollsem = enrollsem->semnptr;
        }
        cout << "In which Semester do you want to enroll: ";
        cin >> sem;
        enrollsem = semHead;
        while (enrollsem != NULL)
        {
            int n = enrollsem->returnnum();
            if (sem == n)
            {
                cout << "Courses Offered in Semester " << sem << " of " << Ses << " " << Year << endl;
                enrollsem->displayycou();
                break;
            }
            enrollsem = enrollsem->semnptr;
        }
        enrollsem->addcourses(name, credithours, coursestaken, numc, coursetaken, coursehetook);
        cout << "student:::Student: " << name << "Credit Hours: " << credithours << endl;
        display();
    }

    void display()
    {
        cout << endl;
        cout << left << setw(20) << "Name: " << name << endl;
        cout << left << setw(20) << "Roll Number:" << roll << endl;
        cout << left << setw(20) << "City:" << city << endl;
        cout << left << setw(20) << "Phone:" << phone << endl;
        cout << left << setw(20) << "Hostel Taken:";
        if (hostel == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << left << setw(20) << "Transport Availed:";
        if (transport == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << setw(20) << "Courses Enrolled: " << numc << endl;
        cout << setw(20) << "Total Credit Hours: " << credithours << endl;
        cout << "List of Courses" << endl;
        for (int i = 0; i < numc; i++)
            cout << "   " << i + 1 << ". " << coursestaken[i] << endl;

    }
    void generatechallan()
    {
        unsigned int sum = 0;
        cout << "             FEE CHALLAN";
        cout << "--------------------------------------------";
        cout << setw(20) << "Credit Hours Taken: " << credithours << endl;
        cout << setw(20) << "Semester Fee: "; cout << credithours * 3000 << endl;
        sum += credithours * 3000;
        cout << setw(20) << "Hostel Charges: ";
        if (hostel == 1)
        {
            cout << 18000 << endl;
            sum += 18000;
        }
        else
        {
            cout << 0;
        }
        cout << setw(20) << "Transport Charges: ";
        if (transport == 1)
        {
            cout << 10000 << endl;
            sum += 10000;
        }
        else
        {
            cout << 0;
        }
        sum += 1000;
        cout << setw(20) << "Internet Charges: " << 1000 << endl;
        cout << setw(20) << endl << "Total Fee: " << sum << endl;
    }

};

class admin : public user
{
public:
    void displaystudents()
    {
        student* display = StuHead;
        if (display == NULL)
        {
            cout << "No Student Registered Yet" << endl;
        }
        else
        {
            cout << left << setw(20) << "NAME" << setw(20) << "ROLL NUMBER" << setw(20) << "CITY" << setw(20) << "PHONE" << setw(20) << "SEMESTER" << setw(20) << "COURSES" << endl;

            while (display != NULL)
            {
                display->diplays();
                display = display->next;
            }
        }

    }
    bool login()
    {
        string p;
        cout << "ENTER ADMIN PASSWORD:" << endl;
    re:
        cin >> p;
        if (p == password)
        {
            cout << "LOGGED IN AS ADMIN" << endl;
            return 1;
        }
        else
        {
            cout << "INCORRECT PASSWORD" << endl;
            cout << "ENTER CORRECT PASSWORD TO LOGIN: ";
            goto re;
        }
    }
    admin(string pass) :user(pass)
    {

    }
    void OfferSemester()
    {

        int count = 0;
        int c1;
        int year;
        string semeste;
        int sem;
        if (sessionselected == 0)
        {
            cout << "Choose Semester" << endl;
            cout << "1. Fall\n2. Spring" << endl;
            cout << "Enter Your Preference: " << endl;
            cin >> c1;
            cout << "Enter Year: ";
            cin >> year;
            Year = year;

            if (c1 == 1) {
                semarray[0] = 1;
                semarray[1] = 3;
                semarray[2] = 5;
                semarray[3] = 7;
                semeste = "Fall";
                Ses = "FALL";
                cout << "Semesters Offered in Fall " << year << ": " << endl;
                cout << "1, 3, 5, 7" << endl;
            }
            else {
                semarray[0] = 2;
                semarray[1] = 4;
                semarray[2] = 6;
                semarray[3] = 8;
                Ses = "SPRING";
                semeste = "Spring";
                cout << "Semesters Offered in Spring " << year << ": " << endl;
                cout << "2, 4, 6, 8" << endl;
            }
        }

        int course;
        do
        {

            cout << "Choose Semester: " << endl;
        in:
            cin >> sem;
            bool c = 0;
            for (int i = 0; i < 4 - count; i++)
            {
                if (sem == semarray[i] && semarray[i] != -1)
                {
                    semarray[i] = -1;
                    count++;
                    c = 1;
                    break;
                }
            }
            if (c == 0)
            {
                cout << "Semester Not Available" << endl << "Choose from available semesters: " << endl;
                goto in;
            }

            semester* semptr;
            semptr = new semester;
            cout << "How many courses do you want to offer in Semester " << sem << " of " << semeste << " " << year << ": " << endl;
            cin >> course;
            semptr->set(semeste, year, sem, course);
            semptr->courses(course);
            if (semHead == NULL)
            {
                semHead = semptr;
                semHead->semnptr = NULL;
            }
            else
            {
                semester* semcptr = semHead;
                while (semcptr->semnptr != NULL)
                    semcptr = semcptr->semnptr;
                semcptr->semnptr = semptr;
                semptr->semnptr = NULL;
            }
            int c2;
            cout << "Do you want to offer more semesters?" << endl;
            cout << "Press 1: Yes" << endl;
            cout << "Press 2: No" << endl;
            cin >> c2;
            if (c2 == 2)
                break;
            if (c2 == 1)
            {
                cout << "Available Semesters: ";
                for (int i = 0; i < (5 - count); i++)
                {
                    if (semarray[i] != -1)
                    {
                        cout << semarray[i];
                        if (i < 4 - count)
                            cout << ", ";
                    }
                }
                cout << endl;

            }
        } while (1);
        cout << "" << endl;
    }

    void displaysemester()
    {
        string c;

        cout << "COURSES OFFERED IN SEMESTERS OF " << Ses << " " << Year << endl;
        semester* display = semHead;
        while (display != NULL)
        {
            display->displayy();
            display = display->semnptr;
        }

    }
    void displayfaculty()
    {
        faculty* display = FacHead;
        if (display == NULL)
        {
            cout << "No Faculty Member Registered Yet" << endl;
        }
        else
        {
            cout << endl << "LIST OF FACULTY" << endl << endl;
            cout << left << setw(20) << "NAME" << setw(20) << "PHONE" << setw(20) << "EXTENSION" << setw(20) << "COURSE" << endl;
            while (display != NULL)
            {
                display->facdis();
                display = display->nptr;
            }
        }

    }

};
admin A("1234");
void studentregistration()
{
    int choice;
    do
    {

        student* stuptr = new student;
        stuptr->setstudent();
        if (StuHead == NULL)
        {
            StuHead = stuptr;
            StuHead->next = NULL;
        }
        else
        {
            student* curr = StuHead;
            while (curr->next != NULL)
                curr = curr->next;
            stuptr->next = NULL;
            curr->next = stuptr;
        }
        cout << "Press 1 to Register Another Student ";
        cout << "Press any key to end student registration: ";
        cin >> choice;
    } while (choice == 1);

}
void course::setmarks()
{
    cout << "Set Marks and Attendance of " << title << endl;
    displaycourse();

    if (marksset == 0)
    {

        cout << "Enter Total Marks of Quizes: ";
        cin >> quizt;
        cout << "Enter Weightage of Quizes: ";
        cin >> quizw;
        cout << "Enter Total Marks of Assignments: ";
        cin >> assignt;
        cout << "Enter Weightage of Assignments: ";
        cin >> assignw;
        cout << "Enter Total Marks of Sessionals: ";
        cin >> markst;
        marksw = 50 - quizw - assignw;
        cout << "Enter Total Days of Attendance: ";
        cin >> attendancet;
        marksset = 1;
    }
    else
        cout << "Marks and Attendance of this course is already set" << endl;
    student* ptr = StuHead;
    string temp, temp3;
    if (ptr != NULL)
    {

        int temp2;
        for (int i = 0; i < students; i++)
        {

            while (ptr != NULL)
            {
                temp = ptr->getname();

                if (studentenrolled[i] == temp)
                {
                    temp2 = ptr->getnumc();
                    for (int j = 0; j < temp2; j++)
                    {
                        temp3 = ptr->coursetaken[i].titlereturn();
                        cout << i + 1 << ". " << temp3 << endl;
                        if (temp3 == title)
                        {

                            copy(ptr->coursetaken[i]);

                        }
                    }
                }
                ptr = ptr->next;
            }
            ptr = StuHead;
        }
    }
}
bool facultylogin()
{
    string use, pass;
    string a;
    bool check = 0;
    cout << "Enter Username: ";
    cin >> use;
    faculty* ptr = FacHead;
    while (ptr != NULL)
    {
        a = ptr->getusername();
        if (use == a)
        {
            check = 1;
            cout << "Enter Password: ";
            cin >> pass;
            a = ptr->getpassword();
            if (pass == a)
            {
                cout << "Logged In as Faculty Member" << endl;
                facultytoset = ptr;
                return 1;
            }
            else
            {
                cout << "Incorrect Password" << endl;
                cout << "Login Failed" << endl;
                return 0;
            }
            break;
        }
        ptr = ptr->nptr;
    }
    if (check == 0)
    {
        cout << "No Such User Id exist" << endl;
        return 0;
    }
}

bool studentlogin()
{
    string use, pass;
    string a;
    bool check = 0;
    cout << "Enter Username: ";
    cin >> use;
    student* ptr = StuHead;
    while (ptr != NULL)
    {
        a = ptr->getusername();
        if (use == a)
        {
            check = 1;
            cout << "Enter Password: ";
            cin >> pass;
            a = ptr->getpassword();
            if (pass == a)
            {
                cout << "Logged In as Student" << endl;
                studenttoset = ptr;
                return 1;
            }
            else
            {
                cout << "Incorrect Password" << endl;
                cout << "Login Failed" << endl;
                return 0;
            }
            break;
        }
        ptr = ptr->next;
    }
    if (check == 0)
    {
        cout << "No Such User Id exist" << endl;
        return 0;
    }
}
void faculty::attendance()
{

    string cours;
    courselink* cou = head;
    int a = 1;
    cours = cou->name;
    if (cou->nptr != NULL)
    {

        while (cou != NULL)
        {
            cout << a++ << ". " << cou->name << endl;
            cou = cou->nptr;
        }
        cout << "Select Course to Mark Attendance:";
        cin >> a;
        cou = head;
        for (int i = 0; i < a; i++)
        {
            cours = cou->name;
            cou = cou->nptr;
        }
    }
    semester* ptr = semHead;
    string name;
    int temp;
    while (ptr != NULL)
    {
        cout << "yahan 1" << endl;
        for (int i = 0; i < ptr->returnnumc(); i++)
        {
            cout << "yahan 2" << endl;

            name = ptr->array[i].returnname();
            if (cours == name)
            {
                cout << "yahan 3" << endl;

                ptr->array[i].courseattendance();
                break;
            }

        }
        ptr = ptr->semnptr;
    }
}
void faculty::grade()
{
    string cours;
    courselink* cou = head;
    int a = 1;
    cours = cou->name;
    if (cou->nptr != NULL)
    {

        while (cou != NULL)
        {
            cout << a++ << ". " << cou->name << endl;
            cou = cou->nptr;
        }
        cout << "Select Course to Grade:";
        cin >> a;
        cou = head;
        for (int i = 0; i < a; i++)
        {
            cours = cou->name;
            cou = cou->nptr;
        }
    }
    semester* ptr = semHead;
    string name;
    int temp;
    while (ptr != NULL)
    {
        for (int i = 0; i < ptr->returnnumc(); i++)
        {

            name = ptr->array[i].returnname();
            if (cours == name)
            {

                ptr->array[i].gradee();
                break;
            }

        }
        ptr = ptr->semnptr;
    }

}
void course::courseattendance()
{
    student* ptrr = StuHead;
    if (marksset == 1)
    {
        cout << " yahan 3.25" << endl;
        for (int i = 0; i < students; i++)
        {
            cout << " yahan 3.5" << endl;

            while (ptrr != NULL)
            {
                cout << " yahan 3.75" << endl;

                temp = ptrr->getname();
                if (studentenrolled[i] == temp)
                {
                    ptrr->coursetostudentsetattendance(title, students);
                }
                ptrr = ptrr->next;
            }
            ptrr = StuHead;
        }
    }
    else
        cout << "Total Marks of " << title << " not set" << endl;
}
void course::gradee()
{
    student* ptrr = StuHead;
    if (marksset == 1)
    {
        for (int i = 0; i < students; i++)
        {
            while (ptrr != NULL)
            {
                temp = ptrr->getname();
                if (studentenrolled[i] == temp)
                {
                    ptrr->coursetostudentset(title, students);
                }
                ptrr = ptrr->next;
            }
            ptrr = StuHead;
        }
    }
    else
        cout << "Total Marks of " << title << " not set" << endl;
}
void student::coursetostudentset(string coursename, int num)
{
    string temp;
    for (int i = 0; i < numc; i++)
    {
        temp = coursetaken[i].returntitle();
        if (temp == coursename)
        {
            cout << "STUDENT " << i + 1 << " of " << num << " : " << name << endl;
            coursetaken[i].studenttocourseset();
        }
    }
}
void registerfaculty()
{
    string instructor;
    faculty* facptr = new faculty;
    cout << "Enter Name: ";
    getline(cin, instructor);
    facptr->setfaculty(instructor);
    if (FacHead == NULL)
    {
        FacHead = facptr;
        FacHead->nptr = NULL;
    }
    else
    {
        faculty* Fac = FacHead;
        while (Fac->nptr != NULL)
            Fac = Fac->nptr;
        Fac->nptr = facptr;
        facptr->nptr = NULL;

    }
}
void semester::semesterread()
{
    // cout << "Semester Read Started" << endl;

    num = stringtoint();
    numc = stringtoint();
    array = new course[numc];
    for (int i = 0; i < numc; i++)
    {
        array[i].coursereadforsemester();
    }
    // cout << "Semester Read Ended" << endl;

}
void semester::semesterwrite()
{
    cout << "Semester Writ Started" << endl;
    file << num << endl;
    file << numc << endl;
    for (int i = 0; i < numc; i++)
    {
        array[i].coursewriteforsemester();
    }
    cout << "Semester Writ Ended" << endl;

}
void course::coursereadforsemester()
{
    // cout << "Course Read Started" << endl;

    title = in();
    code = in();
    instructor = in();
    credit = stringtoint();
    students = stringtoint();
    for (int a = 0; a < students; a++)
        studentenrolled[a] = in();
    marksset = stringtoint();
    if (marksset == 1)
    {
        quizt = stringtoint();
        assignt = stringtoint();
        markst = stringtoint();
        quizw = stringtoint();
        assignw = stringtoint();
        marksw = stringtoint();
        attendancet = stringtoint();
    }
    marksuploaded = stringtoint();
    if (marksuploaded == 1)
    {
        quiz = stringtoint();
        assign = stringtoint();
        marks = stringtoint();
    }
    attendaceset = stringtoint();
    if (attendaceset == 1)
        attendance = stringtoint();
    // cout << "Course Read Ended" << endl;

}
void course::coursewriteforsemester()
{
    // cout << "Course Write Started" << endl;

    file << title << endl;
    file << code << endl;
    file << instructor << endl;
    file << credit << endl;
    file << students << endl;
    for (int a = 0; a < students; a++)
        file << studentenrolled[a];
    file << marksset << endl;
    if (marksset == 1)
    {
        file << quizt << endl;
        file << assignt << endl;
        file << markst << endl;
        file << quizw << endl;
        file << assignw << endl;
        file << marksw << endl;
        file << attendancet << endl;
    }
    file << marksuploaded << endl;
    if (marksuploaded == 1)
    {
        file << quiz << endl;
        file << assign << endl;
        file << marks << endl;
    }
    file << attendaceset << endl;
    if (attendaceset == 1)
        file << attendance << endl;
    // cout << "Course Write Ended" << endl;

}

void faculty::facultywrite()
{
    file << name << endl;
    file << username << endl;
    file << password << endl;
    file << phone << endl;
    file << exten << endl;
    file << numofc << endl;
    courselink* op = head;
    while (op != NULL)
    {
        file << op->name << endl;
        op = op->nptr;
    }
}
void faculty::facultyread()
{
    name = in();
    username = stringtoint();
    password = stringtoint();
    phone = stringtoint();
    exten = stringtoint();
    numofc = stringtoint();

    for (int i = 0; i < numofc; i++)
    {
        courselink* q = new courselink;
        q->name = in();
        if (head == NULL)
        {
            head = q;
            head->nptr = NULL;
        }
        else
        {
            courselink* w = head;
            while (w->nptr != NULL)
                w = w->nptr;
            w->nptr = q;
            q->nptr = NULL;
        }
    }
    // cout << "FacRead End" << endl;

}

void student::studentread()
{
    name = in();
    city = in();
    roll = stringtoint();
    phone = stringtoint();
    sem = stringtoint();
    hostel = stringtoint();
    transport = stringtoint();
    numc = stringtoint();
    credithours = stringtoint();
    for (int d = 0; d < numc; d++)
    {
        coursetaken[d].coursereadforsemester();
    }

}
void student::studentwrite()
{
    file << name << endl;
    file << city << endl;
    file << roll << endl;
    file << phone << endl;
    file << sem << endl;
    file << hostel << endl;
    file << transport << endl;
    file << numc << endl;
    file << credithours << endl;
    for (int d = 0; d < numc; d++)
    {
        coursetaken[d].coursewriteforsemester();
    }

}