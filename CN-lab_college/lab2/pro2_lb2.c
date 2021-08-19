#include <stdio.h>

int swap_Endians(int value)
{
    int leftmost_byte;
    int left_middle_byte;
    int right_middle_byte;
    int rightmost_byte;
    int result;

    leftmost_byte = (value & 0x000000FF) >> 0;
    left_middle_byte = (value & 0x0000FF00) >> 8;
    right_middle_byte = (value & 0x00FF0000) >> 16;
    rightmost_byte = (value & 0xFF000000) >> 24;

    leftmost_byte <<= 24;
    left_middle_byte <<= 16;
    right_middle_byte <<= 8;
    rightmost_byte <<= 0;

    result = (leftmost_byte | left_middle_byte | right_middle_byte | rightmost_byte);

    return result;
}

int main()
{
    unsigned int i = 1;
    char *c = (char *)&i;
    if (*c)
        printf("Little endian\n");
    else
        printf("Big endian\n");

    int big_Endian = 0x98773027;
    int little_Endian = 0x975492147;
    int result1, result2;
    result1 = swap_Endians(big_Endian);

    result2 = swap_Endians(little_Endian);

    printf("Big Endian to Little Endian: 0x%x\nLittle Endian to Big Endian: 0x%x\n",
           result1, result2);

    return 0;
}