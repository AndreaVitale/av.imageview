# Extended Imageview

Currently [Titanium.UI.ImageView](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.ImageView) doesn't support the contentMode property so your rendered image will everytime fit your ImageView. This module allows you to specify which behavior your ImageView must have and adds some extra features to improve the user experience.

## Get it

Clone this repository or directly download the latest packaged module version [here](https://github.com/AndreaVitale/imageview/blob/master/dist/av.imageview-iphone-1.0.0.zip?raw=true).

Now, follow [these steps](http://docs.appcelerator.com/platform/latest/#!/guide/Using_a_Module-section-30082372_UsingaModule-Installingmodules) to install the packaged version of this module into your application.

## Usage
You can easily use this module via Alloy or in a classic way.
### Alloy
Here is how you can use the extended-imageview directly in alloy:

    <Alloy>
        <Window>
            <View class="container">
                <ImageView module="av.imageview" />
            </View>
        </Window>
    </Alloy>

and inside the related TSS you can do

    "ImageView": {
        width: 100,
        height: 100,
        image: "https://static.pexels.com/photos/27954/pexels-photo-27954.jpg",
    }
    
### ListView ItemTemplate
Here is how you can use the extended-imageview directly in alloy:

    <ImageView ns="AvImageview" />

### Classic
You can instantiate an extended-imageview in this way:

    require('av.imageview').createImageView({
        width: 100,
        height: 100,
        image: "https://static.pexels.com/photos/27954/pexels-photo-27954.jpg",
    });

## API

All [Titanium.UI.View](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.View) properties and methods are supported.

About the enabled `contentMode`, you can learn more about this [here](https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIView_Class/index.html#//apple_ref/c/econst/UIViewContentModeScaleToFill).

### Extra properties

| Property | Description | Note |
| ---------- | ---------- | ----- |
| contentMode | Set the ImageView content mode | Supported contentmodes are listed in a next section. |
| defaultImage | __Local__ image to display when the image download is in progress |  |
| brokenLinkImage | __Local__ image to display when the given link doesn't work or the image doesn't exists |  |
| loadingIndicator | Enable or disable the activity indicator when the download is in progress | `true` by default |
| enableMemoryCache | Enable or disable the memory cache mechanism | `true` by default and *Android only* |
| clipsToBound | More details [here](https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIView_Class/#//apple_ref/occ/instp/UIView/clipsToBounds) | (iOS Only) |

### Extra methods

| Method | Description | Note |
| ---------- | ---------- | --- |
| setContentMode | Set the `contentMode` property |  |
| setLoadingIndicator | Set the `loadingIndicator` property |  |
| setDefaultImage | Set the `defaultImage` property |  |
| setBrokenLinkImage | Set the `brokenLinkImage` property |  |
| setClipsToBound | Set the `clipToBounds` property | __iOS only__ |
| getContentMode | Get the value of `contentMode` property |
| getLoadingIndicator | Get the value of `loadingIndicator` property |  |
| getDefaultImage | Get the value of `defaultImage` property |  |
| getBrokenLinkImage | Get the value of `brokenLinkImage` property |  |
| getClipsToBound | Get the value of `clipToBounds` property | __iOS only__ |

### Events

| Event | Description |
| ----- | ----------- |
| load | Fired when the current image was successfully downloaded |
| error | Fired when the image was not fetched |

### Supported Content Modes
Here is a list of supported content modes:

#### Android and iOS
- CONTENT_MODE_ASPECT_FIT
- CONTENT_MODE_ASPECT_FILL

#### iOS only
- CONTENT_MODE_SCALE_TO_FIT
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

### Known issues
Using the Android version inside a ListItemTemplate will cause a rendering problem. To avoid this, set the `loadingIndicator` property to `false` as a temporary workaround.

## Credits
[@mads](https://github.com/viezel) that with his code inspired me to make this module.

[@rs](https://github.com/rs) for the amazing [SDWebImage](https://github.com/rs/SDWebImage) library.

[@bumptech](https://github.com/bumptech) for the amazing [Glide](https://github.com/bumptech/glide) library.
