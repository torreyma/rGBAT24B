# rGBAT24B
This is a required support package for [rGBATl](https://github.com/torreyma/rGBATl) that provides tools to interface with NYC's powerful [Geosupport](https://www.nyc.gov/site/planning/data-maps/open-data/dwn-gde-home.page) geocoding software from within the R programming language on Linux. For it to work, you first need to manually download and unzip NYC's Geosupport software outside of R, which provides the libraries this package needs for doing NYC geocoding. Then you can install this rGBAT24B packageand the rGBATl package, which will allow you to geocode with Geosupport in R.

This package provides functions for R to access to the 24B Geosupport libraries. You need the rGBATl package for the actual tools to use those libraries in R. (See: https://github.com/torreyma/rGBATl)

## Install, the easier way:
1. Manually download NYC's Geosupport version 24B from Bytes of the Big Apple:
    * Search for Linux version of Geosupport Desktop Edition, 24B on NYC DCP's BYTES of the BIG APPLE™ Archive page.
    * Or try this url for direct download: https://s-media.nyc.gov/agencies/dcp/assets/files/zip/data-tools/bytes/linux_geo24b_24.2.zip
2. Unzip the downloaded file (linux_geo24b_24.2.zip) in your home directory so you get a ```version-24b_24.2/``` directory with all the Geosupport libraries in it. 
    * Note: this is stupid, but it HAS to be in your home directory ($HOME/, ~/) and it has to have the name above or it won't work. (See hard installation section if you want to do it differently.)
    * Probably not a bad idea to run a ```chmod -r 755 version-24b_24.2``` to make all the files executable.
3. In R, make sure you have the ```devtools``` package installed. Then run ```devtools::install_github("torreyma/rGBAT24B")```
4. To make use of the functions this package provides, you will also need to install the rGBATl package in R from github (See: https://github.com/torreyma/rGBATl).

## Install, the harder way:
* If you want to put your Geosupport files anywhere other than your home directory, you need to clone this repo locally, then edit the src/Makevars file to adjust the path to point to where your Geosupport files are stashed. 
* Then you have to grep all files in src for GEOFILES and change any references to GEOFILES in the .cpp files in there to point to where you downloaded your Geosupport files.
* Then install locally from your cloned and modified version of the package.
* If it installs with no errors, you then need to install the torreyma/rGBATl package.

## Troubleshooting
* If you get any error about missing .so or .h files, you probably have a path problem, and it is most likely fixed by messing with the src/Makevars file. (That's not to say it will be easy.)
* On an older version of Linux (eg, RHEL, ie, an older version of gcc/ld) try removing the ```-Wl,--disable-new-dtags``` flag from the PKG_LIBS line in src/Makevars. This is related to how the RPATH and RUNPATH variables work in older version of ld vs newer ones. (However, I have tested this flag on RHEL and it works.)
* If you want to use a different (not 24B) version of Geosupport: contact me. It's doable, but there's some build scripts that would need to be run that are not inlcuded in this repo.

## License
* The original package, rGBAT, was written by Gretchen Culp (https://github.com/gmculp).
* This package is released under an MIT license (see LICENSE file).
* Geosupport Desktop Edition™ copyrighted by the New York City Department of City Planning. This product is freely available to the public with no limitations. 




