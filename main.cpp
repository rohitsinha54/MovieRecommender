/**
 * Driver of the MovieRecommender application.
 *
 * @author Malgorzata Sklarek
 */

#include "File.h"
#include "Movies.h"
#include "UserRatings.h"

int main() {

    cout << endl << "== Welcome to Movie Recommender ==" << endl;

    // read the movies file
    cout << "Loading movies.csv file ..." << endl;
    Movies movies;
    movies.load("movies.csv");

    // read the user rating files
    cout << "Loading ratings.csv file ..." << endl;
    UserRatings userRatings;
    userRatings.load("ratings.csv", movies);

    int choice;
    string movieName;
    long mId;
    unsigned long num;
    Movie m;
    vector<Movie> sortedMovies;
    do {
        cout << "Please choose an option: " << endl;
        cout << "1. Add a movie" << endl;
        cout << "2. Delete a movie" << endl;
        cout << "3. Get a movie details" << endl;
        cout << "4. Show top movies" << endl;
        cout << "9. Save files and exit" << endl;
        cin >> choice;
        cin.ignore();


        switch (choice) {
            case 1:
                cout << "Enter movie name: ";
                getline(cin, movieName);
                m = movies.addMovie(movieName);
                cout << "Movie added: " << m << endl;
                break;
            case 2:
                cout << "Enter movie id: ";
                cin >> mId;
                movies.deleteMovie(mId);
                break;
            case 3:
                cout << "Enter movie id: ";
                cin >> mId;
                movies.getMovie(mId, m);
                cout << m << endl;
                break;
            case 4:
                cout << "Enter number of top movies to display: ";
                cin >> num;
                sortedMovies = movies.sort();
                num = num < sortedMovies.size() ? num : sortedMovies.size();
                cout << "Top " << num << " movies are: " << endl;
                for (int i = 0; i < num; i++) {
                    cout << sortedMovies[i] << endl;
                }
                break;
            case 9:
                // save the data to output files
                movies.save("movies_new.csv");
                break;
            default:
                cout << "Invalid selection " << endl;
        }

    } while (choice != 9);

}