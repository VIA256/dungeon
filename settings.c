#include "settings.h"

#include <stdint.h>

typedef enum iSetting {
  SETTING_WIDTH = 0,                         /*00*/
  SETTING_HEIGHT,                            /*01*/
  SETTING_MOUSE_SENSITIVITY,                 /*02*/
  SETTING_ARROW_SENSITIVITY,                 /*03*/
} Setting;

int iSettings[] = { /*indexed by iSetting enum*/
  640,  /*WIDTH*/
  480,  /*HEIGHT*/
  100,  /*MOUSE SENSITIVITY*/
  150,  /*ARROW SENSITIVITY*/
};

#define SETTINGS_START_MAGIC 0x8e110b0b
#define SETTINGS_END_MAGIC   0x9db7eb0b

#define DSF_VERSION_MAJOR 0
#define DSF_VERSION_MINOR 1
#define DSF_VERSION_PATCH 0
#define DSF_VERSION_STRING "alpha 0.1"

LoadSettingsResult loadSettingsFromDSF(const char* filename){
  return LOAD_SETTINGS_SUCCESS;
}
