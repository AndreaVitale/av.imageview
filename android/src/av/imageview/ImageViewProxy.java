/**
 * Andrea Vitale
 * https://github.com/AndreaVitale/
 */
package av.imageview;

import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.common.TiMessenger;
import org.appcelerator.kroll.common.AsyncResult;
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
import android.os.Handler;
import android.os.Message;

@Kroll.
proxy(creatableInModule = ImageViewModule.class,
      propertyAccessors = {"defaultImage", "brokenLinkImage", "image",
                           "contentMode", "enableMemoryCache", "signature",
                           "loadingIndicator", "rounded", "requestHeader",
                           "handleCookies", "dontAnimate", "validatesSecureCertificate"})
public class ImageViewProxy extends TiViewProxy {
  // Standard Debugging variables
  private static final String LCAT = "AVImageViewProxy";
  private static final boolean DBG = TiConfig.LOGD;

  private static final int MSG_FIRST_ID = TiViewProxy.MSG_LAST_ID + 1;
  private static final int MSG_SET_IMAGE_URL = MSG_FIRST_ID + 1001;
  private static final int MSG_SET_IMAGE_BLOB = MSG_FIRST_ID + 1002;
  private static final int MSG_SET_DEFAULT_IMAGE = MSG_FIRST_ID + 1003;
  private static final int MSG_SET_BROKEN_IMAGE = MSG_FIRST_ID + 1004;
  private static final int MSG_SET_CONTENT_MODE = MSG_FIRST_ID + 1005;
  private static final int MSG_SET_REQUEST_HEADER = MSG_FIRST_ID + 1006;
  private static final int MSG_SET_TIMEOUT = MSG_FIRST_ID + 1007;

  private Activity activity;

  // Constructor
  public ImageViewProxy() {
    super();

    activity = TiApplication.getInstance().getCurrentActivity();
  }

  @Override
  public TiUIView createView(Activity activity) {
    view = new AVImageView(this);

    view.getLayoutParams().autoFillsHeight = true;
    view.getLayoutParams().autoFillsWidth = true;

    return view;
  }

  protected AVImageView getView() { return (AVImageView)getOrCreateView(); }

  @Override
  public boolean handleMessage(Message message) {
    AsyncResult result = null;

    switch (message.what) {
    case MSG_SET_IMAGE_URL:
      result = (AsyncResult)message.obj;
      getView().setSource((String)result.getArg());
      result.setResult(null);

      return true;
    case MSG_SET_IMAGE_BLOB:
      result = (AsyncResult)message.obj;
      getView().setBlob((TiBlob)result.getArg());
      result.setResult(null);

      return true;
    case MSG_SET_CONTENT_MODE:
      result = (AsyncResult)message.obj;
      getView().setContentMode((String)result.getArg());
      result.setResult(null);

      return true;
    case MSG_SET_DEFAULT_IMAGE:
      result = (AsyncResult)message.obj;
      getView().setDefaultImage((String)result.getArg());
      result.setResult(null);

      return true;
    case MSG_SET_BROKEN_IMAGE:
      result = (AsyncResult)message.obj;
      getView().setBrokenLinkImage((String)result.getArg());
      result.setResult(null);

      return true;
    case MSG_SET_REQUEST_HEADER:
      result = (AsyncResult)message.obj;
      getView().setRequestHeader((HashMap)result.getArg());
      result.setResult(null);

      return true;
    case MSG_SET_TIMEOUT:
      int timeout = message.arg1;
      getView().setTimeout(timeout);
      result.setResult(null);

      return true;
    default:
      return super.handleMessage(message);
    }
  }

  // Public APIs
  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public String getImage() {
    // clang-format on
    return getView().getImage();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setImage(final Object uri) {
    // clang-format on
    if (TiApplication.isUIThread()) {

      if (uri == null) {
        getView().setSource(null);
      } else if (uri instanceof String) {
        getView().setSource(uri.toString());
      } else {
        getView().setBlob((TiBlob)uri);
      }
    } else {
      if (uri == null) {
        TiMessenger.sendBlockingMainMessage(
            getMainHandler().obtainMessage(MSG_SET_IMAGE_URL), "");
      } else if (uri instanceof String) {
        TiMessenger.sendBlockingMainMessage(
            getMainHandler().obtainMessage(MSG_SET_IMAGE_URL), uri.toString());
      } else {
        TiMessenger.sendBlockingMainMessage(
            getMainHandler().obtainMessage(MSG_SET_IMAGE_BLOB), (TiBlob)uri);
      }
    }
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public String getContentMode() {
    // clang-format on
    return getView().getContentMode();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setContentMode(String contentMode) {
    // clang-format on
    if (TiApplication.isUIThread()) {
      getView().setContentMode(contentMode);
    } else {
      TiMessenger.sendBlockingMainMessage(
          getMainHandler().obtainMessage(MSG_SET_CONTENT_MODE), contentMode);
    }
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public boolean getDontAnimate() {
    // clang-format on
    return getView().getDontAnimate();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setDontAnimate(boolean enabled) {
    // clang-format on
    getView().setDontAnimate(enabled);
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setSignature(String str) {
    // clang-format on
    getView().setSignature(str);
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public boolean getRounded() {
    // clang-format on
    return getView().getRoundedImage();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setRounded(boolean enabled) {
    // clang-format on
    getView().setRoundedImage(enabled);
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public String getDefaultImage() {
    // clang-format on
    return getView().getDefaultImage();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setDefaultImage(String defaultImage) {
    // clang-format on
    if (TiApplication.isUIThread()) {
      getView().setDefaultImage(defaultImage);
    } else {
      TiMessenger.sendBlockingMainMessage(
          getMainHandler().obtainMessage(MSG_SET_DEFAULT_IMAGE), defaultImage);
    }
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public String getBrokenLinkImage() {
    // clang-format on
    return getView().getBrokenLinkImage();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setBrokenLinkImage(String brokenLinkImage) {
    // clang-format on
    if (TiApplication.isUIThread()) {
      getView().setBrokenLinkImage(brokenLinkImage);
    } else {
      TiMessenger.sendBlockingMainMessage(
          getMainHandler().obtainMessage(MSG_SET_BROKEN_IMAGE),
          brokenLinkImage);
    }
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public Boolean getLoadingIndicator() {
    // clang-format on
    return getView().getLoadingIndicator();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setLoadingIndicator(Boolean enabled) {
    // clang-format on
    getView().setLoadingIndicator(enabled);
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public String getLoadingIndicatorColor() {
    // clang-format on
    return getView().getLoadingIndicatorColor();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setLoadingIndicatorColor(String color) {
    // clang-format on
    getView().setLoadingIndicatorColor(color);
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public Boolean getMemoryCacheEnabled() {
    // clang-format on
    return getView().getMemoryCache();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setMemoryCacheEnabled(Boolean enabled) {
    // clang-format on
    getView().setMemoryCache(enabled);
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setRequestHeader(HashMap requestHeader) {
    // clang-format on
    if (TiApplication.isUIThread()) {
      getView().setRequestHeader(requestHeader);
    } else {
      TiMessenger.sendBlockingMainMessage(
          getMainHandler().obtainMessage(MSG_SET_REQUEST_HEADER),
          requestHeader);
    }
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setTimeout(int timeout) {
    // clang-format on
    getView().setTimeout(timeout);
  }

  // clang-format off
  @Kroll.getProperty
  @Kroll.method
  public Boolean getHandleCookies() {
    // clang-format on
    return getView().getHandleCookies();
  }

  // clang-format off
  @Kroll.setProperty
  @Kroll.method
  public void setHandleCookies(Boolean handleCookies) {
    // clang-format on
    getView().setHandleCookies(handleCookies);
  }

  @Kroll.getProperty
	@Kroll.method
	public Boolean getValidatesSecureCertificate() {
		return getView().getValidatesSecureCertificate();
	}

	@Kroll.setProperty
	@Kroll.method
	public void setValidatesSecureCertificate(Boolean validatesSecureCertificate) {
		getView().setValidatesSecureCertificate(validatesSecureCertificate);
	}
}
