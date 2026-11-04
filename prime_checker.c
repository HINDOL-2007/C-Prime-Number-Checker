#include <stdio.h>
int main()
{
    int num;
    printf("Enter The Number :- ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("%d is a Negative and not Prime Number . ", num);
        return 0;
    }
    if (num == 1 || num == 0)
    {
        printf("%d is not a Prime Number . ", num);
    }
    else if (num == 2)
    {
        printf("%d is 1st Prime Number .", num);
    }
    else if (num % 2 == 0)
    {
        printf("%d is not a Prime Number . ", num);
    }
    else if (num > 2)
    {
        for (int i = 3; i * i <= num; i += 2)
        {
            if (num % i == 0)
            {
                printf("%d is not a Prime Number . ", num);
                return 0;
            }
        }
        printf("%d is a Prime Number . ", num);
    }
    return 0;
}
