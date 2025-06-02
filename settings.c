#include "settings.h"

#include <raylib.h>
#include <stdio.h> /*FOR DEBUG*/
#include <stdint.h>

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

#define DSF_START_MAGIC 0x8e110b0b
#define DSF_END_MAGIC   0x9db7eb0b

#define DSF_VERSION_MAJOR 0
#define DSF_VERSION_MINOR 1
#define DSF_VERSION_PATCH 0
#define DSF_VERSION_STRING "alpha 0.1"

uint32_t byteArrayFourToUint32(unsigned char* b){ /*ASSUMES BYTE ARRAY HAS FOUR OR MORE ELEMENTS*/
  return (uint32_t)( b[3] + (b[2] << 8) + (b[1] << 8*2) + (b[0] << 8*3) );
}

LoadSettingsResult loadSettingsFromDSF(const char* filename){
  if(!FileExists(filename)){
      return LOAD_SETTINGS_ERROR_FILE_NOT_FOUND;
  }
  
  int fileLength = GetFileLength(filename);
  if(fileLength <= 0){
      return LOAD_SETTINGS_ERROR_EMPTY_FILE;
  }
  
  unsigned char* fileData = LoadFileData(filename, &fileLength);
  if(!fileData){
    return LOAD_SETTINGS_ERROR_FILE_READ_FAILURE;
  }
  
  uint32_t start_magic = byteArrayFourToUint32(fileData);
  printf("start_magic: %x\n", start_magic);
  if(start_magic != DSF_START_MAGIC){
    return LOAD_SETTINGS_ERROR_START_MAGIC;
  }
  
  UnloadFileData(fileData);
  
  return LOAD_SETTINGS_SUCCESS;
}
