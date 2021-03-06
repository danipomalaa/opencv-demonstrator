# Build instructions


## Build instructions for Windows


### Step 1 - Installing (and if needed building) required dependencies

Ensure that the following packages are already installed:

- MINGW (with GCC version >= 4.6.2)
- MSYS
- libgtkmm-3.0-dev
- OpenCV 3.0
- git

**Important note:** the difficulty of installing those various libraries on
Windows should not be underestimated, especially *one should check the
compatibility of it's GCC (MINGW) version with the GTK DLLs*.


### Step 2 - Building the OpenCV demonstrator

Open a MSYS terminal, and execute the following commands.

```
$ export OCVIPATH="put here the path where the OpenCV include files are installed"
$ export OCVLPATH="put here the path where the OpenCV library files are installed"
$ cd ~/
$ git clone https://github.com/tsdconseil/opencv-demonstrator.git
$ cd opencv-demonstrator
$ make windows
```

Note: typically, `OCVIPATH` would be `path-choosen-to-build-opencv/install/include`,
and `OCVLPATH` would be `path-choosen-to-build-opencv/install/x86/mingw/lib`.

## Build instruction for Linux (Ubuntu)

These instructions will download **opencv-3.0.0**, **opencv_contrib-3.0.0**,
and **OpenCV demonstrator (GUI)** into the home folder.


### Step 1 - Building and installing OpenCV 3.0 (dev)

**Note:** In case you have already another OpenCV version instaled on your machine,
you should first uninstall it, prior to OpenCV 3.0 installation (there is also the possibility
to not install OpenCV 3.0, but only build it, see additionnal instructions below).

```
$ cd ~/
$ sudo aptitude update
$ sudo aptitude upgrade
$ sudo aptitude install build-essential cmake git pkg-config libjpeg8-dev \
    libtiff4-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev \
    libswscale-dev libv4l-dev libgtk2.0-dev libatlas-base-dev gfortran \
    libgtkmm-3.0-1 libgtkmm-3.0-dev libgtkmm-3.0-doc
$ wget https://github.com/Itseez/opencv/archive/3.0.0.tar.gz
$ tar -zxvf 3.0.0.tar.gz
$ rm -rf 3.0.0.tar.gz
$ wget https://github.com/Itseez/opencv_contrib/archive/3.0.0.tar.gz
$ tar -zxvf 3.0.0.tar.gz
$ rm -rf 3.0.0.tar.gz
$ cd opencv-3.0.0
$ mkdir build
$ cd build/
$ cmake \
  -DCMAKE_BUILD_TYPE=RELEASE \
  -DCMAKE_INSTALL_PREFIX=/usr/local \
  -DINSTALL_C_EXAMPLES=ON  \
  -DOPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-3.0.0/modules \
  -DBUILD_EXAMPLES=ON \
  -DBUILD_SHARED_LIBS=ON \
  -DWITH_GTK=ON \
  ../
$ make --jobs=4
$ sudo make install
$ sudo ldconfig
```


### Optionnal: keeping another OpenCV version as the installed one 

If you wish to let the previously installed OpenCV version untouched,
then you should skip the `sudo make install` step in the previous instructions.
Then, however, OpenCV 3.0 include files and libraries will not be
available in the default linux folders. So you can tell the OpenCV demonstrator
where to find it through the following prior definitions:
```
$ export OCVIPATH="~/opencv-3.0.0/build/install/include"
$ export OCVLPATH="~/opencv-3.0.0/build/install/x86/lib"
```

### Step 2 - Building the OpenCV demonstrator


```
$ cd ~/
$ git clone https://github.com/tsdconseil/opencv-demonstrator.git
$ cd opencv-demonstrator
$ make linux
```


## Checking that the demonstrator works

The demonstrator executable is located in (from the download directory)
`ocvdemo/build/debug/ocvdemo.exe`. To work correcly, it is necessary to run
it from the `ocvdemo` folder:


```
$ cd ~/opencv-demonstrator/ocvdemo
$ ./build/debug/ocvdemo.exe
```


## Notes

- While calling ocvdemo.exe, you can add the `-vv` option to see the debug
traces on the terminal.
- The `.exe` extension may seem useless on Linux, but it's because the same
Makefile is used on Windows and Linux. In the future, it should be removed
under Linux!
- You must be in the ocvdemo folder when calling `ocvdemo.exe`, because it will
look for constant data files (xml, images) relative to this folder.


## Platforms where the build has been successfully done

- These instructions were tested on:
  * **`Debian GNU/Linux 8 (jessie)`**
  * **`Ubuntu 14.04.3`**
  * **`Linux Mint 17.1 KDE`**
  * **`Windows 7`** (although we cannot yet describe a repeatable, systematic
  and scriptable procedure to install all the required packages on this platform)  
