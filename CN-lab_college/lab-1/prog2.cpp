#include <stdio.h>
#include <string.h>

struct info
{
    int roll_no;
    char name[50];
    float CGPA;
};

void func(struct info *record);

int main()
{
    struct info record;

    record.roll_no = 1;
    strcpy(record.name, "Naman");
    record.CGPA = 8.65;

    func(&record);
    return 0;
}

void func(struct info *record)
{
    printf(" Roll is: %d \n", record->roll_no);
    printf(" Name is: %s \n", record->name);
    printf(" Percentage is: %f \n", record->CGPA);
}
