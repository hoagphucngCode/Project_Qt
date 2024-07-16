file(REMOVE_RECURSE
  "MediaPlayer/main.qml"
  "MediaPlayer/screen/components/music/Controller.qml"
  "MediaPlayer/screen/components/music/IconButton.qml"
  "MediaPlayer/screen/components/music/List.qml"
  "MediaPlayer/screen/components/music/Player.qml"
  "MediaPlayer/screen/features/MusicPlayer.qml"
  "MediaPlayer/screen/utils.js"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appMediaPlayer_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
