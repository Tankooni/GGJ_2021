// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Runtime/Networking/Public/Interfaces/IPv4/IPv4Address.h"
//#include "NetworkClient.generated.h"


/**
 * Represents a connection to the game server. Allows sending and
 * receiving of game events and updates.
 */
//UCLASS()
class GGJ_2021_API UNetworkClient
{
	//GENERATED_BODY()

public:
	UNetworkClient(/*FIPv4Endpoint addr*/);
	~UNetworkClient();

	bool connect(FIPv4Address addr, uint16 port);
	void disconnect();
	//int32 send_action();

private:
	FSocket *socket;
};
