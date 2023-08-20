// FastJudgeOS For Windows.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
    cout << "FastJudgeOS v0.1.0 Beta Release 1" << endl;
    cout << "(C)Copyright LF5 Synergies" << endl;
    cout << "=======================================" << endl;
    string contest;
    cin >> contest;
    cout << "正在获取比赛" << contest << "..." << endl;
    _sleep(1000);
    cout << "30%" << endl;
    FILE* file=fopen(contest.c_str(), "r");
    if (!file)
    {
        cout << "错误:比赛文件无法读取或不存在，请检查是否有权限读取文件或是否存在'"<<contest<<".fjcf'" << endl;
        system("pause");
        exit(-1);
    }
    _sleep(750);
    cout << "50%" << endl;
    string datain, dataout;
    char buffer[255];
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
    memset(buffer, 0, sizeof(buffer));
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
    dataout.assign(buffer);
    cout << "数据读取成功！" << endl;
    cout << "准备测试数据:";
    if (buffer[strlen(buffer)] + 1 > 254)
    {
        buffer[strlen(buffer) + 1] = '\0';
    }
    else
    {
        cout << "错误:文件名超长" << endl;
        system("pause");
        exit(-1);
    }
    fclose(file);
    return 0;
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
