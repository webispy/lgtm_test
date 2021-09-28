ADD_EXECUTABLE(sample main.cc)
TARGET_LINK_LIBRARIES(sample
    ${CMAKE_BINARY_DIR}/nghttp2/lib/libnghttp2.a
    ${pkgs_LDFLAGS})
ADD_DEPENDENCIES(sample NGHTTP2)
