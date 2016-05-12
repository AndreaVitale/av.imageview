##
## Build an Appcelerator iOS Module
## Then copy it to the default module directory
##


## How to run the script
## write in terminal in the root folder of your project:
## bash ./build-napp.sh

## clean build folder
find ./build -mindepth 1 -delete



## compile the module
./build.py



## where is manifest
FILENAME='./manifest'


## FIND MODULE ID
MODULE_ID=$(grep 'moduleid' $FILENAME -m 1)
MODULE_ID=${MODULE_ID#*: } # Remove everything up to a colon and space

## FIND MODULE VERSION
MODULE_VERSION=$(grep 'version' $FILENAME -m 1) ## only one match
MODULE_VERSION=${MODULE_VERSION#*: } # Remove everything up to a colon and space

## Test app project
PROJECT_PATH='/Volumes/Data/Development/Appcelerator/Modules/kronos-test'

## Delete the old build if existing
rm -rf $PROJECT_PATH/modules/iphone/$MODULE_ID/$MODULE_VERSION/*

## unzip compiled module
unzip -o ./$MODULE_ID-iphone-$MODULE_VERSION.zip -d $PROJECT_PATH

cd $PROJECT_PATH

titanium clean
appc titanium build -p iphone -T simulator --liveview --log-level trace
