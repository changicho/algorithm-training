# 1358. Number of Substrings Containing All Three Characters

[링크](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

슬라이딩 윈도우를 이용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 각 알파벳의 갯수를 저장하는데 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(1)     |

슬라이딩 윈도우를 사용해 현재 알파벳을 왼쪽부터 오른쪽으로 탐색하며 윈도우에 3개의 알파벳이 모두 존재하는 경우를 탐색한다.

현재 알파벳을 증가시키며 만약 현재 윈도우에 3개의 알파벳이 모두 존재하는 경우, 현재 윈도우를 포함하는 경우의 수 중 오른쪽으로 확장하는 경우를 모두 더한다.

이후 왼쪽을 한칸 옮기고 위 조건을 만족하는 경우 이를 반복한다.

```cpp
int numberOfSubstrings(string s) {
  int size = s.size();

  int count[3] = {
      0,
  };

  function<bool()> check = [&]() {
    return count[0] > 0 && count[1] > 0 && count[2] > 0;
  };

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    char c = s[right];
    count[c - 'a']++;

    while (check()) {
      answer += size - right;

      char leftChar = s[left];
      count[leftChar - 'a']--;
      left++;
    }
  }

  return answer;
}
```

## 고생한 점
