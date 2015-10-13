# Copyright (C) 2015  iCub Facility, Istituto Italiano di Tecnologia
# Author: Francesco Romano <francesco.romano@iit.it>
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT


function(yarp_osx_bundle_update_rpath _target_name)
    if(INSTALL_WITH_RPATH OR ENABLE_FORCE_RPATH)
        get_target_property(APPNAME "${_target_name}" OUTPUT_NAME)
        file(RELATIVE_PATH _rel_path "${CMAKE_INSTALL_FULL_BINDIR}/${APPNAME}.app/Contents/MacOS/" "${CMAKE_INSTALL_FULL_LIBDIR}")
        if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
            get_target_property(CURRENT_RPATH "${_target_name}" INSTALL_RPATH)
            list(APPEND CURRENT_RPATH "@loader_path/${_rel_path}")
            set_target_properties("${_target_name}" PROPERTIES INSTALL_RPATH "${CURRENT_RPATH}")
            get_target_property(CURRENT_RPATH "${_target_name}" INSTALL_RPATH)
        endif()
    endif()
endfunction()