/*
myWiFi.h

Separating WiFi SSID and password out to allow config.h to be committed to
a Git repo without storing secrets.

Need to add an include at the top of config.h:

#if __has_include ( "myWifi.h" )
  #include "myWiFi.h"
#else
  #include "myWiFiExample.h"
#endif
*/

#define WIFI_HOSTNAME "dccex"
#define WIFI_SSID "<SSID>"
#define WIFI_PASSWORD "<password>"
