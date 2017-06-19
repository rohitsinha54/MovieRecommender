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

void writeFile(string filename, vector<vector<string> > info) {
    ofstream outputFile;
    outputFile.open(filename);

    if (outputFile.is_open()) {
        // write all the elements of the array to file
        for (int i = 0; i < info.size(); i++) {
            for (int j = 0; j < info[i].size(); j++) {
                outputFile << info[i][j];
                if (j < (info[i].size() - 1)) {
                    outputFile << ",";
                }
            }
            outputFile << endl;
        }
    } else {
        cout << "Failed to open file " << filename << "for writing." << endl;
        exit(1);
    }
    outputFile.close();
}

#endif //MOVIERECOMMENDER_FILE_H
