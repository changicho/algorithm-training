function gcd(a, b) {
  if (a < b) {
    [a, b] = [b, a];
  }

  let temp;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

function solution(w, h) {
  var answer = 1;
  let total = w * h;

  let div = gcd(w, h);

  let w_d = w / div;
  let h_d = h / div;

  let rate = h_d / w_d;
  let before = 0;
  let count = 0;

  for (let i = 1; i <= w_d; i++) {
    let height = rate * i;

    count += Math.ceil(height) - Math.floor(before);
    before = height;
  }

  answer = total - count * div;

  return answer;
}
