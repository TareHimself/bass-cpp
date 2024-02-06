


find_path(BASS_AUDIO_H bass.h)
find_library(BASS_AUDIO_LIB bass)

add_library(bass STATIC IMPORTED)
set_target_properties(bass PROPERTIES
  IMPORTED_LOCATION "${BASS_AUDIO_LIB}"
  INTERFACE_INCLUDE_DIRECTORIES "${BASS_DIR}/bass.h"
)