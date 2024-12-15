#include <iostream>
using namespace std;

template <typename T> 
void selectionSort(T arr[], int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        // swap
        T temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

template <typename T> 
void printArray(T arr[], int size){
    cout << "\n";
    for(int i=0; i<size; i++){        
        cout << arr[i] << " ";
    }
}


int main(){
    // integer array
    cout << "\nNumber of elements in the array (integer array) : ";
    int n;
    cin >> n;
    int arr1[n];

    cout << "Enter elements of array : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    // float array
    cout << "\nNumber of elements in the array (float array) : ";
    int m;
    cin >> m;
    float arr2[m];

    cout << "Enter elements of array : "<< endl;
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    cout << "\nArrays before sorting : ";
    printArray(arr1, n);
    printArray(arr2, m);
    
    selectionSort(arr1, n);
    selectionSort(arr2, m);

    cout << "\nArrays after sorting :";
    printArray(arr1, n);
    printArray(arr2, m);

    return 0;
}