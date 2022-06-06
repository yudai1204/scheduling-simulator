#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "scheduler_base.h"

void sortTaskByArrival(TASK *task, int task_num)
{
    int i, j;
    TASK temp;
    for (i = 0; i < (task_num - 1); i++)
    {
        for (j = (task_num - 1); j > i; j--)
        {
            if (task[j - 1].arrival > task[j].arrival)
            {
                temp = task[j - 1];
                task[j - 1] = task[j];
                task[j] = temp;
            }
        }
    }
    return;
}
void initTasks(TASK *task_array,int task_num){
    for(int i=0; i<task_num; i++){
        task_array[i].state = 2;
        task_array[i].arrival =
        task_array[i].start =
        task_array[i].end =
        task_array[i].response = 
        task_array[i].processing = 
        task_array[i].processed = 0;
        strcpy( task_array[i].name, "undefined" );
    }
    return;
}