#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{

    fstream file;

    file.open("new_records.txt", ios::out);

    cout << "Enter the information to write in the file : " << endl;
    string outputText;
    getline(cin, outputText);
    file << outputText;
    file.close();

    file.open("new_records.txt", ios::in);
    string content;
    if (!file)
    {
        cout << "File not found";
        return 1;
    }

    else
    {
        while (getline(file, content))
        {
            cout << content << endl;
        }
    }
    file.close();
    return 0;
}