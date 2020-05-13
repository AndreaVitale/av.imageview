package av.imageview;

import android.app.Activity;
import android.graphics.drawable.Drawable;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;

import com.bumptech.glide.Glide;
import com.bumptech.glide.RequestBuilder;
import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.request.RequestOptions;
import com.bumptech.glide.request.target.DrawableImageViewTarget;
import com.bumptech.glide.signature.ObjectKey;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.titanium.TiBlob;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.view.TiDrawableReference;
import org.appcelerator.titanium.view.TiUIView;

import java.lang.ref.WeakReference;

import av.imageview.utils.ProgressIndicator;
import av.imageview.utils.RequestListener;

public class AvImageView extends TiUIView
{
    private static final String LCAT = "AvImageView";

    private WeakReference<TiViewProxy> proxy;
    private Activity context;
    private ImageView imageView;
    private ProgressIndicator progressBar;
    private RelativeLayout layout;
    private RequestListener requestListener;

    public AvImageView(Activity context, TiViewProxy proxy) {
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
                "defaultImage",
                "brokenLinkImage",
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

        this.processProperty(key, this.proxy.get().getProperties());
    }

    @Override
    public void release() {
        if (!this.context.isFinishing() && !this.context.isDestroyed()) {
            Glide.with(this.context).clear(this.imageView);
        }

        super.release();
    }

    public void processProperty(String withName, KrollDict fromProperties) {
        if (withName.equals("loadingIndicatorColor")) {
            this.progressBar.setColor(fromProperties.getString(withName));
        } else if (withName.equals("image") && fromProperties.get(withName) == null) {
            this.clearImage();
        } else if (withName.equals("image") && fromProperties.get(withName) instanceof TiBlob) {
            this.setImageAsBlob(TiConvert.toBlob(fromProperties.get(withName)));
        } else if (withName.equals("image") && fromProperties.get(withName) instanceof String) {
            String uri = fromProperties.getString(withName);

            if (uri.startsWith("http") || uri.startsWith("ftp"))
                this.setImageAsURL(uri);
            else
                this.setImageAsLocalUri(uri);
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
        String signature = "";

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

        if (currentProperties.containsKey("shouldCacheImagesInMemory") && !currentProperties.getBoolean("shouldCacheImagesInMemory")) {
            options = options.skipMemoryCache(true);
        }

        if (currentProperties.containsKey("loadingIndicator") && currentProperties.getBoolean("loadingIndicator")) {
            this.progressBar.setVisibility(View.VISIBLE);
        }

        if (currentProperties.containsKey("signature") && currentProperties.getString("signature") != "") {
            signature = currentProperties.getString("signature");
        }

        // Creating request builder
        builder = ImageViewHelper.prepareGlideClientFor(this.context, url);
        builder = builder.listener(this.requestListener);
        builder = builder.apply(options);
        builder = builder.load(url);
        if (signature != null && !signature.equals("")) {
            builder.signature(new ObjectKey(signature));
        }
        builder.into(new DrawableImageViewTarget(this.imageView, true));
    }

    public void setImageAsLocalUri(String filename) {
        Drawable imageDrawable = TiDrawableReference.fromUrl(this.proxy.get(), filename).getDrawable();
        KrollDict currentProperties = this.proxy.get().getProperties();
        RequestBuilder builder;

        RequestOptions options = new RequestOptions();

        if (currentProperties.containsKey("animated") && !currentProperties.getBoolean("animated")) {
            options = options.dontAnimate();
        }

        if (currentProperties.containsKey("rounded") && currentProperties.getBoolean("rounded")) {
            options = options.circleCrop();
        }

        // Creating request builder
        builder = Glide.with(context).asDrawable();
        builder = builder.listener(this.requestListener);
        builder = builder.apply(options);
        builder = builder.load(imageDrawable);

        builder.into(this.imageView);
    }

    public void setImageAsBlob(TiBlob blob) {
        TiDrawableReference drawableReference = TiDrawableReference.fromBlob(this.proxy.get().getActivity(), blob);

        this.imageView.setImageBitmap(drawableReference.getBitmap());

        if (this.proxy.get().hasListeners(ImageViewConstants.EVENT_IMAGE_LOADED)) {
            KrollDict payload = new KrollDict();

            payload.put("image", blob);

            this.proxy.get().fireEvent(ImageViewConstants.EVENT_IMAGE_LOADED, payload);
        }

        if (this.progressBar != null && this.progressBar.getVisibility() == View.VISIBLE) {
            this.progressBar.setVisibility(View.INVISIBLE);
        }
    }

    public void clearImage() {
        this.imageView.setImageBitmap(null);
    }
}
