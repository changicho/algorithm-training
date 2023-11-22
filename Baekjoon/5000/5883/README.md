# 아이폰 9S

[링크](https://www.acmicpc.net/problem/5883)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| 실버 IV |   41.667%   |       1       |

## 설계

### 시간 복잡도

입력받은 배열 A의 길이를 N이라 하자.

연속 구간의 길이를 구하는 데 O(N)의 시간 복잡도를 사용한다.

여기서 무시할 수를 정하고 이를 제외한 연속 구간의 길이를 구한다.

이에 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열에 O(N)의 공간 복잡도를 사용한다.

연속 구간을 구하는 데 O(1)의 공간 복잡도를 사용한다.

## 완전 탐색

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |    O(N)     |

배열에서 건너뛸 숫자를 정하고, 이를 제외한 연속 구간의 길이를 구한다.

이를 배열의 모든 수에 대해 제외할 수로 설정하고 반복한다.

```cpp
int count(vector<int> &arr, int skip) {
  int ret = 0;
  int count = 0;
  int before = -1;
  for (int &num : arr) {
    if (num == skip) continue;

    if (num == before) {
      count++;
    } else {
      before = num;
      count = 1;
    }
    ret = max(ret, count);
  }
  ret = max(ret, count);

  return ret;
}

int solution(vector<int> &arr) {
  int size = arr.size();
  int answer = 0;

  for (int &num : arr) {
    answer = max(answer, count(arr, num));
  }

  return answer;
}
```

## 고생한 점
