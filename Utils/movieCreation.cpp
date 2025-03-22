#include "movieCreation.hpp"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

ostream& operator<<(ostream& stream, const Date& date) {
    return stream << "  Year: " << date.releaseYear << "\n"
                  << "  Month: " << date.releaseMonth << "\n"
                  << "  Day: " << date.releaseDay;
}

ostream& operator<<(ostream& stream, const Movie& movie) {
    return stream << "Title: " << movie.title << "\n"
                  << "Release Date:\n" << movie.releaseDate << "\n"
                  << "Is Popular: " << (movie.isPopular ? "Yes" : "No") << "\n"
                  << "Director: " << movie.director << "\n"
                  << "Rating: " << movie.rating << "/10.0 \n";
}

float validRating() {
    float rating;
    while (true) {
        cin >> rating;
        if (cin.fail() || rating < 0.0 || rating > 10.0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Enter a rating between 0.0 and 10.0: ";
        } else {
            rating = round(rating * 10.0f) / 10.0f;             // rounding to 1 decimal place
            break;
        }
    }
    return rating;
}

bool validBool() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || (input != 0 && input != 1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Enter 1 for Yes or 0 for No: ";
        } else {
            return input == 1;  // only returns when input is 1 for yes
        }
    }
}

int validInt(int givenDigits){
    int num;
    while (true){
        cin >> num;
        
        if (cin.fail() || num <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Please enter the correct value" << endl;
        } else {    // input is int and pos, now check if it is correct digits or not
            int digits = 0;
            int numCopy = num;
            while(numCopy > 0){
                numCopy /= 10;
                digits++;
            }
            if (digits <= givenDigits){     // can capture single-digit input for day/month now
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Please enter the correct value" << endl;
        }
    }
    return num;
}

string validName() {
    string name;
    while (true) {
        cin >> name;  // one word only
        bool isValid = true;

        for (char c : name) {
            if (!isalpha(static_cast<unsigned char>(c))) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Invalid... Please enter only one value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return name;
}


// Function to validate user input for a Movie object
Movie createMovie() {
    Movie movie;

    cout << "Enter the movie title: ";
    getline(cin, movie.title);  // title can have whitespace, numbers, or special characters

    cout << "Enter the director's first name: ";
    string first = validName();
    cout << "Enter the director's last name: ";
    string last = validName();
    movie.director = first + " " + last;

    cout << "Enter the 4-digit release year: ";
    movie.releaseDate.releaseYear = validInt(4);

    cout << "Enter the 2-digit release month: ";
    while (true) {
        int month = validInt(2);
        if (month >= 1 && month <= 12) {
            movie.releaseDate.releaseMonth = month;
            break;
        } else {
            cout << "Invalid month. Please enter a value between 01 and 12: ";
        }
    }

    cout << "Enter the 2-digit release day: ";
    while (true) {
        int day = validInt(2);
        if (day >= 1 && day <= 31) {
            movie.releaseDate.releaseDay = day;
            break;
        } else {
            cout << "Invalid day. Please enter a value between 01 and 31: ";
        }
    }

    cout << "Is the movie popular? (1 = Yes, 0 = No): ";
    movie.isPopular = validBool();

    cout << "Enter the movie rating (0.0 - 10.0): ";
    movie.rating = validRating();

    return movie;
}
