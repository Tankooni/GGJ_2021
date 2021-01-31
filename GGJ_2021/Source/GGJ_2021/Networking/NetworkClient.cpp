#include "NetworkClient.h"
#include "Runtime/Core/Public/Containers/UnrealString.h"

UNetworkClient::UNetworkClient(/*FIPv4Endpoint addr*/) 
  : socket(nullptr) 
{}

UNetworkClient::~UNetworkClient() {
  this->disconnect();
}

bool UNetworkClient::connect(FIPv4Address addr, uint16 port) 
{
  this->socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

  TSharedRef<FInternetAddr> full_addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
  full_addr->SetIp(addr.Value);
  full_addr->SetPort(port);

  return this->socket->Connect(*full_addr);
}

void UNetworkClient::disconnect() {
  if(this->socket) {
    this->socket->Close();
    this->socket = nullptr;
    //delete this->socket;
  }
}