/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.

#define IO_USERNAME    "Poojyak"
#define IO_KEY         "a4116ff10bbe4a12bc81300b1e449337"
/******************************* WIFI **************************************/

#define WIFI_SSID       "AndroidAP2E52"
#define WIFI_PASS       "*************"

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


/*********************************************************************/
