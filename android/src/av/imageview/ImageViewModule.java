package av.imageview;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;

import org.appcelerator.titanium.TiApplication;
import org.appcelerator.kroll.common.TiConfig;

@Kroll.module(name="AvImageviewNew", id="av.imageview")
public class ImageViewModule extends KrollModule
{
	private static final String LCAT = "ImageViewModule";
	private static final boolean DBG = TiConfig.LOGD;

	@Kroll.constant
	public static final String CONTENT_MODE_ASPECT_FILL = ImageViewConstants.CONTENT_MODE_ASPECT_FILL;

	@Kroll.constant
	public static final String CONTENT_MODE_ASPECT_FIT = ImageViewConstants.CONTENT_MODE_ASPECT_FIT;

	public ImageViewModule()
	{
		super();
	}

	@Kroll.onAppCreate
	public static void onAppCreate(TiApplication app)
	{

	}
}

