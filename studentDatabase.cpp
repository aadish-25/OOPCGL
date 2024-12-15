//Develop an object oriented program in C++ to create a database of student information
//System containing the following information: Name, Roll number, Class, division, Date of
//Birth, Blood group, Contact address, telephone number, driving license no. and other.
//Construct the database with suitable member functions for initializing and destroying the
//data viz constructor, default constructor, Copy constructor, destructor, static member
//functions, friend class, this pointer, inline code and dynamic memory allocation
//operators-new and delete.

#include <iostream>
#include <string>

using namespace std;

static int COUNT = 0;
class Person{
    private :
        string name, dob, bloodg, address, dlno, number;
    public:
        //friend class
        friend class Student;

        // default constructor
        Person(){
            name = "";
            dob = "";
            bloodg = "";
            address = "";
            dlno = "";
            number = "";
        }
        // destructor
        ~Person(){
            // cout << "DESTRUCTOR IS CALLED";
        }
        //parameterized constructor
        Person(string n, string dob, string bg, string add, string dln, string num){
            name = n;
            dob = dob;
            bloodg = bg;
            address = add;
            dlno = dln;
            number = num;
        }
        // copy constructor
        Person(Person &obj){
            name = this->name;
            dob = this->dob;
            bloodg = this->bloodg;
            address = this->address;
            dlno = this->dlno;
            number = this->number;
        }
};

class Student:public Person{
    public:
        int rollno, className;
        string division;

        Student(){
            rollno = 0;
            className = 0;
            division = "";
            COUNT++;
        }

        ~Student(){
            // delete division;
        }

        Student(int rn, int cn, char div){
            rollno = rn;
            className = cn;
            division = div;
        }

        int getCount(){
            return COUNT;
        }

        inline void getData(){
            cout << "Enter name: ";
            getline(cin, this->name);
            cout << "Enter date of birth: ";
            getline(cin, this->dob);
            cout << "Enter blood group: ";
            getline(cin, this->bloodg);
            cout << "Enter address: ";
            getline(cin, this->address);
            cout << "Enter phone number: ";
            getline(cin, this->number);
            cout << "Enter driving license number: ";
            getline(cin, this->dlno);
            cout << "Enter roll no: ";
            cin >> this->rollno;
            cin.ignore();  // To consume the leftover newline character
            cout << "Enter class: ";
            cin >> this->className;
            cin.ignore();  // To consume the leftover newline character
            cout << "Enter division: ";
            cin >> this->division;
            cin.ignore(); 

        }
        void printData(){
            cout << "";
            cout << "Name : " << this->name << endl;
            cout << "DOB : " << this->dob << endl;
            cout << "Blood Group : " << this->bloodg << endl;
            cout << "Address : " << this->address << endl;
            cout << "Phone Number : " << this->number << endl;
            cout << "Driving Lic. No : " << this->dlno << endl;
            cout << "Roll number : " << this->rollno << endl;
            cout << "Class : " << this->className << endl;
            cout << "Division : " << this->division << endl;
        }

};

int main(){

    int n;
    cout << "Enter number of students : ";
    cin >> n;
    cin.ignore();

    // Student stud[n];
    Student * stud = new Student[n];
    cout << "The number of student objects that have been created are : " << COUNT << endl;
    cout << "You can now input the data for the students " << endl << endl;

    for(int i=0; i<n; i++){
        cout << "Student " << (i+1) << endl;
        stud[i].getData();
    }
    cout << endl;
    cout << "----------------DISPLAY INFORMATION-----------------" << endl;
    for(int i=0; i<n; i++){
        cout << "Student " << i << endl;
        stud[i].printData();
        cout << endl;
    }
    
    delete [] stud;
    return 0;
}