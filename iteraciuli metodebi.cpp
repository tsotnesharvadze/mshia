#include <iostream>
using namespace std;

const int n = 4;

int main() {
	double a[n][n] = { { 21, 5, -3, -7 },
	{ 0, 15, -1, 4 }, { 8, 11, -31, 2 }, { 6, -13, 7, 35 } };
	double b[n] = { 16, 18, -10, 35 };

	double xold[n], xnew[n] = { 0 }, eps = 0.0000001, norma1;
	int k = 0, max_k = 500;
	do{
		k++;
		for (int i = 0; i < n; i++)
			xold[i] = xnew[i];
		for (int i = 0; i < n; i++){
			xnew[i] = b[i];
			for (int j = 0; j < i; j++)
				xnew[i] -= a[i][j] * xnew[j];
			for (int j = i+1; j < n; j++)
				xnew[i] -= a[i][j] * xnew[j];
			xnew[i] /= a[i][i];
		}

		norma1 = 0;
		for (int i = 0; i < n; i++)
			norma1 +=fabs(xnew[i] - xold[i]);
	} while (norma1>eps &&k < max_k);

	cout << "k= " << k << endl;
	for (int i = 0; i < n; i++)
		cout << xnew[i] << endl;

	return 0;
}