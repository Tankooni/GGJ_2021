#include "NetworkClient.h"
#include "Runtime/Core/Public/Containers/UnrealString.h"

UNetworkClient::UNetworkClient(/*FIPv4Endpoint addr*/) 
  //: endpoint(addr) 
{}

UNetworkClient::~UNetworkClient() {
  
}

int UNetworkClient::connect() 
{
  /*
  listenSocket = FTcpSocketBuilder(TEXT("TcpSocket"))
    .AsReusable();

  ISocketSubsystem* socketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

  listenSocket->Connect(*SocketSubsystem->CreateInternetAddr(endpoint.Address.Value, Endpoint.Port));
  listenSocket->Close();
  */


  FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

  FIPv4Address ip(127, 0, 0, 1);
  TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
  addr->SetIp(ip.Value);
  addr->SetPort(8732);

  bool connected = Socket->Connect(*addr);
  UE_LOG(LogTemp, Display, TEXT("Connected?"));

  uint8 data[256] = "{ \"type\": \"ping\" }\0";
  int32 bytes_sent;

  Socket->Send(data, sizeof(18), bytes_sent);
  Socket->Recv(data, sizeof(data), bytes_sent);

  //FString msg = BytesToString(data, sizeof(data));

  //UE_LOG(LogTemp, Fatal, TEXT("GOT A RESPONSE!!!!!111 -> %s"), *msg);

  Socket->Close();

  return 0;
}