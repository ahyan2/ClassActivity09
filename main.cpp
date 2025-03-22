#include <iostream>
#include <limits>
#include <string>

#include "Utils/movieCreation.hpp"

using namespace std;


int main() {
    Movie newMovie = createMovie();

    cout << endl << "--Movie Details--" << endl;
    cout << newMovie;

    return 0;
}

// TODO: Improvements - can check if days match month, and also if leap year for February
