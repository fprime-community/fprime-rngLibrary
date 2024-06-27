set(SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/RNGTopology.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/intentionally-empty.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/ST-Interface/Input.fpp"
)

register_fprime_module()

set_target_properties(
    ${FPRIME_CURRENT_MODULE}
    PROPERTIES
    SOURCES "${CMAKE_CURRENT_LIST_DIR}/intentionally-empty.cpp"
)
