#include <stdio.h>

void matmult(long long a[][2], long long b[][2], long long c[][2])

{

    int i, j, k;

    for (i = 0; i < 2; i++)

    {
        for (j = 0; j < 2; j++)

        {

            c[i][j] = 0;

            for (k = 0; k < 2; k++)

            {

                c[i][j] += (a[i][k] * b[k][j]);

                c[i][j] = c[i][j];
            }
        }
    }
}
void matpow(long long Z[][2], int n, long long ans[][2])

{

    long long temp[2][2];

    //assign ans= the identity matrix

    ans[0][0] = 1;

    ans[1][0] = 0;

    ans[0][1] = 0;

    ans[1][1] = 1;

    int i, j;

    while (n != 0)

    {

        if (n == 1)

        {
            matmult(ans, Z, temp);

            for (i = 0; i < 2; i++)

                for (j = 0; j < 2; j++)

                    ans[i][j] = temp[i][j];
        }
        matmult(Z, Z, temp);

        for (i = 0; i < 2; i++)

            for (j = 0; j < 2; j++)

                Z[i][j] = temp[i][j];

        n = n / 2;
    }
    return;
}
long long findFibonacci(long long n) {

    long long fib;

    if (n < 2)

    {

        long long int Z[2][2] = {
                {
                    1,
                    1
                },
                {
                    1,
                    0
                }
            },
            result[2][2]; //modify matrix a[][] for other recurrence relations

        matpow(Z, n - 2, result);

        fib = result[0][0] * 1 + result[0][1] * 0; //final multiplication of Z^(n-2) with the initial terms of the series
    } else

        fib = n - 1;

    return fib;
}

int main(){
	printf("%lld\n",findFibonacci(45));
	return 0;
}