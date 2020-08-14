/** @file list5109.hh */
/** Listing 51-9. The isprime Function Template */
template<class T>
bool isprime(T n)
{
    if (n < 2)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0)
        return false;
    else
    {
        for (T test{3}, limit{n / 2}; test < limit; test += 2)
            if (n % test == 0)
                return false;
        return true;
    }
}
