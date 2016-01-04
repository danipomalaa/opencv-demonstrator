# Build instructions

## Build instructions for Windows

### Step 1 - Installing (and if needed building) required dependencies
Ensure that the following packages are already installed:
  - MINGW (with GCC version >= 4.6.2)
  - MSYS
  - bison
  - flex
  - libgtkmm-3.0-dev
  - OpenCV 3.0
  - git

**Important note:** the difficulty of installing this various libraries on Windows should not be underestimated, especially *one should check the compatibility of it's GCC (MINGW) version with the GTK DLLs*.

### Step 2 - Building the OpenCV demonstrator
Open a MSYS terminal, and follow Linux build instructions (from step 2 as described below).


## Build instruction for Linux (Ubuntu)

These instructions will download **opencv-3.0.0**, **opencv_contrib-3.0.0**, and **OpenCV demonstrator (GUI)** into the
folder **`~/build_from_source`**. Feel free to use another folder, if you wish.

### Step 1 - Building and installing OpenCV 3.0 (dev)

```
$ cd ~/
$ sudo aptitude update
$ sudo aptitude upgrade
$ sudo aptitude install build-essential cmake git pkg-config libjpeg8-dev libtiff4-dev \
    libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libgtk2.0-dev libatlas-base-dev gfortran libgtkmm-3.0-1 libgtkmm-3.0-dev \
    libgtkmm-3.0-doc bison flex
$ mkdir build_from_source
$ cd build_from_source/
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
    -DOPENCV_EXTRA_MODULES_PATH=~/build_from_source/opencv_contrib-3.0.0/modules \
    -DBUILD_EXAMPLES=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DWITH_GTK=ON \
    ..
$ make --jobs=4
$ sudo make install
$ sudo ldconfig
$ cd ~/build_from_source
```

### Step 2 - Building the OpenCV demonstrator

```
$ git clone https://github.com/tsdconseil/opencv-demonstrator.git
$ cd opencv-demonstrator
$ export TARGET=LINUX
$ make
```

### Step 3 - Checking that the demonstrator works

The demonstrator executable is located in (from the download directory) `ocvdemo/build/debug/ocvdemo.exe`.
To work correcly, it is necessary to run it from the `ocvdemo` folder:

```
$ cd ocvdemo
$ ./build/debug/ocvdemo.exe
```

Notes:
- While calling ocvdemo.exe, you can add the `-vv` option to see the debug traces on the terminal.
- The `.exe` extension may seem useless on Linux, but it's because the same Makefile is used on Windows and Linux. In the future, it should be removed under Linux!
- You must be in the ocvdemo folder when calling `ocvdemo.exe`, because it will look for constant data files (xml, images) relative to this folder.



## Platforms where the build has been successfully done
- These instructions were tested on:
  *  **`Debian GNU/Linux 8 (jessie)`**
  * **`Ubuntu 14.04.3`**
  * **`Linux Mint 17.1 KDE`**
  * **`Windows 7`** (although we cannot yet describe a repeatable, systematic and scriptable procedure to install all the required packages on this platform)  

