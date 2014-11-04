project(kparttorrentinfo)
find_package (KDE4 REQUIRED)
INCLUDE_DIRECTORIES( ${KDE4_INCLUDES} . )

# include_directories(
#   ${KDE4_INCLUDE_DIR}/kcal
#   ${CMAKE_SOURCE_DIR}/kresources/remote  )

set(kparttorrentinfo_shared_SRCS 
  kparttorrentinfo.cpp
 )


set(kparttorrentinfo_PART_SRCS kparttorrentinfo.cpp)

kde4_add_plugin(kparttorrentinfo ${kparttorrentinfo_PART_SRCS})

target_link_libraries(kparttorrentinfo ${KDE4_KPARTS_LIBS})
if(X11_Xscreensaver_LIB)
	target_link_libraries(kparttorrentinfo  ${X11_Xscreensaver_LIB} )
endif(X11_Xscreensaver_LIB)

install(
  TARGETS
  kparttorrentinfo
  DESTINATION
  ${PLUGIN_INSTALL_DIR}
)

install(
  FILES
  kparttorrentinfo.desktop
  DESTINATION ${SERVICES_INSTALL_DIR}
)
