package av.imageview.utils;

import android.support.annotation.Nullable;

import com.bumptech.glide.load.DataSource;
import com.bumptech.glide.load.engine.GlideException;
import com.bumptech.glide.request.target.Target;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.titanium.proxy.TiViewProxy;

import java.lang.ref.WeakReference;

import av.imageview.ImageViewConstants;

public class RequestListener implements com.bumptech.glide.request.RequestListener {
    private WeakReference<TiViewProxy> proxy;

    public RequestListener(TiViewProxy proxy) {
        this.proxy = new WeakReference<TiViewProxy>(proxy);
    }

    @Override
    public boolean onLoadFailed(@Nullable GlideException e, Object model, Target target, boolean isFirstResource) {
        if (this.proxy.get().hasListeners(ImageViewConstants.EVENT_IMAGE_LOAD_ERROR)) {
            KrollDict payload = new KrollDict();

            payload.put("image", this.proxy.get().getProperties().getString("image"));
            payload.put("reason", e.getMessage());

            this.proxy.get().fireEvent(ImageViewConstants.EVENT_IMAGE_LOAD_ERROR, payload);
        }

        return false;
    }

    @Override
    public boolean onResourceReady(Object resource, Object model, Target target, DataSource dataSource, boolean isFirstResource) {
        if (this.proxy.get().hasListeners(ImageViewConstants.EVENT_IMAGE_LOADED)) {
            KrollDict payload = new KrollDict();

            payload.put("image", this.proxy.get().getProperties().getString("image"));

            this.proxy.get().fireEvent(ImageViewConstants.EVENT_IMAGE_LOADED, payload);
        }

        return false;
    }
}
