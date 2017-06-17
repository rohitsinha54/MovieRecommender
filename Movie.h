// MOVIE CLASS
// IMPORTANT: #include "Movie.h" on the heap file, NOT "Movies.h"

class Movie {
	// private variables include movie id, name, and rating
private:
	int id;
	string name;
	double rating;
public:
	// input: none
	// output: constructor function; will create empty movie object
	Movie() {
		id = 0;
		name = "";
		rating = 0.0;
	}

	// input: integer id, string name, and double rating of movie
	// output: constructor function; will create movie object
	Movie(int i, string n, double r) {
		id = i;
		name = n;
		rating = r;
	}

	// input: integer id
	// output: none; will set the id
	void setid(int i) {
		id = i;
	}

	// input: string name
	// output: none; will set the name
	void setname(string n) {
		name = n;
	}

	// input: double rating
	// output: none; will set the rating
	void setrating(double r) {
		rating = r;
	}

	// input: none
	// output: returns the id
	int getid() {
		return id;
	}

	// input: none
	// output: returns the name
	string getname() {
		return name;
	}

	// input: none
	// output: returns the rating
	double getrating() {
		return rating;
	}
};

/*
Movies.h
class :MovieDetails

// implemented
movieId : int

// implemented
movieName : string

// implemented
avgRating : double

// should be implemented in hash class
HashTable<movieId : int, movieDetail : MovieDetails>

// implemented already in heap class
HeapmovieId : int - movies sorted by avg rating

// should be implemented in load class
load(filename : string) = reads the file using Files.h initialize the hashtable

// should be implemented in hash class
addMovie(movieName : string) add the movie to hashtable with a new unique id if it does not already exists else throws exception

// should be implemented in hash class
deleteMovie(movieId : int) - deletes the movie if it exists else throw exceptions.When a movie is deleted we also delete all its rating from UserRatings.h see below.

// implemented; returns 0 instead of null
getId(movieName : string) : int - returns the id of the movie if it exists else return null

// implemented; returns empty string instead of null
getName(movieId : int) : string - returns the name of the movie if it exists else returns null

// implemented in heap class
getTop(num : int) : List - return top num movies
*/