#ifndef MOVIERATING_H
#define MOVIERATING_H

using namespace std;

class MovieRating {
private :
    int ID;
    double rating;
public :
    MovieRating(int i, double d) {
        ID = i;
        rating = d;
    }

    void setID(int i) {
        ID = i;
    }

    int getID() {
        return ID;
    }

    void setRating(double d) {
        rating = d;
    }

    double getRating() {
        return rating;
    }

    void printData() {
        cout << ID << " : " << rating << endl;
    }
};

#endif // MOVIERATING_H
