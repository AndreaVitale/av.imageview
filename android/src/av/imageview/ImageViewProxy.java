package av.imageview;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.AsyncResult;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.common.TiConfig;
import org.appcelerator.kroll.common.TiMessenger;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiUIView;

import android.app.Activity;
import android.content.Context;
import android.os.Message;

import ti.modules.titanium.gesture.TiDeviceOrientationMonitor;


@Kroll.proxy(creatableInModule= ImageViewModule.class, propertyAccessors = { "requestHeaders", "handleCookies", "contentMode" })
public class ImageViewProxy extends TiViewProxy  {
	private static final String LCAT = "ImageViewProxy";
	private static final boolean DBG = TiConfig.LOGD;

    private static final int MSG_FIRST_ID = TiViewProxy.MSG_LAST_ID + 1;
    private static final int MSG_SET_IMAGE_AS_URL = MSG_FIRST_ID + 1001;

    private Context context;
    private TiDeviceOrientationMonitor orientationMonitor;

	@Override
	public TiUIView createView(Activity activity) {
	    this.context = activity;

		TiUIView view = new AvImageView(this.context, this);

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
            default:
                return super.handleMessage(message);
        }
    }

    @Kroll.setProperty
    @Kroll.method
    public void setImage(final Object uri) {
        if (uri instanceof String) {
            this.setProperty("image", uri);

            if (TiApplication.isUIThread()) {
                this.getView().setImageAsURL(uri.toString());
            } else {
                TiMessenger.sendBlockingMainMessage(this.getMainHandler().obtainMessage(MSG_SET_IMAGE_AS_URL), uri.toString());
            }
        }
    }
}
