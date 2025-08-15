#include "journalModule.h"
//#include "daemonModule.h"
//#include "logFileModule.h"
//#include "vacuumModule.h"
#include <iostream>
#include <unordered_map>
#include <functional>

int main(int argc, char* argv[]){

  std::unordered_map<std::string,std::function<void()>> commands;

  if(argc < 2){
    journalModule::showErrors(50);
    return 0;
  }

  commands["--journal"] = []() {journalModule::showErrors(100);};
  commands["-j"] = []() {journalModule::showErrors(100);};

  auto it = commands.find(argv[1]);
  if(it != commands.end()){
    it -> second();
  }else{
    std::cerr << "Unknown command entry: " << argv[1] << "\n";

  }
  


  return 0;
}
