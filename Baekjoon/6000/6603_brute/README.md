# 6603. 로또

[링크](https://www.acmicpc.net/problem/6603)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   53.661    |

## 설계

### 시간 복잡도

숫자의 갯수 K는 최대 13개 까지이다.

현재 숫자가 포함되어있는지 아닌지 여부에 따라 탐색을 이어나가므로 최악의 경우 2^13 번 연산한다.

이는 8,192‬번 이며 시간 제한 내에 충분하다.

테스트케이스의 수는 정해져 있지 않다.

### 포함 여부 관리

포함 여부의 탐색은 다음 두가지 방법이 존재한다.

- DFS
- next_permutation

DFS의 방법의 경우 숫자 6개를 선택한 경우에 탐색을 중지한다.

현재 숫자를 선택하거나 선택하지 않거나 두 경우에 따라 탐색의 분기가 이루어지며, 함수의 인자로 선택한 숫자의 vector를 갖고 있어야 한다.

```cpp
dfs(int index, vector<int> numbers){
  if(index == K) {
    // print answer
    return;
  }
  if(numbers.size() >= 6) return;
  // backtracking
  if((K - 1) - index < 6 - numbers.size() ) return;

  dfs(index+1, numbers);
  numbers.push_back(arr[index]);
  dfs(index+1, numbers);
}
```

현재 숫자를 선택한다 하더라고 6개의 숫자를 채우지 못하는 경우는 탐색을 진행하지 않는다.

next_permutation을 이용한 방법은 가능한 visited 배열을 전부 만들어 출력하는 방식이다.

다음 형태의 visited 배열을 선언한다.

```cpp
vector<bool> visited(K, true);

for (int i = 0; i < 6; i++) {
  visited[i] = false;
}
```

여기서 초기값을 true로 선언하고, 0 ~ 5 번째 까지의 값을 false로 두는것에 유의한다.

이는 오름차순으로 정렬된 정답을 출력하기 위함이다.

이후 next_permutation을 수행하면 K개의 숫자중 6개를 뽑는 모든 경우의 수를 탐색할 수 있다.

```cpp
do {
  for (int i = 0; i < K; i++) {
    if (!combi[i]) {
      // 현재 i번째 숫자를 선택함
    }
  }

} while (next_permutation(combi.begin(), combi.end()));
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
