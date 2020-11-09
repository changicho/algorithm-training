# 1406. 에디터

[링크](https://www.acmicpc.net/problem/1406)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   26.981    |

## 설계

### 시간 복잡도

문자열의 최대 길이는 100,000 까지이다.

명령어의 최대 길이는 500,000 까지이다.

list 구조를 사용하지 않는 경우 직접 구현했을 때 최악의 경우 시간 복잡도는

500,000,000,000 이므로 제한시간 0.3초 내에 불가능하다.

따라서 list 형을 이용한다.

### 공간 복잡도

list형에 들어갈 정보는 char 형식이다.

### list

C++의 list는 딱 더블 링크드리스트(doubly linked list)와 구조가 같다.

따라서 index로 접근이 불가능하다.

pointer를 이용해 접근할 수 있다.

이 때, erase 연산 이후에는 pointer를 반환함에 유의한다.

```cpp
for (int i = 0; i < N; i++) {
  cin >> command;

  switch (command) {
    case 'L': {
      if (cursor != editor.begin()) {
        cursor--;
      }
      break;
    }
    case 'D': {
      if (cursor != editor.end()) {
        cursor++;
      }
      break;
    }
    case 'B': {
      if (cursor != editor.begin()) {
        cursor--;
        cursor = editor.erase(cursor);
      }
      break;
    }
    case 'P': {
      cin >> temp;

      editor.insert(cursor, temp);
      break;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      68      |       8        |

## 고생한 점
