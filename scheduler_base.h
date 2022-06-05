#ifndef SCHEDULER_BASE_H_
#define SCHEDULER_BASE_H_

#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 32

typedef struct{
    int state;                //0:running state 1:ready state 2:waiting state
    int arrival;              //到着時刻
    int start;                //処理開始時刻　途中でいれる
    int end;                  //処理終了時刻　最後に入れる
    int response;             //応答時間　最後に入れる
    int processing;           //処理に必要な時間
    int processed;            //現状処理し終わった時間
    char name[NAME_LENGTH];   //プロセス名
} TASK;

void sortTaskByArrival(TASK *task, int task_num);
void initTasks(TASK *task_array,int task_num);
void fcfs(TASK *task, int task_num);
void sptf(TASK *task, int task_num);
void roundRobin(TASK *task, int task_num);

#endif /* SCHEDULER_BASE_H_ */