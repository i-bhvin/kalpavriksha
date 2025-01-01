#include <stdio.h>

long long modularExponentiation(long long B, long long N, long long M)
{
    long long result = 1;

    while (N > 0)
    {

        if (N % 2 == 1)
        {
            result = (result * B) % M;
        }

        N /= 2;

        B = (B * N) % M;
    }

    return result;
}

int main()
{
    long long B, N, M;
    printf("Enter values for B, N, M: ");
    scanf("%lld %lld %lld", &B, &N, &M);

    long long result = modularExponentiation(B, N, M);
    printf("(B^N) %% M = %lld\n", result);

    return 0;
}