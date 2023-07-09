#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include "Config.h"
#include "Student_List.h"

// Static Function Prototype
static LinkedListState ListEmpty(List *pl);


// Function Implemented
LinkedListState Create_List(List *pl)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        pl->pHead = NULL;
        pl->pTail = NULL;
        pl->LinkedListSize = 0;
        List_State = TRUE;
    }
    return List_State;
}

LinkedListState New_Student(List *pl, Students.StudentId StudentId, Students.StudentName StudentName, Students.DateOfBirth DateOfBirth, Students.StudentAddress StudentAddress, Students.StudentNumber StudentNumber)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        ListNode *pn = (ListNode *)malloc(sizeof(ListNode));
        if(pn == NULL)
        {
            printf("Memory is Full \n");
            List_State = FALSE;
        }
        else
        {
            pn->Data = StudentId;
            pn->Data = StudentName;
            pn->Data = DateOfBirth;
            pn->Data = StudentAddress;
            pn->Data = StudentNumber;
            pn->pNext = NULL;
            pn->pPrev = NULL;

            pl->LinkedListSize++;

            if(ListEmpty(pl))
            {
                pl->pHead = pl->pTail = pn;
            }
            else
            {
                ListNode *Temp = pl->pHead;

                while(Temp != NULL && Temp->Data.StudentId < StudentId)
                {
                    Temp = Temp->pNext;
                }
                if(Temp == NULL)
                {
                    pl->pTail->pNext = pn;
                    pn->pPrev = pl->pTail;
                    pl->pTail = pn;
                }
                else if(Temp == pl->pHead)
                {
                    pl->pHead->pPrev = pn;
                    pn->pPrev = pl->pHead;
                    pl->pHead = pn;
                }
                else
                {
                    Temp->pPrev->pNext = pn;
                    pn->pNext = Temp;
                    pn->pPrev = Temp->pPrev;
                    Temp->pPrev = pn;
                }
            }
            List_State = TRUE;
            #if(ENABLE_DEBUGGING == ENABLE)
                printf("%ld %s %ld %s %ld Is Inserted in List\n", StudentId, StudentName, DateOfBirth, StudentAddress, StudentNumber);
            #endif
        }
    }
    return List_State;
}

LinkedListState Search_Student(List *pl, Students StudentId, ListNode **ppn)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        ListNode * Temp = pl->pHead;
        while(Temp != NULL && Temp->Data.StudentId != StudentId)
        {
            Temp = Temp->pNext;
        }
        *ppn = Temp;
        LinkedListState TRUE;
    }
    return LinkedListState;
}

LinkedListState Delete_Student(List *pl, Students StudentId)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        if(ListEmpty(pl))
        {
            printf("List is Empty");
            List_State = FALSE;
        }
        else
        {
            ListNode *pn;
            Search_Student(pl, StudentId, pn);
            if(pn == NULL)
            {
                printf("%d Can not be Found\n", StudentId);
            }
            else
            {
                if(pl->pHead == pl->pTail)
                {
                    free(pl->pHead);
                    pl->pHead = pl->pTail = NULL;
                    pl->LinkedListSize = 0;
                }
                else if(pn == pl->pHead)
                {
                    pl->pHead = pn->pNext;
                    pl->pHead->pPrev = NULL;
                    free(pn);
                    pl->LinkedListSize CLASS_CAPACITY--;
                }
                else if(pn == pl->pTail)
                {
                    pl->pTail = pn->pPrev;
                    pl->pTail->pNext = NULL;
                    free(pn);
                    pl->LinkedListSize CLASS_CAPACITY--;
                }
                else
                {
                    pn->pNext->pPrev = pn->pPrev;
                    pn->pPrev->pNext = pn->pNext;
                    pl->LinkedListSize CLASS_CAPACITY--;
                    free(pn);
                }
                List_State = TRUE;
            }
        }
    }
    return List_State
}

LinkedListState Student_List(List *pl)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        if(ListEmpty(pl))
        {
            printf("No Student List Yet\n");
        }
        else
        {
            for(Temp = pl->pHead; Temp != NULL; Temp = Temp->pNext)
            {
                printf("Your Data = %l %s %l %s %l \n", Temp->Data)
            }
            List_State = TRUE;
        }
    }
    return List_State;
}

LinkedListState Student_Edit(List *pl, Students.StudentId StudentId, Students.StudentId NewStudentId)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        while(pl->pHead->pNext != NULL)
        {
            if(pl->pHead->Data.StudentId = StudentId)
            {
                pl->pHead->Data.StudentId = NewStudentId
                printf("%d Id Number Replaced with %d \n", StudentId, NewStudentId);
                pl->pHead = pl->pNext;
                pl->LinkedListSize++;
                List_State = TRUE;
            }
            else
            {
                printf("%d Id Number Not Found \n");
                List_State = FALSE;
            }
            return List_State;
        }
    }
    return List_State;
}


// Rank Score Function Section
LinkedListState Rank_Scores (List *pl)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        for(pl->pHead; pl->pHead->pNext != NULL; pl->pHead = pl->pHead->pNext)
        {
            for(pn = pl->pHead->pNext; pn != NULL; pn = pn->pHead->pNext)
            {
                if(pl->pHead->Data.StudentScores StudentScores > pn->pHead->Data.StduentScores StudentScores)
                {
                    Temp = pl->pHead->Data.StudentScores;
                    pl->pHead->Data.StudentScores = pn->pHead->Data.StduentScores;
                    pn->pHead->Data.StduentScores = Temp;

                    List_State = TRUE;
                }
            }
        }
        List_State = TRUE;
    }
    return List_State;
}

LinkedListState Update_Score (List *pl, Students.StudentScores StudentScore, Students.StudentScores NewStudentScore)
{
    LinkedListState List_State = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer\n");
        List_State = FALSE;
    }
    else
    {
        while(pl->pHead->pNext != NULL)
        {
            if(pl->pHead->Data.StudentScores = StudentScore)
            {
                pl->pHead->Data.StudentScores = NewStudentScore
                printf("%d Id Number Replaced with %d \n", StudentScores, NewStudentScores);
                pl->pHead = pl->pNext;
                pl->LinkedListSize++;
                List_State = TRUE;
            }
            else
            {
                printf("%d Id Number Not Found \n");
                List_State = FALSE;
            }
            return List_State;
        }
    }
    return List_State;
}

// Static Function
static LinkedListState ListEmpty(List *pl)
{
    LinkedListState Local_state = FALSE;
    if(pl == NULL)
    {
        printf("Null Pointer \n");
        Local_state = FALSE;
    }
    else
    {
        if(pl->pHead == NULL)
        {
            Local_state = TRUE;
        }
        else
        {
            Local_state = FALSE;
        }
    }
    return Local_state;
}
