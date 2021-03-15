class Solution {
 public:
  int reverse(int x) {
    int isMinus = x < 0 ? -1 : 1;
    long long number = x;
    number *= isMinus;
    long long temp = 0;

    while (number != 0) {
      temp *= 10;

      if (temp < -2147483648 || temp > 2147483647) {
        return 0;
      }
      temp += number % 10;
      number /= 10;
    }

    return temp * isMinus;
  }
};