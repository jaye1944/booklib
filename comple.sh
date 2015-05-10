#sudo apt-get  install libsqlite3-dev
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
	echo "Compile with ncurses './compile.sh n'"
	tput sgr0
	exit 0
fi

if [ $1 = "s" ];
then
echo "#### compiling with sqlite#### "
gcc -Wall main.c -lsqlite3 -o pp
#gcc -Wall create.c -lsqlite3 -o pp
fi

if [ $1 = "n" ];
then
echo "#### compiling with ncurses#### "
gcc -Wall nmain.c -lncurses -o pp
fi

