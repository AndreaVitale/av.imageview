package av.imageview;

import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.load.model.LazyHeaders;
import com.bumptech.glide.load.model.LazyHeaders.Builder;

import org.appcelerator.kroll.common.Log;

class GlideUrlBuilder {
    public static GlideUrl build(String url, HashMap headers) {
        if (url != null && headers != null) {
            Builder headerBuilder = new LazyHeaders.Builder();
            Iterator iterator = headers.entrySet().iterator();

            while (iterator.hasNext()) {
                Map.Entry pair = (Map.Entry)iterator.next();
                headerBuilder.addHeader(pair.getKey().toString(), pair.getValue().toString());
                iterator.remove();
            }

            return new GlideUrl(url, headerBuilder.build());
        }

        return (url != null) ? new GlideUrl(url) : null;
    }
}
