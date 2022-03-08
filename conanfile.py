from conans import ConanFile, CMake

class TeamPointsCalc(ConanFile):
    name = "team-points-calculator"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = (
        "gtest/1.11.0",
        "nlohmann_json/3.10.5",
    )
    generators = "cmake", "cmake_find_package"
    exports_sources = "CMakeLists.txt", "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()