#include "settings.h"

#include <stdio.h>

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
  default:
    break;
  }
  
  return 0;
}
