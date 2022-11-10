echo "Meta Hacker Cup solved count"
DIR="$(cd "$(dirname "$0")" && pwd -P)"
# echo "path : $DIR"
# echo

count=0

shopt -s dotglob
shopt -s nullglob
childDirs=(*/)
for dir in "${childDirs[@]}"; do
  mainPath="$DIR/$dir"
  cd "$mainPath"
  rounds=(*/)
  curCount=0
  for round in "${rounds[@]}"; do
    cd "$mainPath/$round"
    num=$(ls -d */ | wc -l)
    count=$(expr $count + $num)
    curCount=$(expr $curCount + $num)
  done
  echo "$dir : $(expr $curCount)"
done

echo
echo "total : $count"
