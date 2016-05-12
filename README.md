# Extended Imageview

Currently [Titanium.UI.ImageView](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.ImageView) doesn't support the contentMode property so your rendered image will everytime fit your ImageView. This module allows you to specify which behavior your ImageView must have and adds some extra features to improve the user experience.

## Get it

Clone this repository or directly download the latest packaged module version [here](https://github.com/AndreaVitale/imageview/blob/master/dist/av.imageview-iphone-1.0.0.zip?raw=true).\
Now, follow [these steps](http://docs.appcelerator.com/platform/latest/#!/guide/Using_a_Module-section-30082372_UsingaModule-Installingmodules) to install the packaged version of this module into your application.

## Usage
You can easily use this module via Alloy or in a classic way.
### Alloy
Here is how you can use the extended-imageview directly in alloy:

    <Alloy>
        <Window>
            <View class="container">
                <ImageView platform="ios" module="av.imageview" />
            </View>
        </Window>
    </Alloy>

and inside the related TSS you can do

    "ImageView": {
        width: 100,
        height: 100,
        image: "https://static.pexels.com/photos/27954/pexels-photo-27954.jpg",
    }

### Classic
You can instantiate an extended-imageview in this way:

    require('av.imageview').createImageView({
        width: 100,
        height: 100,
        image: "https://static.pexels.com/photos/27954/pexels-photo-27954.jpg",
    });

## API

All [Titanium.UI.View](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.View) properties and methods are supported.\
About the enabled `contentMode`, you can learn more about this [here](https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIView_Class/index.html#//apple_ref/c/econst/UIViewContentModeScaleToFill).

### Extra properties

| Property | Description | Note |
| ---------- | ---------- | ----- |
| image | Set the image to display | When the image download is in progress, an ActivityIndicator is automatically displayed |
| contentMode | Set the ImageView content mode | Supported contentmodes are listed in a next section. |
| defaultImage | __Local__ image to display when the image download is in progress |  |
| brokenLinkImage | __Local__ image to display when the given link doesn't work or the image doesn't exists |  |
| clipsToBound | More details [here](https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIView_Class/#//apple_ref/occ/instp/UIView/clipsToBounds) |  |

### Extra methods

| Method | Description |
| ---------- | ---------- |
| setImage | Set the `image` property |
| setContentMode | Set the `contentMode` property |
| setClipsToBound | Set the `clipToBounds` property |
| startActivityIndicator | Force the activity indicator to show |
| stopActivityIndicator | Force the activity indicator to hide |

### Supported Content Modes
Here is a list of supported content modes:

- CONTENT_MODE_SCALE_TO_FIT
- CONTENT_MODE_ASPECT_FIT
- CONTENT_MODE_ASPECT_FILL
- CONTENT_MODE_REDRAW
- CONTENT_MODE_CENTER
- CONTENT_MODE_TOP
- CONTENT_MODE_BOTTOM
- CONTENT_MODE_LEFT
- CONTENT_MODE_RIGHT
- CONTENT_MODE_TOP_LEFT
- CONTENT_MODE_TOP_RIGHT
- CONTENT_MODE_BOTTOM_LEFT
- CONTENT_MODE_BOTTOM_RIGHT

## Credits
[@mads](https://github.com/viezel) that with his code inspired me to make this module
