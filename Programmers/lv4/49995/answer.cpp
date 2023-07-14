#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer
// time : O(N^2)
// space : O(1)
int solution(vector<int> cookie) {
  int size = cookie.size();

  int answer = 0;
  for (int mid = 0; mid < size - 1; mid++) {
    int leftI = mid, rightI = mid + 1;
    int leftSum = cookie[leftI], rightSum = cookie[rightI];

    while (true) {
      if (leftSum == rightSum) {
        answer = max(answer, leftSum);
      }

      if (leftSum < rightSum) {
        leftI--;
        if (leftI < 0) break;
        leftSum += cookie[leftI];
      } else {
        rightI++;
        if (rightI >= size) break;
        rightSum += cookie[rightI];
      }
    }
  }

  return answer;
}