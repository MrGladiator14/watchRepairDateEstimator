#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VALIDITY 300

int main()
{
    int schedule[VALIDITY] = {0};
    FILE *file;
    file = fopen("schedule.bin", "rb");
    if (file == NULL)
    {
        printf("ERROR OPENING FILE\n");
    }

    fread(schedule, sizeof(schedule), 1, file);
    fclose(file);
    for (int i = 0; i < VALIDITY; i++)
    {
        printf("schedule[%d]= %d\n", i, schedule[i]);
    }
    return 0;
}