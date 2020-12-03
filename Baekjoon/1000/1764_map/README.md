# 1764. 듣보잡

[링크](https://www.acmicpc.net/problem/1764)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver IV |   39.265    |

## 설계

### 시간 복잡도

N과 M은 500,000이하의 자연수이다.

배열로 이름들을 관리할 경우 후에 이름순으로 정렬해야 하므로 시간 복잡도는 O(N log(N))

중복 되는것을 찾는데 O(N+M)이 소요된다.

map으로 문제를 풀이할 경우 count와 동시에 이름순으로 정렬되므로 시간 복잡도는 O(N log(N)) 이다.

### 공간 복잡도

이름이 저장될 공간은 최대 500,000 까지이다. 이름은 string으로 관리한다.

### map

name, count의 쌍으로 구성된 map을 생성하고, 입력되는 이름마다 count를 한다.

count가 2 이상인 이름만 출력한다.

```cpp
for (int i = 0; i < N + M; i++) {
  cin >> name;
  m[name] += 1;
}

for (pair<string, int> p : m) {
  if (p.second >= 2) answers.push_back(p.first);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      64      |       12       |

## 고생한 점
