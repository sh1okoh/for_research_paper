#include <stdio.h>

//NOTE: 1: CPU時間 0: 遊休時間
int cpuBurst[][16] = {
  {1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0},
  {1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
};

int main(void) {
  int cpuProc[30]; int cpuCount[2] = {0, 0}; int tCount = 0; int Exe=-1;
  while(cpuCount[0] < 16 || cpuCount[1] < 16) {
    // NOTE: 前時刻実行 job が 遊休時間に入ったら実行 job なしとする
    if (Exe >= 0) { 
      if (cpuBurst[Exe][cpuCount[Exe]] == 0) Exe=-1;
    }
    if (Exe < 0) {
      for(int i=0; i<2; i++) { // NOTE: 実行中jobがなければ割り当て
        if(cpuCount[i] < 16 && cpuBurst[i][cpuCount[i]] != 0) {
          Exe=i; break;
        }
      }
    } //NOTE: 遊休時間のjobと実行中Jobの時間カウント 
    for(int i=0; i<2;i++) {
      if(cpuBurst[i][cpuCount[i]]==0) cpuCount[i]++;
      else if (i==Exe) cpuCount[i]++;
    }
    cpuProc[tCount++]=Exe;

    printf("\n\n ** CPUT Burst\n");
    for(int j=1;j<=15; j++) printf("%2d", j%10);
    for(int i=0;i<2;i++) {
      printf("\n Job %C : ", 'A' + i);
      for(int j=0; j<15; j++) {
        if(cpuBurst[i][j]!=0) printf("=?"); else printf("...C");
      }
    }
    printf("\n\n Time Chatrt \n @   @");
    for(int j=1; j<=(tCount-2); j++) printf("%2d", j%10);
    for(int i=0; i<2; i++) {
      printf(" Job %C : ", 'A' + i);
      for(int j=0; j<tCount-2; j++) {
        if(cpuProc[j]==i) printf("=?"); else printf("...c");
      }
    }
  }
  return 0;
}