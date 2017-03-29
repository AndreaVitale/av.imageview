var AvImageview = require("av.imageview");

//Defining URLs
var photos = [
    "http://www.gstatic.com/webp/gallery/1.webp",
    "http://www.gstatic.com/webp/gallery/2.webp",
    "http://www.gstatic.com/webp/gallery/3.webp",
    "http://www.gstatic.com/webp/gallery/4.webp",
    "http://www.gstatic.com/webp/gallery/5.webp",
    "http://www.nationalgeographic.com/content/dam/photography/photos/000/060/6018.ngsversion.1467254523217.adapt.1900.1.jpg",
    "http://www.italiangoodnews.com/wp-content/uploads/2014/11/italy-04.jpg",
    "http://wp-admin.goldenbird-italy.com/wp-content/uploads/2015/07/italy_2631046a.jpg",
    "http://www.travelviaitaly.com/wp-content/uploads/2015/12/Rome-Italy.jpg",
    "http://an.example.of.broken.link.image/"
];

//and creating data source for listview
var source = (function() {
    var array = [];

    photos.forEach(function(photo) {
        array.push({
            photo: {
                image: photo
            }
        });
    });

    return array;
})();

//UI
var default_template = {
    properties: {
        height: 160,
    },
    childTemplates: [{
        type: 'AvImageview.ImageView',
        bindId: 'photo',
        properties: {
            width: Ti.UI.FILL,
            height: 160,
            loadingIndicator: true,
            defaultImage: "/placeholder.png",
            brokenLinkImage: "/broken.png",
            contentMode: AvImageview.CONTENT_MODE_ASPECT_FILL
        }
    }]
};

var window = Ti.UI.createWindow({
    backgroundColor: "white"
});

var list_view = Ti.UI.createListView({
    defaultItemTemplate: 'default',
    templates: {
        'default': default_template
    }
});

var list_section = Ti.UI.createListSection();

list_section.items = source;
list_view.sections = [list_section];

window.add(list_view);
window.open();
