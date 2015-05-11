#sudo sed -i -e 's/archive.ubuntu.com\|security.ubuntu.com/old-releases.ubuntu.com/g' /etc/apt/sources.list
#sudo apt-get install parcellite
#http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/intro.html
#http://www.cyberciti.biz/faq/bash-shell-change-the-color-of-my-shell-prompt-under-linux-or-unix/
#http://www.pauloamgomes.net/blog/dropbox-shell-uploader
#http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
if [ $# -eq 0 ];
then
	tput setaf 3
	echo "Usage is ./compile.sh [option]"
	echo "Compile with sqlite './compile.sh s'"
	#echo "Compile with ncurses './compile.sh n'"
	tput sgr0
	exit 0
fi

if [ $1 = "s" ];
then
tput setaf 2
echo "#### Running with sqlite#### "
tput sgr0
./bin/mycc
#gcc -Wall main.c -lsqlite3 -o pp
#gcc -Wall create.c -lsqlite3 -o pp
fi

#if [ $1 = "n" ];
#then
#echo "#### compiling with ncurses#### "
#gcc -Wall nmain.c -lncurses -o pp
#fi
#0	Black
#1	Red
#2	Green
#3	Yellow
#4	Blue
#5	Magenta
#6	Cyan
#7	White
