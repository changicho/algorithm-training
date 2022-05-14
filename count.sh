echo "count all problems"
DIR="$( cd "$( dirname "$0" )" && pwd -P )"

# source $DIR/LeetCode/count.sh

cd $DIR/Baekjoon
sh ./count.sh

cd $DIR/LeetCode
sh ./count.sh

cd $DIR/GeeksForGeeks
sh ./count.sh

cd $DIR/LintCode
sh ./count.sh

cd $DIR/Samsung
sh ./count.sh

cd $DIR/CodeForces
sh ./count.sh