#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

struct Record{
    string Name;
    string DOB;
    int teleNumber;
};

bool compareName(const Record&r1, const Record&r2){
    return r1.Name < r2.Name;
}

bool compareDOB(const Record&r1, const Record&r2){
    return r1.DOB < r2.DOB;
}

bool compareTele(const Record&r1, const Record&r2){
    return r1.teleNumber < r2.teleNumber;
}

int main(){
    vector <Record> personalRecords;

    int n;
    // string name, dob;
    // int tele;


    cout << "Enter the number of students : ";
    cin >> n;

    cout << "\nEnter the name, DOB and telephone number : " << endl;
    for(int i = 0; i<n; i++){
        Record record;
        cout << "\nName : ";
        cin >> record.Name;
        cout << "DOB (ddmmyyyy) : ";
        cin >> record.DOB;
        cout << "Telephone : ";
        cin >> record.teleNumber;

        record.DOB = record.DOB.substr(0,2) + "/" + record.DOB.substr(2,2) + "/" + record.DOB.substr(4,4);

        personalRecords.push_back(record);
    }

    cout << "\nSort the record by : " << endl;
    cout << "1. Name \n2. DOB \n3. Telephone Numbers\n4. No Sorting" << endl;
    int choice;
    cin >> choice;

    switch(choice){
        default : {
            cout << "\nInvalid choice, sorting not done!!";
            break;
        }
        case 1:{
            sort(personalRecords.begin(), personalRecords.end(), compareName);
            break;
        }
        case 2:{
            sort(personalRecords.begin(), personalRecords.end(), compareDOB);
            break;
        }
        case 3:{
            sort(personalRecords.begin(), personalRecords.end(), compareTele);
            break;
        }
        case 4:{
            cout << "\nNot sorted";
            break;
        }
    }

    for(const auto&RC : personalRecords){
        cout << "Name : " << RC.Name << "\nDOB : " << RC.DOB << "\nTelephone : " << RC.teleNumber << endl  << endl;
    }
    
    cout << "\nSearch the record by : " << endl;
    cout << "1. Name \n2. DOB \n3. Telephone Numbers" << endl;
    cin >> choice;

    switch(choice){
        default : {
            cout << "\nInvalid choice";
            break;
        }
        case 1:{
            cout << "Enter the name of the record to find : " << endl;
            string findName;
            cin >> findName;
            for(const auto&RC : personalRecords){
                if(RC.Name == findName){
                    cout << "\nRecord Found!!!" << endl;
                    cout << "Name : " << RC.Name << "\nDOB : " << RC.DOB << "\nTelephone : " << RC.teleNumber << endl  << endl;
                }
            }
            break;
        }
        case 2:{
            cout << "Enter the DOB of the record to find : " << endl;
            string findDOB;
            cin >> findDOB;
            for(const auto&RC : personalRecords){
                if(RC.DOB == findDOB){
                    cout << "\nRecord Found!!!" << endl;
                    cout << "Name : " << RC.Name << "\nDOB : " << RC.DOB << "\nTelephone : " << RC.teleNumber << endl  << endl;
                }
            }
            break;
        }
        case 3:{
            cout << "Enter the telephone number of the record to find : " << endl;
            int findNum;
            cin >> findNum;
            for(const auto&RC : personalRecords){
                if(RC.teleNumber == findNum){
                    cout << "\nRecord Found!!!" << endl;
                    cout << "Name : " << RC.Name << "\nDOB : " << RC.DOB << "\nTelephone : " << RC.teleNumber << endl  << endl;
                }
            }
            break;
        }
        
    }
    return 0;
}