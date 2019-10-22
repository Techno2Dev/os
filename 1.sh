opt=1
count=0
while [ "$opt" -lt 6 ]
do
	echo -e "**menu**\n1.create\n2.view\n3.insert\n4.delete\n5.modify\n6.exit"
	read opt
	case $opt in
	1)
		echo "enter filename"
		read filename
		if [ -e $filename ];
		then
		rm $filename
		fi
		cont=1
		echo "name\tnumber\t\taddress\n========================================\n" | cat >> $filename
		while [ "$cont" -gt 0 ]
		do
			count=`expr $count + 1`
			echo "\n enter name:"	
			read name
			echo "\nenter phone number of $name :"	
			read number
			echo "enter address of $name:"	
			read address
			echo "$count)$name\t$number\t$address" | cat>>$filename	
	
			echo "enter 0 to stop ,1 to enter next"
			read cont
		done
		
		;; 
	2)
		pr $filename
		 
		
		;;
	3)
			echo "\n enter name:"	
			read name
			echo "\nenter phone number of $name"	
			read number
			echo "enter address of $name:"	
			read address
			echo "$name\t$number\t$address" | cat>>$filename	

		;;
	4)
			echo "delete record\n enter name/phone number"
			read pattern
			temp="temp"
			grep -v $pattern $filename | cat >> $temp
			rm $filename
			cat $temp | cat >> $filename
			rm $temp
		;;
	5)
			echo "modify record\n enter name/phone number"
			read pattern
			temp="temp"
			grep -v $pattern $filename | cat >> $temp
			rm $filename
			cat $temp | cat >> $filename
			rm $temp
			echo "\n enter name:"	
			read name
			echo "\nenter phone number of $name"	
			read number
			echo "enter address of $name:"	
			read address
			echo "$name\t$number\t$address" | cat>>$filename	
		
		;;
	esac
done

