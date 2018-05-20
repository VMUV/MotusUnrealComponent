// Client.h

#pragma once

//#include "TCP/SocketWrapper.h"
#include "Includes/SocketWrapper.h"

class Client
{
private:
	static VMUV_TCP_Cpp::SocketWrapper client;

	static int movecount;
	static int framecount;
public:
	static bool logRawData;

	static void Initialize();
	static void Terminate();
	static int Service();

	static bool HasTraceMessages();

//	static TraceLoggerMessage[] GetTraceMessages();
};
