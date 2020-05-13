package av.imageview;

import android.app.Activity;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.TiConfig;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiUIView;


@Kroll.proxy(creatableInModule= ImageViewModule.class, propertyAccessors = {
        "requestHeaders", "handleCookies", "contentMode", "rounded", "animated", "timeout",
        "shouldCacheImagesInMemory", "loadingIndicator", "loadingIndicatorColor", "image",
        "signature", "defaultImage", "brokenLinkImage"
})
public class ImageViewProxy extends TiViewProxy  {
	private static final String LCAT = "ImageViewProxy";
	private static final boolean DBG = TiConfig.LOGD;

    private static final int MSG_FIRST_ID = TiViewProxy.MSG_LAST_ID + 1;

    private Activity activity;

	@Override
	public TiUIView createView(Activity activity) {
	    this.activity = activity;

		TiUIView view = new AvImageView(this.activity, this);

		view.getLayoutParams().autoFillsHeight = false;
		view.getLayoutParams().autoFillsWidth = false;

		return view;
	}

	protected AvImageView getView() {
	    return (AvImageView) this.getOrCreateView();
    }

	// Handle creation options
	@Override
	public void handleCreationDict(KrollDict properties)
    {
		super.handleCreationDict(properties);
	}
}
