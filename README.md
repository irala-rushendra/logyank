# logyank

A lightweight command-line utility to fetch and display **error logs** from `journalctl` on Linux.

## Features
- Pulls the latest error logs (`journalctl -p err`)
- Limits the number of logs displayed
- Designed to be modular — add new log-handling features easily
- Installable to `~/.local/bin` for system-wide access

## Usage
```bash
# Show default number of logs (50)
logyank

# Show the last 100 error logs
logyank 100

#if ~/.local/bin is not in the PATH
echo 'export PATH=$HOME/.local/bin:$PATH' >> ~/.bashrc
source ~/.bashrc

# Compile and install to ~/.local/bin
g++ -std=c++17 main.cpp journalModule.cpp -o ~/.local/bin/logyank
chmod +x ~/.local/bin/logyank


src/
 ├── main.cpp
 ├── journalModule.cpp
 ├── journalModule.h
 ├── daemonModule.cpp
 ├── daemonModule.h
 └── (future modules)
