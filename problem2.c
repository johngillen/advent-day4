#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * file;
    file = fopen("input", "r");

    int min, max, count = 0;
    fscanf(file, "%d-%d", &min, &max);

    for (min; min < max; min++)
    {
        char current[6];
        sprintf(current, "%d", min);

        int flag = 0;
        for (size_t i = 0; i < 5; i++) 
        {
            int t = 0;
            for (size_t j = 0; j < 6; j++)
            { if (current[i] == current[j]) { t++; } }
            if (t == 2) { flag = 1; }
        }

        for (size_t i = 0; i < 5; i++) 
        { if (current[i] > current[i + 1]) { flag = 0; break; } }

        if (flag) { printf("%d\n", min); count++; }        
    }
    
    printf("Acceptable passwords: %d\n", count);

    return 0;
}
