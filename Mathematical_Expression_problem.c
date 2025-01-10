#include <stdio.h>

long long modularExponentiation(long long Base, long long Power, long long Mod)
{
    long long result = 1;

    while (Power > 0)
    {

        if (Power % 2 == 1)
        {
            result = (result * Base) % Mod;
        }

        Power /= 2;

        Base = (Base * Base) % Mod;
    }

    return result;
}

int main()
{
    long long Base, Power, Mod;
    printf("Enter values for Base, Power, Mod: ");
    scanf("%lld %lld %lld", &Base, &Power, &Mod);
    
    if(Base < 0 || Power < 0 || Mod < 0){
        printf("Only Positive values are accepted");
        return 0;
    }

    long long result = modularExponentiation(Base, Power, Mod);
    printf("(Base^Power) %% Mod = %lld\n", result);

    return 0;
}
