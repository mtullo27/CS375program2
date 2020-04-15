#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector> 
#include <streambuf>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}
int main(int argc, char* argv[]) {
	ifstream infile;
	ofstream outfile;

	string file;

	infile.open(argv[1]);
	outfile.open(argv[2]);

	infile >> file;

	int size = file.length();
	
 }