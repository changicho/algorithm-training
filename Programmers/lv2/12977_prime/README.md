# 12977. 소수 만들기

[링크](https://programmers.co.kr/learn/courses/30/lessons/12977)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   2722   |

## 설계

### 시간복잡도

소수의 범위는 최대 50,000 까지이다. 에라토스테네스의 채를 이용해 소수를 계산한다.

숫자는 50개 이하로 주어진다. 3개의 숫자를 찾기 위해 DFS를 사용하고, 이 때 경우의 수는

```cpp
50 * 49 * 48 = 117,600
```

### 공간 복잡도

수의 크기는 50,000을 넘지 않으므로 int형으로 선언한다.

### 에라토스테네스의 채

```cpp
bool isNotPrime[50001];

void init(){
  isNotPrime[1] = isNotPrime[0] = true;

  for (int i = 2; i < 50001; i++) {
    if (isNotPrime[i]) continue;

    for (int j = i + i; j < 50001; j += i) {
      isNotPrime[j] = true;
    }
  }
}
```

### DFS

```cpp
void dfs(int index, int count, int num, vector<int> arr) {
  if (count == 3) {
    if (!isNotPrime[num]) {
      answer += 1;
    }
    return;
  }
  if (index == arr.size()) return;

  dfs(index + 1, count + 1, num + arr[index], arr);
  dfs(index + 1, count, num, arr);
}
```

## 고생한 점
