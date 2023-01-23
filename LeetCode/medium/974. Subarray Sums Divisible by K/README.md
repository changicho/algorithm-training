# 974. Subarray Sums Divisible by K

[링크](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 원소의 갯수를 N이라 하자.

left, right 범위를 지정해 모든 범위를 탐색하는데 O(N^2)의 시간 복잡도를 사용한다.

prefixSum을 이용할 경우 각 범위의 합을 O(1)의 시간 복잡도로 구할 수 있다. 이를 K로 나누어 떨어지는지 확인한다.

N의 크기는 최대 3 \* 10^4 이므로 O(N^2)의 방법으로는 제한시간 내에 불가능하다.

hash map과 mod의 성질을 이용할 경우 한번의 순회로 풀이가 가능하다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

prefixSum을 사용하는 경우 O(N)의 공간 복잡도를 사용한다.

hash map을 사용하는 경우 mod값만 저장할 경우 O(K)의 공간 복잡도를 사용한다.

### mod count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      63      |    O(N)     |    O(K)     |

특정 범위 left ~ right의 subArray의 합을 k로 나눈 값에 대해 생각해보자.

해당 구간의 subArray의 합을 직접 구할 수 도 있지만, 다음과 같이 생각해 볼 수 있다.

해당 구간의 합을 K로 나눈 값의 나머지를 M이라 하자.

0 ~ (left - 1) 까지의 합의 나머지가 M인 모든 left에 대해 현재 right까지의 subArray의 합은 K의 배수이다.

즉 0부터 right까지의 합에서 0 부터 left - 1 까지의 합을 빼고 해당 수가 K의 배수가 되는 경우를 구하는것이다.

여기서 합이 음수가 될 수도 있음에 유의한다.

여기서 한번 순회하며 현재 구간의 합을 K로 나눈 나머지에 대해서 count를 hash map을 이용해 수행한다.

따라서 right를 증가시키며 위 조건을 충족하는 left의 갯수를 세고, 이후 현재까지 sum을 K로 나눈 나머지를 hash map에 저장한다.

이를 구현하면 다음과 같다.

```cpp
int subarraysDivByK(vector<int>& nums, int k) {
  unordered_map<int, int> mods;  // mod, count

  // init value
  mods[0] = 1;

  int sum = 0;
  int answer = 0;
  for (int& num : nums) {
    sum += num;

    if (sum < 0) sum = k + (sum % k);

    int target = (sum % k);
    if (mods.count(target) > 0) {
      answer += mods[target];
    }

    mods[target]++;
  }

  return answer;
}
```

vector로 구현할 경우 다음과 같다.

```cpp
int subarraysDivByK(vector<int>& nums, int k) {
  vector<int> mods(k);
  int sum = 0;
  int answer = 0;
  mods[0] = 1;
  for (int& num : nums) {
    sum += num;

    int mod = (sum % k + k) % k;

    answer += mods[mod];

    mods[mod]++;
  }

  return answer;
}
```

## 고생한 점
