# Esports Projects
 This repo consists of some projects I am making, to combine my love for epsorts and CS.

## 1) Esports Events Notifier
- The project is made to give discord notifications of upcoming games on discord gaming channel.
- The project has HTTP API integration (PandaScore), JSON parsing, C++ + libcurl networking, Asynchronous data fetching, Webhook integration (Discord), Clean separation of logic (fetch, parse, notify)
- Further details can be found in the Readme file inside the folder
- Some images to demostarte the final output:
  
<img width="400" height="326" src="https://github.com/user-attachments/assets/97bbf036-ee03-42f3-a5da-8bdd16c66849"/><img width="400" height="366" src="https://github.com/user-attachments/assets/561dfd83-3c8c-47ef-b07b-d469f677756a"/>

### Prerequistes
- You'll need CURL, installed and running - https://curl.se/docs/
- You'll need to setup MSYS.
- You'll need to download and add json.hpp to your target folder - https://github.com/nlohmann/json
- Discord server/channel ownership for webhook integrations
- PandaScore account - https://www.pandascore.co/
- APIs can be accessed - https://developers.pandascore.co/reference/get_matches
- Dev docs - https://developers.pandascore.co/docs/introduction

### How to run
- You need to run this in MSYS MINGW64 bash(not powershell/VSCode terminal)
  
```g++ main.cpp fetchSchedule.cpp notificationAlert.cpp -lcurl -o notifier```

- This creates the notifier.exe that needs to be run to activate the notfication.

```./notifier```

## 2) Korean ↔ English Esports Terms Helper
 - This project was developed to understand Korean/English callouts.
 - This project uses glossary file which is parsed to search or partial search required terms. If you have korean knowledge you can search its equivalent version.
 -  Handles Korean Unicode input/output in the console using wstring - https://cplusplus.com/reference/string/wstring/
 -  Parses a custom glossary file for LoL, Valorant, and other games and uses unordered maps, vectors, and efficient lookup logic
 -  Includes romanized version of Korean words to help understand how to pronounce it.
   Example output:
   <img width="808" height="608" alt="image" src="https://github.com/user-attachments/assets/2de1c052-9142-4fc9-8cce-53200bd89dde" />

### Prerequistes
 - Preinstalled Cmake in system - https://cmake.org/download/
 - Cmake tools in VSCode - https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
 - A raw data file of all the terms, for exmaple the included data file is in a sequence of "English | Korean | Category | Defination | Pronounciation |"

### How to run
 - Build and configure cmake to generate build folder. If you have issues running cmake using VSCode, ```CTRL+Shift+p```, run ```CMake: Delete cache and Reconfigure``` and ```Cmake: Build```
 - Using terminal, cd to build folder. ```cd build```
 - Run the ${projectname}.exe file to run the code - ```.\Korean-English-Esports-Glossary.exe```
