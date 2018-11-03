#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllexport) char* GetTeam();
__declspec(dllexport) bool SetMaze(const int** data, int width, int height);
__declspec(dllexport) int** GetMaze(int& width, int& height);
__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos);
__declspec(dllexport) bool SetStart(int xpos, int ypos);
__declspec(dllexport) bool GetStart(int& xpos, int& ypos);
__declspec(dllexport) bool SetEnd(int xpos, int ypos);
__declspec(dllexport) bool GetEnd(int& xpos, int& ypos);
__declspec(dllexport) bool Restart();

namespace UnitTest
{		
	
	TEST_CLASS(UnitTest1)
	{
	public:

		

		TEST_METHOD(GetTeamReturn)
		{
			char* team = GetTeam();
			Assert::IsNotNull(team);
		}

		TEST_METHOD(SetMazeBadWidth)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			bool ref = SetMaze((const int**)maz, -1, 1);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(SetMazeBadHeight)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			bool ref = SetMaze((const int**)maz, 1, -1);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(SetMazeAllGood)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			bool ref = SetMaze((const int**)maz, 10, 10);
			Assert::IsTrue(ref);
		}

		TEST_METHOD(GetMazewithGoodMazeSet)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			int w = 10;
			int h = 10;
			int& width = w;
			int& height = h;
			int** ref = GetMaze(width, height);
			Assert::IsNotNull(ref);
		}

		TEST_METHOD(SetStartBadX)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			bool ref = SetStart(-1, 1);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(SetStartBadY)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			bool ref = SetStart(1, -1);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(SetStartBothGood)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			bool ref = SetStart(1, 1);
			Assert::IsTrue(ref);
		}

		TEST_METHOD(GetStartGoodSetStart)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			SetStart(1, 1);
			int stx = 1;
			int sty = 1;
			bool ref = GetStart(stx, sty);
			Assert::IsTrue(ref);
		}

		TEST_METHOD(GetStartBadSetStart) 
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			SetStart(-1, -1);
			int stx = -1;
			int sty = -1;
			bool ref = GetEnd(stx, sty);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(SetEndBadX)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			bool ref = SetEnd(-1, 1);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(SetEndBadY)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			bool ref = SetEnd(1, -1);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(GetEndBadSetEnd)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			SetEnd(-1, -1);
			int enx = -1;
			int eny = -1;
			bool ref = GetEnd(enx, eny);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(GetEndGoodSetEnd)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			SetEnd(1, 1);
			int enx = 1;
			int eny = 1;
			bool ref = GetEnd(enx, eny);
			Assert::IsTrue(ref);
		}


		TEST_METHOD(GetNextPositionFalse)
		{
			int** maz = new int*[2];
			for (int i = 0; i<1; i++)
			{
				maz[i] = new int[2];
			}
			maz[0][0] = 0;
			maz[0][1] = 1;
			maz[1][0] = 1;
			maz[1][1] = 1;
			SetMaze((const int**)maz, 1, 1);
			int x = 1;
			int y = 1;
			bool ref = GetNextPosition(x, y);
			Assert::IsFalse(ref);
		}

		TEST_METHOD(RestartTrue)
		{
			int** maz = new int*[20];
			for (int i = 0; i<20; i++)
			{
				maz[i] = new int[20];
			}
			for (int i = 0; i<20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					maz[i][j] = 1;
				}
			}
			SetMaze((const int**)maz, 10, 10);
			SetStart(1, 1);
			bool ref = Restart();
			Assert::IsTrue(ref);
		}
	};
}