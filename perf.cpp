#include <cstdint>
#include <iostream>
#include <vector>
#include <array>
#include <string>

 #include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <yaml-cpp/yaml.h>

enum class InstType 
{
  SYST,
  LOAD,
  SAVE,
  CONV,
  MISC,
  NUM
};


int read_perf_info(char * yaml_file, std::array<int64_t, (int)InstType::NUM>& prof_offset)
{
    YAML::Node yaml_ =  YAML::LoadFile(yaml_file);
    prof_offset[(int)InstType::SYST] = yaml_["profile_addr"]["profile_syst_addr_base"].as<int64_t>();
    prof_offset[(int)InstType::LOAD] = yaml_["profile_addr"]["profile_load_addr_base"].as<int64_t>();
    prof_offset[(int)InstType::SAVE] = yaml_["profile_addr"]["profile_save_addr_base"].as<int64_t>();
    prof_offset[(int)InstType::CONV] = yaml_["profile_addr"]["profile_conv_addr_base"].as<int64_t>();
    prof_offset[(int)InstType::MISC] = yaml_["profile_addr"]["profile_misc_addr_base"].as<int64_t>();

    for(int i = 0; i < (int)InstType::NUM; i++) 
    {
        printf("%lx \n", prof_offset[i]);
    }

    return 0;
}

// uint64_t get_file_size(const char *fname) {
//     FILE *fp ;
//     if((fp = fopen(fname, "r")) == NULL)
//     {
//         printf("open failed %s.\n", fname);
//         exit(-1);
//     }

//     char start_line[128];
//     char end_line[128];

//     fgets(start_line, 128, fp);
//     for(int i = 0; i < 128; i++) 
//     {
//         if(start_line[i] == ' ')
//         {
//             start_line[i] = 0;
//         }
//     }
    
//     uint64_t start_addr;
//     sscanf(start_line, "%lx : ", &start_addr);
//     printf("start_line = %s , %lx \n", start_line, start_addr);
//     return 0;
// }


#define M (1024 * 1024)
void load_text_file(char * text_file,  std::array<int64_t, (int)InstType::NUM>& prof_offset)
{
    std::vector<uint8_t> mem( (int)InstType::NUM * M, 0);

    
}

int main(int argc, char** argv) {
    
    if(argc != 3)
    {
        printf("Usage ./prof info.yaml ddr.bin\n");
        return -1;
    }

    std::array<int64_t, (int)InstType::NUM> prof_offset;
    read_perf_info(argv[1], prof_offset);

    load_text_file(argv[2], prof_offset);
}