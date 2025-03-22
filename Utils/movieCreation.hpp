#ifndef Utils_movieCreation
#define Utils_movieCreation

#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Date {
    short releaseYear;
    short releaseMonth;
    short releaseDay;
};

struct Movie {
    string title;
    Date releaseDate;
    bool isPopular;
    string director;
    float rating;       // rating decimal out of 10
};

ostream& operator<<(ostream& stream, const Date& date);

ostream& operator<<(ostream& stream, const Movie& movie);

float validRating();

bool validBool();

int validInt(int givenDigits);

string validName();

Movie createMovie();



#endif
