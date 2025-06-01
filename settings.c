#include "settings.h"

#define DSF_VERSION_MAJOR 0
#define DSF_VERSION_MINOR 1
#define DSF_VERSION_PATCH 0
#define DSF_VERSION_STRING "alpha 0.1"

#define SETTINGS_START_MAGIC 0x8e110b0b
#define SETTINGS_END_MAGIC   0x9db7eb0b

typedef enum Setting {
  SETTING_FPS = 1,                           /*01*/
  SETTING_WIDTH,                             /*02*/
  SETTING_HEIGHT,                            /*03*/
  SETTING_MOUSE_SENSITIVITY,                 /*04*/
  SETTING_ARROW_SENSITIVITY,                 /*05*/
} Setting;

LoadSettingsResult loadSettings(const char* filename){
  /*W.I.P.*/
}
