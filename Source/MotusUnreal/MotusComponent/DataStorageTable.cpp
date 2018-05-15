// DataStorageTable.cpp

#include "DataStorageTable.h"

Motus_1_Platform DataStorageTable::_platformPing;
Motus_1_Platform DataStorageTable::_platformPong;
bool DataStorageTable::_usePing = true;

//int   DataStorageTable::movecount = 4;
//int   DataStorageTable::framecount = 0;

 void DataStorageTable::SetMotus_1_Data(vector<int> data)
 {
//	 // begin generate test data
//	 // pad arrangement:
//	 //				+
//	 //			 forward
//	 //			7	0	1
//	 //	- left	6	8	2 right	+
//	 //			5	4	3
//	 //			   back
//	 //				-
//	 //
//#define TEST_PAD_VALUE 4000
//
//	 vector<int> test_values(9);
//	 test_values[0] = 0; // forward
//	 test_values[1] = 0; // forward right
//	 test_values[2] = 0; // right
//	 test_values[3] = 0; // back right
//	 test_values[4] = 0; // back
//	 test_values[5] = 0; // back left
//	 test_values[6] = 0; // left
//	 test_values[7] = 0; // forward left
//	 test_values[8] = TEST_PAD_VALUE; // center pad
//
//	 // we will be counting 90 frames per move
//	 // 9 moves total, one for each pad
//	 ++framecount;
//	 if (framecount > 90) {
//		 framecount = 0;
//		 if (movecount >= 0 && movecount < 9) {
//			 test_values[movecount] = TEST_PAD_VALUE;
//		 }
//		 ++movecount;
//		 if (movecount >= 9) movecount = 0;
//	 }
//	 data = test_values;
//	 // end generate test data

	 if (_usePing)
	 {
		 _platformPing.SetAllSensorElementValues(data);
		 _usePing = false;
	 }
	 else
	 {
		 _platformPong.SetAllSensorElementValues(data);
		 _usePing = true;
	 }
 }

Motus_1_MovementVector DataStorageTable::GetMotionInput()
{
	 if (_usePing)
		 return _platformPong.GetDirectionalVector();
	 else
		 return _platformPing.GetDirectionalVector();

}

 Motus_1_Platform DataStorageTable::GetPlatformObject()
 {
	 if (_usePing)
		 return _platformPong;
	 else
		 return _platformPing;
 }

