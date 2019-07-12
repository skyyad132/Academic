#!/bin/bash
choice=0
while [ $choice -ne 5 ] ; do
		echo "-----------------------------------------------------------"
		echo "1.Length\n2.Copy\n3.Concatenation\n4.Equality\n5.Exit"
		read -p "Your choice : " choice
		case $choice in
				1)
					echo "Give a string : "
					read str

					echo "\nLength of string $str is ${#str}"
					;;
				2)	
					echo "Give a string : "
					read str
					str2="scoe"
					echo "\nBefore copying :\nStr1 = $str\nStr2 = $str2"
					str2=$str
					echo "\nAfter copying Str1 to Str2:\nStr1 = $str\nStr2 = $str2"
					;;
				3)
					echo "Give strings to concatenate : "
					read -p "String 1 : " cstr1
					read -p "String 2 : " cstr2

					strf=$cstr1$cstr2
					echo "\nstring after concatenation is $strf"
					;;
				4)
					echo "Check for string equality"
					read -p "String 1 : " estr1
					read -p "String 2 : " estr2

					echo
					if ( test $estr1 = $estr2 )
					then 
						echo "\nStrings are equal"
					else 
						echo "\nStrings are not equal"
					fi
					;;
				5)
					echo "Exiting..."
					;;
				*)
					echo "Try again"
					;;
		esac
done
