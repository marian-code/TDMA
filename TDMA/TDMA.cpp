// TDMA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int N=6;
	vector<vector<double>> matrix;
	vector<double> vec;
	int i, j, k;
	vector<double> x;
	double help;

	cout.precision(2);
	cout.setf(std::ios::fixed, std::ios::floatfield);

	x.resize(N);
	vec.resize(N);
	matrix.resize(N);
	for (i = 0; i < N; i++) matrix[i].resize(N);

	matrix[0][0] = 2;
	matrix[0][1] = 1;
	matrix[N-1][N-1] = 2;
	matrix[N - 2][N - 1] = 1;
	matrix[N-1][N-2] = 1;

	for (i = 1; i < N-1; i++)
	{
		matrix[i][i - 1] = 1;
		matrix[i - 1][i] = 1;
		matrix[i][i] = 2;
		vec[i] = i % 3;
	}

	//vyrobit 1 na diagonale v prvom riadku
	/*vec[0] /= matrix[0][0];
	matrix[0][1] /= matrix[0][0];
	matrix[0][0] /= matrix[0][0];*/

	for (j = 0; j < N; j++)
	{
		for (k = 0; k < N; k++)
		{
			cout << matrix[j][k] << " ";
		}
		cout << vec[j] << endl;
	}
	cout << endl;

	for (i = 1; i < N; i++)
	{
		help = matrix[i][i - 1] / matrix[i - 1][i - 1];
		matrix[i][i - 1] -= matrix[i - 1][i - 1] * help;
		matrix[i][i] -= matrix[i - 1][i] * help;;
		vec[i] -= vec[i-1] * help;
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				cout << matrix[j][k] << " ";
			}
			cout <<vec[j]<< endl;
		}
		cout << endl;
	}

	x[N - 1] = vec[N - 1] / matrix[N - 1][N - 1];

	for (i = N - 2; i > -1; i--)
		x[i] = (vec[i] - x[i + 1] * matrix[i][i + 1]) / matrix[i][i];

	system("PAUSE");

    return 0;
}

