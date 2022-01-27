#include<stdio.h>
int main(int argl, char *argv[])
{
    unsigned len;
    unsigned num, start = 99999;
    scanf("%u", &len);
    for(int i = 0; i < len; i++)
    {
        scanf("%u", &num);
        if(start == 99999)
            start = num;
        else if(num % start == 0)
        {
            printf("%u\n", num);
            start = 99999;
        }
    }
    return 0;
}
