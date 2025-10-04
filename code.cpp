// COMSC-210 | Lab 19 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct MovieReviews {
    double rating;
    string comment;
};

class Movie {
    private: 
    string title;
    Movie * reviews;
};

void output(MovieReviews *);

int main() {
    //File Opening
	ifstream file;
	file.open("text.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}

    vector<Movie> movieList;

    //Movie populating
    string line;
    string title;
    int count = 0;
    MovieReviews * head = nullptr;
    MovieReviews * current = nullptr;

    while (getline(file, line)) {
        if (count == 0) { //First line
            title = line;
        }  
        int rating = rand() % 100;

        current->comment 
    }

    MovieReviews * head = nullptr;

    //Asks for User input on each movie
    char continueKey = 'Y';
    while (continueKey == 'Y') { 
        MovieReviews * newVal = new MovieReviews;

        cout << "Enter review rating 0-5: ";
        cin >> newVal->rating;
        while (newVal->rating > 5 || newVal->rating < 0) {
            cout << "Enter a valid rating from 0-5: ";
            cin >> newVal->rating;
        }

        cout << "Enter review comments: ";
        cin >> newVal->comment;
        cout << endl;

        cout << "Enter another review? Y/N: ";
        cin >> continueKey;
        while (continueKey != 'Y' && continueKey != 'N' && continueKey != 'y' && continueKey != 'n') {
            cout << "Enter a valid option Y/N: ";
            cin >> continueKey;
        }
       
        if (!head) { //if first
            head = newVal;
            newVal->next = nullptr;
        }
        else { //if second or more
            newVal->next = head;
            head = newVal;
        }
 
    }

    output(head);
}

void output(MovieReviews * head) {
    if (!head) {
        cout << "Empty list" << endl;
        return;
    }

    MovieReviews * current = head;
    int count = 1;
    int sum = 0;
    while (current) {
        sum += current->rating;
        cout << "Review #" << count++ << ": " << current->rating << ": " << current->comment << endl;
        current = current->next;
    }

    cout << "Average: " << sum / (count - 1) << endl;
}