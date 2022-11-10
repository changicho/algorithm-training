echo "count all problems"
DIR="$(cd "$(dirname "$0")" && pwd -P)"

echo "========================"
cd $DIR/Algospot
sh ./count.sh
echo "========================"
cd $DIR/Baekjoon
sh ./count.sh
echo "========================"
cd $DIR/LeetCode
sh ./count.sh
echo "========================"
cd $DIR/GeeksForGeeks
sh ./count.sh
echo "========================"
cd $DIR/HackerCup
sh ./count.sh
echo "========================"
cd $DIR/KickStart
sh ./count.sh
echo "========================"
cd $DIR/LintCode
sh ./count.sh
echo "========================"
cd $DIR/Samsung
sh ./count.sh
echo "========================"
cd $DIR/CodeForces
sh ./count.sh
echo "========================"
