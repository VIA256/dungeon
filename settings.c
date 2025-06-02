#include "settings.h"

#include <raylib.h>

typedef enum IntSetting {
  SETTING_WIDTH = 0,                         /*00*/
  SETTING_HEIGHT,                            /*01*/
  SETTING_MOUSE_SENSITIVITY,                 /*02*/
  SETTING_ARROW_SENSITIVITY,                 /*03*/
} IntSetting;

int IntSettings[] = { /*indexed by iSetting enum*/
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
  if(!FileExists(filename)){
      return LOAD_SETTINGS_ERROR_FILE_NOT_FOUND;
  }
  
  int fileLength = GetFileLength(filename);
  if(fileLength <= 0){
      return LOAD_SETTINGS_ERROR_EMPTY_FILE;
  }
  
  return LOAD_SETTINGS_SUCCESS;
}
