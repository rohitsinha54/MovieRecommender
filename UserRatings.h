/**
 * Stores the user rating information
 *
 * @author Evs Bei
 */

#ifndef MOVIERECOMMENDER_USERRATINGS_H
#define MOVIERECOMMENDER_USERRATINGS_H

#include <ostream>
#include <vector>
#include "LongHashKey.h"
#include "File.h"
#include "HashMap.h"


class MovieRating {
private :
    long mId;
    double rating;
public :

    MovieRating() {}

    MovieRating(long i, double d) {
        mId = i;
        rating = d;
    }

    void setMId(long i) {
        mId = i;
    }

    long getMId() {
        return mId;
    }

    void setRating(double d) {
        rating = d;
    }

    double getRating() {
        return rating;
    }

    friend std::ostream &operator<<(std::ostream &os, const MovieRating &rating) {
        os << "mId: " << rating.mId << " rating: " << rating.rating;
        return os;
    }
};

class UserRatings {
private:
    HashMap<long, vector<MovieRating>, 10L, LongHashKey<10L> > ratingInfo;
public:
    UserRatings() :
            ratingInfo() {
    }

    void load(string filename, Movies &movies) {
        vector<vector<string> > userRatings = readFile(filename);
        for (int i = 1; i < userRatings.size(); i++) {
            long movieId = stol(userRatings[i][1]);
            double rating = stod(userRatings[i][2]);
            MovieRating movieRating(movieId, rating);
            // add the rating for the user
            vector<MovieRating> movieRatings;
            long userId = stol(userRatings[i][0]);
            bool found = ratingInfo.get(userId, movieRatings);
            movieRatings.push_back(movieRating);
            ratingInfo.put(userId, movieRatings);
            // update the movie information for this rating
            Movie mov;
            if (movies.getMovie(movieId, mov)) {
                mov.setTotalRatings(mov.getTotalRatings() + 1);
                mov.setSumRating(mov.getSumRating() + rating);
                movies.updateMovie(movieId, mov);
            } else {
                cout << "Movie with id " << movieId << " not found" << endl;
            }
        }
    }

    bool getRatings(long userId, vector<MovieRating> &r) {
        return ratingInfo.get(userId, r);
    }
};

#endif //MOVIERECOMMENDER_USERRATINGS_H
