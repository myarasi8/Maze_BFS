int maze()
{
	char charTemp; //temporarly holds each value of the maze
	int count = 0;

	//cout << "Number of rows are: " << rowCount << " and the number of columns are: " << colCount << endl;

	//Creating a matrix and filling it with 0's
	vector<vector<int> > zeroMatrix;
	for (int i = 0; i < rowCount; i++)
	{
		vector<int> myVec;
		for (int j = 0; j < colCount; j++)
		{
			//vecMatrix[i][j] = 0;
			int tempVal = 0;
			myVec.push_back(tempVal);
			//cout << vecMatrix[i][j] << endl;
		}
		zeroMatrix.push_back(myVec);
	}

	vector<vector<int> > mazeMat;
	vector<int>mazeVec;
	myfile.open(file);
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
	//cout << endl;
	myfile.close();


	return 0;
}

	/*
	//printing the matrix of the maze
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			//cout << zeroMatrix[i][j] << " ";
			cout << mazeMat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	//printing the matrix of 0's
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << zeroMatrix[i][j] << " ";
			//cout << mazeMat[i][j] << " ";
		}
		cout << endl;
	}
	*/


			for (int i = 0; i < rowCount; i++)
		{
			vector<int> myVec;
			for (int j = 0; j < colCount; j++)
			{
				//vecMatrix[i][j] = 0;
				int tempVal = 0;
				myVec.push_back(tempVal);
				//cout << vecMatrix[i][j] << endl;
			}
			zeroMatrix.push_back(myVec);
		}


1111111
0000001
0000001
1111111
1000000
1000000
1111111