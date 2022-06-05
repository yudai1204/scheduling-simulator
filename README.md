# scheduling-simulator
スケジューリングプロセスを処理していくデモプログラム
アルゴリズム、プロセスの個数、それぞれのプロセスの到着時刻、処理時間、定時間を入力して実行できます
ランダム設定も可能です
## 使用方法
1. `main.c`, `macro.c`, `algorithm.c`を1つのファイルにコンパイルしてください。このとき、コード内の日本語が文字化けすると思うので、`-fexec-charset=CP932`を指定してください。<br>
  例:`gcc main.c macro.c algorithm.c -fexec-charset=CP932 -o scheduler`<br>
1. 実行してください。
1. 最初に、処理するプロセスの個数を入力してください。
1. 次に、randomモード(到着時刻、処理時間がランダム)か、manualモード(手動で入力)か選択してください。
1. randomモードの場合はスキップしてください。manualモードの場合はすべてのプロセスの情報を入力してください。<br>
    プロセスの名前、到着時刻、処理時間をスペース区切りで入力します。
1. アルゴリズムを選択してください。選べるのは、0:到着順 1:処理時間順 2:ラウンドロビンの3種類です。
1. ラウンドロビンの場合は定時間を入力してください
1. 実行結果が出力されます<br><br>

### 実行例
```
    Input the number of tasks:4
    Select scheduler mode. (0: random , 1: manual)
    0/1: 1
    *manual mode*
    name | arrival_time | processing_time
    Input data:
    A 0 2
    B 1 10
    C 3 7
    D 5 3
    Select the scheduling algorithm.(0:到着順 1:処理時間順 2:ラウンドロビン)
    0-2: 2
    Algorithm: ラウンドロビン
    Input step_num: 2
    START:
      1s| Task:A
      2s| Task:A has now finished.
      3s| Task:B
      4s| Task:B
      5s| Task:C
      6s| Task:C
      7s| Task:B
      8s| Task:B
      9s| Task:D
     10s| Task:D
     11s| Task:C
     12s| Task:C
     13s| Task:B
     14s| Task:B
     15s| Task:D has now finished.
     16s| Task:C
     17s| Task:C
     18s| Task:B
     19s| Task:B
     20s| Task:C has now finished.
     21s| Task:B
     22s| Task:B has now finished.
    END


    **RESULT**
    | Task_Name | Arrival_Time | Processing_Time | Finish_Time | Response_time |
    |          A|             0|                2|            2|              2|
    |          B|             1|               10|           22|             21|
    |          C|             3|                7|           20|             17|
    |          D|             5|                3|           15|             10|

    Average_Process_Time: 12.5
```
