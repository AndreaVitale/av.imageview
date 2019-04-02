package av.imageview;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;

import com.bumptech.glide.Glide;
import com.bumptech.glide.RequestBuilder;
import com.bumptech.glide.TransitionOptions;
import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.request.RequestOptions;
import com.bumptech.glide.load.resource.drawable.DrawableTransitionOptions;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.util.TiRHelper;
import org.appcelerator.titanium.view.TiUIView;

import java.lang.ref.WeakReference;

import av.imageview.utils.ProgressIndicator;
import av.imageview.utils.RequestListener;

public class AvImageView extends TiUIView
{
    private static final String LCAT = "AvImageView";

    private WeakReference<TiViewProxy> proxy;
    private Context context;
    private ImageView imageView;
    private ProgressIndicator progressBar;
    private RelativeLayout layout;
    private RequestListener requestListener;

    public AvImageView(Context context, TiViewProxy proxy) {
        super(proxy);

        this.context = context;
        this.proxy = new WeakReference<>(proxy);
        this.layout = new RelativeLayout(context);
        this.imageView = new ImageView(context);
        this.progressBar = new ProgressIndicator(context);
        this.requestListener = new RequestListener(proxy, this.progressBar);

        this.layout.setLayoutParams(new RelativeLayout.LayoutParams(
                RelativeLayout.LayoutParams.MATCH_PARENT,
                RelativeLayout.LayoutParams.MATCH_PARENT));

        this.imageView.setLayoutParams(new RelativeLayout.LayoutParams(
                RelativeLayout.LayoutParams.MATCH_PARENT,
                RelativeLayout.LayoutParams.MATCH_PARENT));

        this.layout.addView(this.imageView);
        this.layout.addView(this.progressBar);

        setNativeView(this.layout);
    }

    @Override
    public void processProperties(KrollDict properties)
    {
        super.processProperties(properties);

        String[] orderedProperties = {
                "loadingIndicatorColor",
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

    @Override
    public void release() {
        super.release();

        Glide.with(this.context).clear(this.imageView);
    }

    public void processProperty(String withName, KrollDict fromProperties) {
        if (withName.equals("loadingIndicatorColor")) {
            this.progressBar.setColor(fromProperties.getString(withName));
        } else if (withName.equals("image") && fromProperties.get(withName) instanceof String) {
            this.setImageAsURL(fromProperties.getString(withName));
        } else if (withName.equals("contentMode")) {
            ImageView.ScaleType scaleType = fromProperties.getString(withName).equals(ImageViewConstants.CONTENT_MODE_ASPECT_FILL) ?
                    ImageView.ScaleType.CENTER_CROP :
                    ImageView.ScaleType.FIT_CENTER;

            this.imageView.setScaleType(scaleType);
            this.imageView.requestLayout();
        }
    }

    public void setImageAsURL(String uri) {
        Drawable defaultImageDrawable = ImageViewHelper.getDrawableFromProxyProperty("defaultImage", this.proxy.get());
        Drawable brokenLinkImageDrawable = ImageViewHelper.getDrawableFromProxyProperty("brokenLinkImage", this.proxy.get());
        GlideUrl url = new GlideUrl(uri, ImageViewHelper.prepareRequestHeaders(uri, this.proxy.get()));

        KrollDict currentProperties = this.proxy.get().getProperties();

        int timeout = currentProperties.containsKey("timeout")
                ? currentProperties.getInt("timeout")
                : ImageViewConstants.DEFAULT_REQUEST_TIMEOUT;

        RequestOptions options;
        RequestBuilder builder;

        // Creating request options
        options = new RequestOptions();
        options = options.placeholder(defaultImageDrawable);
        options = options.error(brokenLinkImageDrawable);
        options = options.timeout(timeout);

        if (currentProperties.containsKey("animated") && !currentProperties.getBoolean("animated")) {
            options = options.dontAnimate();
        }

        if (currentProperties.containsKey("rounded") && currentProperties.getBoolean("rounded")) {
            options = options.circleCrop();
        }

        if (currentProperties.containsKey("enableMemoryCache") && !currentProperties.getBoolean("enableMemoryCache")) {
            options = options.skipMemoryCache(true);
        }

        if (currentProperties.containsKey("loadingIndicator") && currentProperties.getBoolean("loadingIndicator")) {
            this.progressBar.setVisibility(View.VISIBLE);
        }

        // Creating request builder
        builder = ImageViewHelper.prepareGlideClientFor(this.context, url);
        builder = builder.listener(this.requestListener);
        builder = builder.apply(options);
        builder = builder.load(url);

        builder.into(this.imageView);
    }
}
