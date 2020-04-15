The program will have 2 command line arguments: input file, output file. \n
Input file: 
The structure of the input file is as follows.
Line 1: n,c // n is the size of the problem (the total number of items) and C is the total weight limit 
Lines 2 to n+1: wi,pi // wi is the weight of item i and pi is the profit of item i 
The example problem from slide 12 of Lecture 25 can be converted into the following input file format: 
4,16 
2,40 
5,30 
10,50 
5,10 
Output file: 
The structure of the output file is as follows. 
Line 1: the size of the problem (i.e., the total number of items),the optimal value (i.e., the maximum
profit),the size (k) of the first optimal solution found (i.e., the size of the first optimal subset of items
found to produce the maximum profit) 
Line 2: the total number of nodes visited (by the algorithm from the start to the end of the search
including the root and the last node visited in the binary search space tree),the total number of leaf nodes
visited 
Lines 3 to 3+(k-1): each line contains the weight and profit of an item selected in order for the first
optimal solution found. 
The solution for the above example in the output file format: 
4,90,2
11,6 
2,40 
10,50
