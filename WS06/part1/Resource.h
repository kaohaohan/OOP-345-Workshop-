// Workshop 6 - STL Containers

#ifndef SENECA_RESOURCE_H
#define SENECA_RESOURCE_H
#include "Flags.h"
#include <iostream>
#include <string>

namespace seneca {
class Resource {
protected:
  std::string m_name{};
  std::string m_parent_path{};

public:
  virtual void update_parent_path(const std::string &path) = 0;
  virtual std::string name() const = 0;
  virtual int count() const = 0;
  virtual std::string path() const = 0;
  virtual size_t size() const = 0;
  virtual NodeType type() const = 0;
  virtual ~Resource() = default;
};
} // namespace seneca

#endif
