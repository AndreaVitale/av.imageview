# Features
---------------
Currently [Titanium.UI.ImageView](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.ImageView) doesn't support the contentMode property so your rendered image will everytime fit your ImageView. This module allows you to specify which behavior your ImageView must have and adds some extra features to improve the user experience. The module currently supports the following API's:
- [x] Content Mode
- [x] Broken link image fallback
- [x] Loading image placeholder
- [x] Custom HTTP header, useful if the images are protected
- [x] WebP support
- [x] GIF support

Any PR will be really appreciated!

**Warning**: after the major release of Ti SDK 6.0.0.GA, all Android titanium modules must be rebuilt and will not longer be compatible with previous version of the SDK like 5.x.x.
To give a support on both situations, every release will be built - following the semantic versioning - with two different major number version: 1.x.y for SDK <= 5.5.1.GA and 2.x.y for SDK >= 6.0.0.GA.

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
To include this module in a ListItemTemplate, you have to do:

    <ImageView ns="AvImageview" />

where `AvImageview` is a variable declared in `alloy.js` like this:

    var AvImageview = require("av.imageview");

    //and to use contentmodes constants via alloy
    Alloy.Globals.CONTENT_MODE_FIT = AvImageview.CONTENT_MODE_ASPECT_FIT;
    Alloy.Globals.CONTENT_MODE_FILL = AvImageview.CONTENT_MODE_ASPECT_FILL;

    //If you need to access to protected images you can define which request header fields the module has to use for every request
    Alloy.Globals.REQUEST_HEADERS = {
        'Authorization': 'place or assign dinamically your logged user access token',
        'Another HTTP header field': 'with its value'
    };

A complete example can be:

    <ListView id="Images" defaultItemTemplate="template">
        <Templates>
            <ItemTemplate name="template" height="160">
                <ImageView ns="AvImageview" bindId="photo" height="160" width="Ti.UI.FILL" loadingIndicator="true" contentMode="Alloy.Globals.CONTENT_MODE_FILL" requestHeader="Alloy.Globals.REQUEST_HEADERS" />
            </ItemTemplate>
        </Templates>
        <ListSection>
            <ListItem template="template" photo:image="http://www.nationalgeographic.com/content/dam/photography/photos/000/060/6018.ngsversion.1467254523217.adapt.1900.1.jpg"></ListItem>
            <ListItem template="template" photo:image="http://www.italiangoodnews.com/wp-content/uploads/2014/11/italy-04.jpg"></ListItem>
            <ListItem template="template" photo:image="https://walkingtree.org/wp-content/uploads/2015/09/Elia-Locardi-Whispers-From-The-Past-The-Colosseum-Rome-Italy-1280-WM.jpg"></ListItem>
            <ListItem template="template" photo:image="http://wp-admin.goldenbird-italy.com/wp-content/uploads/2015/07/italy_2631046a.jpg"></ListItem>
            <ListItem template="template" photo:image="http://www.travelviaitaly.com/wp-content/uploads/2015/12/Rome-Italy.jpg"></ListItem>
        </ListSection>
    </ListView>

### Classic
You can instantiate an extended-imageview in this way:

    require('av.imageview').createImageView({
        width: 100,
        height: 100,
        image: "https://static.pexels.com/photos/27954/pexels-photo-27954.jpg",
        requestHeader: {
            'Authorization': 'Bearer your_access_token_here'
        }
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
| requestHeader | An object used to define extra http request header fields |  |

### Extra methods

| Method | Description | Note |
| ---------- | ---------- | --- |
| setContentMode | Set the `contentMode` property |  |
| setLoadingIndicator | Set the `loadingIndicator` property |  |
| setDefaultImage | Set the `defaultImage` property |  |
| setBrokenLinkImage | Set the `brokenLinkImage` property |  |
| setClipsToBound | Set the `clipToBounds` property | __iOS only__ |
| setRequestHeader | Set the `requestHeader` property |  |
| getContentMode | Get the value of `contentMode` property |
| getLoadingIndicator | Get the value of `loadingIndicator` property |  |
| getDefaultImage | Get the value of `defaultImage` property |  |
| getBrokenLinkImage | Get the value of `brokenLinkImage` property |  |
| getClipsToBound | Get the value of `clipToBounds` property | __iOS only__ |
| getRequestHeader | Get the `requestHeader` property |  |

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

## Credits
Anyone who contributes to the module enhanchement!

[@rs](https://github.com/rs) for the amazing [SDWebImage](https://github.com/rs/SDWebImage) library.

[@bumptech](https://github.com/bumptech) for the amazing [Glide](https://github.com/bumptech/glide) library.
