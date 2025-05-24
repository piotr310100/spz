#include "cc/load-spz.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <format> <input_file> <output_file>" << std::endl;
    return 1;
  }

  std::string format = argv[1];
  std::string input_file = argv[2];
  std::string output_file = argv[3];

  if (format == "ply_to_spz") {
    spz::UnpackOptions unpack_options;
    spz::GaussianCloud cloud = spz::loadSplatFromPly(input_file, unpack_options);
    spz::PackOptions pack_options;
    spz::saveSpz(cloud, pack_options, output_file);
  } else if (format == "spz_to_ply") {
    spz::UnpackOptions unpack_options;
    spz::GaussianCloud cloud = spz::loadSpz(input_file, unpack_options);
    spz::PackOptions pack_options;
    spz::saveSplatToPly(cloud, pack_options, output_file);
  } else {
    std::cerr << "Invalid format. Use 'ply_to_spz' or 'spz_to_ply'." << std::endl;
    return 1;
  }

  return 0;
}