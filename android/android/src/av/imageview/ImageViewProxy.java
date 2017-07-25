/**
 * Andrea Vitale
 * https://github.com/AndreaVitale/
 */
package av.imageview;

import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.TiConfig;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.TiBlob;
import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiUIView;

import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

import android.app.Activity;

@Kroll.proxy(creatableInModule=ImageViewModule.class, propertyAccessors = {
	"image","scaleType","defaultImage","brokenLinkImage","loadingIndicator","enableMemoryCache",
	"rounded","requestHeader"
})
public class ImageViewProxy extends TiViewProxy
{
	// Standard Debugging variables
	private static final String LCAT = "AVImageViewProxy";
	private static final boolean DBG = TiConfig.LOGD;

	private Activity activity;

	// Constructor
	public ImageViewProxy() {
		super();

		activity = TiApplication.getInstance().getCurrentActivity();
	}

	@Override
	public TiUIView createView(Activity activity) {
		TiUIView view = new AVImageView(this);

		view.getLayoutParams().autoFillsHeight = true;
		view.getLayoutParams().autoFillsWidth = true;

		return view;
	}

	protected AVImageView getView() {
		return (AVImageView)getOrCreateView();
	}
}
