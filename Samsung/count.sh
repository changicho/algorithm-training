echo "Samsung SW Academy solved count"
echo

DIR="$(cd "$(dirname "$0")" && pwd -P)"
# echo "path : $DIR"
# echo

count=0

shopt -s dotglob
shopt -s nullglob
array=(*/)
for dir in "${array[@]}"; do
  cd $DIR/$dir
  num=$(ls | wc -l)
  echo "$dir : $(expr $num)"
  count=$(expr $count + $num)
done

echo
echo "total : $count"
