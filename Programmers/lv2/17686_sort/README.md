# 17686. [3차] 파일명 정렬

[링크](https://programmers.co.kr/learn/courses/30/lessons/17686)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   1719    |

## 설계

### 시간 복잡도

파일명은 1000개 까지이다. 정렬에는 최소 NlogN의 시간 복잡도가 소요되므로 제한시간 내에 충분하다.

### 공간 복잡도

파일명이 숫자로만 이루어진 경우 최대 100자리의 숫자가 올 수 있다.

문제에서 숫자의 최대 크기는 따로 주어져 있지 않지만, 대소 비교를 문자가 아닌 숫자로 비교해야 하므로 long long 형을 사용한다.

### 파일명 나누기

파일명은 3가지로 나눈다

- head
- number
- tail

나누는 방법은 문자를 하나하나 순서대로 순회하며 분기에 따라 나눈다.

```cpp
struct File {
  string head;
  string numberString;
  long long number;
  string tail;
};

File parse(string file) {
  File ret = {"", "", 0, ""};
  string number = "";
  bool isNumber = false;
  bool isTail = false;

  for (char c : file) {
    if (c >= '0' && c <= '9' && !isTail) {
      number += c;
      isNumber = true;
    } else {
      if (isNumber) {
        isTail = true;
      }

      if (isNumber) {
        ret.tail += c;
      } else {
        ret.head += c;
      }
    }
  }
  ret.numberString = number;
  ret.number = stoll(number);

  return ret;
}
```

### 정렬 stable sort

stable sort 는 정렬후 동일값의 원소 순서를 보장 해준다.

따라서 sort가 아닌 stable sort를 이용해야 한다. (문제 조건 중 "원래 입력에 주어진 순서를 유지한다.")

문자의 비교는 transform을 이용해 모두 소문자로 통실시켜서 비교함

```cpp
bool compare(File a, File b) {
  transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
  transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);

  if (a.head != b.head) {
    return a.head < b.head;
  }
  if (a.number != b.number) {
    return a.number < b.number;
  }
  return false;
}
```

## 고생한 점

stable_sort가 아닌 sort를 이용해 틀렸음
