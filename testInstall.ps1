cmake -S . -B install_build
cmake --build install_build --config Release
cmake --install install_build --prefix install_result --config Release