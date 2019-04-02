package av.imageview.utils;

import android.content.Context;
import android.util.Log;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;

import org.appcelerator.titanium.util.TiConvert;
import org.appcelerator.titanium.util.TiRHelper;

public class ProgressIndicator extends ProgressBar {
    private static final String LCAT = "ProgressIndicator";

    public ProgressIndicator(Context context) {
        super(context);

        RelativeLayout.LayoutParams progresBarParams = new RelativeLayout.LayoutParams(
                RelativeLayout.LayoutParams.WRAP_CONTENT,
                RelativeLayout.LayoutParams.WRAP_CONTENT);

        progresBarParams.addRule(RelativeLayout.CENTER_IN_PARENT, RelativeLayout.TRUE);

        this.setScrollBarStyle(this.getStyleAttr());
        this.setVisibility(View.INVISIBLE);
        this.setLayoutParams(progresBarParams);
    }

    public void setColor(String color) {
        this.getIndeterminateDrawable().setColorFilter(
                TiConvert.toColor(color),
                android.graphics.PorterDuff.Mode.MULTIPLY
        );
    }

    private int getStyleAttr() {
        int defStyleAttr = 0;

        try {
            defStyleAttr = TiRHelper.getAndroidResource("attr.progressBarStyleSmall");
        } catch (TiRHelper.ResourceNotFoundException exception) {
            Log.e(LCAT, exception.getLocalizedMessage());
        }

        return defStyleAttr;
    }
}
