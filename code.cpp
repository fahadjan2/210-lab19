// COMSC-210 | Lab 19 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct MovieReviews {
    double rating;
    string comment;

    MovieReviews * next;
};

class Movie {
    private: 
    string title;
    MovieReviews * head;

    public:
    Movie(string t) {title = t; head = nullptr;}

    //Adds a review
    void addReview(double r, string c) {
        MovieReviews * newReview = new MovieReviews;
        newReview->next = head;
        newReview->rating = r;
        newReview->comment = c;
        head = newReview;
    }

    //Getter for head
    void getReviews() {
        if (!head) {
        cout << "Empty list" << endl;
        return;
        }

        cout << "\nCurrent Title: " << title << endl;
        MovieReviews * current = head;
        int count = 1;
        while (current) {
            cout << "Review #" << count++ << ": " << current->rating << ": " << current->comment << endl;
            current = current->next;
        }
    }
};

int main() {
    //File Opening
	ifstream file;
	file.open("text.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}

    vector<Movie*> movieList;

    //Movie populating
    Movie * NewMovie = nullptr;

    string line;
    int rating;
    bool nextMovie = true;
    
    while (getline(file, line)) {
        if (nextMovie) { //First line / or any new movie title
            NewMovie = new Movie(line);
            nextMovie = false;
        }  
        else if (line == "") { //Means to move to the next movie, adds the movie to the list
            movieList.push_back(NewMovie);
            nextMovie = true;
        }
        else { //Is a review, populates review
            rating = (rand() % 5) + 1;
            NewMovie->addReview(rating, line);
        }
    }

    cout << "Displaying Movies: " << endl;
    for (int i = 0; i < movieList.size(); i++) {
        movieList[i]->getReviews();
        delete movieList[i];
    }
}
