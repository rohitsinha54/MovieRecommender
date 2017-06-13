#include <iostream>
#include <string>
#include <vector>
#include "Files.h"

using namespace std;

int main() {
	Files test;
	fstream testFile;
	fstream wFile;
	vector<string> movies;
	// Testing...
	test.getData(testFile, "Movies.txt");
	test.writeFile(wFile, "writeMovies.txt");
	cin.get();
	cin.get();
	return 0;
}