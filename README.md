<h1 align="center">😎 Shady</h1>
<p align="center">Little OpenCV program written in C++ that augments glasses onto a persons face.</p>
<p align="center"></p>
<p align="center">❗ The following instructions are for Ubuntu 20.04. A similiar process will work for other platforms. ❗</p>
<p align="center"></p>
</p>

## Requirements

### CMake

```console
$ sudo snap install cmake --classic
```

### OpenCV

```console
$ sudo apt update
$ sudo apt install libopencv-dev python3-opencv
```

## Running

### Build from source and run

Install requirements mentioned above

```console
$ sudo apt install build-essential
$ git clone https://github.com/EvanWieland/Shady.git
$ cd /path/to/shady/project
$ mkdir cmake-build-release && cd cmake-build-release && cmake ../
$ cmake --build .
$ ./shady
```

### Run pre-compiled release

Install requirements mentioned above

Download [Release v1.0.0](https://github.com/EvanWieland/Shady/releases/download/1.0.0/1.0.0.zip)

```console
# Decompress the downloaded release zip file
$ cd /path/to/shady/release/filese
$ ./shady
```

### Usage

The Shady program will launch a window showing a stream from your machine's webcam. It will scan for faces and augment readers and sunglasses onto faces that are found.

Press the `ENTER` key to swap between reading glasses and sunglasses.

Press and hold the `ESC` key to terminate the program.

