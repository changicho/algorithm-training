# 1339. 단어 수학

[링크](https://www.acmicpc.net/problem/1339)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   41.690    |

## 설계

### 시간 복잡도

완전 탐색을 수행하는 경우 9! 만큼의 시간복잡도가 소요된다. 이는 제한시간 2초 내에 불가능하다.

따라서 greedy한 방법으로 풀이한다.

각 알파벳별로 자리수를 고려해 count를 해준 뒤 count의 내림차순으로 정렬하는 경우

앞자리 부터 높은 수를 배정할 때 만들 수 있는 가장 큰 수가 된다.

### 공간 복잡도

단어의 최대 길이는 8개이며 단어의 최대 갯수는 10개이다.

10^9 까지 count가 가능하며 이는 int형으로 충분하다.

### 그리디 알고리즘

입력받는 알파벳을 자리수를 고려해 count해준다.

예를 들어 ABC의 경우 100A + 10B + C 로 나타낼 수 있다.

입력받은 모든 단어를 다음과 같이 치환 후에 알파벳 count 순으로 정렬한다.

count가 큰 알파벳에 큰 수를 배당할 때 가장 큰 수를 만들 수 있다.

```cpp
for (int i = 0; i < N; i++) {
  cin >> line;
  reverse(line.begin(), line.end());
  int digit = 1;
  for (char c : line) {
    alpha_count[c] += digit;
    digit *= 10;
  }
}

sort(alpha_count, alpha_count + 'Z' + 1, greater<int>());

int digit = 9;
for (int count : alpha_count) {
  answer += count * digit;
  digit--;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
