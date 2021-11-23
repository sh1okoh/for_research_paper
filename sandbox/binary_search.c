#include <stdio.h>

// cf: https://dev.grapecity.co.jp/support/powernews/column/clang/054/page03.htm
int main() {
  // NOTE: データを昇順にする
  int dataset[] = { 1, 3, 5, 8, 12, 16, 19, 24, 26, 31, 35 };
  int lowid, midid, highid;
  int target = 24;

  // NOTE: 添字の最大値と最小値を初期化
  highid = 10;
  lowid = 0;
  int midValue;

  // NOTE: 最小値を示すlowidの値が、最大値を示すhighidの値以下である間
  while (lowid <= highid) {
    midid = (lowid + highid) / 2;
    midValue = dataset[midid];
    if (midValue == target) {
      printf("Found!");
      break;
    } else if (midValue < target) {
      lowid = midid + 1;
    } else {
      highid = midid - 1;
    }
  }
}