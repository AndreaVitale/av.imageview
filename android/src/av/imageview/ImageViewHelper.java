package av.imageview;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.util.Log;
import android.webkit.MimeTypeMap;

import com.bumptech.glide.Glide;
import com.bumptech.glide.RequestBuilder;
import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.load.model.LazyHeaders;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiDrawableReference;

import java.util.Map;

import av.imageview.utils.CookiesHelper;

public class ImageViewHelper {
    private static final String LCAT = "ImageViewHelper";

    public static String getMimeTypeFor(String url)
    {
        String type = null;
        String extension = MimeTypeMap.getFileExtensionFromUrl(url);

        if (extension != null)
            type = MimeTypeMap.getSingleton().getMimeTypeFromExtension(extension);

        return type;
    }

    public static Drawable getDrawableFromProxyProperty(String propertyName, TiViewProxy proxy) {
        if (!proxy.hasProperty(propertyName)) {
            return null;
        }

        return TiDrawableReference.fromUrl(proxy, proxy.getProperties().getString(propertyName)).getDrawable();
    }

    public static RequestBuilder prepareGlideClientFor(Context context, GlideUrl url)
    {
        String mimeType = ImageViewHelper.getMimeTypeFor(url.toStringUrl());

        if (mimeType == null) {
            return Glide.with(context).asDrawable();
        }

        switch (mimeType) {
            case "image/gif":
                return Glide.with(context).asGif();
            default:
                return Glide.with(context).asDrawable();
        }
    }

    public static LazyHeaders prepareRequestHeaders(String forUrl, TiViewProxy proxy)
    {
        LazyHeaders.Builder requestHeaders = new LazyHeaders.Builder();

        if (proxy.hasProperty("handleCookies") && proxy.getProperties().getBoolean("handleCookies")) {
            String cookiesForUrl = CookiesHelper.getCookiesStringForURL(forUrl);

            if (cookiesForUrl != null) {
                requestHeaders.addHeader("Cookie", cookiesForUrl);
            }
        }

        if (proxy.hasProperty("requestHeaders")) {
            KrollDict providedRequestHeaders = proxy.getProperties().getKrollDict("requestHeaders");

            for (Map.Entry<String, Object> entry : providedRequestHeaders.entrySet()) {
                requestHeaders.addHeader(entry.getKey(), providedRequestHeaders.getString(entry.getKey()));
            }
        }

        return requestHeaders.build();
    }
}
