# 12981. 영어 끝말잇기

[링크](https://programmers.co.kr/learn/courses/30/lessons/12981)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   3005    |

## 설계

### 시간 복잡도

단어의 개수는 최대 100 까지이다.

단어를 순회하며 비교하면 되므로 시간 복잡도는 O(N)

### 공간 복잡도

이전 단어의 끝자리가 필요하므로 char 문자 공간을 선언한다.

### 순회

```cpp
for (string word : words) {
  if (word.front() != before || s.find(word) != s.end()) {
    answer[0] = index % n + 1;
    answer[1] = index / n + 1;

    break;
  }

  s.insert(word);
  before = word.back();
  index += 1;
}
```

## 고생한 점
