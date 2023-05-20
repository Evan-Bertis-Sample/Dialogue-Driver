file(REMOVE_RECURSE
  "libdialogue_driver.dll"
  "libdialogue_driver.dll.a"
  "libdialogue_driver.dll.manifest"
  "libdialogue_driver.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/dialogue_driver.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
