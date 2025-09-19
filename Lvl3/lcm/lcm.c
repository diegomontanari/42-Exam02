unsigned int    mcd(unsigned int a, unsigned int b)
{
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)  // prevenzione divisione per zero
        return 0;
    return (a / mcd(a, b)) * b;
}
