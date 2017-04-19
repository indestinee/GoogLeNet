path=/data1/pic
write_path=$(pwd)
cd $path
file_list=$(ls | grep 'Tumor*')
file_list_cnt=0
file_list_tot=$(ls | grep 'Tumor*' | wc -l)
for file in $file_list
do
	let file_list_cnt=file_list_cnt+1
	echo listing in $file '('$file_list_cnt/$file_list_tot')'
	cd $file
	if [ -d 'img' ]
	then
		cd img
		img_list=$(ls | grep 'Tumor*')
		for img in $img_list
		do
			echo $path/$file/img/$img >> $write_path/img_list.txt
		done		
		cd ..
	else
		echo Error! No img in $file.
	fi
	cd ..
done
