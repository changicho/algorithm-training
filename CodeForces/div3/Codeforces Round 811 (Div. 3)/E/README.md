# E. Add Modulo 10

[링크](https://codeforces.com/contest/1714/problem/E)

| 난이도 |
| :----: |
| \*1400 |

## 설계

### 시간 복잡도

숫자의 갯수를 N이라 하자.

각 수를 순회하며 변환 가능한 조합으로 묶는다.

이후 각 그룹에서 다른그룹으로 이동할 수 있는지 검사한다.

이 경우 순회에 O(N), 그룹으로 묶는데 O(1)의 공간 복잡도를 사용한다.

### 공간 복잡도

각 숫자를 그룹으로 묶으며 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     109      |    O(N)     |    O(N)     |

각 숫자들 별로 다음과 같이 변환할 수 있다. (X는 10의 자리 이상부터의 값)

- X1 : X1 > X2 > X4 > X8 > (X+1)6 > (X+2)2 ...
- X2 : X2 > X4 > X8 > (X+1)6 > (X+2)2 ...
- X3 : X3 > X6 > (X+1)2 > (X+2)4 ...
- X4 : X4 > X8 > (X+1)6 > (X+2)2 ...
- X5 : X5 > (X+1)0
- X6 : X6 > (X+1)2 > (X+2)4 ...
- X7 : X7 > (X+1)4 > (X+1)8 ...
- X8 : X8 > (X+1)6 ...
- X9 : X9 > (X+1)8 ...
- X0 : X0

위와 같이 1의 자리가 5, 0인 경우는 더이상 증가시킬 수 없고 다른 수와도 조합할 수 없음을 알 수 있다.

모든 수의 10의 자리 이상값을 X로, 뒷자리 수를 2로 맞춘다고 하자 (X2 형태로) 

3, 6, 7, 9인 경우는 앞의 자리수가 X+1의 형태로 맞춰지므로 별도로 관리한다.

각 수를 순회하며 1의자리에 따라서 묶는다.

5, 0으로 끝나는 경우는 더했을 때 모두 같은 값이 되는지 확인하며, 이때 5,0으로 끝나는 경우가 아닌 다른 경우들 또한 존재하는 경우 정답이 될 수 있다.

나머지 값들에 대해서 3,6,7,9인 경우는 (X+1)을 2로 나눈 나머지를, 나머지는 X를 2로 나눈 나머지를 set에 저장한다.

해당 set의 크기가 2인경우 모두 같은 수로 만들 수 있다.

```cpp
bool solution(int n, vector<int> &arr) {
  if (n == 1) return true;

  sort(arr.begin(), arr.end());
  vector<int> zeros;
  vector<int> fives;
  vector<int> twos;

  for (int &n : arr) {
    if (n % 10 == 0) {
      zeros.push_back(n);
    } else if (n % 10 == 5) {
      fives.push_back(n);
    } else {
      twos.push_back(n);
    }
  }

  if (!zeros.empty() || !fives.empty()) {
    if (!twos.empty()) return false;

    set<int> nums;
    for (int &zero : zeros) {
      nums.insert(zero);
    }
    for (int &five : fives) {
      nums.insert(five + 5);
    }

    return nums.size() == 1;
  }

  set<int> group;
  for (int &two : twos) {
    int key = (two / 10) % 2;

    if (two % 10 == 7 || two % 10 == 9 || two % 10 == 6 || two % 10 == 3) {
      key++;
      key %= 2;
    }
    group.insert(key);
  }

  if (group.size() == 2) return false;

  return true;
}
```

## 고생한 점
