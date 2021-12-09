#include <iostream>
#include <vector> 
#include <cmath>
#include <string>
#include <fstream>
#include <list>
#include <tuple>

using namespace std; 

tuple<int*, int> stringToIntegers(string s) {
    int integers_size = (int)count(s.begin(), s.end(), ',') + 1;
    int* integers = new int[integers_size];
    int ai=0; // array index
    int si=0; // string index
    while (si<s.length() && si>=0) {
        int comma = s.find(',', si);
        integers[ai] = stoi(s.substr(si,comma));
        si = comma > 0 ? comma+1 : s.length();
        ai++;
    } 
    return integers;
}

int* inputIntegers(int& integers_size) {
    // Read in a line containing comma separated list of integers. Return an array of integers (put the size on the parameter integer)
    // eg: input of "4,5,7,9\n"
    string s;
    getline(cin, s);
    integers_size = (int)count(s.begin(), s.end(), ',') + 1;
    
    int* integers = new int[integers_size];
    int ai=0; // array index
    int si=0; // string index
    while (si<s.length() && si>=0) {
        int comma = s.find(',', si);
        integers[ai] = stoi(s.substr(si,comma));
        si = comma > 0 ? comma+1 : s.length();
        ai++;
    } 
    return integers;
}

vector<string> readFileStrings(const char* filename) {
    ifstream myFile(filename);
    string line;
    vector<string> myLines;
    while (getline(myFile, line)) {
        myLines.push_back(line);
    }
    return myLines;
}


vector<int> readCSVIntegers(const char* filename) {
    ifstream myFile(filename);
    string line;
    vector<vector<int>> myNumbers;
    while (getline(myFile, line)) {
        // Read all comma separated integers in this string
        istringstream s(line);
        string field;
        vector<int>
        while (getline(s, field, ',')) {

        }

        myLines.push_back(line);
    }
    return myNumbers;
}

std::vector<int> parse_input(std::string filename){
	std::vector<int> initial_states;
	std::string parsed;
	std::string line;
	std::ifstream input(filename);
	std::getline(input, line);

	for(char& c: line){
		if (c == ',') {
			initial_states.push_back(std::stoi(parsed));
			parsed.clear();
		} else {
			parsed.push_back(c);
		}
	}
	
	initial_states.push_back(std::stoi(parsed));
	return initial_states;
}
