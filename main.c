main()
{
    int tof = 0;
    int var, t = 0, n, even = 0, odd = 0, s = 60, b = 0, sum = 0, primes = 0;
    printf(" Type in how many random characters you wish to analyse: ");
    scanf(" %i", &var);
    const int sz = var;
    printf(" Type in the span of your characters: ");
    scanf(" %i", &var);
    const int sp = var;
    int vet[sz], loc[sp];
    for (int i = 0; i < sp; i++)
        loc[i] = 0;
    for (int i = 0; i < sz; i++)
    {
        vet[i] = rand() % (sp) + 1;
        loc[vet[i]]++;
        if (s > vet[i])
            s = vet[i];
        if (b < vet[i])
            b = vet[i];
        sum = sum + vet[i];
        if (vet[i] % 2 == 0)
            even++;
        else
            odd++;
        for (int j = 2; j < vet[i] / 2; ++j)
            if (vet[i] % j == 0)
            {
                tof = 1;
                j = vet[i];
            }
        if (tof == 0)
            primes++;
        tof = 0;
    }
    for (int i = 0; i < sp; i++)
        if (t < loc[i])
        {
            t = loc[i];
            n = i;
        }
    printf("\n The most frequent number was: %i, occurring %i times.\n There are %i prime numbers, %i even numbers and %i odd numbers.\n The greatest integer was: %i, while the smallest was: %i.\n The sum of all terms is: %i and their mean: %i\n\n", n, t, primes, even, odd, b, s, sum, sum / sz);
}
