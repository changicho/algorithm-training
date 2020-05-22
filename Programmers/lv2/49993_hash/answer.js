function solution(skill, skill_trees) {
  let answer = 0;
  let m = new Map();

  [...skill].forEach((c, index) => {
    m.set(c, index);
  });

  skill_trees.forEach((skill_tree) => {
    let index = 0;
    let flag = true;

    [...skill_tree].forEach((c) => {
      if (m.has(c) && flag) {
        let get_index = m.get(c);

        if (get_index === index) {
          index += 1;
        } else {
          flag = false;
        }
      }
    });

    if (flag) {
      answer += 1;
    }
  });

  return answer;
}
