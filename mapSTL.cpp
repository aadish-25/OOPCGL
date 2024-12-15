#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    cout << "----------STATE DATABASE------------" << endl;
    
    map <string, int> m1;
    string stateName;
    int population;
    int n;

    cout << "Number of states you want to enter : ";    
    cin >> n;

    cout << "Enter the state names with their population : " << endl;    
    for(int i=0; i<n; i++){
        cin >> stateName;
        cin >> population;
        m1.insert(pair<string, int>(stateName, population));
        // m1[stateName] = population;
    }

    // cout << "The states in the collection are : " << endl;
    // for(auto pair : m1){
    //     cout <<  pair.first  << "-" << pair.second << endl;
    // }

    cout << "Enter the state you want to search : " << endl;
    string searchState;
    cin >> searchState;

    bool found = false;
    for(auto pair : m1){
        if(pair.first == searchState){
            cout << "The population of " << searchState << " is " << pair.second;
            found = true;
        }
    }
    if(found == false)
        cout << "State not found!!" << endl;
    return 0;
}