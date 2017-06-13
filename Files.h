#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#ifndef FILES_H
#define FILES_H

using namespace std;

class Files {
private: vector<string> readFile;

public: 
		// For this class to work you only need to define a 
		// file variable and the path its going to read from
		// into a vector where the data is stored.
		vector<string> getData(fstream &rFile, string filePath) {
	rFile.open(filePath, ios::in);
	string movieTitle;
	while (!rFile.eof()) {
		getline(rFile, movieTitle);
		readFile.push_back(movieTitle);
	}
	for (unsigned int count = 0; count < readFile.size(); ++count) {
		cout << readFile[count] << endl;
	}
	rFile.close();
	return readFile;
}
		// This function will open and create a file where it will read
		// and write the movie titles into the write path 
		void writeFile(fstream &wFile, string writePath) {
			wFile.open(writePath, ios::out);
			for (unsigned int count = 0; count < readFile.size(); ++count) {
				wFile << readFile[count] << endl;
			}
			wFile.close();
		}
};
#endif