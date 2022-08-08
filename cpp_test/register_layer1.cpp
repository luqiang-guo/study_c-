#include <string.h>

#include <any>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

class Tensor {
 public:
  Tensor(std::string& name) : name_(name) {}
  std::string name_;
};

template <class Type>
using Ptr = std::unique_ptr<Type>;
class Layer;
using Creator =
    std::function<Ptr<Layer>(std::vector<Tensor>&, std::vector<Tensor>&,
                             std::map<std::string, std::any>&)>;

class LayerRegistry {
 public:
  using CreatorRegistry = std::map<std::string, Creator>;

  static CreatorRegistry& Registry() {
    static CreatorRegistry registry;
    return registry;
  }

  static Ptr<Layer> CreateLayer(const std::string& type,
                                std::vector<Tensor>& input,
                                std::vector<Tensor>& output,
                                std::map<std::string, std::any>& attr) {
    auto& registry = Registry();
    // CHECK_EQ(registry.count(type), 1) << "unknown layer type: " << type << "
    // (known types: " << ListLayerType() << ")";;
    return registry[type](input, output, attr);
  }

  static void AddCreator(const std::string& type, const Creator& creator) {
    auto& registry = Registry();
    registry[type] = creator;
  }

 private:
  LayerRegistry() = default;
};

class LayerRegisterer {
 public:
  LayerRegisterer(const std::string& type, const Creator& creator) {
    LayerRegistry::AddCreator(type, creator);
  }
};

#define REGISTER_LAYER(layer)                                     \
  static LayerRegisterer g_creator_##layer(                             \
      #layer, [](std::vector<Tensor>& input, std::vector<Tensor>& output, \
               std::map<std::string, std::any>& attr) {                 \
        return Ptr<Layer>(new layer(input, output, attr));              \
      });

// Layer
class Layer {
 public:
  Layer(std::vector<Tensor>& input, std::vector<Tensor>& output,
        std::map<std::string, std::any>& attr)
      : input_(input), output_(output), attr_(attr) {}

  std::string name;
  std::vector<Tensor> input_;
  std::vector<Tensor> output_;
  std::map<std::string, std::any> attr_;
};

class BinaryOp : public Layer {
 public:
  BinaryOp(std::vector<Tensor>& input, std::vector<Tensor>& output,
           std::map<std::string, std::any>& attr)
      : Layer(input, output, attr) {
    std::cout << "device : " << std::any_cast<std::string>(attr_["device"])
              << std::endl;
  }
};

REGISTER_LAYER(BinaryOp);

int main() {
  std::vector<Tensor> input{};
  std::vector<Tensor> output{};
  std::map<std::string, std::any> attr;
  std::string npu = "NPU";
  attr["device"] = npu;
  attr["test"] = "test";

  auto add = LayerRegistry::CreateLayer("BinaryOp", input, output, attr);
  return 0;
}