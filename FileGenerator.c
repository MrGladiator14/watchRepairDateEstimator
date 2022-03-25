#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VALIDITY 3000
#define sx 3

const char *IN_FORMAT1 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d\n}\n";
const char *IN_FORMAT2 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d,\n\t\"F\":%d,\n\t\"G\":%d,\n\t\"H\":%d,\n\t\"I\":%d,\n\t\"J\":%d,\n\t\"K\":%d,\n\t\"L\":%d\n}\n";

const char *OUT_FORMAT1 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d\n}\n";
const char *OUT_FORMAT2 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d,\n\t\"F\":%d,\n\t\"G\":%d,\n\t\"H\":%d,\n\t\"I\":%d,\n\t\"J\":%d,\n\t\"K\":%d,\n\t\"L\":%d\n}\n";

typedef struct component1
{
    int noOfParts[5];
} GEARS, BATTERY;

typedef struct component2
{
    int noOfParts[12];
} STRAP, CASE;

int main(int argc, char *argv[])
{

    int schedule[VALIDITY] = {0};
    for (int i = 0; i < VALIDITY; i++)
    {                   //(2 mechanics*(7hrs a day*(60 min)))=840 total working minutes
        if (i % 7 == 0) // sunday
        {
            schedule[i] = 0;
        }
        else if ((i + 1) % 7 == 0)
        {
            schedule[i] = 420; // halfDay
        }
        else
        {
            schedule[i] = 840; // regularDay
        }
    }

    FILE *file;
    file = fopen("schedule.bin", "wb");
    if (file == NULL)
    {
        printf("ERROR OPENING FILE\n");
    }
    fwrite(schedule, sizeof(schedule), 1, file);
    fclose(file);
    file = fopen("schedule.bin", "rb");
    if (file == NULL)
    {
        printf("ERROR OPENING FILE\n");
    }
    fread(schedule, sizeof(schedule), 1, file);
    fclose(file);
    for (int i = 0; i < VALIDITY; i++) // note that due to some reason not all binary filles content are displayed
    {
        printf("schedule[%d]= %d\n", i, schedule[i]);
    }

    GEARS s = {
        .noOfParts[0] = 10,
        .noOfParts[1] = 10,
        .noOfParts[2] = 10,
        .noOfParts[3] = 10,
        .noOfParts[4] = 10,
    };
    FILE *file1;
    fopen_s(&file1, "gearStock.json", "w+");
    if (file1 == NULL)
        return 1;

    fprintf_s(file1, OUT_FORMAT1, s.noOfParts[0], s.noOfParts[1], s.noOfParts[2], s.noOfParts[3], s.noOfParts[4]);

    fclose(file1);

    BATTERY t = {
        .noOfParts[0] = 10,
        .noOfParts[1] = 10,
        .noOfParts[2] = 10,
        .noOfParts[3] = 10,
        .noOfParts[4] = 10,
    };
    FILE *file2;
    fopen_s(&file2, "batteryStock.json", "w+");
    if (file2 == NULL)
        return 1;
    fprintf_s(file2, OUT_FORMAT1, t.noOfParts[0], t.noOfParts[1], t.noOfParts[2], t.noOfParts[3], t.noOfParts[4]);
    fclose(file2);

    STRAP u = {
        .noOfParts[0] = 10,
        .noOfParts[1] = 10,
        .noOfParts[2] = 10,
        .noOfParts[3] = 10,
        .noOfParts[4] = 10,
        .noOfParts[5] = 10,
        .noOfParts[6] = 10,
        .noOfParts[7] = 10,
        .noOfParts[8] = 10,
        .noOfParts[9] = 10,
        .noOfParts[10] = 10,
        .noOfParts[11] = 10,
    };
    FILE *file3;
    fopen_s(&file3, "strapStock.json", "w+");
    if (file3 == NULL)
        return 1;
    fprintf_s(file3, OUT_FORMAT2, u.noOfParts[0], u.noOfParts[1], u.noOfParts[2], u.noOfParts[3], u.noOfParts[4], u.noOfParts[5], u.noOfParts[6], u.noOfParts[7], u.noOfParts[8], u.noOfParts[9], u.noOfParts[10], u.noOfParts[11]);
    fclose(file3);

    CASE v = {
        .noOfParts[0] = 10,
        .noOfParts[1] = 10,
        .noOfParts[2] = 10,
        .noOfParts[3] = 10,
        .noOfParts[4] = 10,
        .noOfParts[5] = 10,
        .noOfParts[6] = 10,
        .noOfParts[7] = 10,
        .noOfParts[8] = 10,
        .noOfParts[9] = 10,
        .noOfParts[10] = 10,
        .noOfParts[11] = 10,
    };
    FILE *file4;
    fopen_s(&file4, "casingStock.json", "w+");
    if (file4 == NULL)
        return 1;
    fprintf_s(file4, OUT_FORMAT2, v.noOfParts[0], v.noOfParts[1], v.noOfParts[2], v.noOfParts[3], v.noOfParts[4], v.noOfParts[5], v.noOfParts[6], v.noOfParts[7], v.noOfParts[8], v.noOfParts[9], v.noOfParts[10], v.noOfParts[11]);
    fclose(file4);
    printf("files created\n");

    return 0;
}