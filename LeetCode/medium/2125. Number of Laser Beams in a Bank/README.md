# 2125. Number of Laser Beams in a Bank

[링크](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C라고 하자.

모든 행과 열을 한번씩 순회해야 하므로 시간 복잡도는 O(R \* C)이다.

이후 각 행마다 빔을 쏘는 보안 기계가 있는 수를 센다.

이후 인접한 수의 곱을 구해 정답에 더하고 이는 O(R)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

보안 기계의 수를 저장할 O(R)의 공간이 필요하다.

### 인접 곱

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |  O(R \* C)  |    O(R)     |

각 행마다의 보안 기계의 수를 센다.

이 때 0인 경우는 무시하며 1 이상인 경우만 벡터에 삽입한다.

이후 보안 기계가 있는 두 행에서 레이저가 나올 수 있는 갯수는 이전 행의 수와 현재 행의 수가 된다.

따라서 인접한 두 수끼리 보안 기계의 수의 곱을 정답에 더한다.

이 때 보안 기계가 없거나, 행이 1개인 경우는 정답이 0임에 유의한다.

```cpp
int getCount(string &str) {
  int count = 0;
  for (char &c : str) {
    if (c == '1') count++;
  }
  return count;
}

int numberOfBeams(vector<string> &bank) {
  vector<int> beams;

  for (string &b : bank) {
    int count = getCount(b);

    if (count > 0) beams.push_back(count);
  }

  int size = beams.size();

  int answer = 0;
  for (int i = 0; i < size - 1; i++) {
    answer += beams[i] * beams[i + 1];
  }
  return answer;
}
```

## 고생한 점

다음과 같은 경우 for루프가 실행되 에러가 발생한다.

```cpp
// beams.size() == 0 case
for (int i = 0; i < beams.size() - 1; i++) {
  answer += beams[i] * beams[i + 1];
}
```
