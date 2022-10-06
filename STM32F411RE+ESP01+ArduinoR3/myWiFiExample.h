/*
myWiFi.h

Separating WiFi SSID and password out to allow config.h to be committed to
a Git repo without storing secrets.

Need to add an include at the top of config.h:

#include "myWiFi.h"
*/

#define WIFI_SSID "<SSID>"
#define WIFI_PASSWORD "<password>"
#define WIFI_HOSTNAME "hostname"