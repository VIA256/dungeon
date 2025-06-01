#ifndef H_SETTINGS_H
#define H_SETTINGS_H

typedef enum LoadSettingsResult {
  LOAD_SETTINGS_SUCCESS = 0,
  LOAD_SETTINGS_ERROR_LOAD_FILE,
  LOAD_SETTINGS_ERROR_START_MAGIC,
  LOAD_SETTINGS_ERROR_VERSION,
} LoadSettingsResult;

LoadSettingsResult loadSettingsFromDSF(const char* filename);

#endif
