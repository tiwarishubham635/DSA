bool isPowerOfThree(int n) 
{
    return fmod(log10(n)/log10(3), 1)==0;
}
The fmod function returns remainder of floating division, like here it returns the remainder when log10(n) is divided by 1. We are checking if it is zero.
