# 1128. Number of Equivalent Domino Pairs

[링크](https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열 dominoes의 크기를 N, 도미노의 종류를 M이라 하자.

각 도미노를 순회하며 종류별로 count 할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

이후 종류별로 순회하며 정답에 더한다. 이에 총 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

종류별로 저장할 공간이 필요하며 이에 O(M)의 공간 복잡도를 사용한다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(M)     |

도미노를 회전시킬 수 있으므로 (a, b) 와 (b, a)는 같은 도미노다.

따라서 앞자리에 작은 숫자를 두고 뒤에 큰 숫자를 두는 방법으로 도미노를 정렬한다.

각 도미노의 수를 세고, 각 도미노의 수 마다 쌍의 갯수를 구해 정답에 더한다.

```cpp
int convert(vector<int> &d) {
  int first = min(d[0], d[1]);
  int second = max(d[0], d[1]);

  return first * 10 + second;
}

int numEquivDominoPairs(vector<vector<int>> &dominoes) {
  int count[100] = {
      0,
  };

  for (vector<int> &d : dominoes) {
    int key = convert(d);

    count[key]++;
  }

  int answer = 0;
  for (int &val : count) {
    answer += (val) * (val - 1) / 2;
  }
  return answer;
}
```

## 고생한 점
