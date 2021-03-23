### How to RUN

```
cmake -S. -B build
cmake --build build 
cd build
./main
```

## How to Instal WXWidgets on Linux
> ##### If you compile wxWidgets on Linux for the first time and don't like to read
> ##### install instructions just do (in the base dir):

> - mkdir buildgtk
> - cd buildgtk
> - ../configure --with-gtk
> - make
> - su <type root password>
> - make install
> - ldconfig



##### [if you get "ldconfig: command not found", try using "/sbin/ldconfig"]

##### If you don't do the 'make install' part, you can still use the libraries from the buildgtk directory, but they may not be available to other users.