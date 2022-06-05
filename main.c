#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "scheduler_base.h"
#include "macro.h"
void ptintResult(TASK *task ,int task_num);

int main(void){
    int mode, task_num, algorithm;
    
    //タスク数入力
    printf("Input the number of tasks:");
    scanf("%d",&task_num);
    //タスク用メモリ動的確保
    TASK *task = (TASK*)malloc(sizeof(TASK)*task_num);
    initTasks(task,task_num);
    printf("Select scheduler mode. (0: random , 1: manual)\n0/1: ");
    scanf("%d",&mode);
    if(mode == 0){
        for(int i=0; i<task_num; i++){
            char alphabet[] = {65+i,'\0'};
            strcpy(task[i].name,alphabet);
            srand((unsigned int)time(NULL)+i);
            task[i].arrival = rand()%30;
            task[i].processing=rand()%30;
        }
    }elif(mode == 1){
        printf("*manual mode*\n");
        printf("name | arrival_time | processing_time\nInput data:\n");
        for(int i=0; i<task_num; i++){
            scanf("%s %d %d",
                task[i].name, &task[i].arrival, &task[i].processing);
        }
    }
    //スケジューリングアルゴリズム
    printf("Select the scheduling algorithm.(0:到着順 1:処理時間順 2:ラウンドロビン)\n0-2: ");
    scanf("%d",&algorithm);
    switch(algorithm){
        case 0:
            printf("Algorithm: 到着順\n");
            fcfs(task, task_num);
            break;
        case 1:
            printf("Algorithm: 処理時間順\n");
            sptf(task, task_num);
            break;
        case 2:
            printf("Algorithm: ラウンドロビン\n");
            roundRobin(task, task_num);
            break;
        default:
            printf("An error occured.");
            break;
    }
    ptintResult(task, task_num);
    return 0;
}

void ptintResult(TASK *task, int task_num){
    printf("\n\n**RESULT**\n");
    printf("| Task_Name | Arrival_Time | Processing_Time | Finish_Time | Response_time |\n");
    int sum=0;
    for(int i=0; i<task_num; i++){
        printf("|% 11s|% 14d|% 17d|% 13d|% 15d|\n",task[i].name,task[i].arrival,task[i].processing,task[i].end,task[i].response);
        sum += task[i].response;
    }
    printf("\nAverage_Process_Time: %g\n" , (double)(sum)/task_num);
}