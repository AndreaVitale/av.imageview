package av.imageview;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.AsyncResult;
import org.appcelerator.kroll.common.TiConfig;
import org.appcelerator.kroll.common.TiMessenger;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.TiBlob;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.view.TiUIView;

import android.app.Activity;
import android.os.Message;


@Kroll.proxy(creatableInModule= ImageViewModule.class, propertyAccessors = { "requestHeaders", "handleCookies", "contentMode", "rounded", "animated", "timeout", "shouldCacheImagesInMemory", "loadingIndicator", "loadingIndicatorColor" })
public class ImageViewProxy extends TiViewProxy  {
	private static final String LCAT = "ImageViewProxy";
	private static final boolean DBG = TiConfig.LOGD;

    private static final int MSG_FIRST_ID = TiViewProxy.MSG_LAST_ID + 1;
    private static final int MSG_SET_IMAGE_AS_URL = MSG_FIRST_ID + 1001;
    private static final int MSG_SET_IMAGE_AS_BLOB = MSG_FIRST_ID + 1002;
    private static final int MSG_SET_IMAGE_AS_EMPTY = MSG_FIRST_ID + 1003;

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

	@Override
    public boolean handleMessage(Message message)
    {
        AsyncResult result;

	    switch (message.what)
        {
            case MSG_SET_IMAGE_AS_URL:
                result = (AsyncResult) message.obj;
                this.getView().setImageAsURL((String) result.getArg());
                result.setResult(null);

                return true;
            case MSG_SET_IMAGE_AS_BLOB:
                result = (AsyncResult) message.obj;
                this.getView().setImageAsBlob((TiBlob) result.getArg());
                result.setResult(null);

                return true;
            case MSG_SET_IMAGE_AS_EMPTY:
                result = (AsyncResult) message.obj;
                this.getView().clearImage();
                result.setResult(null);

                return true;
            default:
                return super.handleMessage(message);
        }
    }

    @Kroll.setProperty
    @Kroll.method
    public void setImage(Object uri) {
        if (uri == null) {
            this.setProperty("image", null);

            if (TiApplication.isUIThread()) {
                this.getView().clearImage();
            } else {
                TiMessenger.sendBlockingMainMessage(this.getMainHandler().obtainMessage(MSG_SET_IMAGE_AS_EMPTY));
            }
        } else if (uri instanceof String) {
            this.setProperty("image", uri.toString());

            if (TiApplication.isUIThread()) {
                this.getView().setImageAsURL(uri.toString());
            } else {
                TiMessenger.sendBlockingMainMessage(this.getMainHandler().obtainMessage(MSG_SET_IMAGE_AS_URL), uri.toString());
            }
        } else {
            this.setProperty("image", TiConvert.toBlob(uri));

            if (TiApplication.isUIThread()) {
                this.getView().setImageAsBlob(TiConvert.toBlob(uri));
            } else {
                TiMessenger.sendBlockingMainMessage(this.getMainHandler().obtainMessage(MSG_SET_IMAGE_AS_BLOB), TiConvert.toBlob(uri));
            }
        }
    }
}
