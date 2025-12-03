This project consists of:
HTTP API integration (PandaScore)
JSON parsing
C++ + libcurl networking
Asynchronous data fetching
Webhook integration (Discord)
Clean separation of logic (fetch, parse, notify)

This is made for *LEAGUE OF LEGENDS*, but pandascore has apis to intergrate other games.

1) Curl
- This project needs curl so you download the libs and run the code using MSYS MINGW64.
- If it gives includePath error, edit the JSON file of properties and add the path of where curl is located.

2) APIs
- The epsorts api can be found at https://developers.pandascore.co/reference
- The league specific api can be found at https://developers.pandascore.co/reference/get_lol_matches_upcoming
- You can find the required CURL request on here itself

NOTE: RIOT APIs no more allow integrations(atleast I couldn't get them run locally), hence you can't access the data from Riot's official website

3) Discord webhooks
- You need your own server and some channel in that server
- The webhooks can be found at channel->edit channel->intergartion->create webhooks

4) Pictures:
- Some screenshots are attached to demonstarte how the notification will look like in terminal, discord channel and discord toast notification