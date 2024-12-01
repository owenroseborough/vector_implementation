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
			Assert::AreEqual(vec.size(), (size_t)3);
			vec.print();  // Expected output: 1 2 3

			// Test 2: Change the vector size to 2 with a smaller initializer list
			vec = { 10, 20 };  // Assign a smaller vector with size 2
			// Verify the vector contains the new values and the size is adjusted
			Assert::AreEqual(vec.size(), (size_t)2);
			vec.print();  // Expected output: 10 20

			// Test 3: Change the vector size to 4 with a larger initializer list
			vec = { 100, 200, 300, 400 };  // Assign a larger vector with size 4
			// Verify the vector contains the new values and the size is adjusted
			Assert::AreEqual(vec.size(), (size_t)4);
			vec.print();  // Expected output: 100 200 300 400

			// Test 4: Test assignment with an empty initializer list
			vec = {};  // Assign an empty vector
			// Verify the vector is empty
			Assert::AreEqual(vec.size(), (size_t)0);
			vec.print();  // Expected output: (empty line)
		}
	};
}
