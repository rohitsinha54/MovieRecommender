/**
 * Reads and Writes CSV files
 *
 * @author David Banh
 */
#ifndef MOVIERECOMMENDER_FILE_H
#define MOVIERECOMMENDER_FILE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<string> > readFile(string filename) {
    ifstream dataFile;
    dataFile.open(filename);
    vector<vector<string> > data;
    if (dataFile.is_open()) {
        string line;
        while (getline(dataFile, line)) {
            // remove whitespaces from the end of line and add to vector
            line = line.erase(line.find_last_not_of("\n\r") + 1);
            stringstream lineStream(line);
            string cell;
            vector<string> cur;
            while (getline(lineStream, cell, ',')) {
                cur.push_back(cell);
            }
            data.push_back(cur);
        }
        dataFile.close();
    }
        // if failed to open file then show message
    else {
        cout << "Failed to open file: " << filename << endl;
        exit(1);
    }
    return data;
}

#endif //MOVIERECOMMENDER_FILE_H
