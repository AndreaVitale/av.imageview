package av.imageview;

import av.imageview.utils.ImageLoader;
import av.imageview.utils.glide.GlideUrlBuilder;
import av.imageview.utils.glide.GlideCircleTransform;
import av.imageview.utils.glide.StreamModelLoaderWrapper;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.res.ResourcesCompat;
import android.view.View;
import android.widget.ImageView;
import android.webkit.MimeTypeMap;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.RelativeLayout.LayoutParams;

import okhttp3.OkHttpClient;

import com.bumptech.glide.Glide;
import com.bumptech.glide.GifRequestBuilder;
import com.bumptech.glide.DrawableRequestBuilder;
import com.bumptech.glide.DrawableTypeRequest;
import com.bumptech.glide.load.engine.DiskCacheStrategy;
import com.bumptech.glide.load.model.GlideUrl;
import com.bumptech.glide.load.resource.drawable.GlideDrawable;
import com.bumptech.glide.load.resource.gif.GifDrawable;
import com.bumptech.glide.request.RequestListener;
import com.bumptech.glide.request.target.Target;
import com.bumptech.glide.request.target.SimpleTarget;
import com.bumptech.glide.integration.okhttp3.OkHttpUrlLoader;
import com.bumptech.glide.load.model.stream.StreamModelLoader;
import com.bumptech.glide.signature.StringSignature;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.KrollPropertyChange;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.TiBlob;
import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.util.TiRHelper;
import org.appcelerator.titanium.util.TiRHelper.ResourceNotFoundException;
import org.appcelerator.titanium.view.TiDrawableReference;
import org.appcelerator.titanium.view.TiUIView;

import java.util.HashMap;
import java.util.List;
import java.util.concurrent.TimeUnit;

import av.imageview.utils.CookiesHelper;
import av.imageview.utils.SSLHelper;
import javax.net.ssl.HostnameVerifier;
import javax.net.ssl.SSLSession;
import javax.net.ssl.X509TrustManager;

public class AVImageView extends TiUIView {
  private static final String LCAT = "AVImageView";

  private TiViewProxy proxy;

  private String source;
  private ImageView imageView;
  private ProgressBar progressBar;
  private RelativeLayout layout;
  private OkHttpClient okHttpClient;

  // Config variables
  private String loadingIndicatorColor;
  private boolean loadingIndicator;
  private boolean memoryCache;
  private boolean roundedImage;
  private String defaultImage;
  private String brokenImage;
  private String contentMode;
  private HashMap requestHeader;
  private boolean handleCookies;
  private boolean dontAnimate;
  private String signature;
  private boolean validatesSecureCertificate;

  private RequestListener<String, GlideDrawable> requestListener;

  public AVImageView(TiViewProxy proxy) {
    super(proxy);

    this.proxy = proxy;

    // Setting up default values
    this.loadingIndicatorColor = null;
    this.loadingIndicator = true;
    this.contentMode = ImageViewModule.CONTENT_MODE_ASPECT_FIT;
    this.memoryCache = true;
    this.dontAnimate = false;
    this.handleCookies = true;
    this.validatesSecureCertificate = true;
    this.signature = "";
    this.okHttpClient = new OkHttpClient
                            .Builder() // default timeouts are 5 seconds
                            .connectTimeout(5, TimeUnit.SECONDS)
                            .readTimeout(5, TimeUnit.SECONDS)
                            .build();

    // Setting up layout and imageview
    layout = new RelativeLayout(this.proxy.getActivity());
    imageView = new ImageView(this.proxy.getActivity());

    layout.setLayoutParams(new RelativeLayout.LayoutParams(
        RelativeLayout.LayoutParams.MATCH_PARENT,
        RelativeLayout.LayoutParams.MATCH_PARENT));
    imageView.setLayoutParams(new RelativeLayout.LayoutParams(
        RelativeLayout.LayoutParams.MATCH_PARENT,
        RelativeLayout.LayoutParams.MATCH_PARENT));

    try {
      progressBar = new ProgressBar(
          this.proxy.getActivity(), null,
          TiRHelper.getAndroidResource("attr.progressBarStyleSmall"));

      progressBar.setProgressDrawable(ContextCompat.getDrawable(
          this.proxy.getActivity().getBaseContext(),
          TiRHelper.getApplicationResource("drawable.circular_progress")));
      progressBar.setVisibility(View.INVISIBLE);

      RelativeLayout.LayoutParams progressBarStyle =
          new RelativeLayout.LayoutParams(
              RelativeLayout.LayoutParams.WRAP_CONTENT,
              RelativeLayout.LayoutParams.WRAP_CONTENT);
      progressBarStyle.addRule(RelativeLayout.CENTER_IN_PARENT,
                               RelativeLayout.TRUE);

      progressBar.setLayoutParams(progressBarStyle);

      layout.addView(imageView);
      layout.addView(progressBar);
    } catch (ResourceNotFoundException exception) {
      layout.addView(imageView);
    }

    setNativeView(layout);
  }

  @Override
  public void processProperties(KrollDict args) {
    super.processProperties(args);

    String[] properties = {"validatesSecureCertificate", // Needs to be at the very begining, at least before request is launched
                           "loadingIndicator",
                           "loadingIndicatorColor",
                           "enableMemoryCache",
                           "contentMode",
                           "defaultImage",
                           "brokenLinkImage",
                           "requestHeader",
                           "rounded",
                           "signature",
                           "dontAnimate",
                           "image"};

    for (String key : properties) {
      if (args.containsKey(key)) {
        this.applyPropertyChanges(key, args.get(key));
      }
    }
  }

  public void applyPropertyChanges(String key, Object value) {
    if (key.equals("loadingIndicator"))
      this.setLoadingIndicator(TiConvert.toBoolean(value));
    if (key.equals("loadingIndicatorColor") && value != null)
      this.setLoadingIndicatorColor(value.toString());
    if (key.equals("enableMemoryCache"))
      this.setMemoryCache(TiConvert.toBoolean(value));
    if (key.equals("contentMode"))
      this.setContentMode(value.toString());
    if (key.equals("defaultImage"))
      this.setDefaultImage(value.toString());
    if (key.equals("brokenLinkImage"))
      this.setBrokenLinkImage(value.toString());
    if (key.equals("requestHeader"))
      this.setRequestHeader((HashMap)value);
    if (key.equals("rounded"))
      this.setRoundedImage(TiConvert.toBoolean(value));
    if (key.equals("dontAnimate"))
      this.setDontAnimate(TiConvert.toBoolean(value));
    if (key.equals("signature"))
      this.setSignature(value.toString());
    if (key.equals("image")) {
      Object uri = value;

      if (uri instanceof String) {
        this.setSource(value.toString());
      } else {
        this.setBlob(TiConvert.toBlob(uri));
      }
    }
    if (key.equals("timeout")) {
      okhttp3.OkHttpClient.Builder builder = new OkHttpClient.Builder()
      .connectTimeout(TiConvert.toInt(value), TimeUnit.MILLISECONDS)
      .readTimeout(TiConvert.toInt(value), TimeUnit.MILLISECONDS);
			if(!this.validatesSecureCertificate)
			{
				Log.d(LCAT, "Not validating SSL");
				builder.sslSocketFactory(SSLHelper.trustAllSslSocketFactory, (X509TrustManager)SSLHelper.trustAllCerts[0]);
		    builder.hostnameVerifier(new HostnameVerifier() {
		      @Override
		      public boolean verify(String hostname, SSLSession session) {
		        return true;
		      }
		    });
			}

			this.okHttpClient = builder.build();
    }
    if (key.equals("handleCookies"))
      this.setHandleCookies(TiConvert.toBoolean(value));
    if (key.equals("validatesSecureCertificate"))
      this.setValidatesSecureCertificate(TiConvert.toBoolean(value));
  }

  @Override
  public void propertyChanged(String key, Object oldValue, Object newValue,
                              KrollProxy proxy) {
    super.propertyChanged(key, oldValue, newValue, proxy);

    this.applyPropertyChanges(key, newValue);
  }

  @Override
  public void propertiesChanged(List<KrollPropertyChange> changes,
                                KrollProxy proxy) {
    for (KrollPropertyChange change : changes) {
      propertyChanged(change.getName(), change.getOldValue(),
                      change.getNewValue(), proxy);
    }
  }

  public void setSource(String url) {
    this.source = sanitizeUrl(url);

    // If it is correctly set I'll display the image
    if (this.source != null && this.source != "") {
      this.setImage(this.source);
    } else {
      this.imageView.setImageBitmap(null);
    }
  }

  public void setImage(String image) {

    Glide.clear(this.imageView);
    if (image == null || image == "") {
      // clear image
      this.imageView.setImageBitmap(null);
      return;
    }

    if (TiApplication.isUIThread())
      startRequest(image, this.loadingIndicator);
    else
      this.proxy.getActivity().runOnUiThread(
          new ImageLoader(this, this.source));
  }

  public void setBlob(TiBlob blob) {
    if (TiApplication.isUIThread())
      this.displayBlob(blob);
    else
      this.proxy.getActivity().runOnUiThread(new ImageLoader(this, blob));
  }

  public void displayBlob(TiBlob blob) {
    TiDrawableReference drawableReference =
        TiDrawableReference.fromBlob(this.proxy.getActivity(), blob);

    this.imageView.setScaleType(
        (this.contentMode != null &&
         this.contentMode.equals(ImageViewModule.CONTENT_MODE_ASPECT_FILL))
            ? ImageView.ScaleType.CENTER_CROP
            : ImageView.ScaleType.FIT_CENTER);
    this.imageView.setImageBitmap(drawableReference.getBitmap());

    drawableReference = null;
    blob = null;
  }

  public void startRequest(String url, Boolean loadingIndicator) {
    RequestListenerBuilder requestListenerBuilder =
        new RequestListenerBuilder();

    DrawableTypeRequest drawableRequest;
    DrawableRequestBuilder drawableRequestBuilder;
    GifRequestBuilder gifRequestBuilder;

    Drawable defaultImageDrawable =
        (this.defaultImage != null)
            ? TiDrawableReference.fromUrl(proxy, this.defaultImage)
                  .getDrawable()
            : null;
    Drawable brokenLinkImageDrawable =
        (this.brokenImage != null)
            ? TiDrawableReference.fromUrl(proxy, this.brokenImage).getDrawable()
            : null;

    if (this.loadingIndicator) {

      // if user provide loading indicator color
      if (this.loadingIndicatorColor != null) // update the spinner color
        this.progressBar.getIndeterminateDrawable().setColorFilter(
            TiConvert.toColor(this.loadingIndicatorColor),
            android.graphics.PorterDuff.Mode.MULTIPLY);

      this.progressBar.setVisibility(View.VISIBLE);
    }

    // Switching between local and remote url
    if (url.startsWith("file://"))
      drawableRequest =
          Glide.with(this.proxy.getActivity().getBaseContext()).load(url);
    else {
      if (this.handleCookies) {
        String cookiesString = CookiesHelper.getCookiesStringForURL(url);
        if (cookiesString != null && cookiesString.length() > 0) {
          if (this.requestHeader == null) {
            this.requestHeader = new HashMap();
          }
          this.requestHeader.put("Cookie", cookiesString);
        }
      }
      drawableRequest =
          Glide.with(this.proxy.getActivity().getBaseContext())
              .using(new StreamModelLoaderWrapper<GlideUrl>(
                  new OkHttpUrlLoader(okHttpClient)))
              .load(GlideUrlBuilder.build(url, this.requestHeader));
    }

    // Handling GIF
    if (this.getMimeType(url) != null && this.getMimeType(url) == "image/gif") {
      gifRequestBuilder =
          drawableRequest.asGif()
              .skipMemoryCache(this.memoryCache)
              .signature(new StringSignature(this.signature))
              .diskCacheStrategy(DiskCacheStrategy.SOURCE)
              .placeholder(defaultImageDrawable)
              .error(brokenLinkImageDrawable)
              .listener(requestListenerBuilder.createListener(url));

      if (this.roundedImage) {
        if (this.dontAnimate) {
          gifRequestBuilder
              .transform(new GlideCircleTransform(
                  this.proxy.getActivity().getBaseContext()))
              .dontAnimate()
              .into(this.imageView);
        } else {
          gifRequestBuilder
              .transform(new GlideCircleTransform(
                  this.proxy.getActivity().getBaseContext()))
              .into(this.imageView);
        }
      } else {
        if (this.contentMode == null ||
            this.contentMode.equals(ImageViewModule.CONTENT_MODE_ASPECT_FIT)) {
          if (this.dontAnimate) {
            gifRequestBuilder.fitCenter().dontAnimate().into(this.imageView);
          } else {
            gifRequestBuilder.fitCenter().into(this.imageView);
          }
        } else {
          if (this.dontAnimate) {
            gifRequestBuilder.centerCrop().dontAnimate().into(this.imageView);
          } else {
            gifRequestBuilder.centerCrop().into(this.imageView);
          }
        }
      }
    }
    // Handling simple images
    else {
      drawableRequestBuilder =
          drawableRequest.skipMemoryCache(this.memoryCache)
              .placeholder(defaultImageDrawable)
              .error(brokenLinkImageDrawable)
              .signature(new StringSignature(this.signature))
              .listener(requestListenerBuilder.createListener(url));

      if (this.roundedImage) {
        if (this.dontAnimate) {
          drawableRequestBuilder
              .transform(new GlideCircleTransform(
                  this.proxy.getActivity().getBaseContext()))
              .dontAnimate()
              .into(this.imageView);
        } else {
          drawableRequestBuilder
              .transform(new GlideCircleTransform(
                  this.proxy.getActivity().getBaseContext()))
              .into(this.imageView);
        }
      } else {
        if (this.contentMode == null ||
            this.contentMode.equals(ImageViewModule.CONTENT_MODE_ASPECT_FIT)) {
          if (this.dontAnimate) {
            drawableRequestBuilder.fitCenter().dontAnimate().into(
                this.imageView);
          } else {
            drawableRequestBuilder.fitCenter().into(this.imageView);
          }
        } else {
          if (this.dontAnimate) {
            drawableRequestBuilder.centerCrop().dontAnimate().into(
                this.imageView);
          } else {
            drawableRequestBuilder.centerCrop().into(this.imageView);
          }
        }
      }
    }
  }

  public void setTimeout(int timeout) {
    okhttp3.OkHttpClient.Builder builder = new OkHttpClient.Builder()
    .connectTimeout(TiConvert.toInt(timeout), TimeUnit.MILLISECONDS)
    .readTimeout(TiConvert.toInt(timeout), TimeUnit.MILLISECONDS);
    if(!this.validatesSecureCertificate)
    {
      builder.sslSocketFactory(SSLHelper.trustAllSslSocketFactory, (X509TrustManager)SSLHelper.trustAllCerts[0]);
      builder.hostnameVerifier(new HostnameVerifier() {
        @Override
        public boolean verify(String hostname, SSLSession session) {
          return true;
        }
      });
    }
    this.okHttpClient = builder.build();
  }

  private String sanitizeUrl(String url) {
    if (url == null || !(url instanceof String))
      return null;

    return (url.toString().startsWith("http") ||
            url.toString().startsWith("ftp"))
        ? url.toString()
        : this.proxy.resolveUrl(null, url.toString());
  }

  private String getMimeType(String url) {
    String type = null;
    String extension = MimeTypeMap.getFileExtensionFromUrl(url);

    if (extension != null)
      type = MimeTypeMap.getSingleton().getMimeTypeFromExtension(extension);

    return type;
  }

  private boolean handleException(Exception e) {
    Log.w(LCAT, source + ": resource not loaded.");
    Log.w(LCAT,
          (e != null) ? e.getMessage() : "No detailed message available.");

    if (progressBar.getVisibility() == View.VISIBLE)
      progressBar.setVisibility(View.INVISIBLE);

    if (proxy.hasListeners("error")) {
      KrollDict payload = new KrollDict();

      payload.put("image", source);
      payload.put("reason", e.getMessage());

      proxy.fireEvent("error", payload);
    }

    return false;
  }

  private boolean handleResourceReady() {
    if (progressBar.getVisibility() == View.VISIBLE)
      progressBar.setVisibility(View.INVISIBLE);

    if (proxy.hasListeners("load")) {
      KrollDict payload = new KrollDict();

      payload.put("image", source);

      proxy.fireEvent("load", payload);
    }

    return false;
  }

  @Override
  public void release() {
    super.release();
  }

  // Config stuff
  synchronized public String getImage() { return this.source; }

  synchronized public void setLoadingIndicatorColor(String color) {
    this.loadingIndicatorColor = color;
  }

  synchronized public void setLoadingIndicator(boolean enabled) {
    this.loadingIndicator = enabled;
  }

  synchronized public void setMemoryCache(boolean enabled) {
    this.memoryCache = enabled;
  }

  synchronized public void setSignature(String str) { this.signature = str; }

  synchronized public void setContentMode(String contentMode) {
    this.contentMode = contentMode;
  }

  synchronized public void setBrokenLinkImage(String url) {
    this.brokenImage = url;
  }

  synchronized public void setDefaultImage(String url) {
    this.defaultImage = url;
  }

  synchronized public void setRoundedImage(boolean enabled) {
    this.roundedImage = enabled;
  }
  synchronized public void setDontAnimate(boolean enabled) {
    this.dontAnimate = enabled;
  }

  synchronized public void setRequestHeader(HashMap headers) {
    this.requestHeader = headers;
  }

  synchronized public boolean getLoadingIndicator() {
    return this.loadingIndicator;
  }

  synchronized public String getLoadingIndicatorColor() {
    return this.loadingIndicatorColor;
  }

  synchronized public boolean getMemoryCache() { return this.memoryCache; }

  synchronized public String getSignature() { return this.signature; }

  synchronized public String getContentMode() { return this.contentMode; }

  synchronized public String getBrokenLinkImage() { return this.brokenImage; }

  synchronized public String getDefaultImage() { return this.defaultImage; }

  synchronized public boolean getRoundedImage() { return this.roundedImage; }

  synchronized public boolean getDontAnimate() { return this.dontAnimate; }

  synchronized public HashMap getRequestHeader() { return this.requestHeader; }

  synchronized public void setHandleCookies(boolean handleCookies) {
    this.handleCookies = handleCookies;
  }

  synchronized public boolean getHandleCookies() { return this.handleCookies; }

  synchronized public void setValidatesSecureCertificate(boolean validatesSecureCertificate) {
    if(this.validatesSecureCertificate == validatesSecureCertificate)
    {
      return; // Nothing to do
    }

    if(this.okHttpClient != null)
    {
      if(validatesSecureCertificate)
      { // Recreate a standard OkHttpClient with pre-set timeouts
        this.okHttpClient = new OkHttpClient.Builder()
        .connectTimeout(this.okHttpClient.connectTimeoutMillis(), TimeUnit.MILLISECONDS)
        .readTimeout(this.okHttpClient.readTimeoutMillis(), TimeUnit.MILLISECONDS)
        .build();
      }
      else
      { // Clone existing OkHttpClient with alltrustedcertificates
        this.okHttpClient = SSLHelper.trustAllSslClient(this.okHttpClient);
      }
    }
    else
    {
      if(validatesSecureCertificate)
      {
        this.okHttpClient = new OkHttpClient.Builder() // default timeouts are 5 seconds
        .connectTimeout(5, TimeUnit.SECONDS)
        .readTimeout(5, TimeUnit.SECONDS)
        .build();
      }
      else
      {
        this.okHttpClient = new OkHttpClient.Builder() // default timeouts are 5 seconds
        .connectTimeout(5, TimeUnit.SECONDS)
        .readTimeout(5, TimeUnit.SECONDS)
        .sslSocketFactory(SSLHelper.trustAllSslSocketFactory, (X509TrustManager)SSLHelper.trustAllCerts[0])
        .hostnameVerifier(new HostnameVerifier() {
          @Override
          public boolean verify(String hostname, SSLSession session) {
            return true;
          }
        })
        .build();
      }
    }
    this.validatesSecureCertificate = validatesSecureCertificate;
	}

	synchronized public boolean getValidatesSecureCertificate() {
			return this.validatesSecureCertificate;
	}

  // Utility to create a specific request listener
  private class RequestListenerBuilder {
    private String LCAT = "RequestListenerBuilder";

    public RequestListener createListener(String url) {
      if (url == null)
        return null;

      if (getMimeType(url) == "image/gif") {
        if (url.startsWith("file://"))
          return new RequestListener<String, GifDrawable>() {
            @Override
            public boolean onException(Exception e, String model,
                                       Target<GifDrawable> target,
                                       boolean isFirstResource) {
              return handleException(e);
            }

            @Override
            public boolean onResourceReady(
                GifDrawable resource, String model, Target<GifDrawable> target,
                boolean isFromMemoryCache, boolean isFirstResource) {
              return handleResourceReady();
            }
          };

        return new RequestListener<GlideUrl, GifDrawable>() {
          @Override
          public boolean onException(Exception e, GlideUrl model,
                                     Target<GifDrawable> target,
                                     boolean isFirstResource) {
            return handleException(e);
          }

          @Override
          public boolean onResourceReady(
              GifDrawable resource, GlideUrl model, Target<GifDrawable> target,
              boolean isFromMemoryCache, boolean isFirstResource) {
            return handleResourceReady();
          }
        };
      }

      if (url.startsWith("file://"))
        return new RequestListener<String, GlideDrawable>() {
          @Override
          public boolean onException(Exception e, String model,
                                     Target<GlideDrawable> target,
                                     boolean isFirstResource) {
            return handleException(e);
          }

          @Override
          public boolean onResourceReady(GlideDrawable resource, String model,
                                         Target<GlideDrawable> target,
                                         boolean isFromMemoryCache,
                                         boolean isFirstResource) {
            return handleResourceReady();
          }
        };

      return new RequestListener<GlideUrl, GlideDrawable>() {
        @Override
        public boolean onException(Exception e, GlideUrl model,
                                   Target<GlideDrawable> target,
                                   boolean isFirstResource) {
          handleException(e);

          return false;
        }

        @Override
        public boolean onResourceReady(GlideDrawable resource, GlideUrl model,
                                       Target<GlideDrawable> target,
                                       boolean isFromMemoryCache,
                                       boolean isFirstResource) {
          handleResourceReady();

          return false;
        }
      };
    }
  }
}
