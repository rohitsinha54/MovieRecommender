#ifndef USERRATING_H
#define USERRATING_H

using namespace std;

class UserRating {
private :
    int ID;
    double rating;
public :
    UserRating(int i, double d) {
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
        cout << "\nUser ID : " << ID << "\nRating : " << rating << endl;
    }
};

#endif // USERRATING_H
