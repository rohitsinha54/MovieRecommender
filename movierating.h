#ifndef MOVIERATING_H
#define MOVIERATING_H

#include <vector>
#include "userrating.h"

using namespace std;

class MovieRating {
private :
    int ID;
    double rating;
    vector<UserRating> UR;
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
    
    void updateRating() {
        double d = 0;
        for (int i = 0; i < UR.size(); i++) {
            d += UR[i].getRating();
        }
        rating = d/UR.size();
    }

    void setRating(double d) {
        rating = d;
    }

    double getRating() {
        return rating;
    }
    
    void addUserRating(UserRating r) {
        UR.push_back(r);
    }
    
    void printUserRatings() {
        for (int i = 0; i < UR.size(); i++) {
            UR[i].printData();
        }
    }

    void printData() {
        cout << "\nMovie ID : " << ID << "\nRating : " << rating << endl;
    }
};

#endif // MOVIERATING_H
