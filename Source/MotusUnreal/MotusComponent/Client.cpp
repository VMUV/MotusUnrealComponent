// Client.cpp

#include "Client.h"

//#include "CommsProtocol/Motus_1_RawDataPacket.h"
#include "Includes/Motus_1_RawDataPacket.h"
#include "DataStorageTable.h"

#define TEST_PAD_VALUE 4000
#define TEST_PAD_VALUE_LSB 0xa0
#define TEST_PAD_VALUE_MSB 0x0f

VMUV_TCP_Cpp::SocketWrapper Client::client(VMUV_TCP_Cpp::client);

bool Client::logRawData = false;

void Client::Initialize()
{
	client.ClientStartRead();
}

void Client::Terminate()
{
	client.ClientCleanup();
}

// returns error count
int Client::Service()
{
	int errorCount = 0;

	client.ClientRead();

	vector<byte> rxData = client.ClientGetRxData();

	byte type = (byte)Comms_Protocol_Cpp::motus_1_raw_data_packet;

	Comms_Protocol_Cpp::Motus_1_RawDataPacket packet;
	if (type == (byte)Comms_Protocol_Cpp::motus_1_raw_data_packet)
	{
		packet.Serialize(rxData);
		vector<short> sData = packet.DeSerialize();
		vector<int> data(sData.size());

		for (int i = 0; i < data.size(); i++)
			data[i] = (int)sData[i];
		DataStorageTable::SetMotus_1_Data(data);

	//	if (logRawData)
	//	{
	//		string msg = data[0].ToString();
	//		for (int i = 1; i < data.Length; i++)
	//			msg += "," + data[i].ToString();
	//		Logger.LogMessage(msg);
	//	}
	}
	return errorCount;
}

bool Client::HasTraceMessages()
{
//	return client.HasTraceMessages();
	return false; // temporary
}

//TraceLoggerMessage[] Client::GetTraceMessages()
//{
//	return client.GetTraceMessages();
//}
