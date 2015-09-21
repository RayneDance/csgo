#include <sourcemod>
#include <adminmenu>

char players[12][];  //Steam IDs of connected players
char client[12][];  //Client index
int readystatus[] = 0;
int players_connected[12] = {0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0,
							 0, 0, 0, 0};

public Plugin myinfo =
{
	name = "Austin CSGO Tournament Plugin",
	author = "Freedom/Alex Jordan",
	description = "Tournament management plugin",
	version = "0.0.1",
	url = "https://github.com/RayneDance/csgo/"
}

public void OnPluginStart(){
	PrintToServer("Austin CSGO Tournament Plugin has launched.");
	RegConsoleCmd("sm_ready", AddReadyStatus, "Add ready status for client;
	
}

//Store our connected players.
public void OnClientAuthorized(client, id){

	//store steam IDs of connected players
	if(id != "BOT")StorePlayerInfo(client, id);
}


pubic void OnClientDisconnect(client){
	int i = 0;
	
	while(client[i] != client){i++;}
	
	players[i][] = "";
	client[i][] = "";
	readystatus[i] = 0;
	players_connected[i] = 0;
	
}

private void StorePlayerInfo(client, id){
	int i = 0;
	while(players_connected[i]){i++;}
	
	players[i][] = id;
	client[i][] = client;
	players_connected[i] = 1;
	
}

public void AddReadyStatus(client, args){
	
	int i = 0;
	while(clients[i][] != client){i++;}
	
	readystatus[i] = 1;
	
	i = 0;
	for(n=0;n<11;n++){
		if(readystatus[i]=1){i++;}
	}
	if(i>9){
		PrintToServer("Ready status has fired.");
		
	}
}
