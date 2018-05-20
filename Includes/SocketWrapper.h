// SocketWrapper.h

#pragma once
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;


#include "StateObject.h"
#include "Packetizer.h"
//#include "..\..\..\TraceLogger\Trace Logger Cpp\Trace Logger Cpp\TraceLogger.h"
#include "TraceLogger.h"

namespace VMUV_TCP_Cpp
{
	/// <summary>
	/// The possible configurations of the <c>SocketWrapper</c> instance.
	/// </summary>
	enum Configuration
	{
		server,
		client
	};

#define DEFAULT_BUFLEN 512

	class SocketWrapper
	{
	public:
		SocketWrapper();
		/// <summary>
		/// Instantiates a new instance of <c>SocketWrapper</c> configured as either a client or a server.
		/// </summary>
		/// <param name="configuration"></param>
		SocketWrapper(Configuration configuration);
		virtual ~SocketWrapper();

	private:
		Packetizer packetizer;
		Trace_Logger_Cpp::TraceLogger traceLogger;
		SOCKET ListenSocket;
		SOCKET ConnectSocket;
		SOCKET ClientSocket;
		const int port = 11069;

//		const byte *sendbuf = "this is a test";
		byte recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;

		vector<byte> txDataPing;  // Do this incase Start() is called before the user sets any data
		vector<byte> txDataPong;  // Do this incase Start() is called before the user sets any data
		vector<byte> rxDataPing;  // Do this incase GetRxData() is called before the user gets any data
		vector<byte> rxDataPong;  // Do this incase GetRxData() is called before the user gets any data
		byte rxTypePing;
		byte rxTypePong;
		bool usePing;
		Configuration config;
		bool clientIsBusy;
		string moduleName;
		int numPacketsRead;

	public:
		/// <summary>
		/// Version number of the current release.
		/// </summary>
		const string version = "1.1.1";

		/// <summary>
		/// Sets the data from <c>payload</c> into the transmit data buffer.
		/// </summary>
		/// <param name="payload"></param>
		/// <param name="type"></param>
		void ServerSetTxData(vector<byte> payload, byte type);

		/// <summary>
		/// Acquires the most recently received valid data payload.
		/// </summary>
		/// <returns>byte buffer with a copy of the most recently receieved valid data payload.</returns>
		vector<byte> ClientGetRxData();

		/// <summary>
		/// Acquires the most recently received payload type.
		/// </summary>
		/// <returns>byte with the most recent payload type. </returns>
		byte ClientGetRxType();

		/// <summary>
		/// Call this method only once after instantiation of the <c>SocketWrapper</c> object. This will start the 
		/// server listener for incoming connections.
		/// </summary>
		void StartServer();
		int ContinueServer();
		// breakdown of ContinueServer for motus emulation
		void ServerCloseListenSocket();
		int ServerAcceptCBClientSocket();
		void ServerCleanup();

		/// <summary>
		/// Call this method in from the main thread to start the next client read process.
		/// </summary>
		void ClientStartRead();
		void ClientContinueRead();
		// breakdown of ClientContinueRead for motus emulation
		void ClientRead();
		void ClientCleanup();

		/// <summary>
		/// Returns all stored trace messages within the <c>TraceLogger</c> object. Call this method after first determining if the 
		/// <c>TraceLogger</c> object has any stored messages using the <c>HasTraceMessages</c> method.
		/// </summary>
		/// <returns>A list of <c>TraceLoggerMessage</c> elements.</returns>
		vector<Trace_Logger_Cpp::TraceLoggerMessage> GetTraceMessages();

		/// <summary>
		/// Returns true if there are unread messages stored in the <c>TraceLogger</c> object.
		/// </summary>
		/// <returns>True if unread messages are available. False otherwise.</returns>
		bool HasTraceMessages();

	private:
		int AcceptCB(SOCKET handler);

		int Send(SOCKET handler, vector<byte> data);

		void SendCB(SOCKET handler);

		void ResetServer();

		void ConnectCB(SOCKET client);

		void Read(SOCKET client);

		void ReadCB(StateObject state);

		void DebugPrint(string s);

	public:
		// start a server using its own thread
		void StartServerTestThread();
		void StopServerTestThread();
		void runServerTest();
		bool serverTestRunning;

		// start a client using its own thread
		void StartClientTestThread();
		void StopClientTestThread();
		void runClientTest();
		bool clientTestRunning;
	private:
		HANDLE m_ServerTestThread;
		static DWORD __stdcall WASAPIServerTestThread(LPVOID Context);
		HANDLE m_ClientTestThread;
		static DWORD __stdcall WASAPIClientTestThread(LPVOID Context);
	};

	class ArgumentNullException
	{
	public:
		ArgumentNullException(string arg1, string arg2)
		{
			Message = arg1;
			StackTrace = arg2;
		};

		string Message;
		string StackTrace;
	};
	class SocketException
	{
	public:
		SocketException(string arg1, string arg2)
		{
			Message = arg1;
			StackTrace = arg2;
		};

		string Message;
		string StackTrace;
	};
	class ObjectDisposedException
	{
	public:
		ObjectDisposedException(string arg1, string arg2)
		{
			Message = arg1;
			StackTrace = arg2;
		};

		string Message;
		string StackTrace;
	};
	class SecurityException
	{
	public:
		SecurityException(string arg1, string arg2)
		{
			Message = arg1;
			StackTrace = arg2;
		};

		string Message;
		string StackTrace;
	};
	class NotSupportedException
	{
	public:
		NotSupportedException(string arg1, string arg2)
		{
			Message = arg1;
			StackTrace = arg2;
		};

		string Message;
		string StackTrace;
	};
	class InvalidOperationException
	{
	public:
		InvalidOperationException(string arg1, string arg2)
		{
			Message = arg1;
			StackTrace = arg2;
		};

		string Message;
		string StackTrace;
	};
}