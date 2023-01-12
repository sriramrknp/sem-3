#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define sze 20

int main()
{
    char **left, **right;
    int total = 0;

    printf("Enter number of entities: ");
    scanf("%d", &total);

    left = malloc(total * (sizeof(char *)));
    right = malloc(total * (sizeof(char *)));
    char buffer[sze];
    int length = 0;

    while(getchar()!='\n');

    printf("\n");
    for (int i = 0; i < total; i++)
    {
        printf("Enter left attributes of FD %d: ", i + 1);
        fgets(buffer, sze, stdin);
        length = strlen(buffer);
        buffer[length - 1] = '\0';
        left[i] = malloc(length * (sizeof(char)));
        strcpy(left[i], buffer);
    
        printf("Enter right attributes of FD %d: ", i + 1);
        fgets(buffer, sze, stdin);
        length = strlen(buffer);
        buffer[length - 1] = '\0';
        right[i] = malloc(length * (sizeof(char)));
        strcpy(right[i], buffer);
    
        printf("\n");
    }

    int count[total], temp=0;
    for (int i = 0; i < total;i++)
    {
        count[i] = 0;
    }

        for (int i = 0; i < total; i++)
        {
            for (int j = 0; (*(*(right + i) + j) != '\0'); j++)
            {
                // printf("%c     %c", *(*(left + i) + j), *(*(right + i) + j));
                for (int k = 0; (*(*(left + i) + k) != '\0'); k++)
                {
                    if (*(*(right + i) + j) == *(*(left + i) + k))
                    {
                        count[i]++;
                    }
                }
            }
        }

    for (int i = 0; i < total;i++){
        if (count[i] <= strlen(left[i]) && count[i]==strlen(right[i])){
            printf("%d FD is Trivial\n", i+1);
            temp++;
        }
        else if (count[i] ==0)
        {
            printf("%d FD is Non-Trivial\n", i+1);
            temp++;
        }
        else if (temp == 0)
            printf("%d FD is Semi-Trivial\n", i+1);
    }

            printf("\n");
    return 0;
}