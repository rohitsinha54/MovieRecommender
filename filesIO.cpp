#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const int OPEN_ERROR = 1;
const string INPUT_FILE = "Movies.txt";

int main() {
	fstream dataFile;
	fstream writingFile;
	dataFile.open(INPUT_FILE, ios::in); //Open file and reading in...
	if (dataFile.fail()) {
		cout << "Could not open file " << INPUT_FILE;
		exit(OPEN_ERROR);
	}
	writingFile.open("writeMovies.txt",ios::out);
	
	// String to hold the names of the movies from each line.
	string movieTitle;
	
	// Until the file is at eof it will continue to get each 
	// line or title of the movie and write it into a newly created
	// writing folder.
	while (!dataFile.eof()) { 
		getline(dataFile, movieTitle);
		cout << movieTitle << endl;
		writingFile << movieTitle << endl;
	}
	// Closing the files.
	dataFile.close();
	writingFile.close();
}
