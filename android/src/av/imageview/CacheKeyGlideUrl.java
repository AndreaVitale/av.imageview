package av.imageview;

import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.load.model.Headers;

/**
 * A GlideUrl that is cached under a fixed key instead of its URL, so an image whose URL changes
 * between requests (e.g. a signed URL with an expiry) is still found in the memory and disk caches.
 */
public class CacheKeyGlideUrl extends GlideUrl {
    private final String cacheKey;

    public CacheKeyGlideUrl(String url, Headers headers, String cacheKey) {
        super(url, headers);
        this.cacheKey = cacheKey;
    }

    @Override
    public String getCacheKey() {
        return cacheKey;
    }
}
