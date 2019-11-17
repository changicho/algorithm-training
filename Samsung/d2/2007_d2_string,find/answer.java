import java.util.Scanner;

class Solution {
  public static Scanner sc = new Scanner(System.in);

  public static void solution(int testCase) {
    int answer = 0;
    String str = sc.next();

    for (int i = 1; i <= 10; i++) {
      String sub = str.substring(0, i);
      String subNext = str.substring(i, i + i);

      if (sub.equals(subNext)) {
        answer = i;
        break;
      }
    }

    System.out.println("#" + testCase + " " + answer);
  }

  public static void main(String args[]) {
    int T = sc.nextInt();

    for (int testCase = 1; testCase <= T; testCase++) {
      solution(testCase);
    }
  }

}