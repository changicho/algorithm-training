# Problem B: Alchemy

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/B)

| 난이도 |
| :----: |
| 15 pt  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

스택을 이용해 3개의 연속된 색을 폭팔하지 않도록 모두 합치며 계속 진행한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택에 O(N)의 공간 복잡도를 사용한다.

### 스택 & 그리디

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

왼쪽부터 차례로 순회하며 현재 색을 스택에 집어넣는다.

스택에서 top부터 연이은 3개의 색을 합칠 수 있는 경우 합친다.

이를 현재 스택에서 합치는것이 불가능할 때 까지 반복한다.

이를 이용해 모든 색을 순회했을 때 스택에 한개의 색만 남은 경우 압축이 가능한 경우이다.

```cpp
bool solution(int size, string stones) {
  string curStack = "";

  for (char &c : stones) {
    curStack.push_back(c);

    while (curStack.length() >= 3) {
      map<char, int> counts;
      for (int i = 0; i < 3; i++) {
        counts[curStack[curStack.length() - 1 - i]]++;
      }

      if (counts.size() <= 1) break;
      char next = 'A';
      if (counts['B'] == 2) {
        next = 'B';
      }

      for (int i = 0; i < 3; i++) {
        curStack.pop_back();
      }
      curStack.push_back(next);
    }
  }

  return curStack.length() == 1;
}
```

## 고생한 점
