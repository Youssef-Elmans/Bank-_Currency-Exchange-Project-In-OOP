#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;
	static short Length(string Text) {
		return Text.length();
	}
	short Length() {
		return Length(_Value);
	}
	static short CountWords(string Txt) {
		short Counter = 0;
		string delim = " ";
		short Pos = 0;
		string sWord;
		while ((Pos = Txt.find(delim)) != Txt.npos) {
			sWord = Txt.substr(0, Pos);
			if (sWord != "")
				Counter++;

			Txt.erase(0, Pos + delim.length());
		}
		if (Txt != "")
			Counter++;

		return Counter;
	}
	short CountWords() {
		return CountWords(_Value);
	}
	static vector<string>Split(string Txt, string Delim) {
		short Pos = 0;
		string sWord;
		vector<string>vTxt;
		while ((Pos = Txt.find(Delim)) != Txt.npos) {
			sWord = Txt.substr(0, Pos);
			//if (sWord != "")
				vTxt.push_back(sWord);

			Txt.erase(0, Pos + Delim.length());
		}
		if (Txt != "")
			vTxt.push_back(Txt);

		return vTxt;
	}
	vector<string>Split(string Delim) {
		return Split(_Value, Delim);
	}
	static string TrimLeft(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			if (Txt[i] != ' ')
				return Txt.substr(i, Txt.length() - i);
		}
		return "";
	}
	static string TrimRight(string Txt) {
		for (short i = Txt.length() - 1; i >= 0; i--) {
			if (Txt[i] != ' ')
				return Txt.substr(0, i + 1);
		}
		return "";
	}
	static string Trim(string Txt) {
		return TrimLeft(TrimRight(Txt));
	}
	void TrimLeft() {
		_Value= TrimLeft(_Value);
	}
	void TrimRight() {
		_Value= TrimRight(_Value);
	}
	void Trim() {
		_Value= Trim(_Value);
	}
	static string ReverseWords(string Txt, string Delim) {
		string  ReversedTxt = "";
		vector <string>vString = Split(Txt, Delim);
		vector <string>::iterator iter = vString.end();
		while (iter != vString.begin()) {
			--iter;
			ReversedTxt += *iter + Delim;
		}
		return ReversedTxt.substr(0, ReversedTxt.length() - Delim.length());
	}
	void  ReverseWords(string Delim) {
		_Value = ReverseWords(_Value,Delim);
	}
	static string ReplaceWordsCustom(string Txt, string ReplacedWord, string WordReplaceTo, bool MatchCase = true) {
		vector <string>vString = Split(Txt, " ");
		for (string& Word : vString) {
			if (MatchCase) {
				if (Word == ReplacedWord)
					Word = WordReplaceTo;

			}
			else {
				if (LowerAllLetters(Word) == LowerAllLetters(ReplacedWord))
					Word = WordReplaceTo;

			}
		}
		return JoinString(vString, " ");
	}
	void ReplaceWordsCustom(string ReplacedWord, string WordReplaceTo, bool MatchCase = true) {
		_Value= ReplaceWordsCustom(_Value, ReplacedWord, WordReplaceTo, MatchCase);
	}
	static string ReplaceWordUsingBuiltInFunction(string Text, string
		ReplacedWord, string WordReplaceTo)
	{
		short pos = Text.find(ReplacedWord);
		while (pos != std::string::npos)
		{
			Text = Text.replace(pos, ReplacedWord.length(),
				WordReplaceTo);
			pos = Text.find(ReplacedWord);
		}
		return Text;
	}
	void ReplaceWordUsingBuiltInFunction(string
		ReplacedWord, string WordReplaceTo) {
		_Value= ReplaceWordUsingBuiltInFunction(_Value, ReplacedWord, WordReplaceTo);
	}
	static string RemovePunctuations(string Txt) {
		string TxtWithOutPunct = "";
		for (short i = 0; i < Txt.length(); i++) {
			if (!ispunct(Txt[i]))
				TxtWithOutPunct += Txt[i];
		}
		return TxtWithOutPunct;
	}
	void RemovePunctuations() {
		_Value= RemovePunctuations(_Value);
	}
	static void PrintEachWord(string Txt) {
		string delim = " ";
		short Pos = 0;
		string sWord;
		while ((Pos = Txt.find(delim)) != Txt.npos) {
			sWord = Txt.substr(0, Pos);
			if (sWord != "")
				cout << sWord << endl;

			Txt.erase(0, Pos + delim.length());
		}
		if (Txt != "")
			cout << Txt;
	}
	void PrintEachWord() {
		PrintEachWord(_Value);
	}
	static string Encrypt(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string Decrypt(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}
	void Encrypt(short EncryptionKey) {
		_Value= Encrypt(_Value, EncryptionKey);
	}
	void Decrypt(short EncryptionKey) {
		_Value= Decrypt(_Value, EncryptionKey);
	}
	static bool GuessPassword(string OriginalPassword)
	{
		string word = "";
		int Counter = 0;

		cout << "\n";


		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{

					word = word + char(i);
					word = word + char(j);
					word = word + char(k);

					Counter++;


					cout << "Trial [" << Counter << "] : " << word << endl;


					if (word == OriginalPassword)
					{
						cout << "\nPassword is " << word << "\n";
						cout << "Found after " << Counter << " Trial(s)\n";

						return true;
					}


					word = "";
				}
			}
		}

		return false;
	}
	bool GuessPassword() {
		return GuessPassword(_Value);
	}
	static void PrintFirstLetter(string Txt) {
		bool IsFirstLetter = true;
		cout << "\nFirst Letters Of This String : \n";
		for (short i = 0; i < Txt.length(); i++) {
			if (Txt[i] != ' ' && IsFirstLetter)
				cout << Txt[i] << endl;

			IsFirstLetter = (Txt[i] == ' ' ? true : false);
		}
	}
	void PrintFirstLetter() {
		PrintFirstLetter(_Value);
	}
	static string UpperCaseEachWordFirstLetter(string Txt) {
		bool IsFirstLetter = true;
		for (short i = 0; i < Txt.length(); i++) {
			if (Txt[i] != ' ' && IsFirstLetter)
				Txt[i] = toupper(Txt[i]);

			IsFirstLetter = (Txt[i] == ' ' ? true : false);
		}
		return Txt;
	}
	static string LowerAllLetters(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			Txt[i] = tolower(Txt[i]);
		}
		return Txt;
	}
	static string UpperAllLetters(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			Txt[i] = toupper(Txt[i]);
		}
		return Txt;
	}
	void UpperCaseEachWordFirstLetter() {
		_Value= UpperCaseEachWordFirstLetter(_Value);
	}
	void LowerAllLetters() {
		_Value= LowerAllLetters(_Value);
	}
	void UpperAllLetters() {
		_Value= UpperAllLetters(_Value);
	}
	static short CountCapitalLetters(string Txt) {
		short CounterCapitalLetters = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (isupper(Txt[i]))
				CounterCapitalLetters++;
		}
		return CounterCapitalLetters;
	}
	static short CountSmallLetters(string Txt) {
		short CounterSmallLetters = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (islower(Txt[i]))
				CounterSmallLetters++;
		}
		return CounterSmallLetters;
	}
	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}
	short CountSmallLetters() {
		return CountSmallLetters(_Value);
	}
	static short CountSpecificLetter(string Txt, char CharacterToCount, bool MatchCase = true) {
		short Counter = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (MatchCase) {
				if (Txt[i] == CharacterToCount)
					Counter++;
			}
			else {
				if (tolower(Txt[i]) == tolower(CharacterToCount))
					Counter++;
			}
		}
		return Counter;
	}
	short CountSpecificLetter(char CharacterToCount, bool MatchCase = true) {
		return CountSpecificLetter(_Value, CharacterToCount, MatchCase);
	}
	static void PrintLetterPattern(int Number)
	{
		cout << "\n";


		for (int i = 65; i <= 65 + Number - 1; i++)
		{

			for (int j = 1; j <= i - 65 + 1; j++)
			{
				cout << char(i);
			}

			cout << "\n";
		}
	}
	static void PrintInvertedLetterPattern(int Number)
	{
		cout << "\n";


		for (int i = 65 + Number - 1; i >= 65; i--)
		{

			for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
			{
				cout << char(i);
			}

			cout << "\n";
		}
	}
	static char InvertOneSpecificLetterCase(char Character) {
		return (isupper(Character) ? tolower(Character) : toupper(Character));
	}
	static string InvertLettersCase(string Txt) {
		for (short i = 0; i < Txt.length(); i++) {
			Txt[i] = InvertOneSpecificLetterCase(Txt[i]);
		}
		return Txt;
	}
	void InvertLettersCase() {
		_Value= InvertLettersCase(_Value);
	}
	static bool IsVowelChar(char Character) {
		char UpperCharacter = toupper(Character);
		return ((UpperCharacter == 'A') || (UpperCharacter == 'E') || (UpperCharacter == 'I') || (UpperCharacter == 'O') || (UpperCharacter == 'U'));
	}
	static short CountVowelLetters(string Txt) {
		short Counter = 0;
		for (short i = 0; i < Txt.length(); i++) {
			if (IsVowelChar(Txt[i]))
				Counter++;
		}
		return Counter;
	}
	static void PrintVowels(string Txt) {
		cout << "\nVowels In String Are : ";
		for (short i = 0; i < Txt.length(); i++) {
			if (IsVowelChar(Txt[i]))
				cout << Txt[i] << "	";
		}
	}
	short CountVowelLetters() {
		return CountVowelLetters(_Value);
	}
	void PrintVowels() {
		PrintVowels(_Value);
	}
	static string JoinString(vector<string>& vTxt, string Delim) {
		string  Txt = "";
		for (const string& Word : vTxt) {
			Txt += Word + Delim;
		}
		return Txt.substr(0, Txt.length() - Delim.length());
	}
	static string JoinString(string arrTxt[], short Length, string Delim) {
		string  Txt = "";
		for (short i = 0; i < Length; i++) {
			Txt += arrTxt[i] + Delim;
		}
		return Txt.substr(0, Txt.length() - Delim.length());
	}
};