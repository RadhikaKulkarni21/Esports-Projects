# Esports Projects
 This repo consists of some projects I am making, to combine my love for epsorts and CS.

## 1) Esports Events Notifier
- The project is made to give discord notifications of upcomig games on disocrd gaming channel.
- The project has HTTP API integration (PandaScore), JSON parsing, C++ + libcurl networking, Asynchronous data fetching, Webhook integration (Discord), Clean separation of logic (fetch, parse, notify)
- Further details can be found in the Readme file inside the folder
Some images to demostarte the final output:
  
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
```./notifier```

## 2) Korean ↔ English Esports Terms Helper
 - This project was developed to understand Korean/English callouts.
 - This project uses glossary file which is parsed to search or partial search required terms. If you have korean knowledge you can search its equivalent version.
 -  Handles Korean Unicode input/output in the console
 -  Parses a custom glossary file for LoL, Valorant, and other games and uses unordered maps, vectors, and efficient lookup logic
   Example output:
   <img width="841" height="683" alt="스크린샷 2025-12-09 144149" src="https://github.com/user-attachments/assets/00344d00-7240-4141-8e31-b7c1c874b93e" />

### Prerequistes
 - Preinstalled Cmake in system
 - Cmake tools in VSCode

### How to run
 - Build and configure cmake to generate build folder
 - Using terminal, cd to build folder.
 - Run the projectname.exe file to run the code.
