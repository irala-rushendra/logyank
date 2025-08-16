#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "journalModule.h"

namespace journalModule{
  void showErrors(int lastN){
    std::string cmd = "journalctl -p err --no-pager -n " + std::to_string(lastN);

    FILE* pipe = popen(cmd.c_str(),"r");
    if(!pipe){
      std::cerr << "Error: Unable to open pipe for journalctl\n";
      return;
    }
    
    char buffer[256];
    std::vector<std::string> logs;

    while(fgets(buffer, sizeof(buffer),pipe)){
      logs.push_back(buffer);
    }

    pclose(pipe);

    for(const auto& line : logs){
      std::cout << line;
    }
  }
  //void analyzeBruteforce(int thrld)
  
}


