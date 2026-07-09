#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "lexer.h"
using namespace std;

int main() {
	ifstream infile("file.txt");
	ofstream outfile("output.txt");

	string line;
	int lineNumber = 1;
	while (getline(infile, line)) {
		cout << "-----------------------" << " Line " << lineNumber << " -----------------------" << endl;
		outfile << "-----------------------" << " Line " << lineNumber << " -----------------------" << endl;
		cout << tokenization(line);
		outfile << tokenization(line);
		lineNumber++;
	}
	cout << "------------------------------------------------------" << endl;
	outfile << "------------------------------------------------------" << endl;
    return 0;
}
