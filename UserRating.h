class MovieRating {
    private :
        int movieID;
        double rating;
        // HashTable users
    public:
    
        MovieRating(int n, double d) {
            movieID = n;
            rating = d;
            // users = new HashTable();
        };
        
        void setID(int n) {
            movieID = n;
        };
        
        int getID() {
            return movieID;
        };
        
        void setRating(double d) {
            rating = d;
        };
        
        double getRating() {
            return rating;
        };
        
        /*
        void load(string url) {
            ifstream data;
            data.open(url);
            while (data.good()) {
                string userID;
                double rating;
                data >> user;
                users.add(userID, rating);
            }
        }
        
        void addRating(int userID, double rating) {
            users.add(userID, rating);
        }
        
        void deleteRating(int userID) {
            users.delete(userID);
        }
        
        void updateRating(int userID, rating) {
            users.update(userID, rating);
        }
        */
};