find_package(Protobuf REQUIRED)
if(NOT PROTOBUF_FOUND)
    message(WARNING "Protobuf not found !")
endif()

#设置输出路径
# (MESSAGE_DIR ${CMAKE_BINARY_DIR}/onnx_test)
set(ONNX_DIR ${CMAKE_CURRENT_BINARY_DIR})
# if(EXISTS "${ONNX_DIR}" AND IS_DIRECTORY "${ONNX_DIR}")

# else()
#         file(MAKE_DIRECTORY ${ONNX_DIR})
# endif()

# set(ONNX_DIR ${CMAKE_BINARY_DIR}/onnx_test)
# LIST(APPEND PROTO_FLAGS -I${CMAKE_SOURCE_DIR}/msg/message)
list(APPEND ONNX_SRC "${ONNX_DIR}/onnx.pb.cc")
list(APPEND ONNX_HDRS  "${ONNX_DIR}/onnx.pb.h")
# --proto_path=/home/guoluqiang/study_c-/cmake/onnx/onnx/
execute_process(COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} --proto_path =${CMAKE_CURRENT_SOURCE_DIR} onnx.proto --cpp_out=${ONNX_DIR} )