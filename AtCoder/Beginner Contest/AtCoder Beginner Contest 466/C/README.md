# C - Count Close Pairs

[링크](https://atcoder.jp/contests/abc466/tasks/abc466_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

점의 갯수를 N이라 하자.

투 포인터를 이용해 현재 구간의 제일 왼쪽 점과 제일 오른쪽 점 사이 거리가 최대 1인지 검사한다.

이후 구간을 이동시켜가며 갱신하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

투 포인터에 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

가장 왼쪽 범위부터 투 포인터를 사용해 가장 오른쪽 점까지 최대 거리가 1인 구간을 매번 갱신해나간다.

이 때 현재 right가 가능할 경우 현재 right를 포함하는 새로운 쌍들의 갯수를 정답에 더한다.

```cpp
long long solution(int n) {
  long long answer = 0;

  int left = 1, right = 2;

  while (right <= n) {
    string ret;

    cout << "? " << left << " " << right << endl;
    cout.flush();

    cin >> ret;

    if (ret == "Yes") {
      long long cur = right - left;
      answer += cur;

      right++;
    } else {
      left++;
      if (left == right) {
        right++;
      }
    }
  }

  return answer;
}
```

## 고생한 점
