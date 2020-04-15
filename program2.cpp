#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector> 
#include <streambuf>
#include <tuple>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

vector<tuple<int, int>> getPair(vector<string> s) {
	vector<tuple<int, int>> ret;
	for (int i = 0; i < s.size(); i++) {
		int first;
		int second;
		string str = s.at(i);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == ',') {
				string t1 = str.substr(0, j);
				string t2 = str.substr(j + 1); 
				first = stoi(&t1);
				second = stoi(&t2);
				tuple<int, int> temp = make_tuple(first, second);
				ret.push_back(temp);
				j = str.length();
			}
		}
	}
	return ret;
}
int main(int argc, char* argv[]) {
	ifstream infile;
	ofstream outfile;

	string file;

	infile.open(argv[1]);
	outfile.open(argv[2]);
	
	vector<string> lines;

	while (getline(infile, file))
		lines.push_back(file);

	vector < tuple<int, int> pairs= getPair(lines);
	
 }