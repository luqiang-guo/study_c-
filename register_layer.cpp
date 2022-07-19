#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <any>

class Tensor {
public:
    Tensor(std::string& name) : name_(name){}
    std::string name_;
};

#define DEFINE_LAYER_CREATOR(name)                                                              \
    Layer* name##_layer_creator(std::vector<Tensor> &inputs , std::vector<Tensor> & outputs, std::map<std::string, std::any>& attr)    \
    {                                                                                           \
        return new name(inputs, outputs, attr);                                                       \
    }


class Layer {
public:
    Layer() {}

    std::string name;
    std::vector<Tensor> inputs_;
    std::vector<Tensor> outputs_;
    std::map<std::string, std::any> attr_;
};

class BinaryOp :public Layer {
public:
    BinaryOp(std::vector<Tensor> &inputs, std::vector<Tensor> &outputs, std::map<std::string, std::any>& attr) {
        name = "BinaryOp";
        inputs_ = inputs;
        outputs_ = outputs;
        attr_  = attr;
        std::cout<< "device : " <<  std::any_cast<std::string>(attr["device"]) << std::endl;
    }
};

DEFINE_LAYER_CREATOR(BinaryOp);

class TestOp :public Layer {
public:
    TestOp(std::vector<Tensor> &inputs, std::vector<Tensor> &outputs, std::map<std::string, std::any> attr) {
        name = "TestOp";
        inputs_ = inputs;
        outputs_ = outputs;
        attr_  = attr;
        std::cout<< "device : " <<  std::any_cast<const char *>(attr["test"]) << std::endl;
    }
};

DEFINE_LAYER_CREATOR(TestOp);

// layer factory function
// typedef Layer* (*layer_creator_func)(void*);
typedef Layer* (*layer_creator_func)(std::vector<Tensor> &, std::vector<Tensor> &, std::map<std::string, std::any>&);
typedef void (*layer_destroyer_func)(Layer*, void*);

struct layer_registry_entry
{
    const char* name;
    layer_creator_func creator;
};

static const layer_registry_entry layer_registry[] = {
    {"BinaryOp", BinaryOp_layer_creator},
    {"TestOp", TestOp_layer_creator},
};


static const int layer_registry_entry_count = sizeof(layer_registry) / sizeof(layer_registry_entry);

int layer_to_index(const char* type)
{
    for (int i = 0; i < layer_registry_entry_count; i++)
    {
        if (strcmp(type, layer_registry[i].name) == 0)
            return i;
    }

    return -1;
}

Layer* create_layer(int index, std::vector<Tensor> &inputs , std::vector<Tensor> & outputs, std::map<std::string, std::any> attr)
{
    if (index < 0 || index >= layer_registry_entry_count)
        return 0;

    // clang-format off
    // *INDENT-OFF*
    layer_creator_func layer_creator = 0;

    layer_creator = layer_registry[index].creator;

    if (!layer_creator)
        return 0;

    Layer* layer = layer_creator(inputs, outputs, attr);
    // layer->typeindex = index;
    return layer;
}

Layer* create_layer(const char* type, std::vector<Tensor> &input , 
                                    std::vector<Tensor> & output,
                                    std::map<std::string, std::any> attr)
{
    int index = layer_to_index(type);
    if (index == -1)
        return 0;

    return create_layer(index, input, output, attr);
}

int  main() {

    // std::vector<>
    std::vector<Tensor>  inputs {};
    std::vector<Tensor>  outputs {};
    std::map<std::string, std::any> attr;
    std::string npu = "NPU";
    attr["device"] = npu;
    attr["test"] = "test";


    auto binary_layer_0 = create_layer("BinaryOp", inputs, outputs, attr);
    auto binary_layer_1 = create_layer("TestOp", inputs, outputs, attr);

    std::cout << "layer name = " << binary_layer_0->name << std::endl;
    std::cout << "layer name = " << binary_layer_1->name << std::endl;

    return 0;
}   