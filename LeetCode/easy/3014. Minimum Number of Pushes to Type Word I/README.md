# 3014. Minimum Number of Pushes to Type Word I

[링크](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자. N은 최대 26이며 중복되지 않은 알파벳으로 구성되어있다.

알파벳의 수를 센 뒤 탐욕알고리즘을 이용해 배치할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도를 사용한다.

### 그리디 (탐욕 알고리즘)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

알파벳을 8개의 버튼에 배치해야한다.

버튼에 골고루 배치하는편이 유리하며 하나의 버튼에 알파벳이 여러개 있을 경우 여러번 눌러야한다.

이를 이용해 8개의 버튼에 순서대로 배치하며 누르는 횟수를 정답에 더한다.

```cpp
int minimumPushes(string word) {
  int size = word.size();

  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer += (i / 8 + 1);
  }
  return answer;
}
```

## 고생한 점
