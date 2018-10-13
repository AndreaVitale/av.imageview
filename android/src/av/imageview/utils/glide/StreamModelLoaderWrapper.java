package av.imageview.utils.glide;

import java.io.InputStream;

import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.load.data.DataFetcher;
import com.bumptech.glide.load.model.ModelLoader;
import com.bumptech.glide.load.model.stream.StreamModelLoader;

/**
 * Workaround for <a href="https://github.com/bumptech/glide/issues/1832">bumptech/glide#1832</a>.
 *
 * @deprecated not needed after 3.8.0
 */
@Deprecated
public class StreamModelLoaderWrapper<GlideUrl> implements StreamModelLoader<GlideUrl> {
    public final ModelLoader<GlideUrl, InputStream> wrapped;

    public StreamModelLoaderWrapper(ModelLoader<GlideUrl, InputStream> wrapped) {
        this.wrapped = wrapped;
    }

    @Override
    public DataFetcher<InputStream> getResourceFetcher(GlideUrl model, int width, int height) {
        return wrapped.getResourceFetcher(model, width, height);
    }
}
