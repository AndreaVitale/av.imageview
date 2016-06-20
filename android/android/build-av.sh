##
## Build Appcelerator Android Module
##

## clean build folder
find ./build -mindepth 1 -delete

## compile the module
ant

## where is manifest
FILENAME='./manifest'

## FIND MODULE ID
MODULE_ID=$(grep 'moduleid' $FILENAME -m 1)
MODULE_ID=${MODULE_ID#*: } # Remove everything up to a colon and space

## FIND MODULE VERSION
MODULE_VERSION=$(grep 'version' $FILENAME -m 1) ## only one match
MODULE_VERSION=${MODULE_VERSION#*: } # Remove everything up to a colon and space

mv ./dist/$MODULE_ID-android-$MODULE_VERSION.zip ../../releases/

exit

## Test app project
PROJECT_PATH='/Volumes/Data/Development/Appcelerator/Applications/comehome'

## Delete the old build if existing
rm -rf $PROJECT_PATH/modules/android/$MODULE_ID/$MODULE_VERSION/*

## unzip compiled module
unzip -o ../../releases/$MODULE_ID-android-$MODULE_VERSION.zip -d $PROJECT_PATH

cd $PROJECT_PATH

titanium clean
appc titanium build -p android -T device --liveview --log-level trace
