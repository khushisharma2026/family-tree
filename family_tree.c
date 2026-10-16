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
    scanf("%d", age_out);
}

void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me)
{
    printf("####### FAMILY TREE RELATIONSHIPS #######\n");

    printf("1. ME: \n");
    printf("Name: %s  Age: %d\n", me->name, me->age);

    printf("2. PARENTS: \n");
    printf("Father name: %s  Age: %d \n", me->father->name, me->father->age);
    printf("Mother name: %s  Age: %d \n\n", me->mother->name, me->mother->age);

    printf("3. PATERNAL GRANDPARENTS: \n");
    printf("P_Grandfather name: %s  Age: %d\n", me->father->father->name, me->father->father->age);
    printf("P_Grandmother name: %s  Age: %d\n\n", me->father->mother->name, me->father->mother->age);

    printf("4. MATERNAL GRANDPARENTS: \n");
    printf("M_Grandfather name: %s  Age: %d\n", me->mother->father->name, me->mother->father->age);
    printf("M_Grandmother name: %s  Age:%d \n\n", me->mother->mother->name, me->mother->mother->age);
}

void free_family_tree(Person *people[], int count)
{
    for (int i = 0; i < count; i++)
    {
        free(people[i]);
    }
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
    people[2] = create_person(name, age);

    read_person_info("Maternal Grandmother", name, &age);
    people[3] = create_person(name, age);

    read_person_info("Father", name, &age);
    people[4] = create_person(name, age);

    read_person_info("Mother", name, &age);
    people[5] = create_person(name, age);

    read_person_info("Child", name, &age);
    people[6] = create_person(name, age);

    link_parents(people[4], people[0], people[1]);
    link_parents(people[5], people[2], people[3]);
    link_parents(people[6], people[4], people[5]);

    print_family_relationships(people[6]);

    free_family_tree(people, 7);

    return 0;
}
