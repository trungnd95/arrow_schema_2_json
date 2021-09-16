#!/bin/sh

### 1. Install apache 
sudo apt update
sudo apt install -y -V ca-certificates lsb-release wget
wget https://apache.jfrog.io/artifactory/arrow/$(lsb_release --id --short | tr 'A-Z' 'a-z')/apache-arrow-apt-source-latest-$(lsb_release --codename --short).deb
sudo apt install -y -V ./apache-arrow-apt-source-latest-$(lsb_release --codename --short).deb
sudo apt update
sudo apt install -y -V libarrow-dev # For C++
sudo apt install -y -V libarrow-glib-dev # For GLib (C)
sudo apt install -y -V libarrow-dataset-dev # For Apache Arrow Dataset C++
sudo apt install -y -V libarrow-flight-dev # For Apache Arrow Flight C++
# Notes for Plasma related packages:
#   * You need to enable "non-free" component on Debian GNU/Linux
#   * You need to enable "multiverse" component on Ubuntu
#   * You can use Plasma related packages only on amd64
sudo apt install -y -V libplasma-dev # For Plasma C++
sudo apt install -y -V libplasma-glib-dev # For Plasma GLib (C)
sudo apt install -y -V libgandiva-dev # For Gandiva C++
sudo apt install -y -V libgandiva-glib-dev # For Gandiva GLib (C)
sudo apt install -y -V libparquet-dev # For Apache Parquet C++
sudo apt install -y -V libparquet-glib-dev # For Apache Parquet GLib (C)

### 2. Install Cmake 
sudo apt-get install cmake

### 3. Install GTest
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakelists.txt
sudo make 
sudo cp *a /usr/lib

### 4. Json lib
git clone https://github.com/nlohmann/json
cd json
mkdir build
cmake ..
make install
