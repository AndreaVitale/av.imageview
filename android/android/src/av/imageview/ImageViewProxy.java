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

import android.app.Activity;

@Kroll.proxy(creatableInModule=ImageviewAndroidModule.class)
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
		TiUIView view = new ExtendedImageView(this);

		view.getLayoutParams().autoFillsHeight = true;
		view.getLayoutParams().autoFillsWidth = true;

		return view;
	}

	// Handle creation options
	@Override
	public void handleCreationDict(KrollDict options) {
		super.handleCreationDict(options);

		if (options.containsKey("scaleType"))
			this.setContentMode(options.getString("scaleType"));
		if (options.containsKey("defaultImage"))
			this.setDefaultImage(options.getString("defaultImage"));
		if (options.containsKey("brokenLinkImage"))
			this.setBrokenLinkImage(options.getString("brokenLinkImage"));
		if (options.containsKey("loadingIndicator"))
			this.setLoadingIndicator(options.getBoolean("loadingIndicator"));
		if (options.containsKey("enableMemoryCache"))
			this.setMemoryCacheEnabled(options.getBoolean("enableMemoryCache"));
		if (options.containsKey("image"))
			this.setImage(options.getString("image"));
	}

	protected ExtendedImageView getView() {
		return (ExtendedImageView)getOrCreateView();
	}

	// Public API
	@Kroll.getProperty
	@Kroll.method
	public String getImage() {
		return getView().getImage();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setImage(Object uri) {
		if (uri instanceof String)
			getView().setSource(uri.toString());
		else
			getView().setBlob((TiBlob) uri);
	}

	@Kroll.getProperty
	@Kroll.method
	public String getContentMode() {
        return getView().getContentMode();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setContentMode(String contentMode) {
	    getView().setContentMode(contentMode);
	}

	@Kroll.getProperty
	@Kroll.method
	public String getDefaultImage() {
        return getView().getDefaultImage();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setDefaultImage(String defaultImage) {
	    getView().setDefaultImage(defaultImage);
	}

	@Kroll.getProperty
	@Kroll.method
	public String getBrokenLinkImage() {
        return getView().getBrokenLinkImage();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setBrokenLinkImage(String brokenLinkImage) {
	    getView().setBrokenLinkImage(brokenLinkImage);
	}

	@Kroll.getProperty
	@Kroll.method
	public Boolean getLoadingIndicator() {
	    return getView().getLoadingIndicator();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setLoadingIndicator(Boolean enabled) {
	    getView().setLoadingIndicator(enabled);
	}

	@Kroll.getProperty
	@Kroll.method
	public Boolean getMemoryCacheEnabled() {
		return getView().getMemoryCache();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setMemoryCacheEnabled(Boolean enabled) {
		getView().setMemoryCache(enabled);
	}
}
