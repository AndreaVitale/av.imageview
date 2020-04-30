package av.imageview.utils;

import java.util.ArrayList;
import java.util.List;
import java.net.URL;
import java.net.HttpCookie;

import ti.modules.titanium.network.NetworkModule;
import org.appcelerator.kroll.common.Log;
/**
 * This class is a helper for HTTPCookies handling. It uses Titanium's Cookie Manager
 * to get all stored cookies and then iterates over it to get cookies matching
 * domain and path.
 * TODO: check expiration date
 */
public class CookiesHelper
{
    private static final String LCAT = "AVImageView";

    public static String getCookiesStringForURL(String urlString)
    {
        try
        {
            StringBuilder cookieStringBuffer = new StringBuilder();
            HttpCookie[] urlCookies = getHTTPCookiesForURL(urlString);

            if(urlCookies != null)
            {
                for(int i=0;i<urlCookies.length;i++)
                {
                    cookieStringBuffer.append(urlCookies[i].getName());
                    cookieStringBuffer.append("=");
                    cookieStringBuffer.append(urlCookies[i].getValue());
                    if(i+1 < urlCookies.length)
                    {
                        cookieStringBuffer.append("; ");
                    }
                }
                return cookieStringBuffer.toString();
            }
            else
            {
                if (Log.isDebugModeEnabled()) {
                    Log.d(LCAT, "No cookie found for " + urlString);
                }
                return null;
            }
        }
        catch(Exception ex)
        {
            Log.w(LCAT, "Exception getting cookies for URL " + urlString + "\n" + ex.getStackTrace());
            return null;
        }
    }

    private static HttpCookie[] getHTTPCookiesForURL(String urlString) throws Exception
    {
        URL url = new URL(urlString);
        String domain = url.getHost();
        String path = url.getPath();

        if (Log.isDebugModeEnabled()) {
            Log.d(LCAT, "Getting HTTP Cookies for " + domain);
        }

        if (domain == null || domain.length() == 0) {
            if (Log.isDebugModeEnabled()) {
                Log.e(LCAT, "Unable to get the HTTP cookies. Need to provide a valid domain.");
            }
            return null;
        }
        ArrayList<HttpCookie> cookieList = new ArrayList<HttpCookie>();
        List<HttpCookie> cookies = NetworkModule.getCookieManagerInstance().getCookieStore().getCookies();
        for (HttpCookie cookie : cookies) {
            String cookieDomain = cookie.getDomain();
            String cookiePath = cookie.getPath();
            if (domainMatch(cookieDomain, domain) && pathMatch(cookiePath, path)) {
                Log.d(LCAT, "Found cookie " + cookie.getName());
                cookieList.add(cookie);
            }
        }
        if (!cookieList.isEmpty()) {
            return cookieList.toArray(new HttpCookie[cookieList.size()]);
        }
        return null;
    }

    /**
     * Helper method to decide whether the domain matches the cookie's domain. If the both domains are null, return true.
     * The domain matching follows RFC6265 (http://tools.ietf.org/html/rfc6265#section-5.1.3).
     * This method is copied by phobeous from Titanium SDK (ti.modules.titanium.network.NetworkModule.java)
     * @param cookieDomain cookie's domain
     * @param domain domain to match
     * @return true if the domain matches cookieDomain; false otherwise. If the both domains are null, return true.
     */
    private static boolean domainMatch(String cookieDomain, String domain)
    {
        if (cookieDomain == null && domain == null) {
            return true;
        }
        if (cookieDomain == null || domain == null) {
            return false;
        }

        String lower_cookieDomain = cookieDomain.toLowerCase();
        String lower_domain = domain.toLowerCase();
        if (lower_cookieDomain.startsWith(".")) {
            if (lower_domain.endsWith(lower_cookieDomain.substring(1))) {
                int cookieLen = lower_cookieDomain.length();
                int domainLen = lower_domain.length();
                if (domainLen > cookieLen -1) {
                    // make sure bar.com doesn't match .ar.com
                    return lower_domain.charAt(domainLen - cookieLen) == '.';
                }
                return true;
            }
            return false;
        } else {
            return lower_domain.equals(lower_cookieDomain);
        }
    }

    // Method grabbed from
    // http://www.hccp.org/java-net-cookie-how-to.html
    private static boolean pathMatch(String cookiePath, String path) {
        if(cookiePath == null) {
            return true;
        } else if (cookiePath.equals("/")) {
            return true;
        } else if (path.regionMatches(0, cookiePath, 0, cookiePath.length())) {
            return true;
        } else {
            return false;
        }
    }
}
