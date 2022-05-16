# 2269. Find the K-Beauty of a Number

[링크](https://leetcode.com/problems/find-the-k-beauty-of-a-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

num의 길이를 N, 주어진 수를 K라 하자.

num의 subStr중 길이가 K인 모든 경우를 탐색하고 정답으로 count한다.

이 경우 시간 복잡도는 O(N * K)이다.

### 공간 복잡도

매번 경우를 탐색할 때 길이 K의 문자열을 생성한다.

이는 각 과정마다 별개로 일어나므로 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N * K)   |    O(1)     |

num을 문자열로 변환한다.

각 index에서 시작하는 길이 K의 문자열을 추출하고 숫자로 변환한다.

이후 num을 해당 숫자로 나누었을때 나누어 떨어지는지를 확인한다.

이를 구현하면 다음과 같다.

```cpp
int divisorSubstrings(int num, int k) {
  string numStr = to_string(num);

  int count = 0;
  int length = numStr.length();
  for (int i = 0; i <= length - k; i++) {
    string cur = numStr.substr(i, k);

    int curNum = stoi(cur);
    if (curNum == 0) continue;
    if (num % curNum == 0) count++;
  }
  return count;
}
```

## 고생한 점
