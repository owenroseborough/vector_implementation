#include "pch.h"
#include "CppUnitTest.h"
#include "../Vector Implementation/owens_vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTesting
{
	TEST_CLASS(VectorTests)
	{
	public:

		TEST_METHOD(DefaultConstructorTest)
		{
			// Create an instance of owens_vector with the default constructor
			owens_vector<int> vec;
			// If the constructor completes without crashing, the test passes
			// Add any further checks, if applicable
		}
		TEST_METHOD(DestructorTest)
		{
			// Test to ensure the destructor properly cleans up resources
			// This is implicitly tested as part of other tests.
			// You can create scoped blocks to force destruction at the end of the block
			{
				owens_vector<int> vec(42);
			}
			// If the code runs without crashing, the destructor works.
		}

		TEST_METHOD(OperatorEqualsWithBracedInitializationTest)
		{
			// Test 1: Create a vector with initial size and assign with braced initialization
			owens_vector<int> vec(3);  // Initial vector of size 3
			vec = { 1, 2, 3 };  // Assign new values using braced initialization
			// Verify the vector contains the assigned values
			int testArray[] = { 1, 2, 3 };
			Assert::AreEqual(vec.size(), (size_t)3);
			for (size_t i = 0; i < 3; i++) {
				Assert::AreEqual(vec[i], testArray[i]);
			}
			vec.print();  // Expected output: 1 2 3

			// Test 2: Change the vector size to 2 with a smaller initializer list
			vec = { 10, 20 };  // Assign a smaller vector with size 2
			// Verify the vector contains the new values and the size is adjusted
			int testArray1[] = {10, 20};
			Assert::AreEqual(vec.size(), (size_t)2);
			for (size_t i = 0; i < 2; i++) {
				Assert::AreEqual(vec[i], testArray1[i]);
			}
			vec.print();  // Expected output: 10 20

			// Test 3: Change the vector size to 4 with a larger initializer list
			vec = { 100, 200, 300, 400 };  // Assign a larger vector with size 4
			// Verify the vector contains the new values and the size is adjusted
			int testArray2[] = { 100, 200, 300, 400 };
			Assert::AreEqual(vec.size(), (size_t)4);
			for (size_t i = 0; i < 4; i++) {
				Assert::AreEqual(vec[i], testArray2[i]);
			}
			vec.print();  // Expected output: 100 200 300 400

			// Test 4: Test assignment with an empty initializer list
			vec = {};  // Assign an empty vector
			// Verify the vector is empty
			Assert::AreEqual(vec.size(), (size_t)0);
			Assert::ExpectException<std::out_of_range>([&vec]() {
				vec[0];
			});
			vec.print();  // Expected output: (empty line)
		}
		TEST_METHOD(IteratorTests)
		{
			owens_vector<int> vec(3);  // Initial vector of size 3
			vec = { 1, 2, 3 };  // Assign new values using braced initialization
			int testArray[] = {1, 2, 3};
			size_t i = 0;
			for (const int& value : vec) {
				Assert::AreEqual(value, testArray[i]);
				i++;
			}
		}
		TEST_METHOD(PushBackTests)
		{
			owens_vector<int> vec(3);  // Initial vector of size 3
			vec = { 1, 2, 3 };  // Assign new values using braced initialization
			vec.push_back(4);
			auto var = vec[3];
			Assert::AreEqual(vec[3], 4);  //element in position 3 should be the one we just inserted
			Assert::AreEqual(vec.memory_size(), (size_t)6); //vec size should now be 6, as we double
		}
		TEST_METHOD(PopBackTests) {
			owens_vector<int> vec(3);  // Initial vector of size 3
			vec = { 1, 2, 3 };  // Assign new values using braced initialization
			Assert::AreEqual(vec.size(), (size_t)3); //vec size should be 3
			vec.pop_back();
			Assert::AreEqual(vec.size(), (size_t)2); //vec size should now be 2, as we popped off element
			vec.pop_back();
			vec.pop_back();
			Assert::AreEqual(vec.size(), (size_t)0); //vec size should now be 0, as we popped off all elements
			vec.pop_back();
			Assert::AreEqual(vec.size(), (size_t)0); //vec size should now be 0, as we popped off all elements
		}
		TEST_METHOD(InsertTestsSingleVal) {
			owens_vector<int> vec(3);  // Initial vector of size 3
			vec = { 1, 2, 3 };  // Assign new values using braced initialization
			vec.insert(1, 4);   // insert 4 at position 1
			Assert::AreEqual(vec[1], 4); //element at position 1 should be 4 now

			Assert::ExpectException<std::out_of_range>([&vec]() {
				vec.insert(-1, 5);
			});
			Assert::ExpectException<std::out_of_range>([&vec]() {
				vec.insert(4, 5);
			});

			vec.insert(3, 5);
			Assert::AreEqual(vec[3], 5); //element at position 3 should be 5 now

			int testArray[] = { 1, 4, 2, 5, 3 };
			size_t i = 0;
			for (const int& value : vec) {
				Assert::AreEqual(value, testArray[i]);
				i++;
			}
		}
		TEST_METHOD(InsertTestsInitializerList) {

		}
	};
}
