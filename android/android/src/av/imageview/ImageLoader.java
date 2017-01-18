package av.imageview;

import android.widget.ImageView;

import org.appcelerator.kroll.common.Log;
import org.appcelerator.titanium.TiBlob;

public class ImageLoader implements Runnable {
    private static final String LCAT = "ImageLoader";

    private String url;
    private TiBlob blob;
    private ExtendedImageView module;

    public ImageLoader(ExtendedImageView imageViewModule, Object image) {
        if (image instanceof String)
            this.url = image.toString();
        else if (image instanceof TiBlob)
            this.blob = (TiBlob)image;

        this.module = imageViewModule;
    }

    public void run() {
        if (this.url != null) {
            if (this.url.startsWith("http") || this.url.startsWith("ftp"))
                this.module.startRequest(this.url, this.module.getLoadingIndicator());
        } else if (this.blob != null) {
            this.module.displayBlob(this.blob);
            this.blob = null;
        }
        else
            Log.w(LCAT, "Unknown given image format.");
    }
}
