#include "settings.h"

#include <stdio.h>
#include <stdint.h>

int main(void){
  LoadSettingsResult sres = loadSettingsFromDSF("shit.dsf");
  
  switch(sres){
  case LOAD_SETTINGS_SUCCESS:
    printf("success\n");
    break;
  case LOAD_SETTINGS_ERROR_FILE_NOT_FOUND:
    printf("file not found\n");
    break;
  case LOAD_SETTINGS_ERROR_EMPTY_FILE:
    printf("file is empty\n");
    break;
  case LOAD_SETTINGS_ERROR_FILE_READ_FAILURE:
    printf("failed to read file\n");
    break;
  case LOAD_SETTINGS_ERROR_START_MAGIC:
    printf("start magic bytes did not match expectation\n");
    break;
  case LOAD_SETTINGS_ERROR_INVALID_FORMAT:
    printf("invalid format\n");
    break;
  default:
    break;
  }
  
  return 0;
}
