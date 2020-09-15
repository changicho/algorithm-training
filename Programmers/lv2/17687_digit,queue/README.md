# 17687. [3차] n진수 게임

[링크](https://programmers.co.kr/learn/courses/30/lessons/17687)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   1969    |

## 설계

### 시간 복잡도

미리 구할 숫자의 개수 t는 최대 1000, 게임에 참가하는 인원의 수 m은 100 까지이다.

미리 구해놔야 하는 숫자들의 총 개수는 100,000개 까지 이다.

따라서 시간 복잡도는 최악의 경우 O(100,000) 까지 이다.

### 공간 복잡도

숫자의 절대 크기는 최대 16 이내이고, string의 최대 길이 또한 100,000 이므로

int형과 string으로 선언한다.

### 진수 변환

진수 변환은 끝자리부터 찾을 수 있다.

```cpp

char tables[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string convert(int number, int digit) {
  string ret = "";

  while (number >= digit) {
    ret += tables[number % digit];
    number /= digit;
  }
  ret += tables[number];

  reverse(ret.begin(), ret.end());
  return ret;
}
```

### 모든 숫자를 미리 구하기

정답을 구하기 위해 순회해야 하는 모든 수를 미리 구해놓는다.

```cpp
string line = "";
int index = 0;
while (line.length() < t * m) {
  line += convert(index, n);
  index += 1;
}
```

## 고생한 점
