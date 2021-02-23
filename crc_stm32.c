#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t crc32_st(uint32_t *pbuf, uint32_t size)
{
	const uint32_t st_const_value = 0x04c11db7;
	uint32_t crc_value = 0xffffffff;
	uint32_t xbit, bits, i;

	for (i = 0; i < size; i++)
	{
		xbit = 0x80000000;
		for (bits = 0; bits < 32; bits++)
		{
			if (crc_value & 0x80000000)
			{
				crc_value <<= 1;
				crc_value ^= st_const_value;
			}
			else
			{
				crc_value <<= 1;
			}
			if (pbuf[i] & xbit)
			{
				crc_value ^= st_const_value;
			}
			xbit >>= 1;
		}
	}
	return crc_value;
}

int main(int argc, char *argv[]) {
    uint32_t write[32];
    
    for(int i = 0; i < 32; i++) {
        memset(write + i, i, sizeof(uint32_t));
        printf("0x%08x\n", *(write + i));
    }
    
    uint32_t crc = crc32_st(write, 32);

    printf("crc is:0x%08x\n", crc);


    return 0;
}
