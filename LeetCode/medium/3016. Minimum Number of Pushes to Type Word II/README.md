# 3016. Minimum Number of Pushes to Type Word II

[링크](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

각 알파벳의 갯수를 센 뒤, 빈도가 높은 알파벳일수록 버튼을 적게 누르도록 한다.

이를 위해 각 알파벳의 위치를 찾아내야 하므로 시간 복잡도는 O(N)이다.

각 알파벳마다 빈도를 정렬하는 데 O(26 \* log_2(26)) 이므로 최종 시간 복잡도는 O(N) 이다.

### 공간 복잡도

알파벳의 빈도를 저장할 배열이 필요하다. 이 배열의 크기는 26이다.

따라서 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      63      |    O(N)     |    O(1)     |

각 알파벳 중 빈도가 높은 알파벳을 버튼을 적게 누르게 하는것이 유리하다.

따라서 각 알파벳의 빈도를 세고, 빈도가 높은 순으로 정렬한다.

이후 빈도가 높은 순으로 버튼에 할당한다.

이 때 버튼의 수는 8개 이므로 9개째 알파벳 부터는 버튼의 횟수가 증가한다.

따라서 버튼을 누르는 횟수를 계산해야 한다.

```cpp
int minimumPushes(string word) {
  int counts[26] = {
      0,
  };

  for (char &c : word) {
    counts[c - 'a']++;
  }
  sort(counts, counts + 26, greater<int>());

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    int press = 1 + i / 8;

    answer += counts[i] * press;
  }

  return answer;
}
```

## 고생한 점
