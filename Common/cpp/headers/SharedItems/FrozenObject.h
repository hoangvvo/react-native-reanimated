#pragma once

#include <jsi/jsi.h>
#include "RuntimeManager.h"
#include "SharedParent.h"
#include "WorkletsCache.h"

using namespace facebook;

namespace reanimated {

class FrozenObject : public jsi::HostObject {
  friend WorkletsCache;
  friend void extractMutables(
      jsi::Runtime &rt,
      std::shared_ptr<ShareableValue> sv,
      std::vector<std::shared_ptr<MutableValue>> &res);

 private:
  std::unordered_map<std::string, std::shared_ptr<ShareableValue>> map;

 public:
  FrozenObject(
      jsi::Runtime &rt,
      const jsi::Object &object,
      RuntimeManager *runtimeManager);
  jsi::Object shallowClone(jsi::Runtime &rt);
  bool containsHostFunction = false;
};

} // namespace reanimated
