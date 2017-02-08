### Geolocator

## How to compile

# OSX

You'll need Xcode and CLI developer tools.

```bash
brew install gdal
mkdir build
cd -DCMAKE_BUILD_TYPE=Release build
cmake ..
CPLUS_INCLUDE_PATH=/home/rydgel/geolocator/lib/asio:/home/rydgel/geolocator/lib/ make
```

# GNU/Linux

CentOS

```bash
yum groupinstall 'Development Tools'
yum install cmake unzip
yum install -y epel-release
vim /etc/yum.repos.d/epel.repo
# install gdal and gdal-devel deps
yum install gdal gdal-devel spatialite
# then remove these 2 packages, there are old
yum remove gdal gdal-devel gdal-libs
# get a gdal from the internet
wget http://download.osgeo.org/gdal/1.11.5/gdal1115.zip
unzip gdal1115.zip
cd gdal-1.11.5/
./configure --prefix=/usr/local --with-spatialite --with-sqlite3=/usr
make
make install
# ln -s the libs into /usr/lib64 / /usr/include if needed
```

# optional rpath

Just pass `-Wl,-R,'$ORIGIN/lib'` to gcc.

# packaging

If you enable rpath, you can bundle the libs with it. Don't forget the `share` folder too.