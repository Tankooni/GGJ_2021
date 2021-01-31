// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPAddress.h"


/**
 * Represents a connection to the game server. Allows sending and
 * receiving of game events and updates.
 */
class GGJ_2021_API NetworkClient
{
public:
	NetworkClient() void;
	NetworkClient(FInternetAddress addr);
	~NetworkClient();

	void connect();
	void send_action();
};
