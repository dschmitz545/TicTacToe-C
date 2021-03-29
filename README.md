### How to RUN with CMake

```
cmake -S. -B build
cmake --build build 
cd build
./main
```
### How to RUN with g++
```
g++ main.cpp `wx-config --cxxflags --libs std` -o main.sh
```

### How to Run MinGw cross compiling Windows/Linux
```
sudo apt-get install mingw-w64
```
###### To run
```
i686-w64-mingw32-g++ main.cpp `wx-config --cxxflags --libs std` -o app.exe
```


## How to Instal WXWidgets on Linux

##### Dependences

> Ubuntu exemple:
```
sudo apt-get install libgtk-3-dev build-essential checkinstall
```

> - mkdir buildgtk
> - cd buildgtk
> - ../configure --with-gtk --disable-shared --enable-unicode
> - make
> - sudo checkinstall

##### Track the installed files
```
dpkg -L package_name
```