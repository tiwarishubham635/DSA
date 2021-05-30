long long reversedBits(long long num) 
{
    unsigned int count = 31;
    unsigned int reverse_num = num;

    num >>= 1; 
    while(num)
    {
       reverse_num <<= 1;       
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}
