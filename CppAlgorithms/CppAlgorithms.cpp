
#include <iostream>
#include <vector>
#include <array>
#include <string>

//forward declarations to allow main() to be the first function
const int getMinimum(int* arr, int length);
const int getMinimum(std::vector<int>* list);
void normalizeArray(float* arr, int length);
void normalizeArray(std::vector<float>* list);
int newstrlen(const char* str);
int newstrlen(std::string str);
const char* toHex(char* str, int length);

template<typename T>
void assertEqual(T value, T expected, const char* name);




int main()
{
	std::cout << "Running tests: " << std::endl;

	int values[5] = { -10, -5 , 0, 5, 10 };
	assertEqual<int>(getMinimum(values, 5), -10, "getMinimum C");

	std::vector<int> list = { -10,-5,0,5,10 };
	assertEqual<int>(getMinimum(&list), -10, "getMinimum vector");

	std::cout << std::endl;

	//normalize tests
	float arr[6] = { -2,-1,0,0.5f,1,2 };
	normalizeArray(arr,6);
	std::cout << "normalizeArray C result: (";
	for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << ", ";
	std::cout << ")" << std::endl;

	std::vector<float> vector = { -2, -1, 0, 0.5f, 1, 2 };
	normalizeArray(&vector);
	std::cout << "normalizeArray Vector result: (";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << ", ";
	std::cout << ")" << std::endl;

	std::cout << std::endl;

	assertEqual<int>(newstrlen("Hello"), 5, "newstrlen C");

	assertEqual<int>(newstrlen(std::string("Hello")), 5, "newstrlen string");

	std::cout << std::endl;

	std::cout << "byte array to hex: ";
	const char* msg = "Hello World!";
	const char* hex = toHex((char*)msg, 13);

	std::cout << msg << " expected 48656C6C6F20576F726C642100 got " << (hex == nullptr? "nullptr" : hex) << std::endl;

	int i;
	std::cin >> i;
}


//calculates the smallest element of an integer array
const int getMinimum(int* arr, int length)
{
	return 0;
}

const int getMinimum(std::vector<int>* list)
{
	return 0;
}

//takes an array, every element gets changed in the following way:
// values smaller than -1 are set to -1
// values larger than 1 are set to 1

void normalizeArray(float* arr, int length)
{

}

void normalizeArray(std::vector<float>* list)
{

}

//reimplementation of standard C strlen
//returns the length of a C string (const char[])
// C strings always end in a null terminator which has value: '\0'(char) or 0x00 (hex) or 0 (dec)
int newstrlen(const char* str)
{
	return 0;
}

int newstrlen(std::string str)
{
	return 0;
}


// converts a byte array to a C string Hex representation of it
// for example "Hello" would become -> "48656C6C6F"
static const char  hexDigits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

const char* toHex(char* str, int length)
{
	return nullptr;
}



//template method to log results
template<typename T>
void assertEqual(T value, T expected, const char* name)
{
	if (value == expected)
	{
		std::cout << name << " OK" << std::endl;
	}
	else
	{
		std::cout << name << " Error: expected " << expected << " but got " << value << std::endl;
	}
}