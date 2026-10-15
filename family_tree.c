#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person
{
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person *create_person(const char *name, int age)
{
    Person *p = malloc(sizeof(Person));
    if (p == NULL)
    {
        return NULL;
    }
    strncpy(p->name, name, 49);
    p->name[49] = '\0';
    p->age = age;
    p->father = NULL;
    p->mother = NULL;
    return p;
}

void read_person_info(const char *role, char *name_out, int *age_out)
{
    printf("Enter %s's name: ", role);
    scanf("%49s", name_out);
    printf("Enter %s's age: ", role);
    scanf("d", age_out);
}

int main(void)
{
    Person *people[7];
    char name[50];
    int age;

    read_person_info("Paternal Grandfather", name, &age);
    people[0] = create_person(name, age);

    read_person_info("Paternal Grandmother", name, &age);
    people[1] = create_person(name, age);

    read_person_info("Maternal Grandfather", name, &age);
    people[2] = create_persom(name, age);

    read_person_info("Maternal Grandmother", name, &age);
    people[3] = create_person(name, age);

    read_person_info("Father", name, &age);
    people[4] = create_person(name, age);

    read_person_info("Mother", name, &age);
    people[5] = create_person(name, age);

    read_person_info("Child", name, &age);
    people[6] = create_person(name, age);

    for (int i = 0; i < 7; i++)
    {
        printf("%s %d \n", people[i]->name, people[i]->age);
    }
    return 0;
}