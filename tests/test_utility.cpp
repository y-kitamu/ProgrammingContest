/*
 * test_modulus.cpp
 *
 * Create Date : 2020-04-26 19:31:26
 * Copyright (c) 2019- Y.Kitamu <ymyk6602@gmail.com>
 */
#include <iostream>

#include <glog/logging.h>
#include <gperftools/profiler.h>
#include <boost/filesystem.hpp>

#include "utility.hpp"


namespace fs = boost::filesystem;


int main(int argc, char** argv) {
    // logging codes
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    fs::path save_dir("./prof");
    if (!fs::exists(save_dir)) {
        fs::create_directories(save_dir);
    }
    auto save_path = (save_dir / fs::path(fs::basename(fs::path(argv[0])) + ".prof")).generic_string();
    ProfilerStart(save_path.c_str());
    std::cout << "Profiling to " << save_path << std::endl;
    // end logging codes


    ProfilerStop();
}
