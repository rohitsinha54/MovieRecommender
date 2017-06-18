/**
 * Driver of the MovieRecommender application.
 *
 * @author Malgorzata Sklarek
 */

#include "File.h"
#include "Movies.h"
#include "UserRatings.h"

int main() {

    // read the movies file
    Movies movies;
    movies.load("movies.csv");

    // read the user rating files
    UserRatings userRatings;
    userRatings.load("ratings.csv", movies);

    // ask user for movieId
    long movieId;
    cout << "Please enter the movieID whose average rating needs to be found: ";
    cin >> movieId;

    // display movie information
    Movie m;
    movies.getMovie(movieId, m);
    cout << m << endl;
}