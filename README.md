## MATRIX MULTIPLICATION
We first need to check whether the matrices are compatible for multiplication or not. To understand this please refer https://www.mathsisfun.com/algebra/matrix-multiplying.html.<br/>
**Solution1: Brute Force approach :** <br/>
![image](https://user-images.githubusercontent.com/60324321/111648678-9e8cdb00-8829-11eb-9879-885fb6c2b5ac.png)
<br/>
In this we will manually calculate all the elements of product matrix (the one which will contain the product of given compatible matrix). For each element of product matrix we will need to calculate product of each element of row of matrix 1 and each element of column column of matrix 2, in which row and column number depends on the element of product matrix which we want to calculate. For this we need n iterations, if order is n, and there are such nxn elements, therefore we iterate n^2 x n = n^3, which is the time complexity i.e, T(n) = n^(3).<br/>
From proper analysis we can come to result that **T(n) = A·n^(3) + B·n^(2) + C·n + D, therefore T(n) = Θ(n^(3)).**<br/><br/>
**Solution2: Divide and Conquer approach :** <br/>
In this approach we divide the matrix into 4 quarters such that they are equal, to do so we make input matrices' dimensions in power of x, so that whenever we diide the matrix, we can divide it again by 2, as we will do dividion of matrices into dimensions n/2 x n/2, if originally the matrix provided is of dimensions n x n. In doing so we fill the extra created spaces with 0s, so that they won't contribute in the product matrix.<br/>
We go on dividing the matrix till the point only one element is remaining, and this is our terminating condition.<br/>
**Partition A, B, and C into four n/2 × n/2 matrices:<br/>
![image](https://user-images.githubusercontent.com/60324321/111648943-ea3f8480-8829-11eb-9700-5f99a7e12289.png)
<br/> Here C is the product matrix. <br/>
Hence the equation C = A · B becomes:<br/>
![image](https://user-images.githubusercontent.com/60324321/111649038-ffb4ae80-8829-11eb-90be-316b9bbf590f.png)
<br/>
This corresponds to the four equations:<br/>
C11 = A11 · B11 + A12 · B21<br/>
C12 = A11 · B12 + A12 · B22<br/>
C21 = A21 · B11 + A22 · B21<br/>
C22 = A21 · B12 + A22 · B22<br/>
<br/>
C11 = MATRIX_MULTIPLY(A11,B11)  [1] + MATRIX_MULTIPLY(A12,B21) [2]<br/>
C12 = MATRIX_MULTIPLY(A11,B12)  [3] + MATRIX_MULTIPLY(A12,B22) [4]<br/>
C21 = MATRIX_MULTIPLY(A21,B11)  [5] + MATRIX_MULTIPLY(A22,B21) [6]<br/>
C22 = MATRIX_MULTIPLY(A21,B12)  [7] + MATRIX_MULTIPLY(A22,B22) [8]<br/>
THIS IS THE JOINING PROCESS.<br/>
**Therefore,  T(n) = Θ(1), when n = 1,<br/>
            T(n) = 8T(n/2) + Θ(n^(2)) [for 4 addition and partition]<br/>
Therefore T(n) = n^(log(base 2)(arg (8))) or n^(log8) = n^3**<br/>
**Solution3: Stressen's Algorithm :** <br/>
In Stressen's algorithm we minimise the recursive call my using properties of matrix multiplication and by terminating the repetitive calculation as follows :<br/>
![image](https://user-images.githubusercontent.com/60324321/111648373-4950c980-8829-11eb-856f-9b9478e753b4.png)
<br/>
And then using this we again need to get the 4 elements of product matrix C as follows :<br/>
![image](https://user-images.githubusercontent.com/60324321/111649531-76ea4280-882a-11eb-90b7-8f36e9be7350.png)
<br/>
And by doing so we reduce the recursive from 8 to 7, so the recursive relation becomes : <br/>
![image](https://user-images.githubusercontent.com/60324321/111649651-941f1100-882a-11eb-9704-9c94f383cfa3.png)
<br/>
And by using master method we get : 
![image](https://user-images.githubusercontent.com/60324321/111649704-a305c380-882a-11eb-9ffe-7fc23cd8128a.png)
<br/>
This may look smaller but when we do matrix multiplication in real life like in calculating voltages and current using matrix method, we need to calculate product of very large matrices, and at that time 2.8's effect is very large.
