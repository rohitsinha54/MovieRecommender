#include <iostream>
#include <string>
#include <vector>
#include "files.h"
#include "heap.h"
#include "Movie.h"

const string DATA_FILE = "movies.txt";
const string WRITE_FILE = "writeMovies.txt";

using namespace std;

int main() {
	Files test;
	Movie sort;
	fstream testFile;
	fstream wFile;
	vector<string> movies;
	// Testing...
	test.getData(testFile, DATA_FILE);
	test.writeFile(wFile, WRITE_FILE);

	return 0;
}