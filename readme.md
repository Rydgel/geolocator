### Linux

yum groupinstall 'Development Tools'
yum install –y epel-release
vim /etc/yum.repos.d/epel.repo
yum install gdal


### for compling under amazon ami

_LD_LIBRARY_PATH_
-Wl,-R,'$ORIGIN/../lib'

yum install gdal gdal-devel

cmake -DCMAKE_BUILD_TYPE=Release ..

CPLUS_INCLUDE_PATH=/home/geolocator/lib/asio:/home/geolocator/lib/ make


Installing:
 gdal                x86_64    1.7.3-15.el6                  epel         3.0 M
Installing for dependencies:
 cfitsio             x86_64    3.240-3.el6                   epel         498 k
 compat-libtiff3     x86_64    3.9.4-18.14.amzn1             amzn-main    160 k
 geos                x86_64    3.4.2-1.4.amzn1               amzn-main    613 k
 giflib              x86_64    4.1.6-3.1.6.amzn1             amzn-main     37 k
 hdf5                x86_64    1.8.5.patch1-10.el6           epel         1.4 M
 jasper-libs         x86_64    1.900.1-16.9.amzn1            amzn-main    157 k
 libICE              x86_64    1.0.6-1.4.amzn1               amzn-main     54 k
 libSM               x86_64    1.2.1-2.6.amzn1               amzn-main     38 k
 libX11              x86_64    1.6.0-2.2.12.amzn1            amzn-main    748 k
 libX11-common       x86_64    1.6.0-2.2.12.amzn1            amzn-main    230 k
 libXau              x86_64    1.0.6-4.9.amzn1               amzn-main     25 k
 libdap              x86_64    3.11.0-1.el6                  epel         445 k
 libgeotiff          x86_64    1.2.5-6.el6                   epel         574 k
 libgfortran         x86_64    4.8.3-9.111.amzn1             amzn-main    411 k
 libjpeg-turbo       x86_64    1.2.90-5.14.amzn1             amzn-main    144 k
 libpng              x86_64    2:1.2.49-2.14.amzn1           amzn-main    264 k
 libquadmath         x86_64    4.8.3-9.111.amzn1             amzn-main    234 k
 librx               x86_64    1.5-24.el6                    epel          32 k
 libtool-ltdl        x86_64    2.4.2-20.4.8.3.31.amzn1       amzn-main     51 k
 libxcb              x86_64    1.8.1-1.18.amzn1              amzn-main    143 k
 mysql51-libs        x86_64    5.1.73-3.69.amzn1             amzn-main    1.4 M
 netcdf              x86_64    4.1.1-3.el6.5                 epel         4.8 M
 ogdi                x86_64    3.2.0-0.14.beta2.el6          epel         230 k
 postgresql8-libs    x86_64    8.4.20-5.52.amzn1             amzn-main    239 k
 proj                x86_64    4.7.0-1.el6                   epel         158 k
 unixODBC            x86_64    2.2.14-14.7.amzn1             amzn-main    483 k
 xerces-c            x86_64    3.0.1-0.20.1.el6              epel         862 k
 
 
 Executable deps
 
 
linux-vdso.so.1 =>  (0x00007ffed4b47000)
libgdal.so.1 => /usr/lib64/libgdal.so.1 (0x00007f79d4a4d000)
libstdc++.so.6 => /usr/lib64/libstdc++.so.6 (0x00007f79d4748000)
libm.so.6 => /lib64/libm.so.6 (0x00007f79d4445000)
libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007f79d422f000)
libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f79d4013000)
libc.so.6 => /lib64/libc.so.6 (0x00007f79d3c50000)
libgeos_c.so.1 => /usr/lib64/libgeos_c.so.1 (0x00007f79d3a2a000)
libsqlite3.so.0 => /usr/lib64/libsqlite3.so.0 (0x00007f79d3777000)
libodbc.so.2 => /usr/lib64/libodbc.so.2 (0x00007f79d350f000)
libodbcinst.so.2 => /usr/lib64/libodbcinst.so.2 (0x00007f79d32fe000)
libexpat.so.1 => /lib64/libexpat.so.1 (0x00007f79d30d5000)
libxerces-c-3.0.so => /usr/lib64/libxerces-c-3.0.so (0x00007f79d2b35000)
libjasper.so.1 => /usr/lib64/libjasper.so.1 (0x00007f79d28dc000)
libhdf5.so.6 => /usr/lib64/libhdf5.so.6 (0x00007f79d22f4000)
libogdi.so.3 => /usr/lib64/libogdi.so.3 (0x00007f79d20d2000)
libgif.so.4 => /usr/lib64/libgif.so.4 (0x00007f79d1ec9000)
libjpeg.so.62 => /usr/lib64/libjpeg.so.62 (0x00007f79d1c76000)
libgeotiff.so.1.2 => /usr/lib64/libgeotiff.so.1.2 (0x00007f79d1a45000)
libtiff.so.3 => /usr/lib64/libtiff.so.3 (0x00007f79d17e0000)
libpng12.so.0 => /usr/lib64/libpng12.so.0 (0x00007f79d15ba000)
libnetcdf.so.6 => /usr/lib64/libnetcdf.so.6 (0x00007f79d1274000)
libcfitsio.so.0 => /usr/lib64/libcfitsio.so.0 (0x00007f79d0ec0000)
libpq.so.5 => /usr/lib64/libpq.so.5 (0x00007f79d0c98000)
librt.so.1 => /lib64/librt.so.1 (0x00007f79d0a8f000)
libdl.so.2 => /lib64/libdl.so.2 (0x00007f79d088b000)
libdap.so.11 => /usr/lib64/libdap.so.11 (0x00007f79d059b000)
libdapclient.so.3 => /usr/lib64/libdapclient.so.3 (0x00007f79d036c000)
libdapserver.so.7 => /usr/lib64/libdapserver.so.7 (0x00007f79d0161000)
librx.so.0 => /usr/lib64/librx.so.0 (0x00007f79cff52000)
libxml2.so.2 => /usr/lib64/libxml2.so.2 (0x00007f79cfbe9000)
libcurl.so.4 => /usr/lib64/libcurl.so.4 (0x00007f79cf974000)
libmysqlclient.so.16 => /usr/lib64/mysql/libmysqlclient.so.16 (0x00007f79cf5ef000)
libz.so.1 => /lib64/libz.so.1 (0x00007f79cf3d8000)
libcrypt.so.1 => /lib64/libcrypt.so.1 (0x00007f79cf1a1000)
libnsl.so.1 => /lib64/libnsl.so.1 (0x00007f79cef88000)
libssl.so.10 => /usr/lib64/libssl.so.10 (0x00007f79ced1a000)
libcrypto.so.10 => /lib64/libcrypto.so.10 (0x00007f79ce934000)
/lib64/ld-linux-x86-64.so.2 (0x000055f6ac28f000)
libgeos-3.4.2.so => /usr/lib64/libgeos-3.4.2.so (0x00007f79ce59a000)
libltdl.so.7 => /usr/lib64/libltdl.so.7 (0x00007f79ce391000)
libproj.so.0 => /usr/lib64/libproj.so.0 (0x00007f79ce14d000)
libSM.so.6 => /usr/lib64/libSM.so.6 (0x00007f79cdf46000)
libICE.so.6 => /usr/lib64/libICE.so.6 (0x00007f79cdd2a000)
libX11.so.6 => /usr/lib64/libX11.so.6 (0x00007f79cd9ee000)
libhdf5_hl.so.6 => /usr/lib64/libhdf5_hl.so.6 (0x00007f79cd7bc000)
libkrb5.so.3 => /lib64/libkrb5.so.3 (0x00007f79cd4d6000)
libcom_err.so.2 => /usr/lib64/libcom_err.so.2 (0x00007f79cd2d3000)
libgssapi_krb5.so.2 => /lib64/libgssapi_krb5.so.2 (0x00007f79cd087000)
libldap_r-2.4.so.2 => /lib64/libldap_r-2.4.so.2 (0x00007f79cce2c000)
libuuid.so.1 => /lib64/libuuid.so.1 (0x00007f79ccc28000)
liblzma.so.5 => /usr/lib64/liblzma.so.5 (0x00007f79cca03000)
libidn.so.11 => /lib64/libidn.so.11 (0x00007f79cc7d1000)
libssh2.so.1 => /usr/lib64/libssh2.so.1 (0x00007f79cc5a9000)
libpsl.so.0 => /usr/lib64/libpsl.so.0 (0x00007f79cc333000)
libssl3.so => /usr/lib64/libssl3.so (0x00007f79cc0f0000)
libsmime3.so => /usr/lib64/libsmime3.so (0x00007f79cbec9000)
libnss3.so => /usr/lib64/libnss3.so (0x00007f79cbba9000)
libnssutil3.so => /usr/lib64/libnssutil3.so (0x00007f79cb97d000)
libplds4.so => /lib64/libplds4.so (0x00007f79cb779000)
libplc4.so => /lib64/libplc4.so (0x00007f79cb573000)
libnspr4.so => /lib64/libnspr4.so (0x00007f79cb336000)
libk5crypto.so.3 => /lib64/libk5crypto.so.3 (0x00007f79cb104000)
liblber-2.4.so.2 => /lib64/liblber-2.4.so.2 (0x00007f79caef4000)
libldap-2.4.so.2 => /lib64/libldap-2.4.so.2 (0x00007f79caca2000)
libfreebl3.so => /lib64/libfreebl3.so (0x00007f79caa9f000)
libxcb.so.1 => /usr/lib64/libxcb.so.1 (0x00007f79ca882000)
libkrb5support.so.0 => /lib64/libkrb5support.so.0 (0x00007f79ca672000)
libkeyutils.so.1 => /lib64/libkeyutils.so.1 (0x00007f79ca46f000)
libresolv.so.2 => /lib64/libresolv.so.2 (0x00007f79ca255000)
libsasl2.so.2 => /usr/lib64/libsasl2.so.2 (0x00007f79ca039000)
libicuuc.so.50 => /usr/lib64/libicuuc.so.50 (0x00007f79c9cc3000)
libXau.so.6 => /usr/lib64/libXau.so.6 (0x00007f79c9abf000)
libselinux.so.1 => /usr/lib64/libselinux.so.1 (0x00007f79c989e000)
libicudata.so.50 => /usr/lib64/libicudata.so.50 (0x00007f79c82ca000)