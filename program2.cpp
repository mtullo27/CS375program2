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
				first = stoi(t1, nullptr, 0);
				second = stoi(t2, nullptr, 0);
				tuple<int, int> temp = make_tuple(first, second);
				ret.push_back(temp);
				j = str.length();
			}
		}
	}
	return ret;
}
int knapSack(int capacity, vector<tuple<int, int>> items, int size, vector<tuple<int, int>> included) {
	int K[size + 1][capacity + 1];
	for (int i = 0; i < size+1; i++) {
		for (int j = 0; j < capacity + 1; j++) {
			tuple<int, int> temp = items[i-1];
			if (i == 0 || j == 0)
				K[i][j] = 0;
			else if (get<0>(temp) <= j) {
				K[i][j] = max(get<1>(temp) + K[i - 1][j - get<0>(temp)], K[i - 1][j]);
			}
			else
				K[i][j] = K[i - 1][j];
		}
	}
	int ret = K[size][capacity];
	int j = capacity;
	for (int i = size; i > 0 && ret > 0; i--{
		if(ret == K[i-1][j])
			continue;
		else {
			included.push_back(items[i-1]);
			ret-=get<1>(items[i-1]);
			j-=get<0>(items[i-1]);
		}
	}
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
	vector <tuple<int, int>> pairs = getPair(lines);
	int capacity = get<1>(pairs[0]);
	int numItems = get<0>(pairs[0]);
	pairs.erase(pairs.begin());
	//for (int i = 0; i < pairs.size(); i++) 
		//cout << get<0>(pairs[i]) <<" , "<< get<1>(pairs[i]) << endl;
	vector < tuple<int, int>> includer;
	int ret = knapSack(capacity, pairs, numItems, includer);
	for (int i = 0; i < includer.size(); i++)
		cout << get<0>(includer) << "," << get<1>(includer);
	cout << endl;
	cout << ret << endl;
}