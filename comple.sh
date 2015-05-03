#sudo apt-get install libsqlite3-dev
#sudo sed -i -e 's/archive.ubuntu.com\|security.ubuntu.com/old-releases.ubuntu.com/g' /etc/apt/sources.list
echo "compiling... "
gcc main.c -lsqlite3 -o pp

