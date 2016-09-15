/**
 * Andrea Vitale
 * https://github.com/AndreaVitale/
 */
package av.imageview;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.common.TiConfig;


@Kroll.module(name="ImageviewAndroid", id="av.imageview")
public class ImageviewAndroidModule extends KrollModule
{
	private static final String LCAT = "ImageviewAndroidModule";
	private static final boolean DBG = TiConfig.LOGD;

	@Kroll.constant
	public static final String CONTENT_MODE_ASPECT_FILL = "centerCrop";

	@Kroll.constant
	public static final String CONTENT_MODE_ASPECT_FIT = "fitCenter";

	public ImageviewAndroidModule()
	{
		super();
	}

	@Kroll.onAppCreate
	public static void onAppCreate(TiApplication app)
	{
		// put module init code that needs to run when the application is created
	}
}
