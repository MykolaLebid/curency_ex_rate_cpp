add_executable(cpp_main "")

target_sources(cpp_main
  PRIVATE
  main.cpp
)
if (TARGET libcurl)
  target_link_libraries(cpp_main
    PRIVATE
    libcurl
  )
else()
  message(STATUS "taget libcurl isn't exists")	
endif()
