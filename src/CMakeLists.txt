set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header ${header_path}/Ocean.h ${header_path}/Cell.h ${header_path}/Common.h ${header_path}/Prey.h ${header_path}/Predator.h ${header_path}/Stone.h ${header_path}/Object.h ${header_path}/Object.h)
set(src Ocean.cpp Cell.cpp Predator.cpp Prey.cpp Stone.cpp Object.cpp)


add_library(SRC_FILES ${PROJECT_SOURCE_DIR}/src/Ocean.cpp
              ${PROJECT_SOURCE_DIR}/src/Stone.cpp
              ${PROJECT_SOURCE_DIR}/src/Prey.cpp
              ${PROJECT_SOURCE_DIR}/src/Predator.cpp
	      ${PROJECT_SOURCE_DIR}/src/Object.cpp
	      ${PROJECT_SOURCE_DIR}/src/Cell.cpp
INCLUDE_FILES ${PROJECT_SOURCE_DIR}/include/Ocean.h
              ${PROJECT_SOURCE_DIR}/include/Stone.h
              ${PROJECT_SOURCE_DIR}/include/Prey.h
              ${PROJECT_SOURCE_DIR}/include/Predator.h
	      ${PROJECT_SOURCE_DIR}/include/Object.h
	      ${PROJECT_SOURCE_DIR}/include/Cell.h
 )
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
  pthread)

  
add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")