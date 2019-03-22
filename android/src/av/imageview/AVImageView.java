package av.imageview;

import android.content.Context;
import android.util.Log;
import android.widget.ImageView;

import com.bumptech.glide.Glide;
import com.bumptech.glide.RequestBuilder;
import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.load.model.LazyHeaders;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiUIView;

import java.lang.ref.WeakReference;
import java.util.Map;

import av.imageview.utils.CookiesHelper;
import av.imageview.utils.RequestListener;

public class AvImageView extends TiUIView
{
    private static final String LCAT = "AvImageView";

    private WeakReference<TiViewProxy> proxy;
    private Context context;
    private ImageView imageView;
    private RequestListener requestListener;

    public AvImageView(Context context, TiViewProxy proxy)
    {
        super(proxy);

        this.context = context;
        this.proxy = new WeakReference<>(proxy);
        this.requestListener = new RequestListener(proxy);
        this.imageView = new ImageView(context);

        setNativeView(this.imageView);
    }

    @Override
    public void processProperties(KrollDict properties)
    {
        super.processProperties(properties);

        String[] orderedProperties = {
                "contentMode",
                "image"
        };

        for (String name : orderedProperties) {
            Object propertyValue = properties.get(name);

            if (propertyValue != null) {
                this.processProperty(name, properties);
            }
        }
    }

    @Override
    public void propertyChanged(String key, Object oldValue, Object newValue, KrollProxy proxy) {
        super.propertyChanged(key, oldValue, newValue, proxy);

        Log.d(LCAT, "Property " + key + " has changed.");

        this.processProperty(key, this.proxy.get().getProperties());
    }

    public void processProperty(String withName, KrollDict fromProperties)
    {
        if (withName.equals("image") && fromProperties.get(withName) instanceof String) {
            this.setImageAsURL(fromProperties.getString(withName));
        } else if (withName.equals("contentMode")) {
            ImageView.ScaleType scaleType = fromProperties.getString(withName).equals(ImageViewConstants.CONTENT_MODE_ASPECT_FILL) ?
                    ImageView.ScaleType.CENTER_CROP :
                    ImageView.ScaleType.FIT_CENTER;

            this.imageView.setScaleType(scaleType);
            this.imageView.requestLayout();
        }
    }

    public void setImageAsURL(String uri)
    {
        GlideUrl url = new GlideUrl(uri, ImageViewHelper.prepareRequestHeaders(uri, this.proxy.get()));
        RequestBuilder builder;

        builder = ImageViewHelper.prepareGlideClientFor(this.context, url);
        builder = builder.listener(this.requestListener);
        builder = builder.load(url);

        builder.into(this.imageView);
    }
}
