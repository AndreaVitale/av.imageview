

<h1 align="center">av.imageview</h1>

<div align="center">
	<strong>An optimized ImageView module</strong>
</div>
<div align="center">
  <sub>
  	for Axway Appcelerator Titanium Framework <br />
  	<img src="https://jira.appcelerator.org/secure/attachment/62974/Axwaylog%20icon.png" height="20px">
  </sub>
</div>
<br />

<div align="center">
  <a href="https://img.shields.io/badge/platform-android-green.svg">
  	<img src="https://img.shields.io/badge/platform-android-brightgreen.svg?style=flat-square">
  </a>
  <a href="https://img.shields.io/badge/platform-android-green.svg">
  	<img src="https://img.shields.io/badge/platform-ios-blue.svg?style=flat-square">
  </a>
  <a href="https://img.shields.io/badge/platform-android-green.svg">
  	<img src="https://img.shields.io/badge/available_on-gittio-red.svg?style=flat-square">
  </a>
  <a href="https://opensource.org/licenses/Apache-2.0">
  	<img src="https://img.shields.io/badge/license-apache_2-lightgrey.svg?style=flat-square">
  </a>
</div>

<div align="center">
  <h3>
    <a href="#features">Features</a>
    <span> | </span>
    <a href="#installation">Installation</a>
    <span> | </span>
    <a href="#api">API</a>
    <span> | </span>
    <a href="#usage">Usage</a>
    <span> | </span>
    <a href="#contributions">Contributions</a>
  </h3>
</div>

## Features

Currently [Titanium.UI.ImageView](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.ImageView) doesn't support the `contentMode` property so your rendered image will everytime fit your ImageView. The main feature of this module is `contentMode` handling that allows you to specify which behavior your ImageView must have and, in addition, the module adds some extra features like image caching and placeholder-fallback images.

Here is an example of two mainly supported content modes: `CONTENT_MODE_ASPECT_FIT` and `CONTENT_MODE_ASPECT_FILL`.

<div align="center">
	<img src="https://i.ibb.co/pygDk2R/fit.png" width="30%" />
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<img src="https://i.ibb.co/Z8VBW0x/fill.png" width="30%"/>
</div>

All other macro-features can be grouped in the following list:

- [x] ContentModes handling
- [x] Loading image placeholder
- [x] Broken link image fallback
- [x] Custom HTTP header, useful if the images are protected
- [x] WebP support
- [x] GIF support

## Installation


Pick the latest version of the module from [here](https://github.com/AndreaVitale/av.imageview/releases) and unzip it inside your application module folder or install it automatically via <a href="http://gitt.io/">gitt.io</a>

    $ gittio install av.imageview

In your application's <i>tiapp.xml</i> the <i>av.imageview</i> module is declared as follows:

    <modules>
        <module platform="iphone">av.imageview</module>
        <module platform="android">av.imageview</module>
    </modules>

and you're ready to use it.

## API

All [Titanium.UI.View](http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.View) properties and methods are supported.

| Property | Description | iOS | Android | Note |
| -------- | ----------- | --- | ------- | ---- |
| contentMode | Sets the ImageView content mode | ✅ | ✅ | Supported content modes are listed in a [next section](https://github.com/AndreaVitale/av.imageview#supported-content-modes). |
| defaultImage | Image to display when the image download is in progress |  ✅ | ✅ | Must refers to a __local__ image  |
| brokenLinkImage | Image to display when the image fetch goes in error | ✅ | ✅ | Must refers to a __local__ image |
| loadingIndicator | Enable or disable the activity indicator when the download is in progress | ✅ | ✅ | `true` by default |
| loadingIndicatorColor | Changes the loading indicator color | ✅ | ✅ | |
| requestHeader | An object used to define extra http request header fields | ✅ | ✅ | |
| timeout | Sets timeout for requests, in milliseconds | ✅ | ✅ | |
| handleCookies | Enables cookie handling for remote images | ✅ | ✅ | |
| shouldCacheImagesInMemory | Activates in-memory cache mechanism | ✅ | ✅| `true` by default |
| shouldDecompressImages | Enables image decompression | ✅ | 🚫| `true` by default |
| maxCacheAge | The maximum length of time to keep an image in the cache, in seconds | ✅ | 🚫 | integer value |
| maxCacheSize | The maximum size of the cache, in bytes | ✅ | 🚫| integer value |
| rounded | Renders the image in a circle | 🚫 | ✅ | Use with `CONTENT_MODE_ASPECT_FIT` for a correct rendering |
| animated | Disables the fade-in animation | 🚫 | ✅ | |
| signature | Sets a custom caching signature (<a href="https://github.com/bumptech/glide/wiki/Caching-and-Cache-Invalidation#custom-cache-invalidation" target="_blank">Glide documentation</a>) | 🚫 | ✅ | |

#### Events

- `load` an event that is fired when an image was correctly loaded
	- `image` as a _string_  if a remote or local url was given or as a _blob_ otherwise
- `error` an event that is fired when the image fetch goes in error
	- `image` as a _string_  if a remote or local url was given or as a _blob_ otherwise
	- `reason` contains the reason why the image fetch goes in error

## Supported content modes
Here is a list of supported content modes:

#### Android and iOS
- `CONTENT_MODE_ASPECT_FIT`
- `CONTENT_MODE_ASPECT_FILL`

#### iOS only
- `CONTENT_MODE_SCALE_TO_FIT`
- `CONTENT_MODE_REDRAW`
- `CONTENT_MODE_CENTER`
- `CONTENT_MODE_TOP`
- `CONTENT_MODE_BOTTOM`
- `CONTENT_MODE_LEFT`
- `CONTENT_MODE_RIGHT`
- `CONTENT_MODE_TOP_LEFT`
- `CONTENT_MODE_TOP_RIGHT`
- `CONTENT_MODE_BOTTOM_LEFT`
- `CONTENT_MODE_BOTTOM_RIGHT`

## Usage

You can simply use this module by declaring an `ImageView` in your `controller.xml` file as follows:

```xml
    <ImageView id="Photo" module="av.imageview" />
```
and style it by using the related `controller.tss` file:

```tss
    "#Photo": {
        width: Ti.UI.FILL,
        height: 200,
        contentMode: Alloy.Globals.CONTENT_MODE_FILL,
        loadingIndicatorColor: "red"
    }
```

and of course expose as a global variable your desired `CONTENT_MODE` inside `Alloy.Globals` namespace.

#### ListView ItemTemplate
Using the module in a `ListItemTemplate` is a bit difference because custom module proxies cannot be directly used inside of it.


```xml
    <ItemTemplate>
        <ImageView ns="AvImageview" />
    </ItemTemplate>
```
where `AvImageview` is a variable declared in `alloy.js` like as follows:
```javascript
    const AvImageview = require("av.imageview");

    //and to use contentmodes constants via alloy
    Alloy.Globals.CONTENT_MODE_FIT = AvImageview.CONTENT_MODE_ASPECT_FIT;
    Alloy.Globals.CONTENT_MODE_FILL = AvImageview.CONTENT_MODE_ASPECT_FILL;

    //If you need to access to protected images you can define which request header fields the module has to use for every request
    Alloy.Globals.REQUEST_HEADERS = {
        'Authorization': 'place or assign dinamically your logged user access token',
        'Another HTTP header field': 'with its value'
    };
```
A complete example can be:
```xml
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
```

Do you want a more complete example? Look a the sample [app.js](https://github.com/everyup/ti.linkedin/blob/master/example/app.js).

## Contributions

If you enjoy this module, feel free to contribute with your PR or [donate](https://paypal.me/VitaleAndrea) :-)
