# 800. Similar RGB Color

[링크](https://leetcode.com/problems/similar-rgb-color/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

정답으로 반환할 숫자의 종류는 R, G, B에 대해 각각 16가지이다. ('0' ~ 'f')

또한 차이는 각 색에대해서만 판단하면 되므로 각 색에 대해 완전 탐색을 이용해 정답을 구할 수 있다.

이 경우 O(1)의 시간 복잡도를 사용한다.

혹은 원본 색에 대해 근사치를 이용해 정답을 구할 수 있다. 이 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

완전탐색을 이용하는데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(1)     |    O(1)     |

R, G, B 각 색에 대해서 16가지 경우를 모두 탐색하고 정답을 찾는다.

이를 다음과 같이 구현한다.

```cpp
char convert(int num) {
  if (num < 10) return '0' + num;
  return 'a' + (num - 10);
}

string similarRGB(string color) {
  int red = stoi(color.substr(1, 2), NULL, 16);
  int green = stoi(color.substr(3, 2), NULL, 16);
  int blue = stoi(color.substr(5, 2), NULL, 16);

  string answer = "#000000";
  for (int r = 0, minimum = INT_MAX; r < 16; r++) {
    int diffR = (red - (r * 16 + r));
    diffR *= diffR;

    if (diffR < minimum) {
      minimum = diffR;
      answer[1] = answer[2] = convert(r);
    }
  }
  for (int g = 0, minimum = INT_MAX; g < 16; g++) {
    int diffG = (green - (g * 16 + g));
    diffG *= diffG;

    if (diffG < minimum) {
      minimum = diffG;
      answer[3] = answer[4] = convert(g);
    }
  }
  for (int b = 0, minimum = INT_MAX; b < 16; b++) {
    int diffB = (blue - (b * 16 + b));
    diffB *= diffB;

    if (diffB < minimum) {
      minimum = diffB;
      answer[5] = answer[6] = convert(b);
    }
  }

  return answer;
}
```

### 근사치 이용

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(1)     |    O(1)     |

각 원본 색상에 대해서 반올림을 이용해 근사한 값을 구한다.

이를 구현하면 다음과 같다.

```cpp
string findTarget(string colorSection) {
  int num = stoi(colorSection, NULL, 16);

  int target = round(num * 1.0 / 17);

  char hex = (target >= 10 ? 'a' + (target - 10) : target + '0');
  return {hex, hex};
}

string similarRGB(string color) {
  string answer = "#";

  answer += findTarget(color.substr(1, 2));  // R
  answer += findTarget(color.substr(3, 2));  // G
  answer += findTarget(color.substr(5, 2));  // B

  return answer;
}
```

## 고생한 점
