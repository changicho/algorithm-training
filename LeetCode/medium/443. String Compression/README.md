# 443. String Compression

[링크](https://leetcode.com/problems/string-compression/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 문자열을 한번 순회해야 한다. 이 연산에 O(N)이 소요된다.

counting을 진행하면서 이전과 다른 문자열이 나올 경우 문자열을 치환해야 한다.

이는 새로운 문자열을 덮어씌우는 방법과, index를 이동시키며 변경하는 방법 두가지 다 가능하다.

결과적으로 한번 순회하는것은 같으므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

새로운 문자열로 덮어씌우는 경우 O(N)의 공간 복잡도가 필요하다.

index를 이동하며 변경하는 경우 별도의 공간 복잡도가 필요하지 않다.

### counting

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

연속적으로 발생하는 문자에 대해서 counting을 수행하며 새로운 문자열을 만든다.

```cpp
int compress(vector<char>& chars) {
  vector<char> line;

  char before = chars.front();
  int count = 0;
  for (char c : chars) {
    if (c != before) {
      line.emplace_back(before);

      if (count > 1) {
        for (char digit : to_string(count)) {
          line.emplace_back(digit);
        }
      }

      before = c;
      count = 1;
      continue;
    }
    count += 1;
  }
  line.emplace_back(before);
  if (count > 1) {
    for (char digit : to_string(count)) {
      line.emplace_back(digit);
    }
  }

  chars = line;

  return line.size();
}
```

### index changing

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

위 counting 방법을 그대로 사용하되, 새로운 문자열로 치환하는 것이 아닌 기존 문자열의 index를 변경해간다.

```cpp
int compress(vector<char>& chars) {
  int size = chars.size();
  if (size == 1) return size;

  int index = 0, newIndex = 0;

  while (index < size) {
    chars[newIndex] = chars[index];

    int count = 0;
    while (index < size && chars[index] == chars[newIndex]) {
      count++;
      index++;
    }

    if (count > 1) {
      for (char digit : to_string(count)) {
        newIndex++;
        chars[newIndex] = digit;
      }
    }
    newIndex++;
  }

  return newIndex;
}
```

## 고생한 점
