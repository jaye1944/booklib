## booklib
book store library 
* c
* sqlite3

### Install sqlite3 libs 
(Avoid sqlite3.h not found error) 
~~~
sudo apt-get install libsqlite3-dev
~~~
* IF you can't find packge via ***sudo apt-get*** (**Old ubuntu relese**) 
* visit https://packages.debian.org/squeeze/libs/
* Download libsqlite3-0_3.7.3-1_i386.deb and libsqlite3-dev_3.7.3-1_i386.deb
* Install them using 
~~~
sudo dpkg -i libsqlite3-0_3.7.3-1_i386.deb
sudo dpkg -i libsqlite3-dev_3.7.3-1_i386.deb
~~~
