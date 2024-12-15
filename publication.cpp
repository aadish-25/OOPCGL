// Problem Statement: Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of a publication.
// From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). Write a program that instantiates the book and tape classes, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.

#include <iostream>
#include <string>

using namespace std;

class Publication{
    public : 
        string title;
        float price;

        Publication(){
            title = "";
            price = 0.0;
        }
        
        Publication(string t, int p){
            title = t;
            price = p;
        }
};

class Book : public Publication{
    public:
        int pagecount;
        Book(){
            pagecount = 0;
        }
        Book(int pc){
            pagecount = pc;
        }
};

class Tape : public Publication{
    public:
        float playingtime;
        Tape(){
            playingtime = 0.0;
        }
        Tape(float pt){
            playingtime = pt;
        }
};

void displayBook(Book&book){
    cout << "--------BOOK DATA----------" << endl;
    cout << "\nTitle : " << book.title;
    cout << "\nPrice : " << book.price;
    cout << "\nPage Count : " << book.pagecount << endl;
}

void displayTape(Tape&tape){
    cout << "\n--------TAPE DATA----------" << endl;
    cout << "\nTitle : " << tape.title;
    cout << "\nPrice : " << tape.price;
    cout << "\nPLaying time : " << tape.playingtime << "min" << endl;
}

int main(){

    Book book;
    Tape tape;

    cout << endl;
    cout << "--------BOOK DETAILS-----------" << endl << endl;

    try{
        cout << "Enter the book title : ";
        cin >> book.title;
        cout << "Enter the book price : ";
        cin >> book.price;
        cout << "Enter the book page count: ";
        cin >> book.pagecount;
        if(book.pagecount < 0){
            throw 100;
        }
    }catch(int n){
        if(n==100){
            cout << "\nERROR : Page count cannot be negative";
            book = Book();
            tape = Tape();
            // return 1;
        }
    }

    cout << endl;
    cout << "\n--------TAPE DETAILS-----------" << endl << endl;

    try{
        cout << "Enter the tape title : ";
        cin >> tape.title;
        cout << "Enter the tape price : ";
        cin >> tape.price;
        cout << "Enter the tape playing time: ";
        cin >> tape.playingtime;
        if(tape.playingtime < 0){
            throw 100;
        }
    }catch(int n){
        if(n==100){
            cout << "\nERROR : Playing time cannot be negative";
            book = Book();
            tape = Tape();
            // return 1;
        }
    }

    displayBook(book);
    displayTape(tape);

    return 0;
}