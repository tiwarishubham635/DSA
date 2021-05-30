unsigned int swapBits(unsigned int n)
    {
    	unsigned int a = n&0xAAAAAAAA; // even bits
    	unsigned int b = n&0x55555555; // odd bits
    	return (a>>1) | (b<<1);
    }
