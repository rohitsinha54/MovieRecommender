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
#include <vector>
#include <algorithm>

class Movie {
    // private variables include movie id, name, and sum and totalRating
private:
    long id;
    string name;
    double sumRating;
    double totalRatings;
    string genre;
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

    Movie(long i, string n, string g) {
        id = i;
        name = n;
        genre = g;
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

    const string &getGenre() const {
        return genre;
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
        // calculate the average rating and return if total rating is 0 use 1 to avoid divide by zero error
        return (Movie::sumRating / (Movie::totalRatings == 0 ? 1 : Movie::totalRatings));
    }

    friend ostream &operator<<(ostream &os, const Movie &movie) {
        os << "id: " << movie.id << " name: " << movie.name << " genre: " << movie.genre << " sumRating: "
           << movie.sumRating << " totalRatings: " << movie.totalRatings << " avgRating: " << movie.getAvgRating();
        return os;
    }

    /**
     * This is used to support sorting of Movie. We sort them on basis of the average rating.
     */
    bool operator<(const Movie &rhs) const {
        return this->getAvgRating() > rhs.getAvgRating();
    }
};

class Movies {
private:
    HashMap<long, Movie, 10L, LongHashKey<10L> > moviesInfo;
    long highestMovieId;
public:
    Movies() :
            moviesInfo() {
        highestMovieId = 0;
    }

    void load(string filename) {
        vector<vector<string> > movies = readFile(filename);
        // skip the 0th record as its header information
        for (int i = 1; i < movies.size(); i++) {
            long movieId = atol(movies[i][0].c_str());
            moviesInfo.put(movieId, Movie(movieId, movies[i][1], movies[i][2]));
            highestMovieId = movieId > highestMovieId ? movieId : highestMovieId;
        }
    }

    void save(string filename) {
        vector<HashNode<long, Movie> *> nodes;
        nodes = moviesInfo.getAll();
        vector<vector<string> > info;
        vector<string> headers;
        headers.push_back("movieId");
        headers.push_back("title");
        headers.push_back("genres");
        info.push_back(headers);
        for (long i = 0; i < nodes.size(); i++) {
            vector<string> minfo;
            minfo.push_back(to_string(nodes[i]->getValue().getid()));
            minfo.push_back(nodes[i]->getValue().getname());
            minfo.push_back(nodes[i]->getValue().getGenre());
            info.push_back(minfo);
        }
        writeFile(filename, info);
    }

    bool getMovie(long mId, Movie &m) {
        return moviesInfo.get(mId, m);
    }

    void updateMovie(long mId, Movie &m) {
        moviesInfo.put(mId, m);
    }

    long getHighestMovieId() const {
        return highestMovieId;
    }

    Movie addMovie(string mName) {
        long mId = getHighestMovieId() + 1;
        Movie m(mId, mName);
        moviesInfo.put(m.getid(), m);
        return m;
    }

    void deleteMovie(long mId) {
        Movie m;
        if (moviesInfo.get(mId, m)) {
            moviesInfo.remove(mId);
            cout << "Deleted movie: " << m << endl;
        } else {
            cout << "Movie with id: " << mId << " not found" << endl;
        }
    }

    /**
     * @return a sorted list of Movie which is sorted on basis of their average rating
     */
    std::vector<Movie> sort() {
        vector<HashNode<long, Movie> *> nodes;
        nodes = moviesInfo.getAll();
        vector<Movie> movies;
        for (long i = 0; i < nodes.size(); i++) {
            movies.push_back(nodes[i]->getValue());
        }
        std::sort(movies.begin(), movies.end());
        return movies;

    }
};

#endif //MOVIERECOMMENDER_MOVIE_H
