#include <bits/stdc++.h>
using namespace std;


/* initialising matrix in form of a square matrix of order n */
int **initmat(int n)
{
	int **mat = new int *[n];
	int i, j;
	for(i = 0 ; i < n ; i++)
		mat[i] = new int[n];
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
			mat[i][j] = 0;
	}
	return mat;
}

/* Funtion to sub two matrices */
int **sub(int **mat1, int **mat2, int n)
{
	int **mat = initmat(n);
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
			mat[i][j] = mat1[i][j] - mat2[i][j];
	}
	return mat;
}

/* Funtion to add two matrices */
int **add(int **mat1, int **mat2, int n)
{
	int **mat = initmat(n);
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
			mat[i][j] = mat1[i][j] + mat2[i][j];
	}
	return mat;
}

/* Product of two matrices using Stressen's algorithm*/
int **multiply(int **A, int **B, int n)
{
	if(n == 1)
	{
		int **P = initmat(n);
		P[0][0] = A[0][0] * B[0][0];
		return P;
	}

	/* Initialising the Product matrix pord */
	int **P = initmat(n);

    /* Initialising the division matrix A into 4 halves */
    int **A11 = initmat(n/2);
    int **A12 = initmat(n/2);
    int **A21 = initmat(n/2);
    int **A22 = initmat(n/2);

    /* Initialising the division matrix B into 4 halves */
    int **B11 = initmat(n/2);
    int **B12 = initmat(n/2);
    int **B21 = initmat(n/2);
    int **B22 = initmat(n/2);

	/* Splitting matrix */
    for(int i = 0 ; i < n/2 ; i++)
    {   for(int j = 0 ; j < n/2 ; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+n/2];
            A21[i][j] = A[i+n/2][j];
            A22[i][j] = A[i+n/2][j+n/2];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+n/2];
            B21[i][j] = B[i+n/2][j];
            B22[i][j] = B[i+n/2][j+n/2];
        }
    }

	int** P11 = add(multiply(A11, B11, n/2), multiply(A12, B21, n/2), n/2);
	int** P12 = add(multiply(A11, B12, n/2), multiply(A12, B22, n/2), n/2);
	int** P21 = add(multiply(A21, B11, n/2), multiply(A22, B21, n/2), n/2);
	int** P22 = add(multiply(A21, B12, n/2), multiply(A22, B22, n/2), n/2);

	/* Joining 4 halves into FINAL PRODUCT matrix */
	for(int i = 0 ; i < n/2 ; i++)
	{
	    for(int j = 0 ; j < n/2 ; j++) 
		{
	        P[i][j] = P11[i][j];
	        P[i][j+n/2] = P12[i][j];
	        P[i+n/2][j] = P21[i][j];
	        P[i+n/2][j+n/2] = P22[i][j];
	    }
	}
	return P;
}

int main()
{
	int m1 = 0, m2 = 0, flag = 0, n1 = 0 , n2 = 0;
    do
    {
		if(flag == 1)
		{
			cout << "MATRIX NOT COMPATIBLE FOR MULTIPLYING!" << endl;
			cout << "PLEASE ENTER VALUES COMPATIBLE FOR MATRIX MULTIPLICATION." << endl;
		}
        cout << "PLEASE ENTER NUMBER OF ROWS AND COLS FOR MATRIX1 ( m1xn1 ): ";
        cin >> m1 >> n1;
        cout << "PLEASE ENTER NUMBER OF ROWS AND COLS FOR MATRIX2 ( m2xn2 ): ";
        cin >> m2 >> n2;
		flag = 1;
    } while ( n1 != m2 );

    int **mat1, **mat2, **prod;

	//converting to 2^n size square matrix;
    int n = max(m1, max(n1, max(m2, n2)));
	if(ceil(log2(n)) != floor(log2(n)))
		n=pow(2,ceil(log2(n)));

	cout << "To make matrix multiplication in dimensions of power of 2" << endl;
	cout << "we change the matrix order to nearest greater 2's power order" << endl;
	cout << "and make the extra elements 0 so that they don't effect the multiplication." << endl;
	cout << "Here that value is : " << n << "." << endl;
	
	mat1 = initmat(n);
	mat2 = initmat(n);

    cout << "PLEASE ENTER ELEMENTS FOR MATRIX 1 :" << endl;
    for (int i = 0 ; i < m1 ; i++)
    {
        for(int j = 0 ; j < n1 ; j++)
        {
            cout << "ENTER ELEMENT ( " << i+1 << ", " << j+1 << " ) : ";
            cin >> mat1[i][j];
        }
    }

    cout << "PLEASE ENTER ELEMENTS FOR MATRIX 2 :" << endl;
    for (int i = 0 ; i < m2 ; i++)
    {
        for(int j = 0 ; j < n2 ; j++)
        {
            cout << "ENTER ELEMENT ( " << i+1 << ", " << j+1 << " ) : ";
            cin >> mat2[i][j];
        }
    }

	cout << endl << "MATRIX 1 :" << endl;
 	for(int i = 0 ; i < m1 ; i++)
	{
		for(int j = 0 ; j < n1 ; j++)
			cout<< mat1[i][j] << " ";
		cout<<endl;
	}

	cout << endl << "MATRIX 2 :" << endl;
 	for(int i = 0 ; i < m2 ; i++)
	{
		for(int j = 0 ; j < n2 ; j++)
			cout << mat2[i][j] << " ";
		cout<<endl;
	}

	prod = multiply(mat1, mat2, n);
 	
	cout << endl << "PRODUCT OF ABOVE PROVIDED MATRIX IS :" << endl;
	
	for(int i = 0 ; i < m1 ; i++)
	{
		for(int j = 0 ; j < n2 ; j++)
			cout << prod[i][j] << " ";
		cout<<endl;
	}
	return 0;
}
