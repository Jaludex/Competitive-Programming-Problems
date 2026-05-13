#include <iostream>
#include <cmath>

#define io_boost std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define weird_mod 1000000007ULL

//Saca fact(n) % mod integrando la operacion de mod en cada iteracion para evitar overflows
unsigned long long mod_factorial(unsigned long long n, unsigned long long mod) 
{
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; ++i) {
        result = (result * i) % mod;
    }
    return result;
}

unsigned long long mod_power(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long res = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp % 2 == 1) res = (res * base) % mod;

        base = (base * base) % mod;
        exp = exp >> 1;
    }

    return res;
}

//Mediante el pequeño teorema de fermat
unsigned long long mod_inverse(unsigned long long a, unsigned long long mod) 
{
    return mod_power(a, mod - 2, mod);
}

unsigned long long mod_combination(unsigned long long n, unsigned long long m, unsigned long long mod)
{
    //La idea aqui es sacar el modulo de nCm con el modulo raro que piden, para multiplicacion es solo multiplicar los modulos pero en division necesito el inverso multiplicativo modular, sacando modulos en cada producto
    return (mod_factorial(n, mod) * (mod_inverse(mod_factorial(m, mod), mod) * mod_inverse(mod_factorial(n - m, mod), mod) % mod)) % mod;
}

int main()
{
    io_boost;

    unsigned long long n, m;
    std::cin >> n >> m;

    unsigned long long ways = mod_combination(n + m - 1, n - 1 , weird_mod);

    std::cout << ways << std::endl;
    
    return 0;
}