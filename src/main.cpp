#include "journalModule.h"
//#include "daemonModule.h"
//#include "logFileModule.h"
//#include "vacuumModule.h"
#include <iostream>
#include <unordered_map>
#include <functional>

int main(int argc, char* argv[]){

  std::unordered_map<std::string,std::function<void(int)>> commands;

  auto helpCmd = [](){
    std::cout 
      << "Usage:\n "
      << "[logyank]: shows 50 error logs by default no args\n"
      << "[logyank -j/--journal [count]]: shows COUNT no of logs from journalctl\n"
      << "[logyank -h/--help]: displays all commands for reference\n";
  };

  if(argc < 2){
    journalModule::showErrors(50);
    return 0;
  }

  if(std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help"){
    helpCmd();
    return 0;
  }


  commands["--journal"] = [](int cnt) {journalModule::showErrors(cnt);};
  commands["-j"] = [](int cnt) {journalModule::showErrors(cnt);};


  auto it = commands.find(argv[1]);
  if(it != commands.end()){
    int cnt = 100;
    if(argc >= 3){
      cnt = std::atoi(argv[2]);
      if(cnt <= 0) cnt = 100;
    }
    it -> second(cnt);
  }else{
    std::cerr << "Unknown command entry: " << argv[1] << "\n";
    std::cerr << "Use --help to see available options.\n";
  }
  


  return 0;
}
