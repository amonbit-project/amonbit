if (WIN32 OR STATIC)
  add_definitions(-DSTATICLIB)
  # miniupnp changed their static define
  add_definitions(-DMINIUPNP_STATICLIB)
endif ()

function (amonbit_private_headers group)
  source_group("${group}\\Private"
    FILES
      ${ARGN})
endfunction ()

function (amonbit_install_headers subdir)
  install(
    FILES       ${ARGN}
    DESTINATION "include/${subdir}"
    COMPONENT   development)
endfunction ()

function (enable_stack_trace target)
  if(STACK_TRACE)
    set_property(TARGET ${target}
      APPEND PROPERTY COMPILE_DEFINITIONS "STACK_TRACE")
    if (STATIC)
      set_property(TARGET "${target}"
        APPEND PROPERTY LINK_FLAGS "-Wl,--wrap=__cxa_throw")
    endif()
  endif()
endfunction()

function (amonbit_add_executable name)
  source_group("${name}"
    FILES
      ${ARGN})

  add_executable("${name}"
    ${ARGN})
  target_link_libraries("${name}"
    PRIVATE
      ${EXTRA_LIBRARIES})
  set_property(TARGET "${name}"
    PROPERTY
      FOLDER "prog")
  set_property(TARGET "${name}"
    PROPERTY
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
  enable_stack_trace("${name}")
  
  amonbit_set_target_no_relink("${name}")
  amonbit_set_target_strip    ("${name}")
endfunction ()

include(Version)
amonbit_add_library(version SOURCES ${CMAKE_BINARY_DIR}/version.cpp DEPENDS genversion)

add_subdirectory(common)
add_subdirectory(cli)
add_subdirectory(crypto)
add_subdirectory(ringct)
add_subdirectory(checkpoints)
add_subdirectory(cryptonote_basic)
add_subdirectory(cryptonote_core)
add_subdirectory(lmdb)
add_subdirectory(multisig)
add_subdirectory(net)
add_subdirectory(hardforks)
add_subdirectory(blockchain_db)
add_subdirectory(mnemonics)
add_subdirectory(rpc)
if(NOT IOS)
  add_subdirectory(serialization)
endif()
add_subdirectory(wallet)
if(NOT IOS)
  add_subdirectory(p2p)
endif()
add_subdirectory(cryptonote_protocol)
if(NOT IOS)
  add_subdirectory(gen_multisig)
  add_subdirectory(gen_ssl_cert)
  add_subdirectory(daemonizer)
  add_subdirectory(daemon)
  add_subdirectory(blockchain_utilities)
endif()

if(BUILD_DEBUG_UTILITIES)
  add_subdirectory(debug_utilities)
endif()

if(PER_BLOCK_CHECKPOINT)
  add_subdirectory(blocks)
endif()

add_subdirectory(device)
add_subdirectory(device_trezor)
