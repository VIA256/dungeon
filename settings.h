#ifndef H_SETTINGS_H
#define H_SETTINGS_H

typedef enum LoadSettingsResult {
  LOAD_SETTINGS_SUCCESS = 0,
  LOAD_SETTINGS_ERROR_VERSION,
} LoadSettingsResult;

LoadSettingsResult loadSettings(const* char filename);

#endif
