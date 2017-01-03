
for i in `find ./ -name "*day*.txt"|sort`
do
	cat $i >> uc.txt
done

sed -i '/^$/d' uc.txt
