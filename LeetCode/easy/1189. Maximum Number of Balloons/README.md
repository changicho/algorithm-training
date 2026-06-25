# 1189. Maximum Number of Balloons

[링크](https://leetcode.com/problems/maximum-number-of-balloons/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 알파벳을 카운트 후 balloon을 만들 수 있는 갯수를 세는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

알파벳 카운트에 O(1)의 공간 복잡도를 사용한다.

### 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

알파벳의 갯수를 센 뒤 타겟 문자열을 몇개 만들 수 있는지 검사한다.

```cpp
int maxNumberOfBalloons(string text) {
  int count[26] = {
      0,
  };
  for (char& c : text) {
    count[c - 'a']++;
  }

  string target = "balloon";
  int answer = 0;
  while (true) {
    bool flag = true;
    for (char& c : target) {
      count[c - 'a']--;

      if (count[c - 'a'] < 0) {
        flag = false;
        break;
      }
    }

    if (flag) {
      answer++;
    } else {
      break;
    }
  }
  return answer;
}
```

## 고생한 점
