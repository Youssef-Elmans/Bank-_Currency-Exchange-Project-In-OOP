#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include"clsInputValidation.h";
using namespace std;
class clsUtil
{
public:
	enum enCharType {
		SamallLetter = 1,
		CapitalLetter = 2,
		Digit = 3,
		SpecialCharacter = 4,
		MixChars=5
	};
	static void PrintFileContent(string FileName) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				cout << Line << endl;
			}

		}

	}
	static void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				vFileContent.push_back(Line);
			}
			MyFile.close();
		}
	}
	static void SaveVectorToFile(string FileName, vector<string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::out);
		if (MyFile.is_open()) {
			for (const string& Line : vFileContent) {
				if (Line != "") {
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}
	static void DeleteRecordFromFile(string FileName, string Record) {
		vector <string>vFileContent;
		LoadDataFromFileToVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = "";
			}
		}
		SaveVectorToFile(FileName, vFileContent);
	}
	static void UpdateRecordInFile(string FileName, string Record, string UpdateTo) {
		vector <string>vFileContent;
		LoadDataFromFileToVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = UpdateTo;
			}
		}
		SaveVectorToFile(FileName, vFileContent);
	}
	static void ResetScreen() {
		system("cls");
		system("color 07");
	}
	static string Tabs(short NumberOfTabs) {
		string t = "";
		for (short i = 1; i <= NumberOfTabs; i++) {
			t = t + "\t";
		}
		return t;
	}
	static float GetFractionPart(float Number) {
		return Number - int(Number);
	}
	static void  Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int GetRandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == enCharType::MixChars)
			CharType = enCharType(GetRandomNumber(1, 3));

		switch (CharType)
		{
		case enCharType::SamallLetter:
		{

			return char(GetRandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{

			return char(GetRandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{

			return char(GetRandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{

			return char(GetRandomNumber(48, 57));
			break;
		}
		}
		return '\0';
	}
	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;


		for (int i = 1; i <= Length; i++)
		{

			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharType CharType)
	{
		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}
	static void GenerateKeys(enCharType CharType,short NumberOfKeys)
	{

		for (int i = 1; i <= NumberOfKeys; i++)
		{

			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}
	static bool IsPrimeNumber(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return false;
		}
		return true;
	}
	static bool IsPerfectNumber(int Number)
	{
		int Sum = 0;


		for (int i = 1; i < Number; i++)
		{

			if (Number % i == 0)
				Sum += i;
		}

		return Number == Sum;
	}
	static int SumOfDigits(int Number)
	{
		int Sum = 0;
		int Remainder = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}

		return Sum;
	}
	static int ReverseNumber(int Number)
	{
		int Remainder = 0;
		int Number2 = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;
	}
	static int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0;
		int Remainder = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;


			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}
		return FreqCount;
	}

	static bool IsPalindromeNumber(int Number)
	{

		return Number == ReverseNumber(Number);
	}

	static bool IsEvenNumber(int Number) {
		int Remainder = Number % 2;
		if (Remainder == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void FibonacciSeriusUsingLoop(short NumOfElements) {
		short FebNumber = 0;
		short Prev2 = 0, Prev1 = 1;
		cout << "1	";
		for (short i = 2; i <= NumOfElements; i++) {
			FebNumber = Prev1 + Prev2;
			cout << FebNumber << "	";
			Prev2 = Prev1;
			Prev1 = FebNumber;
		}
	}
	static string NumberToText(long  long int Number) {
		if (Number == 0) {
			return "";
		}
		if (Number >= 1 && Number <= 19) {
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven",
				"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
				"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy",
				"Eighty","Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {
			return NumberToText(Number / 100) + "Hundreds" + " " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999) {
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999) {
			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999) {
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999) {
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else {
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}
	static void PrintDigits(int Number)
	{
		int Sum = 0, Remainder = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}

	static void PrintAllDigitsFrequencey(int Number)
	{
		cout << endl;


		for (int i = 0; i < 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = CountDigitFrequency(i, Number);


			if (DigitFrequency > 0)
			{
				cout << "Digit " << i << " Frequency is "
					<< DigitFrequency << " Time(s).\n";
			}
		}
	}
	static void PrintNumberPattern(int Number)
	{
		cout << "\n";


		for (int i = 1; i <= Number; i++)
		{

			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << "\n";
		}
	}
	static void PrintInvertedNumberPattern(int Number)
	{
		cout << "\n";


		for (int i = Number; i >= 1; i--)
		{

			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}

			cout << "\n";
		}
	}
	static void PrintPrimeNumbersFrom1ToN(int Number)
	{
		cout << "\n";

		cout << "Prime Numbers from " << 1 << " To " << Number;
		cout << " are : " << endl;


		for (int i = 1; i <= Number; i++)
		{

			if (IsPrimeNumber(i))
			{

				cout << i << endl;
			}
		}
	}
	static void FillArrayWithRandomNumbers(int ArrOfNumbers[], short ArrSize, int From, int To)
	{



		for (int i = 0; i < ArrSize; i++)
			ArrOfNumbers[i] = GetRandomNumber(From, To);
	}
	static void FillArrayWithRandomWords(string ArrOfNumbers[], short ArrSize,enCharType CharsType , short WordLength)
	{
		for (int i = 0; i < ArrSize; i++)
			ArrOfNumbers[i] = GenerateWord(CharsType, WordLength);
	}
	static void FillArrayWithRandomKeys(enCharType CharsType, string arr[100], short arrLength)
	{

		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharsType);
	}
	static void FillArrayWith1toN(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
			arr[i] = i + 1;
	}
	static void AddArrElement(int Number, int ArrOfNumbers[], int& ArrLegth) {
		ArrOfNumbers[ArrLegth] = Number;
		ArrLegth++;
	}
	static void InputNumbersToArr(int ArrOfNumbers[], int& ArrLength) {

		bool AddOrNot = true;
		do {
			AddArrElement(clsInputValidation::ReadPositiveIntNumber("please enter a number ?"), ArrOfNumbers, ArrLength);
			cout << "Do You Want To Add More Numbers? [0]:No,[1]:Yes ? ";
			cin >> AddOrNot;
		} while (AddOrNot);

	}
	static void CopyArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			AddArrElement(ArrSource[Arr2Length], ArrDestination, Arr2Length);
		}
	}
	static void CopyOnlyOddNumbersToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			if (!IsEvenNumber(ArrSource[i])) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	static void CopyOnlyEvenNumbersToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			if (IsEvenNumber(ArrSource[i])) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	static void CopyOnlyPrimeNumbersToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {
		for (int i = 0; i < Arr1Length; i++) {
			if (IsPrimeNumber(ArrSource[i])) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;
		}

		return -1;
	}
	static bool IsNumberInArray(int Number, int arr[100], int arrLength)
	{

		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}
	static void CopyDistinctUniqueElementsToArr(int ArrSource[], int ArrDestination[], int Arr1Length, int& Arr2Length) {

		for (int i = 0; i < Arr1Length; i++) {
			if (!IsNumberInArray(ArrSource[i], ArrDestination, Arr2Length)) {
				AddArrElement(ArrSource[i], ArrDestination, Arr2Length);
			}
		}
	}
	static void CopyArrayInReversedOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)

			arrDestination[i] = arrSource[arrLength - 1 - i];
	}
	static bool IsPalindromeArray(int ArrOfNumbers[], int ArrLength) {
		for (int i = 0; i < (ArrLength / 2); i++) {
			if (ArrOfNumbers[i] != ArrOfNumbers[ArrLength - i - 1]) {
				return false;
			}
		}
		return true;
	}
	static short CountOddNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		short CountOddNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (!IsEvenNumber(ArrOfNumbers[i])) {
				CountOddNumbers++;
			}
		}
		return CountOddNumbers;
	}
	static short CountEvenNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		short CountEvenNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (IsEvenNumber(ArrOfNumbers[i])) {
				CountEvenNumbers++;
			}
		}
		return CountEvenNumbers;
	}
	static short CountPositiveNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		short CountPositiveNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (ArrOfNumbers[i] > 0) {
				CountPositiveNumbers++;
			}
		}
		return CountPositiveNumbers;
	}
	static short CountNegativeNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		short CountNegativeNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (ArrOfNumbers[i] < 0) {
				CountNegativeNumbers++;
			}
		}
		return CountNegativeNumbers;
	}
	static short CountPrimeNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		short CountPrimeNumbers = 0;
		for (int i = 0; i < ArrLength; i++) {
			if (IsPrimeNumber(ArrOfNumbers[i])) {
				CountPrimeNumbers++;
			}
		}
		return CountPrimeNumbers;
	}
	static short CountNonPrimeNumbersInArr(int ArrOfNumbers[], int ArrLength) {
		return ArrLength - CountPrimeNumbersInArr(ArrOfNumbers, ArrLength);
	}
	static void PrintArray(string arr[100], int arrLength)
	{
		cout << "\nArray elements:\n\n";

		for (int i = 0; i < arrLength; i++)
		{
			cout << "Array[" << i << "] : ";
			cout << arr[i] << "\n";
		}
		cout << "\n";
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{

			int index1 = GetRandomNumber(1, arrLength) - 1;
			int index2 = GetRandomNumber(1, arrLength) - 1;

			Swap(arr[index1], arr[index2]);
		}
	}
	static void ShuffleArray(string arr[100], int arrLength)
	{

		for (short i = 0; i < arrLength; i++)
		{

			short index1 = GetRandomNumber(1, arrLength) - 1;
			short index2 = GetRandomNumber(1, arrLength) - 1;

			Swap(arr[index1], arr[index2]);
		}
	}
	static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}
	static int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;


		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}

		return Sum;
	}
	static float ArrayAverage(int arr[100], int arrLength)
	{

		return (float)SumArray(arr, arrLength) / arrLength;
	}
	static int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = arr[0];


		for (int i = 0; i < arrLength; i++)
		{

			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}
	static int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;


		for (int i = 0; i < arrLength; i++)
		{

			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}
	static short TimesRepeatedInArr(int Number, int arr[100], int arrLength)
	{
		short count = 0;

		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				count++;
			}
		}
		return count;
	}
	static void PrintMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		for (int i = 0; i < NumOfRows; i++) {
			for (int j = 0; j < NumOfColumns; j++) {
				printf("%0*d	", 2, Matrix[i][j]);
			}
			cout << endl;
		}
	}
	static int RowSumInMatrix(int Matrix[3][3], short RowIndex, short NumOfColumns) {
		int Sum = 0;
		for (short i = 0; i < NumOfColumns; i++) {
			Sum += Matrix[RowIndex][i];
		}
		return Sum;
	}
	static int ColumnSumInMatrix(int Matrix[3][3], short NumOfRows, short ColumnIndex) {
		int Sum = 0;
		for (short i = 0; i < NumOfRows; i++) {
			Sum += Matrix[i][ColumnIndex];
		}
		return Sum;
	}
	static void TransposeMatrix(int Matrix[3][3], int TransposedMatrix[3][3], short NumOfRows, short NumOfColumns) {
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				TransposedMatrix[i][j] = Matrix[j][i];
			}
		}

	}
	static int SumMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		int Sum = 0;
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				Sum += Matrix[i][j];
			}
		}
		return Sum;
	}
	static bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short NumOfRows, short NumOfColumns) {
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				if (Matrix1[i][j] != Matrix2[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	static bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short NumOfRows, short NumOfColumns) {
		return (SumMatrix(Matrix1, 3, 3)) == (SumMatrix(Matrix2, 3, 3));
	}
	static bool IsIdentityMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				if (i == j && Matrix[i][j] != 1)
					return false;

				else if (i != j && Matrix[i][j] != 0)
					return false;
			}
		}
		return true;

	}
	static void FillMatrixWithOrderdNumbers(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		short Number = 1;
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				Matrix[i][j] = Number;
				Number++;
			}
		}
	}
	static bool IsIScalarMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		int FirstDiagElement = Matrix[0][0];
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				if (i == j && Matrix[i][j] != FirstDiagElement)
					return false;

				else if (i != j && Matrix[i][j] != 0)
					return false;
			}
		}
		return true;

	}
	static short CountNumberFrequencyInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns, int NumberToCheck) {
		short NumFreq = 0;
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				if (Matrix[i][j] == NumberToCheck)
					NumFreq++;
			}
		}
		return NumFreq;
	}
	static bool IsSparseMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		short ZeroFreq = CountNumberFrequencyInMatrix(Matrix, 3, 3, 0);
		short MatrixSize = NumOfRows * NumOfColumns;
		return (ZeroFreq >= ceil((float)MatrixSize / 2));
	}
	static bool IsNumberInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns, int NumberToCheck) {
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				if (Matrix[i][j] == NumberToCheck)
					return true;
			}
		}
		return false;
	}
	static void FillMatrixWithRandomNumbers(int Matrix[3][3], short NumOfRows, short NumOfColumns, int RandomNumFrom, int RandomNumTo) {
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				Matrix[i][j] = GetRandomNumber(RandomNumFrom, RandomNumTo);
			}
		}
	}
	static void PrintIntersectedNumbersInTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], short NumOfRowsMatrix1, short NumOfColumnsMatrix1, short NumOfRowsMatrix2, short NumOfColumnsMatrix2) {
		cout << "\nIntersected Numbers Are : \n";
		for (short i = 0; i < NumOfRowsMatrix1; i++) {
			for (short j = 0; j < NumOfColumnsMatrix1; j++) {
				if (IsNumberInMatrix(Matrix2, NumOfRowsMatrix2, NumOfColumnsMatrix2, Matrix1[i][j]))
					cout << Matrix1[i][j] << "	";
			}
		}
	}
	static int MinimumNumberInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		int Min = Matrix[0][0];
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				Min = (Matrix[i][j] < Min) ? Matrix[i][j] : Min;
			}
		}
		return Min;
	}
	static int MaximumNumberInMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		int Max = Matrix[0][0];
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < NumOfColumns; j++) {
				Max = (Matrix[i][j] > Max) ? Matrix[i][j] : Max;
			}
		}
		return Max;
	}
	static bool IsPalindromeMatrix(int Matrix[3][3], short NumOfRows, short NumOfColumns) {
		for (short i = 0; i < NumOfRows; i++) {
			for (short j = 0; j < (NumOfColumns / 2); j++) {
				if (Matrix[i][j] != Matrix[i][NumOfColumns - j - 1])
					return false;
			}
		}
		return true;
	}

};