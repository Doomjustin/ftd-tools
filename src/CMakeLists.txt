set(TOOLS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_library(FTD_TOOLS
    STATIC
        ${TOOLS_INCLUDE_DIR}/ftd/Utility.h
        ${TOOLS_INCLUDE_DIR}/ftd/Concepts.h
        ${TOOLS_INCLUDE_DIR}/ftd/Enumerator.h
        ${TOOLS_INCLUDE_DIR}/ftd/Noncopyable.h
        ${TOOLS_INCLUDE_DIR}/ftd/FunctionWrapper.h
        ${TOOLS_INCLUDE_DIR}/ftd/ThreadPool.h
        ${TOOLS_INCLUDE_DIR}/ftd/Timer.h
        ${TOOLS_INCLUDE_DIR}/ftd/Log.h
        ThreadPool.cpp
        Log.cpp
        SpdLogger.h
        SpdLogger.cpp
)

add_library(ftd::tools ALIAS FTD_TOOLS)

target_include_directories(FTD_TOOLS PUBLIC ${TOOLS_INCLUDE_DIR})
target_link_libraries(FTD_TOOLS PUBLIC spdlog::spdlog)
