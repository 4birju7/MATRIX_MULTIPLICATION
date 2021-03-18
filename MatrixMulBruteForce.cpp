#include<bits/stdc++.h>
using namespace std;

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
        cout << "PLEASE ENTER NUMBER OF ROWS AND COLS FOR MATRIX1 ( m1 n1 ): ";
        cin >> m1 >> n1;
        cout << "PLEASE ENTER NUMBER OF ROWS AND COLS FOR MATRIX2 ( m2 n2 ): ";
        cin >> m2 >> n2;
		flag = 1;
    } while ( n1 != m2 );
    
    int mat1[m1][n1], mat2[m2][n2], prod[m1][n2];
    
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
    
    //MATRIX MULTIPLICATION BRUTE FORCE
    for (int i = 0 ; i < m1 ; i++)
    {
        for (int j = 0 ; j < n2 ; j++)
        {
            prod[i][j] = 0;
            for (int k = 0 ; k < n1 ; k++)
                prod[i][j] += mat1[i][k]*mat2[k][j];
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

    cout << endl << "PRODUCT OF ABOVE PROVIDED MATRIX IS :" << endl;
    for (int i = 0; i < m1 ; i++)
    {
        for (int j = 0; j < n2 ; j++)
            cout << prod[i][j] << ' ';
        cout << endl;   
    }
    return 0;
}
