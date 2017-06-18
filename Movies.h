/**
 * Stores the movie information
 *
 * @author Justin Read
 */

#ifndef MOVIERECOMMENDER_MOVIE_H
#define MOVIERECOMMENDER_MOVIE_H

// MOVIE CLASS
// IMPORTANT: #include "Movies.h" on the heap file, NOT "Movies.h"

#include <ostream>
#include "LongHashKey.h"
#include "HashMap.h"

class Movie {
    // private variables include movie id, name, and sum and totalRating
private:
    long id;
    string name;
    double sumRating;
    double totalRatings;
public:
    // input: none
    // output: constructor function; will create empty movie object
    Movie() {}

    // input: integer id, string name, and double rating of movie
    // output: constructor function; will create movie object
    Movie(long i, string n, double sr, double tr) {
        id = i;
        name = n;
        sumRating = sr;
        totalRatings = tr;
    }

    Movie(long i, string n) {
        id = i;
        name = n;
        sumRating = 0;
        totalRatings = 0;

    }

    // input: integer id
    // output: none; will set the id
    void setid(long i) {
        id = i;
    }

    // input: string name
    // output: none; will set the name
    void setname(string n) {
        name = n;
    }

    // input: none
    // output: returns the id
    long getid() {
        return id;
    }

    // input: none
    // output: returns the name
    string getname() {
        return name;
    }

    double getSumRating() const {
        return sumRating;
    }

    double getTotalRatings() const {
        return totalRatings;
    }

    void setSumRating(double sumRating) {
        Movie::sumRating = sumRating;
    }

    void setTotalRatings(double totalRatings) {
        Movie::totalRatings = totalRatings;
    }

    double getAvgRating() const {
        // calculate the average rating and return
        return (Movie::sumRating / Movie::totalRatings);
    }

    friend ostream &operator<<(ostream &os, const Movie &movie) {
        os << "id: " << movie.id << " name: " << movie.name << " sumRating: " << movie.sumRating << " totalRatings: "
           << movie.totalRatings << " avgRating: " << movie.getAvgRating();
        return os;
    }
};

class Movies {
private:
    HashMap<long, Movie, 10L, LongHashKey<10L> > moviesInfo;
public:
    Movies() :
            moviesInfo() {
    }

    void load(string filename) {
        vector<vector<string> > movies = readFile(filename);
        // skip the 0th record as its header information
        for (int i = 0; i < movies.size(); i++) {
            long movieId = atol(movies[i][0].c_str());
            moviesInfo.put(movieId, Movie(movieId, movies[i][1]));
        }
    }

    bool getMovie(long mId, Movie &m) {
        return moviesInfo.get(mId, m);
    }

    void updateMovie(long mId, Movie &m) {
        moviesInfo.put(mId, m);
    }

    long addMovie(string mName) {
        // check if a movie with the given name does not already exists
        // if exists then just return its id
        // if does not exists then add the movie with unique id and return the id
        return 0;
    }

    void deleteMovie(long mId) {
        // check if the  given movie exists
        // if it does delete it
    }
};

#endif //MOVIERECOMMENDER_MOVIE_H
