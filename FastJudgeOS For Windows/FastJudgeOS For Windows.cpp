// FastJudgeOS For Windows.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma comment(lib,"Shlwapi.lib")
#pragma warning(disable:4996)
#include <iostream>
#include <chrono>
#include <stdio.h>
#include <Shlwapi.h>
#include <Windows.h>
using namespace std;
const string _stderr = "\0\0\0ERROR\0\0\0";
string getdatafrom(string prog)
{
	const char* cmd = "ping -c 4 google.com";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) {
		cout << "错误:无法向test.exe获取输出数据，请检查该评测机是否拥有Admin权限(推荐)或SYSTEM权限(可能会有被攻击的风险)" << endl;
		return _stderr;
	}
	char buffer[512];
	string _Val;
	while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
	{
		_Val += buffer;
	}
	_pclose(pipe);
	return _Val;
}
bool checkfile(string filepath)
{
	return PathFileExists(((LPCWSTR)filepath.c_str())) == true;
}
bool putdatato(string prog,string input)
{
	FILE* pipe = _popen(prog.c_str(), "w");
	if (pipe == NULL) {
		printf("错误:无法向test.exe发送输入测试数据，请检查该评测机是否拥有Admin权限(推荐)或SYSTEM权限(可能会有被攻击的风险)\n");//不知道什么原因，反正有跟下面一条注释同样的问题
		return 1;
	}
	const char* data = input.c_str();
	size_t len = strlen(data);
	if (fwrite(data, sizeof(char), len, pipe) != len) {
		printf("错误:无法向test.exe发送输入测试数据，请检查该评测机是否拥有Admin权限(推荐)或SYSTEM权限(可能会有被攻击的风险)\n");//不知道为什么，反正cout就是用不了，非得用printf
		_pclose(pipe);
		return 1;
	}
	_pclose(pipe);
	return 0;
}
int main()
{
	cout << "FastJudgeOS v0.1.0 Beta Release 2" << endl;
	cout << "(C)Copyright LF5 Synergies" << endl;
	cout << "=======================================" << endl;
	cout << "请确保已禁用强制重定向I/O，以防止恶意代码攻击" << endl;
	system("pause");
	cout << "输入比赛名称:";
	string contest;
	cin >> contest;
	cout << "正在获取比赛" << contest << "..." << endl;
	_sleep(1000);
	cout << "30%" << endl;
	FILE* file=fopen(contest.c_str(), "r");
	if (!file)
	{
		cout << "错误:比赛文件无法读取或不存在，请检查是否有权限读取文件或是否存在'"<<contest<<"'" << endl;
		system("pause");
		exit(-1);
	}
	_sleep(750);
	cout << "50%" << endl;
	string datain[16], dataout[16];
	char buffer[255];
	int cnt;
	if (!fscanf(file, "%d", &cnt))
	{
		cout << "错误:数据错误或文件损坏，请检查文件是否损坏并重试" << endl;
		system("pause");
		exit(-1);
	}
	if (cnt > 15)
	{
		cout << "错误:Stack_OverFlow_By_Inputing_Data(StdErr[-1])" << endl;
		system("pause");
		exit(-1);
	}
	for (int i = 0; i < cnt; i++)
	{
		if (!fscanf(file, "%[^\n]", buffer))
		{
			cout << "错误:数据错误或文件损坏，请检查文件是否损坏并重试" << endl;
			system("pause");
			exit(-1);
		}
		_sleep(500);
		cout << "75%" << endl;
		if (buffer[strlen(buffer)] + 1 > 254)
		{
			buffer[strlen(buffer) + 1] = '\0';
		}
		else
		{
			cout << "错误:输入样例文件名超长" << endl;
			system("pause");
			exit(-1);
		}
		datain[i].assign(buffer);
	}
	memset(buffer, 0, sizeof(buffer));
	for (int i = 0;i < cnt; i++)
	{

		if (!fscanf(file, "%[^\n]", buffer))
		{
			cout << "错误:数据错误或文件损坏，请检查文件是否损坏并重试" << endl;
			system("pause");
			exit(-1);
		}
		if (buffer[strlen(buffer)] + 1 > 254)
		{
			buffer[strlen(buffer) + 1] = '\0';
		}
		else
		{
			cout << "错误:输出样例文件名超长" << endl;
			system("pause");
			exit(-1);
		}
		dataout[i].assign(buffer);
	}
	cout << "数据读取成功！" << endl;
	cout << "准备编译代码:本地文件'test.cpp'" << endl;
	fclose(file);
	WinExec("g++ test.cpp -o test.exe -O2 -std=c++14", SW_SHOW);
	_sleep(1000);
	if (!system("taskkill /f /im g++.exe"))
	{
		cout << "错误:编译超时" << endl;
		return 256;
	}
	int score = 0;
		if (!checkfile("test.exe"))
		{
			cout << "错误:编译错误或无法生成" << endl;
			return 128;
		}
	for (int i = 0; i < cnt; i++)
	{
		WinExec("test.exe", SW_SHOW);
		if (putdatato("test.exe", datain[i]))
		{
			system("pause");
			exit(-1);
		}
		string GetVal = getdatafrom("test.exe");
		auto start = std::chrono::high_resolution_clock::now();
		int elapsedTime = 0;
		while (elapsedTime < 1000) {
			auto now = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
			elapsedTime = duration.count();
		}
		if (GetVal == dataout[i])
		{
			score += (100 / cnt);
		}
		else
		{
			system("taskkill /f /im test.exe");
			cout << "错误:代码运行超时" << endl;
			cout << "最终得分:" << score << endl;
			return score + 256;
		}
	}
	cout << "最终得分:" << score << endl;
	return score;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
