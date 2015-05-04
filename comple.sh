#sudo apt-get  install libsqlite3-dev
#sudo sed -i -e 's/archive.ubuntu.com\|security.ubuntu.com/old-releases.ubuntu.com/g' /etc/apt/sources.list
#sudo apt-get install parcellite
#http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/intro.html
if [ $# -eq 0 ];
then
	echo "Usage is ./compile.sh [option]"
	echo "Compile with sqlite './compile.sh s'"
	echo "Compile with ncurses './compile.sh n'"
	exit
fi

if [ $1 = "s" ];
then
echo "#### compiling with sqlite#### "
gcc -Wall main.c -lsqlite3 -o pp
fi

if [ $1 = "n" ];
then
echo "#### compiling with ncurses#### "
gcc -Wall nmain.c -lncurses -o pp
fi

