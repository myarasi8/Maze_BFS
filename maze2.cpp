#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include <queue>
#include <climits>
using namespace std;


//matrix coordinate
struct Node
{
	int row;
	int col;
};

//Queue used for BFS
struct Queue
{
	Node coord;
	int shortestDist;
};

int mazeSize() //returns the size of maze.txt
{
	string currentLine = ""; //string that will recieve each line of the file
	int rowCount = 0; //the number of rows in the file
	int colCount = 0; //the number of columns in the file

	//creating and opening the file
	string file;
	file = "maze.txt";
	ifstream myfile;
	myfile.open(file.c_str());

	if (!myfile.is_open())
		cout << "Not open" << endl;
	else
	{
		//finds the dimensions of the input maze
		while(getline(myfile, currentLine))
		{
			colCount = currentLine.size(); //the number of columns
			rowCount += 1; //the number of rows
			//cout << "here" << endl;
		}
	}
	myfile.close();

	if (rowCount != colCount)
	{
		cout << "Invalid Matrix, not NxN" << endl;
		return 0;
	}

	return rowCount;
}

//bool isGood(vector<vector<int> >maze, int row, int col)
bool isGood(int row, int col)
{
	int dimension = mazeSize();

	if (row >= 0 && row < dimension && col >= 0 && col < dimension)// && maze[row][col] == 1)
	{
		return true;
	}
	return false;
}

int solveMaze(vector<vector<int> >mazeMat, Node src, Node destination) //this is a BFS approach
{
	int dimension = mazeSize();
	vector<vector<bool> > zeroMatrix;
	
	
	for (int i = 0; i < dimension; i++)
	{
		vector<bool> myVec;
		for (int j = 0; j < dimension; j++)
		{
			//vecMatrix[i][j] = 0;
			int tempVal = false;
			myVec.push_back(tempVal);
			//cout << vecMatrix[i][j] << endl;
		}
		zeroMatrix.push_back(myVec);
	}


	zeroMatrix[src.row][src.col] = true; 

	//queue that will be used for the BFS
	queue<Queue> q;


	//distance of the source from itself is 0
	Queue s = {src, 0};


	//enqueue the source 
	q.push(s);


	vector<int>rowNum;
	//int temp = -1;
	rowNum.push_back(-1);
	rowNum.push_back(0);
	rowNum.push_back(0);
	rowNum.push_back(1);

	vector<int>colNum;
	colNum.push_back(0);
	colNum.push_back(-1);
	colNum.push_back(1);
	colNum.push_back(0);



	while(!q.empty())
	{
		Queue currentNode = q.front();
		Node coord = currentNode.coord;

	//	cout << coord.row << " " << destination.row << endl;

		if (coord.row == (destination.row-1) && coord.col == (destination.col-1))
		{
			//cout << "here" << endl;
			return currentNode.shortestDist;
		}


		//else dequeue the front cell
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int r = coord.row + rowNum[i];
			int c = coord.col + colNum[i];

			//if adjacent cell is good, that means there is a path and we enqueue it
			if (isGood(r, c) && mazeMat[r][c] && !zeroMatrix[r][c])
			{
				zeroMatrix[r][c] = true;
				Queue AdjacentCell = {{r,c}, currentNode.shortestDist + 1};

				q.push(AdjacentCell);
			}
		}

	}
	//cout << zeroMatrix[src.row][src.col] << endl;
	
	return INT_MAX;
}

int createMaze() //creates the zero matrix and turns the maze into a matrix (2-D arrays)
{
	char charTemp; //temporarly holds each value of the maze
	int rowCount = mazeSize();
	int colCount = mazeSize();

	string file;
	file = "maze.txt";
	ifstream myfile;
	myfile.open(file.c_str());

	vector<vector<int> > mazeMat;
	vector<int>mazeVec;

	vector<vector<int> > zeroMatrix;
	if (!myfile.is_open())
		cout << "Not open" << endl;
	else
	{
		//create a matrix with the values from the maze
		while(!myfile.eof())
		{
			myfile.get(charTemp);
			int temp = charTemp - '0';
			
			if (temp != -38)
			{
				//cout << temp << " ";
				if (mazeVec.size() != (colCount-1))
				{
					mazeVec.push_back(temp);
				}
				else
				{
					//cout << endl;
					mazeVec.push_back(temp);
					mazeMat.push_back(mazeVec);
					mazeVec.clear();
					//mazeVec.push_back(temp);
				}
			}
		}
	}


	//cout << endl;
	myfile.close();

	int dimension = mazeSize();
	Node src = {0,0};
	Node destination = {dimension,dimension};

	int dist = solveMaze(mazeMat,src,destination);

	if (dist != INT_MAX)
	{
		cout << "Shortest path is " << dist << endl;
	}
	else
	{
		return 0;
	}

	return 1;
}




int main()
{
	createMaze();

}