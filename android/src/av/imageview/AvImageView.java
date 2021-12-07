package av.imageview;

import android.annotation.SuppressLint;
import android.graphics.drawable.Drawable;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;

import com.bumptech.glide.Glide;
import com.bumptech.glide.RequestBuilder;
import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.request.RequestOptions;
import com.bumptech.glide.signature.ObjectKey;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.TiBlob;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.view.TiDrawableReference;
import org.appcelerator.titanium.view.TiUIView;

import av.imageview.utils.ProgressIndicator;
import av.imageview.utils.RequestListener;

public class AvImageView extends TiUIView {
    private static final String LCAT = "AvImageView";
    private ImageView imageView;
    private ProgressIndicator progressBar;
    private RelativeLayout layout;

    public AvImageView(TiViewProxy proxy) {
        super(proxy);

        this.layout = new RelativeLayout(proxy.getActivity());
        this.imageView = new ImageView(proxy.getActivity());
        this.progressBar = new ProgressIndicator(proxy.getActivity());

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

        this.processProperty(key, proxy.getProperties());
    }

    @Override
    public void release() {
        if (this.imageView != null) {
            // this line might not be required as calling the clear will eventually stop image-resource being loaded
            // but unfortunately it'll try to show the current placeholder
            //Glide.with(this.imageView.getContext()).clear(this.imageView);

            clearImage();
            this.imageView = null;
        }

        if (this.progressBar != null) {
            this.progressBar = null;
        }

        if (this.layout != null) {
            this.layout.removeAllViews();
            this.layout = null;
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

    @SuppressLint("CheckResult")
    public void setImageAsURL(String uri) {
        Drawable defaultImageDrawable = ImageViewHelper.getDrawableFromProxyProperty("defaultImage", proxy);
        Drawable brokenLinkImageDrawable = ImageViewHelper.getDrawableFromProxyProperty("brokenLinkImage", proxy);
        GlideUrl url = new GlideUrl(uri, ImageViewHelper.prepareRequestHeaders(uri, proxy));

        KrollDict currentProperties = proxy.getProperties();

        int timeout = currentProperties.containsKey("timeout")
                ? currentProperties.getInt("timeout")
                : ImageViewConstants.DEFAULT_REQUEST_TIMEOUT;

        RequestOptions options;
        String signature = "";

        // Creating request options
        options = new RequestOptions();
        options = options.placeholder(defaultImageDrawable);
        options = options.error(brokenLinkImageDrawable);
        options = options.timeout(timeout);

        if (currentProperties.containsKeyAndNotNull("animated") && !currentProperties.getBoolean("animated")) {
            options = options.dontAnimate();
        }

        if (currentProperties.containsKeyAndNotNull("rounded") && currentProperties.getBoolean("rounded")) {
            options = options.circleCrop();
        }

        if (currentProperties.containsKeyAndNotNull("shouldCacheImagesInMemory") && !currentProperties.getBoolean("shouldCacheImagesInMemory")) {
            options = options.skipMemoryCache(true);
        }

        if (currentProperties.containsKeyAndNotNull("loadingIndicator") && currentProperties.getBoolean("loadingIndicator")) {
            this.progressBar.setVisibility(View.VISIBLE);
        }

        if (currentProperties.containsKeyAndNotNull("signature") && !currentProperties.getString("signature").isEmpty()) {
            signature = currentProperties.getString("signature");
        }

        // Creating request builder
        RequestBuilder builder = ImageViewHelper.prepareGlideClientFor(TiApplication.getInstance(), url);
        builder = builder.listener(new RequestListener(proxy, this.progressBar));
        builder = builder.apply(options);
        builder = builder.load(url);
        if (signature != null && !signature.equals("")) {
            builder.signature(new ObjectKey(signature));
        }
        builder.into(this.imageView);
    }

    public void setImageAsLocalUri(String filename) {
        Drawable imageDrawable = TiDrawableReference.fromUrl(proxy, filename).getDrawable();
        KrollDict currentProperties = proxy.getProperties();

        RequestOptions options = new RequestOptions();

        if (currentProperties.containsKey("animated") && !currentProperties.getBoolean("animated")) {
            options = options.dontAnimate();
        }

        if (currentProperties.containsKey("rounded") && currentProperties.getBoolean("rounded")) {
            options = options.circleCrop();
        }

        // Creating request builder
        RequestBuilder<Drawable> builder = Glide.with(TiApplication.getInstance()).asDrawable();
        builder = builder.listener(new RequestListener(proxy, this.progressBar));
        builder = builder.apply(options);
        builder = builder.load(imageDrawable);

        builder.into(this.imageView);
    }

    public void setImageAsBlob(TiBlob blob) {
        TiDrawableReference drawableReference = TiDrawableReference.fromBlob(proxy.getActivity(), blob);

        this.imageView.setImageBitmap(drawableReference.getBitmap());

        if (proxy.hasListeners(ImageViewConstants.EVENT_IMAGE_LOADED)) {
            KrollDict payload = new KrollDict();

            payload.put("image", blob);

            proxy.fireEvent(ImageViewConstants.EVENT_IMAGE_LOADED, payload);
        }

        if (this.progressBar != null && this.progressBar.getVisibility() == View.VISIBLE) {
            this.progressBar.setVisibility(View.INVISIBLE);
        }
    }

    public void clearImage() {
        this.imageView.setImageBitmap(null);
    }
}
