package av.imageview.utils;

import android.view.View;
import android.widget.ProgressBar;

import androidx.annotation.Nullable;

import com.bumptech.glide.load.DataSource;
import com.bumptech.glide.load.engine.GlideException;
import com.bumptech.glide.request.target.Target;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.titanium.proxy.TiViewProxy;

import java.lang.ref.WeakReference;

import av.imageview.ImageViewConstants;

public class RequestListener implements com.bumptech.glide.request.RequestListener {
    private WeakReference<TiViewProxy> proxy;
    private WeakReference<ProgressBar> progressBar;

    public RequestListener(TiViewProxy proxy) {
        this.proxy = new WeakReference<TiViewProxy>(proxy);
        this.progressBar = null;
    }

    public RequestListener(TiViewProxy proxy, ProgressBar progressBar) {
        this.proxy = new WeakReference<TiViewProxy>(proxy);
        this.progressBar = new WeakReference<ProgressBar>(progressBar);
    }

    @Override
    public boolean onLoadFailed(@Nullable GlideException e, Object model, Target target, boolean isFirstResource) {
        if (this.proxy == null || this.proxy.get() == null) { return false; }
        
        KrollDict currentProperties = this.proxy.get().getProperties();

        if (this.proxy.get().hasListeners(ImageViewConstants.EVENT_IMAGE_LOAD_ERROR)) {
            KrollDict payload = new KrollDict();

            payload.put("image", currentProperties.getString("image"));

            if (e != null) {
                payload.put("reason", e.getMessage());
            } else {
                payload.put("reason", "unknown");
            }

            this.proxy.get().fireEvent(ImageViewConstants.EVENT_IMAGE_LOAD_ERROR, payload);
        }

        if (this.progressBar != null && this.progressBar.get() != null) {
            this.progressBar.get().setVisibility(View.INVISIBLE);
        }

        return false;
    }

    @Override
    public boolean onResourceReady(Object resource, Object model, Target target, DataSource dataSource, boolean isFirstResource) {
        if (this.proxy == null || this.proxy.get() == null) { return false; }

        KrollDict currentProperties = this.proxy.get().getProperties();

        if (this.proxy.get().hasListeners(ImageViewConstants.EVENT_IMAGE_LOADED)) {
            KrollDict payload = new KrollDict();

            payload.put("image", currentProperties.getString("image"));

            this.proxy.get().fireEvent(ImageViewConstants.EVENT_IMAGE_LOADED, payload);
        }

        if (this.progressBar != null && this.progressBar.get() != null) {
            this.progressBar.get().setVisibility(View.INVISIBLE);
        }

        return false;
    }
}
