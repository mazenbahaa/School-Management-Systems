#ifndef _STUDENTLIST_H
#define _STUDENTLIST_H

#define CLASS_CAPACITY 15
#define DATE_BIRTH 10

// User Define Data Types

typedef struct StudentData
{
    u32 StudentId[CLASS_CAPACITY];
    u8 StudentName[CLASS_CAPACITY];
    u32 DateOfBirth[DATE_BIRTH];
    //u32 Day, Month, Year;
    u8 StudentAddress[CLASS_CAPACITY];
    u32 StudentNumber[CLASS_CAPACITY];
    u32 StudentScores[CLASS_CAPACITY];
}Students;

typedef struct myNode
{
    struct StudentData *Data;
    struct myNode *pNext;
    struct myNode *pPrev;
}ListNode;

typedef struct myList
{
    struct myNode *pHead;
    struct myNode *pTail;
    u32 LinkedListSize;
}List;

typedef enum myState
{
    FALSE,
    TRUE
}LinkedListState;

// Non Static Functions Prototypes
LinkedListState Create_List(List *pl);
LinkedListState New_Student(List *pl, Students.StudentId StudentId, Students.StudentName StudentName, Students.DateOfBirth DateOfBirth, Students.StudentAddress StudentAddress, Students.StudentNumber StudentNumber);
LinkedListState Search_Student(List *pl, Students.StudentId StudentId, ListNode **ppn);
LinkedListState Delete_Student(List *pl, Students.StudentId StudentId);
LinkedListState Student_List(List *pl);
LinkedListState Student_Edit(List *pl, Students.StudentId StudentId);

// Non Static Function Prototypes (Scores Section)
LinkedListState Rank_Scores (List *pl);
LinkedListState Update_Score (List *pl, Students.StudentScores StudentScore, Students.StudentScores NewStudentScore);

#endif // _STUDENTLIST_H
