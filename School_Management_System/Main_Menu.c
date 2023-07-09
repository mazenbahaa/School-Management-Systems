#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include "Config.h"
#include "Main_Menu.h"
#include "Student_List.h"

void Main_Menu()
{
    List L;
    StudentList Choice;
    Students Id, Name, DateOfBirth, Address, PhoneNumber;
    Create_List(&L);

    do
    {
        printf("Enter Your Choice Between These Option \n");
        printf("1-Insert Student\t 2-Delete Student\t 3-View Student\t 4-Edit Student\t 5-Rank Score\t 6-Update Score\t 7-Exit \n");
        printf("Your Choice:");
        scanf("%d", &Choice);

        switch(Choice)
        {
        case INSERT_STUDENT:
            {
                printf("Enter Student Data\n");
                printf("Enter Student ID\t Enter Student Name\t Enter DayOfBirth\t Enter Student Address\t Enter Student PhoneNumber \n");
                scanf("%ld %s %ld %s %ld", &Id, &Name, &DateOfBirth, &Address, &PhoneNumber);
                New_Student(&L, Id, Name, DateOfBirth, Address, PhoneNumber);
            }
            break;
        case DELETE_STUDENT:
            printf("I'm in Delete\n");
            break;
        case VIEW_STUDENT:
            printf("I'm in View\n");
            break;
        case EDIT_STUDENT:
            printf("I'm in Edit\n");
            break;
        case RANK_SCORE:
            printf("I'm in Rank Score\n");
            break;
        case UPDATE_SCORE:
            printf("I'm in Update\n");
            break;
        case EXIT:
            printf("I'm in Exit\n");
            break;
        default:
            printf("Wrong Choice\n");
        }
    }while(Choice != EXIT);

}

