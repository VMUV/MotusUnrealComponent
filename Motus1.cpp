// Motus1.cpp

#include "Motus1.h"

#include "DataStorageTable.h"
#include "Client.h"

bool Motus1::_isInitalized = false;
string Motus1::_versionInfo = "2.0.2";


void Motus1::Initialize(bool rawDataLog)
{

	Client::Initialize();

	//if (rawDataLog)
	//	Client.logRawData = true;

	//if (!_isInitalized)
	//{
	//	Logger.CreateLogFile();
	//	Logger.LogMessage("Unity Motus Plugin v" + _versionInfo);
	//	Logger.LogMessage("Client side TCP v" + SocketWrapper.version);

	//	_isInitalized = true;
	//}

	//ServerApp appLauncher = new ServerApp();
	//appLauncher.LaunchProcess(ServerApp.fname);

	//if (appLauncher.HasTraceLoggerMessages())
	//{
	//	TraceLoggerMessage[] msgs = appLauncher.GetTraceLoggerMessages();
	//	string[] strMsg = new string[msgs.Length];

	//	for (int i = 0; i < msgs.Length; i++)
	//		strMsg[i] = TraceLogger.TraceLoggerMessageToString(msgs[i]);

	//	Logger.LogMessage(strMsg);
	//}
}
void Motus1::Terminate(bool rawDataLog)
{
	Client::Terminate();
}

// returns error count
int Motus1::Service()
{

	int errorcount = Client::Service();

	//if (Client.HasTraceMessages())
	//{
	//	TraceLoggerMessage[] msgs = Client.GetTraceMessages();
	//	string[] strMsg = new string[msgs.Length];

	//	for (int i = 0; i < msgs.Length; i++)
	//		strMsg[i] = TraceLogger.TraceLoggerMessageToString(msgs[i]);

	//	Logger.LogMessage(strMsg);
	//}
	return errorcount;
}

Motus_1_MovementVector Motus1::GetMotionVector()
{
	return DataStorageTable::GetMotionInput();
}

//Motus_1_Platform Motus1::GetRawPlatformData()
//{
	//return DataStorageTable.GetPlatformObject();
//}
