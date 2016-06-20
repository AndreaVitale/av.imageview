/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /private/var/folders/hf/x65vzkh94mn_q1j1fzjyxsf40000gn/T/Andrea/av.imageview-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/hf/x65vzkh94mn_q1j1fzjyxsf40000gn/T/Andrea/av.imageview-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "av.imageview.ImageviewAndroidModule.h"
#include "av.imageview.ImageViewProxy.h"


#line 14 "/private/var/folders/hf/x65vzkh94mn_q1j1fzjyxsf40000gn/T/Andrea/av.imageview-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 9, duplicates = 0 */

class ImageviewAndroidBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
ImageviewAndroidBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
ImageviewAndroidBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 27,
      MAX_WORD_LENGTH = 35,
      MIN_HASH_VALUE = 27,
      MAX_HASH_VALUE = 35
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 17 "/private/var/folders/hf/x65vzkh94mn_q1j1fzjyxsf40000gn/T/Andrea/av.imageview-generated/KrollGeneratedBindings.gperf"
      {"av.imageview.ImageViewProxy", ::av::imageview::imageviewandroid::ImageViewProxy::bindProxy, ::av::imageview::imageviewandroid::ImageViewProxy::dispose},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 16 "/private/var/folders/hf/x65vzkh94mn_q1j1fzjyxsf40000gn/T/Andrea/av.imageview-generated/KrollGeneratedBindings.gperf"
      {"av.imageview.ImageviewAndroidModule", ::av::imageview::ImageviewAndroidModule::bindProxy, ::av::imageview::ImageviewAndroidModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 18 "/private/var/folders/hf/x65vzkh94mn_q1j1fzjyxsf40000gn/T/Andrea/av.imageview-generated/KrollGeneratedBindings.gperf"

