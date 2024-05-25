#include <fstream>
#include <intersight/model/mesh.h>
#include <intersight/model/primitives.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace intersight;

template <typename T> Mesh3d<T>::Mesh3d() {
  vertices_ = std::vector<Vector3d<T>>();
}

template <typename T> Mesh3d<T>::Mesh3d(const std::string &filename) {
  vertices_ = std::vector<Vector3d<T>>();
}

template <typename T> void Mesh3d<T>::load_obj(const std::string &filename) {
  std::ifstream ifstream(filename);

  if (ifstream.fail()) {
    std::cerr << "Failed to open file " << filename << '\n';
    return;
  }

  std::string line, command;
  while (std::getline(ifstream, line)) {
    std::istringstream istream(line);
    istream >> command;

    if (command == "#")
      continue;

    if (command == "v") {
      Vector3d<T> vertex;
      istream >> vertex;
      vertices_.emplace_back(vertex);
      continue;
    }
  }
}

template <typename T>
const std::vector<Vector3d<T>> &Mesh3d<T>::get_vertices() const {
  return vertices_;
}

template class intersight::Mesh3d<float>;
template class intersight::Mesh3d<double>;
template class intersight::Mesh3d<long double>;