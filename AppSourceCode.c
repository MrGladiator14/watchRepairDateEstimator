#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define VALIDITY 3000
int schedule[VALIDITY];
int k[4] = {0};
// JSON file read formats
const char *OUT_FORMAT1 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d\n}\n";
const char *OUT_FORMAT2 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d,\n\t\"F\":%d,\n\t\"G\":%d,\n\t\"H\":%d,\n\t\"I\":%d,\n\t\"J\":%d,\n\t\"K\":%d,\n\t\"L\":%d\n}\n";

const char *IN_FORMAT1 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d\n}";
const char *IN_FORMAT2 = "{\n\t\"A\":%d,\n\t\"B\":%d,\n\t\"C\":%d,\n\t\"D\":%d,\n\t\"E\":%d,\n\t\"F\":%d,\n\t\"G\":%d,\n\t\"H\":%d,\n\t\"I\":%d,\n\t\"J\":%d,\n\t\"K\":%d,\n\t\"L\":%d\n}";
// structure indicating number part number
typedef struct component1
{
    int noOfParts[5];
} GEARS, BATTERY;

typedef struct component2
{
    int noOfParts[12];
} STRAP, CASE;
// creating struct object
GEARS g;
BATTERY b;
STRAP s;
CASE c;
// defining fodel number for identification
typedef struct MODEL
{
    char gears, strap, casing, battery;
} model;
model m;

typedef struct date // date structure                  
{
    int d, m, y;
} date;
date created = {.d = 20, .m = 02, .y = 2022}; // sunday
date finaldate;

int days(date c)
{
    int leapyr = 0, dayC = 0;
    for (int i = 1; i < c.y; i++) // counts leapyears from 0 AD
    {
        if ((i % 4 == 0) && !(i % 100 == 0) || (i % 400 == 0))
            leapyr++;
    }
    for (int i = 1; i < c.m; i++) // counts days passed in the given year by months
    {
        if ((i - 1 == 1) || (i - 1 == 3) || (i - 1 == 5) || (i - 1 == 7) || (i - 1 == 8) || (i - 1 == 10))
        {
            dayC += 31;
            break;
        }
        if (i - 1 == 2)
        {
            dayC += 28;
            break;
        }
        else if (i - 1 != 0)
        {
            dayC += 30;
            break;
        }
    }
    if ((c.m > 2) && ((c.y % 4 == 0) && (c.y % 100 != 0) || (c.y % 400 == 0))) // checks if current year is a leap year and adds 29th Feb accordingly
    {
        return (1 + dayC + leapyr + (365 * c.y) + c.d);
    }
    else
        return (dayC + leapyr + (365 * c.y) + c.d);
}

int Difference(date a, date b)
{
    int d1 = days(a);

    int d2 = days(b);

    return d1 - d2;
}

date Add_days(date c, int n)
{
    date d;
    d.m = c.m;
    d.y = c.y;
    d.d = c.d;
    for (int i = n; i > 0; i--)
    {
        d.d++;
        if (((d.y % 4 == 0) && (d.y % 100 != 0)) || (d.y % 400 == 0))
        {
            if ((d.d > 29) && (d.m == 2))
            {
                d.m++;
                d.d = 1;
            }
            else if ((d.d > 31) && ((d.m == 1) || (d.m == 3) || (d.m == 5) || (d.m == 7) || (d.m == 8) || (d.m == 10) || (d.m == 12)))
            {
                d.d = 1;
                d.m++;
            }
            else if ((d.d > 30) && !((d.m == 1) || (d.m == 3) || (d.m == 5) || (d.m == 7) || (d.m == 8) || (d.m == 10) || (d.m == 12)))
            {
                d.m++;
                d.d = 1;
            }
            if (d.m > 12)
            {
                d.m = 1;
                d.y++;
            }
        }
        else
        {
            if ((d.d > 28) && (d.m == 2))
            {
                d.m++;
                d.d = 1;
            }
            else if ((d.d > 31) && ((d.m == 1) || (d.m == 3) || (d.m == 5) || (d.m == 7) || (d.m == 8) || (d.m == 10) || (d.m == 12)))
            {
                d.m++;
                d.d = 1;
            }
            else if ((d.d > 30) && !((d.m == 1) || (d.m == 3) || (d.m == 5) || (d.m == 7) || (d.m == 8) || (d.m == 10) || (d.m == 12)))
            {
                d.m++;
                d.d = 1;
            }
            if (d.m > 12)
            {
                d.m = 1;
                d.y++;
            }
        }
    }
    return d;
}

void productEntry()
{

    int d = 0;
    while (d == 0)
    {
        printf("enter 4 alphabet product code: 'X X X X' \t"); // 4 alphabet code
        scanf("%c %c %c %c", &m.gears, &m.strap, &m.casing, &m.battery);
        if (((m.battery >= 'A') && (m.battery <= 'E')))
        {
            d++;
        }
        if (((m.gears >= 'A') && (m.gears <= 'E')))
        {
            d++;
        }
        if (((m.strap >= 'A') && (m.strap <= 'L')))
        {
            d++;
        }
        if (((m.casing >= 'A') && (m.casing <= 'L')))
        {
            d++;
        }
        if (d == 0)
        {
            printf("\n\tINVALID ENTRY\n");
        }
    }
}
bool gearsStock()
{
    FILE *file;
    fopen_s(&file, "gearStock.json", "r"); //'w+' to read and write
    fscanf_s(file, IN_FORMAT1, &g.noOfParts[0], &g.noOfParts[1], &g.noOfParts[2], &g.noOfParts[3], &g.noOfParts[4]);
    --g.noOfParts[m.gears - 'A'];
    /* for(int i=0; i<5;i++){
         printf("\n%d\t",g.noOfParts[i]);
     }*/
    if ((g.noOfParts[m.gears - 'A'] <= 2) && (g.noOfParts[m.gears - 'A'] >= 0))
        printf("\nGears %c needs to be restocked soon\n", m.gears);
    if (g.noOfParts[m.gears - 'A'] < 0)
    {
        printf("\nGears %c out of stock\n", m.gears);
        return false;
    }
    fclose(file);

    return true;
}

bool batteryStock()
{
    FILE *file;
    fopen_s(&file, "batteryStock.json", "r"); //'w+' to read and write
    fscanf_s(file, IN_FORMAT1, &b.noOfParts[0], &b.noOfParts[1], &b.noOfParts[2], &b.noOfParts[3], &b.noOfParts[4]);
    --b.noOfParts[m.battery - 'A'];
    if ((b.noOfParts[m.battery - 'A'] <= 2) && (b.noOfParts[m.battery - 'A'] >= 0))
        printf("\nBattery %c needs to be restocked soon\n", m.battery);
    if (b.noOfParts[m.battery - 'A'] < 0)
    {
        printf("\nBattery %c out of stock\n", m.battery);
        return false;
    }
    fclose(file);

    return true;
}

bool strapStock()
{
    FILE *file;
    fopen_s(&file, "strapStock.json", "r"); //'w+' to read and write
    fscanf_s(file, IN_FORMAT2, &s.noOfParts[0], &s.noOfParts[1], &s.noOfParts[2], &s.noOfParts[3], &s.noOfParts[4], &s.noOfParts[5], &s.noOfParts[6], &s.noOfParts[7], &s.noOfParts[8], &s.noOfParts[9], &s.noOfParts[10], &s.noOfParts[11], &s.noOfParts[12]);
    --s.noOfParts[m.strap - 'A'];
    if ((s.noOfParts[m.strap - 'A'] <= 2) && (s.noOfParts[m.strap - 'A'] >= 0))
        printf("\nStraps %c needs to be restocked soon\n", m.strap);
    if (s.noOfParts[m.strap - 'A'] < 0)
    {
        printf("\nStrap %c out of stock\n", m.strap);
        return false;
    }
    fclose(file);

    return true;
}

bool casingStock()
{
    FILE *file;
    fopen_s(&file, "casingStock.json", "r"); //'w+' to read and write
    fscanf_s(file, IN_FORMAT2, &c.noOfParts[0], &c.noOfParts[1], &c.noOfParts[2], &c.noOfParts[3], &c.noOfParts[4], &c.noOfParts[5], &c.noOfParts[6], &c.noOfParts[7], &c.noOfParts[8], &c.noOfParts[9], &c.noOfParts[10], &c.noOfParts[11], &c.noOfParts[12]);
    --c.noOfParts[m.casing - 'A'];
    if ((c.noOfParts[m.casing - 'A'] <= 2) && (c.noOfParts[m.casing - 'A'] >= 0))
        printf("\nCasing %c needs to be restocked soon\n", m.casing);
    if (c.noOfParts[m.casing - 'A'] < 0)
    {
        printf("\nCasing %c out of stock\n", m.casing);
        return false;
    }
    fclose(file);

    return true;
}
void emptyStock()
{
    printf("\nSUPPLIER CONTACT: 0832 1080 240\tsupplier@titan.ac.in\nEnterd Part Number Not In Stock\n");
    return;
}

bool stockCheck()//simple function to ckeck stock
{
    bool b = true;
    int c = 0,ct =0;
    while ((c != 9)&&(ct<4) )
    {
        printf("enter replacement part :1>Gears 2>Strap 3>Casing 4>Battery 9>exit\t");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            b *= gearsStock();

            if (!b)
            {
                emptyStock();
                ct++;
                break;
            }
            k[1]++;
            ct++;
            break;

        case 2:
            b *= strapStock();

            if (!b)
            {
                emptyStock();
                ct++;
                break;
            }
            k[2]++;
            ct++;
            break;

        case 3:
            b *= casingStock();

            if (!b)
            {
                emptyStock();
                ct++;
                break;
            }
            k[3]++;
            ct++;
            break;

        case 4:
            b *= batteryStock();

            if (!b)
            {
                emptyStock();
                ct++;
                break;
            }
            k[0]++;
            ct++;
            break;

        case 9:
            printf("\n........\n");
            break;
        default:
            printf("\nERROR IN CHOICE\n");
            break;
        }
    }
    return k;
}

// wirting back to file
void writingBackGearstock()
{
    FILE *file1;
    fopen_s(&file1, "gearStock.json", "w+");
    if (file1 == NULL)
        return 1;

    fprintf_s(file1, OUT_FORMAT1, g.noOfParts[0], g.noOfParts[1], g.noOfParts[2], g.noOfParts[3], g.noOfParts[4]);
    fclose(file1);
}
void writingBackBatteryStock()
{
    FILE *file2;

    fopen_s(&file2, "batteryStock.json", "w+");
    if (file2 == NULL)
        return 1;
    fprintf_s(file2, OUT_FORMAT1, b.noOfParts[0], b.noOfParts[1], b.noOfParts[2], b.noOfParts[3], b.noOfParts[4]);
    fclose(file2);
}
void writingBackStrapStock()
{
    FILE *file3;
    fopen_s(&file3, "strapStock.json", "w+");
    if (file3 == NULL)
        return 1;
    fprintf_s(file3, OUT_FORMAT2, s.noOfParts[0], s.noOfParts[1], s.noOfParts[2], s.noOfParts[3], s.noOfParts[4], s.noOfParts[5], s.noOfParts[6], s.noOfParts[7], s.noOfParts[8], s.noOfParts[9], s.noOfParts[10], s.noOfParts[11]);
    fclose(file3);
}
void writingBackCaseStock()
{
    FILE *file4;
    fopen_s(&file4, "casingStock.json", "w+");
    if (file4 == NULL)
        return 1;
    fprintf_s(file4, OUT_FORMAT2, c.noOfParts[0], c.noOfParts[1], c.noOfParts[2], c.noOfParts[3], c.noOfParts[4], c.noOfParts[5], c.noOfParts[6], c.noOfParts[7], c.noOfParts[8], c.noOfParts[9], c.noOfParts[10], c.noOfParts[11]);
    fclose(file4);
}
void writingBackSchedule()
{
    FILE *file;
    file = fopen("schedule.bin", "wb");
    if (file == NULL)
    {
        printf("ERROR OPENING FILE\n");
    }
    fwrite(schedule, sizeof(schedule), 1, file);
    fclose(file);

    FILE *file4;
    fopen_s(&file4, "casingStock.json", "w+");
    if (file4 == NULL)
        return 1;
    fprintf_s(file4, OUT_FORMAT2, c.noOfParts[0], c.noOfParts[1], c.noOfParts[2], c.noOfParts[3], c.noOfParts[4], c.noOfParts[5], c.noOfParts[6], c.noOfParts[7], c.noOfParts[8], c.noOfParts[9], c.noOfParts[10], c.noOfParts[11]);
    fclose(file4);
    return;
}

void productReady()
{ /// hv to write product READY and create files
    date today;
    // int day;
    printf("\nenter todays date strictly in 'dd/mm/yyyy' format\t");
    scanf("%d/%d/%d", &today.d, &today.m, &today.y);
    // printf("\nenter todays weekday: sun=0,mon=1,tue=2,wed=3,thu=4,fri=5,sat=6\n");
    // scanf("%d",&day);

    int index;
    index = Difference(today, created); // number of days since creation
    FILE *file;
    file = fopen("schedule.bin", "rb");
    if (file == NULL)
    {
        printf("ERROR OPENING schedule.bin\n");
    }
    fread(schedule, sizeof(schedule), 1, file);
    fclose(file);
    int off = 0;
    printf("\nenter total off hours (in hours only): ");
    scanf("%d", &off);
    off *= 60;
    int q = 0; // counts number of days till repair

    for (int i = index; i < VALIDITY; i++)
    {
        int s = 0; // checks if days are not skipped when there's time to do less time consuming repair
        if (k[0] == 1)
        {

            if (schedule[i] > 15)
            {
                schedule[i] -= 15;
                k[0] = 0;
                writingBackBatteryStock();
            }
            else
            {
                i++;
                q++;
                if (schedule[i] > 15)
                {
                    schedule[i] -= 15;
                    k[0] = 0;
                    writingBackBatteryStock();
                }
                if (schedule[i] > 5)
                {
                    i--;
                    s = 1;
                }
            }
        }
        if (k[1] == 1)
        {
            if (schedule[i] > 15)
            {
                schedule[i] -= 15;
                k[1] = 0;
                writingBackGearstock();
            }
            else
            {
                i++;
                q++;
                if (schedule[i] > 15)
                {
                    schedule[i] -= 15;
                    k[1] = 0;
                    writingBackGearstock();
                }
                if (schedule[i] > 5)
                {
                    i--;
                    s = 1;
                }
            }
        }

        if (k[2] == 1)
        {
            if (schedule[i] > 5)
            {
                schedule[i] -= 5;
                k[2] = 0;
                writingBackStrapStock();
            }
            else
            {
                i++;
                if (!s)
                    q++;
                if (schedule[i] > 5)
                {
                    schedule[i] -= 5;
                    k[2] = 0;
                    writingBackStrapStock();
                }
            }
        }
        if (k[3] == 1)
        {
            if (schedule[i] > 5)
            {
                schedule[i] -= 5;
                k[3] = 0;
                writingBackCaseStock();
            }
            else
            {
                i++;
                if (!s)
                    q++;
                if (schedule[i] > 5)
                {
                    schedule[i] -= 5;
                    k[3] = 0;
                    writingBackCaseStock();
                }
            }
        }
        if ((schedule[i] > off) && (off > 0)) // if the mechanic is taking an off day, it should be reflected in the delivery date
        {
            schedule[i] -= off;
            off = 0;
            writingBackSchedule();
        }
        else if (off > 0)
        {

            if (schedule[i] > off)
            {
                schedule[i] -= off;
                off = 0;
                writingBackSchedule();
            }
        }
    }
    int workingdays = q;
    finaldate = Add_days(today, workingdays);
    printf("\nExpected date of repair:\t %d/%d/%d\n", finaldate.d, finaldate.m, finaldate.y);
}

int main()
{
    productEntry();
    stockCheck();
    productReady();
    return 0;
}