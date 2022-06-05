#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "scheduler_base.h"
#include "macro.h"

//到着順
void fcfs(TASK *task, int task_num){
    int current = 0;
    //到着順にソート
    sortTaskByArrival(task,task_num);
    printf("START:\n");
    for(int time=0; current<task_num; time++){
        //satate変更
        for(int i=0; i<task_num; i++){
            if(task[i].arrival == time){
                task[i].state = 1;
            }
        }
        //実行開始
        if( task[current].state == 1 ){
            task[current].start = time;
            task[current].state = 0;
        }
        //表示
        printf("% 3ds| Task:%s ", time+1 , (task[current].state == 2)?"Waiting":task[current].name );
        //実行終了
        if( task[current].state == 0 && task[current].start + task[current].processing <= time+1){
            task[current].end = time +1 ;
            task[current].response = time - task[current].arrival +1 ;
            task[current].state = -1;
            printf("has now finished.");
            current++;
        }
        printf("\n");
    }
    printf("END\n");
    return;
}

//処理時間順
void sptf(TASK *task, int task_num){
    int current = 0 , flag = false;
    //到着順にソート
    sortTaskByArrival(task,task_num);
    printf("START:\n");
    for(int time=0,count=0; count<task_num; time++){
        //satate変更
        for(int i=0; i<task_num; i++){
            if(task[i].arrival == time){
                task[i].state = 1;
            }
        }
        //実行開始
        if( task[current].state == 1 ){
            task[current].start = time;
            task[current].state = 0;
        }
        //表示
        printf("% 3ds| Task:%s ", time+1 , (task[current].state == 2)?"Waiting":task[current].name );
        //実行終了
        if( task[current].state == 0 && task[current].start + task[current].processing <= time+1){
            task[current].end = time +1 ;
            task[current].response = time - task[current].arrival +1 ;
            task[current].state = -1;
            printf("has now finished.");
            count++;
            flag = true;
        }
        //current決定
        if(flag){
            int min = INT_MAX;
            flag = false;
            for(int i=0; i<task_num && task[i].state != 2 ; i++){
                if(task[i].state == 1 && task[i].processing < min){
                    min = task[i].processing;
                    current = i;
                }
            }
        }
        printf("\n");
    }
    printf("END\n");
    return;
}

//ラウンドロビン
void roundRobin(TASK *task, int task_num){
    int step_num;
    //プロセスの順番を保存するキューを生成、初期化
    int *que = (int*)malloc(sizeof(int)*(task_num+1));
    for(int i=0; i<task_num+1; i++){
        que[i] = -1;
    }
    //定時間の入力
    printf("Input step_num: ");
    scanf("%d",&step_num);
    int current = 0 , flag = false;
    //到着順にソート
    sortTaskByArrival(task,task_num);
    printf("START:\n");
    for(int time=0, process_count=0, step_count=0; process_count < task_num; time++ , step_count++){
        //step_numにより分岐
        if(step_count >= step_num || flag == true){
            step_count = 0;
            flag = true;
        }
        //current決定
        if(flag){
            flag = false;
            for(int i=1; i<task_num+1; i++){
                if(que[i] == -1){
                    que[i] = que[0];
                    break;
                }
            }
            for(int i=0; i<task_num; i++){
                que[i] = que[i+1];
            }
            que[task_num] = -1;
            current = que[0];
        }
        //satate変更
        for(int i=0; i<task_num; i++){
            if(task[i].arrival == time){
                task[i].state = 1;
                for(int j=0; j<task_num;j++){
                    if(que[j] == -1){
                        que[j] = i;
                        break;
                    }
                }
            }
        }
        //実行開始
        if( task[current].state == 1 ){
            task[current].start = time;
            task[current].state = 0;
        }
        task[current].processed++;
        //表示
        printf("% 3ds| Task:%s ", time+1 , (task[current].state == 2)?"Waiting":task[current].name );
        //実行終了
        if( task[current].state == 0 && task[current].processed >= task[current].processing){
            task[current].end = time +1 ;
            task[current].response = time - task[current].arrival +1 ;
            task[current].state = -1;
            printf("has now finished.");
            process_count++;
            flag = true;
            que[0]=-1;
        }
        
        printf("\n");
    }
    printf("END\n");
    return;
}
