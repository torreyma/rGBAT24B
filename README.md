# rGBAT24B
This package provides tools to interface with NYC's Geosupport geocoding software from within the R programming language on Linux. You need to both install this package to your R library, and also get NYC's Geosupport software which provides the libraries this package needs for doing NYC geocoding. This package currently only works with Linux version 24B of Geosupport.


## Install, the easier way:
* You need to manually download NYC's geosupport version 24B from Bytes of the Big Apple:
    * Search for Linux version of Geosupport Desktop Edition, 24B on NYC DCP's BYTES of the BIG APPLE™ Archive page.
    * Or try this url for direct download: https://s-media.nyc.gov/agencies/dcp/assets/files/zip/data-tools/bytes/linux_geo24b_24.2.zip
* Unzip the downloaded file (linux_geo24b_24.2.zip) in your home directory so you get a version-24b_24.2/ directory with all the Geosupport libraries in it. 
    * Probably not a bad idea to run a ```chmod -r 755 version-24b_24.2``` to make all the files executable.
* In R, make sure you have the ```devtools``` package installed. Then run ```devtools::install_github("torreyma/rGBAT24B")```
* If it installs with no errors, you should be able to use the package to start geocoding.
    * (TODO: fix rGBAT help)

## Install, the harder way:
* If you want to put your Geosupport files anywhere other than your home directory, you need to clone this repo locally, then edit the src/Makevars file to adjust the path to point to where your Geosupport files are stashed.

## Troubleshooting
* If you get any error about missing .so or .h files, you probably have a path problem, and it is most likely fixed by messing with the srx/Makevars file. (That's not to say it will be easy.)
* On an older version of Linux (eg, RHEL, ie, an older version of gcc/ld) try removing the ```-Wl,--disable-new-dtags``` flag from the PKG_LIBS line in src/Makevars. This is related to how the RPATH and RUNPATH variables work in older version of ld vs newer ones.

## License
* This package is released under an MIT license (see LICENSE file).
* Geosupport Desktop Edition™ copyrighted by the New York City Department of City Planning. This product is freely available to the public with no limitations. 




