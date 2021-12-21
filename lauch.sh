#!/bin/bash

nameSource='chall.c'
# Reset
Reset="\033[0m"       # Text Reset

# Regular Colors
Black="\033[0;30m"        # Black
Red="\033[0;31m"          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

All(){
	for i in day{01..24}/Part{1,2}
	do
		filename="${i}/${nameSource}"
		size=$(wc -c < $filename)
		if [ $size == 0 ]
		then
			echo -e "${Red}Sorry but ${filename} is empty for moment${Reset}"
		else
			if [ "$1" == "comp" ]
			then
				gcc -o "${i}/chall" "${i}/chall.c" -lm
				if test -f "$i/chall"
				then
					echo -e "\n$i/chall created, proof:"
					ls -lart $i/chall
					echo -e "\n"
				fi
			else
				echo -e "\n\n___________${i}/chall___________\n\n"
				./${i}/chall
				if [ $? != 0 ]
				then
					echo -e "${Purple} /!\ Problem with this program /!\ ${Reset}\n"
				fi
				echo -e "\n\n________________________________\n\n"
			fi
		fi
	done
}

Day(){
	if [[ $1 -ge 1 && $1 -le 24 ]];
	then
		if [[ $1 -ge 1 && $1 -le 9 ]];
		then
			day=0$1
		else
			day=$1
		fi
		for i in day$day/Part{1,2}
		do
			size=$(wc -c < $i/chall.c)
			if [ $size == 0 ]
			then
				echo -e "${Red}Sorry but ${filename} is empty for moment${Reset}"
			else
				if [ "$2" == comp ]
				then
					gcc -o "${i}/chall" "${i}/chall.c" -lm
					if test -f "$i/chall"
					then
						echo -e "$i/chall created, proof:"
						ls -lart $i/chall
						echo -e "\n"
					fi
				else
					echo -e "\n\n___________${i}/chall___________\n\n"
					./${i}/chall
					if [ $? != 0 ]
					then
						echo -e "${Purple} /!\ Problem with this program /!\ ${Reset}\n"
					fi
					echo -e "\n\n________________________________\n\n"
				fi
			fi
		done
	elif [[ $1 -ge 24 || $1 -le 10 ]]
	then
		echo -e "Sorry but number need to be beetween 1 and 24"
	fi
}

DayPart(){
	if [[ $2 == 1 || $2 == 2 ]]
	then
		if [[ $1 -ge 1 && $1 -le 24 ]];
		then
			if [[ $1 -ge 1 && $1 -le 9 ]];
			then
				day=0$1
			else
				day=$1
			fi
			i=day$day/Part"$2"
			size=$(wc -c < $i/chall.c)
			if [ $size == 0 ]
			then
				echo "Sorry but ${i} is empty for moment"
			else
				if [ "$3" == "comp" ]
				then
					gcc -o "${i}/chall" "${i}/chall.c" -lm
					if test -f "$i/chall"
					then
						echo -e "$i/chall created, proof:"
						ls -lart $i/chall
						echo -e "\n"
					fi
				else
					echo -e "\n\n___________${i}/chall___________\n\n"
					./${i}/chall
					if [ $? != 0 ]
					then
						echo -e "${Purple} /!\ Problem with this program /!\ ${Reset}\n"
					fi
					echo -e "\n\n________________________________\n\n"
				fi
			fi
		elif [[ $1 -ge 24 || $1 -le 10 ]]
		then
			echo -e "Sorry but number need to be beetween 1 and 24"
		fi
	else
		echo -e "Sorry but Part is 1 or 2"
	fi
}

if [ "$1" == "compil" ] && [ $# == 1 ]
then
	All "comp"
elif [ "$1" == "compil" ] && [ $# == 2 ]
then
	Day $2 "comp"
elif [ "$1" == "compil" ] && [ $# == 3 ]
then
	DayPart $2 $3 "comp"
elif [ "$1" == "exec" ] && [ $# == 1 ]
then
	All "exec"
elif [ "$1" == "exec" ] && [ $# == 2 ]
then
	Day $2 "exec"
elif [ "$1" == "exec" ] && [ $# == 3 ]
then
	DayPart $2 $3 "exec"
elif [ "$1" == "clean" ]
then
	for i in day{01..24}/Part{1,2}
	do
		if test -f "$i/chall"
		then
			rm $i/chall
			echo "$i/chall n'existe plus"
		fi
	done
elif [ "$1" == "checkInput" ]
then
	for i in Input/day{1..24}.txt
	do
		if test -f "$i"
		then
			size=$(wc -c < $i)
			if [ $size == 0 ]
			then
				echo -e "${Yellow}$i exist but empty${Reset}"
			else
				echo -e "$i exist and filled"
			fi
		else
			echo -e "${Red}$i doesn't exist${Reset}"
		fi

	done
elif [ "$1" == "help" ]
then
	echo -e "compil :\n\tCompile all available files and display missing ones\n"
	echo -e "compil <daynumber>:\n\tCompile all the files of this day\n"
	echo -e "compil <daynumber> <1 or 2>:\n\tCompile the part for one day\n"
	echo -e "exec :\n\tExecutes all executables present in the whole project\n"
	echo -e "exec <daynumber>:\n\tExecutes all the executables of a day\n"
	echo -e "exec <daynumber> <1 or 2>:\n\tExecute all the executables of the part of a day\n"
	echo -e "checkInput\n\tChecks the presence of the inputs of each day\n"
else
	echo -e "Sorry but you are using this script wrong, can you do help to get some indication ?"
fi
