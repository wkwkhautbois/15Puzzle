#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>
#include "Field.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Puzzle15;

namespace test_lib15Puzzle
{		
	TEST_CLASS(Test_Block)
	{
		TEST_METHOD(test_num)
		{			
			Assert::AreEqual(5, Block(5).num());
			Assert::AreEqual(1, Block(1).num());
			Assert::AreEqual(15, Block(15).num());
			Assert::AreEqual(-10, Block(-10).num());
		}

	};


	TEST_CLASS(Test_Field)
	{
		//FIELD_H=4, FIELD_W=4
		TEST_METHOD(test_Constructor)
		{
			Field field;
			Assert::AreEqual(1, field[0]->num());
			Assert::AreEqual(2, field[1]->num());
			Assert::AreEqual(11, field[10]->num());
		}

		//TEST_METHOD(test_GetNumField)
		//{
		//	Field field;
		//	
		//	//‰Šúó‘Ô
		//	

		//}

		TEST_METHOD(test_Initialize)
		{
			Field field;
			field.Initialize();
			
			field.Swap(0, 1);
			Assert::AreNotEqual(1, field[0]->num());
			Assert::AreNotEqual(2, field[1]->num());

			field.Initialize();
			Assert::AreEqual(1, field[0]->num());
			Assert::AreEqual(2, field[1]->num());
			Assert::AreEqual(11, field[10]->num());

			//auto g = [&](){return field[18]; };
			Assert::ExpectException<std::out_of_range>([&](){return field[18]->num(); });
			Assert::ExpectException<std::out_of_range>([&](){return field[16]->num(); });
			Assert::IsFalse(field[15]);
		}

		TEST_METHOD(test_Swap)
		{
			Field field;

			field.Swap(0, 1);
			Assert::AreEqual(2, field[0]->num());
			Assert::AreEqual(1, field[1]->num());
			Assert::AreEqual(3, field[2]->num());
			Assert::AreNotEqual(1, field[0]->num());
			Assert::AreNotEqual(2, field[1]->num());
			field.Swap(1, 14);
			Assert::AreEqual(1, field[14]->num());
			Assert::IsTrue(field[11]);
			Assert::IsFalse(field[15]);
			field.Swap(11, 15);
			Assert::IsFalse(field[11]);
			Assert::IsTrue(field[15]);

		}

		TEST_METHOD(test_CheckComplete)
		{
			Field field; //{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 , 16 }
			field.Swap(0, 1); //{ 2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
			field.Swap(4, 2); //{ 2, 1, 5, 4, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 , 16 }
			field.Swap(15, 7); //{ 2, 1, 5, 4, 3, 6, 7, 16, 9, 10, 11, 12, 13, 14, 15, 8 }
			
			Assert::IsFalse(field.CheckComplete());
			field.Swap(15, 7);
			Assert::IsFalse(field.CheckComplete());
			field.Swap(2, 4);
			Assert::IsFalse(field.CheckComplete());
			field.Swap(1, 0);
			Assert::IsTrue(field.CheckComplete());

		}

		TEST_METHOD(test_getBlankPosition)
		{
			Field field; //{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
			Assert::AreEqual<const int>(15, field.getBlankPosition());

			field.Swap(0, 1); //{ 2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
			Assert::AreEqual<const int>(15, field.getBlankPosition());

			field.Swap(15, 6);
			Assert::AreEqual<const int>(6, field.getBlankPosition());

			field.Swap(15, 6);
			Assert::AreEqual<const int>(15, field.getBlankPosition());
			
			field.Swap(15, 0);
			Assert::AreEqual<const int>(0, field.getBlankPosition());

			field.Swap(4, 0);
			Assert::AreEqual<const int>(4, field.getBlankPosition());

		}


		TEST_METHOD(test_CheckOnEdges)
		{
			Field field; //{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
			Assert::IsFalse(field.CheckBlankOnLeftEdge());
			Assert::IsFalse(field.CheckBlankOnTopEdge());
			Assert::IsTrue(field.CheckBlankOnRightEdge());
			Assert::IsTrue(field.CheckBlankOnBottomEdge());

			field.Swap(0, 1); //{ 2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
			field.Swap(4, 2); //{ 2, 1, 5, 4, 3, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
			Assert::IsFalse(field.CheckBlankOnLeftEdge());
			Assert::IsFalse(field.CheckBlankOnTopEdge());
			Assert::IsTrue(field.CheckBlankOnRightEdge());
			Assert::IsTrue(field.CheckBlankOnBottomEdge());

			field.Swap(15, 7);
			/*{  2,  1,  5,  4,
			     3,  6,  7, 16,
			     9, 10, 11, 12,
			    13, 14, 15,  8 }*/
			Assert::IsFalse(field.CheckBlankOnLeftEdge());
			Assert::IsFalse(field.CheckBlankOnTopEdge());
			Assert::IsTrue(field.CheckBlankOnRightEdge());
			Assert::IsFalse(field.CheckBlankOnBottomEdge());

			field.Swap(7, 1);
			/*{  2, 16,  5,  4,
			     3,  6,  7,  1,
				 9, 10, 11, 12,
				13, 14, 15,  8 }*/
			Assert::IsFalse(field.CheckBlankOnLeftEdge());
			Assert::IsTrue(field.CheckBlankOnTopEdge());
			Assert::IsFalse(field.CheckBlankOnRightEdge());
			Assert::IsFalse(field.CheckBlankOnBottomEdge());

			field.Swap(1, 12);
			/*{  2, 13,  5,  4,
				 3,  6,  7,  1,
				 9, 10, 11, 12,
				16, 14, 15,  8 }*/
			Assert::IsTrue(field.CheckBlankOnLeftEdge());
			Assert::IsFalse(field.CheckBlankOnTopEdge());
			Assert::IsFalse(field.CheckBlankOnRightEdge());
			Assert::IsTrue(field.CheckBlankOnBottomEdge());

			field.Swap(12, 9);
			/*{  2, 13,  5,  4,
				 3,  6,  7,  1,
				 9, 16, 11, 12,
				10, 14, 15,  8 }*/
			Assert::IsFalse(field.CheckBlankOnLeftEdge());
			Assert::IsFalse(field.CheckBlankOnTopEdge());
			Assert::IsFalse(field.CheckBlankOnRightEdge());
			Assert::IsFalse(field.CheckBlankOnBottomEdge());
		}

		TEST_METHOD(test_MoveDownToBlank)
		{
			bool flagMoved;
			Field field;
			/*{  1,  2,  3,  4,
				 5,  6,  7,  8,
				 9, 10, 11, 12,
				13, 14, 15,  X } */
			Assert::IsTrue(field[11]);
			Assert::IsFalse(field[15]);
			
			flagMoved = field.MoveDownToBlank();
			/*{  1,  2,  3,  4,
				 5,  6,  7,  8,
				 9, 10, 11,  X,
				13, 14, 15, 12 } */
			Assert::AreEqual<const int>(11, field.getBlankPosition());
			Assert::IsFalse(field[11]);
			Assert::IsTrue(field[15]);
			Assert::IsTrue(flagMoved);

			flagMoved = field.MoveDownToBlank();
			flagMoved = field.MoveDownToBlank();
			/*{  1,  2,  3,  X,
				 5,  6,  7,  4,
				 9, 10, 11,  8,
				13, 14, 15, 12 } */
			Assert::AreEqual<const int>(3, field.getBlankPosition());
			Assert::IsTrue(flagMoved);

			flagMoved = field.MoveDownToBlank();
			Assert::IsFalse(flagMoved);	//‰½‚à•Ï‚í‚ç‚È‚¢‚Í‚¸
			Assert::AreEqual<const int>(3, field.getBlankPosition());
		
		}

		TEST_METHOD(test_MoveRightToBlank)
		{
			bool flagMoved;
			Field field;
			/*{  1,  2,  3,  4,
				 5,  6,  7,  8,
				 9, 10, 11, 12,
				13, 14, 15,  X } */
			field.MoveDownToBlank();
			field.MoveDownToBlank();
			field.MoveDownToBlank();
			/*{  1,  2,  3,  X,
				 5,  6,  7,  4,
				 9, 10, 11,  8,
				13, 14, 15, 12 } */

			flagMoved = field.MoveRightToBlank();
			/*{  1,  2,  X,  3,
				 5,  6,  7,  4,
				 9, 10, 11,  8,
				13, 14, 15, 12 } */
			Assert::AreEqual(2, field.getBlankPosition());
			Assert::IsTrue(flagMoved);

			flagMoved = field.MoveRightToBlank();
			flagMoved = field.MoveRightToBlank();
			/*{  X,  1,  2,  3,
				 5,  6,  7,  4,
				 9, 10, 11,  8,
				13, 14, 15, 12 } */
			Assert::IsFalse(field[0]);
			Assert::IsTrue(flagMoved);


			flagMoved = field.MoveRightToBlank();	//•Ï‚í‚ç‚È‚¢
			Assert::IsFalse(field[0]);
			Assert::IsFalse(flagMoved);
		}

		TEST_METHOD(test_MoveUpToBlank)
		{
			bool flagMoved;
			Field field;
			/*{  1,  2,  3,  4,
			5,  6,  7,  8,
			9, 10, 11, 12,
			13, 14, 15,  X } */
			field.MoveDownToBlank();
			field.MoveDownToBlank();
			field.MoveDownToBlank();
			/*{
			1,  2,  3,  X,
			5,  6,  7,  4,
			9, 10, 11,  8,
			13, 14, 15, 12 } */

			flagMoved = field.MoveUpToBlank();
			/*{
			1,  2,  3,  4,
			5,  6,  7,  X,
			9, 10, 11,  8,
			13, 14, 15, 12 } */
			Assert::IsFalse(field[7]);
			Assert::IsTrue(flagMoved);

			flagMoved = field.MoveUpToBlank();
			flagMoved = field.MoveUpToBlank();
			/*{
			1,  2,  3,  4,
			5,  6,  7,  8,
			9, 10, 11,  12,
			13, 14, 15, X } */

			flagMoved = field.MoveUpToBlank();	//•Ï‚í‚ç‚È‚¢
			flagMoved = field.MoveUpToBlank();	//•Ï‚í‚ç‚È‚¢
			Assert::IsFalse(field[15]);
			Assert::IsFalse(flagMoved);
			Assert::IsTrue(field[11]);
		}

		TEST_METHOD(test_MoveLeftToBlank)
		{
			bool flagMoved;
			Field field;
			/*{  1,  2,  3,  4,
			5,  6,  7,  8,
			9, 10, 11, 12,
			13, 14, 15,  X } */
			
			field.MoveRightToBlank();
			field.MoveRightToBlank();
			/*{  1,  2,  3,  4,
			5,  6,  7,  8,
			9, 10, 11, 12,
			13, X, 14,  15 } */

			flagMoved = field.MoveLeftToBlank();
			/*{  1,  2,  3,  4,
			5,  6,  7,  8,
			9, 10, 11, 12,
			13, 14, X,  15 } */
			Assert::IsTrue(field[13]);
			Assert::IsFalse(field[14]);
			Assert::IsTrue(flagMoved);

			flagMoved = field.MoveLeftToBlank();
			/*{  1,  2,  3,  4,
			5,  6,  7,  8,
			9, 10, 11, 12,
			13, 14, 15, X } */
			Assert::IsTrue(flagMoved);
			Assert::IsTrue(field[14]);
			Assert::IsFalse(field[15]);

			flagMoved = field.MoveLeftToBlank();	//•Ï‚í‚ç‚È‚¢
			Assert::IsFalse(flagMoved);
			Assert::IsTrue(field[14]);
			Assert::IsFalse(field[15]);

		}

	};
}