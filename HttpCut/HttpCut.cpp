#include "HttpCut.h"

namespace my
{
	bool HttpCut(string _in_ name)
	{
		//设置文件输入输出流
		size_t pos_tail = name.find(".txt");
		if (pos_tail == string::npos)
			name += ".txt";

		fstream file;
		file.open(name, ios::in);

		if (!file)
		{
			cout << "文件名称错误！" << endl;
			return FAIL;
		}

		//读取
		string txt, line{};
		while (getline(file, line))
			txt += line;
		file.close();

		//处理
		DeleteStr(txt, " ");
		DeleteStr(txt, "\n");

		if (txt.empty() == true)
		{
			cout << "文本内容为空！" << endl;
			return FAIL;
		}

		FindReplace(txt, "https://", "\nhttps://");
		FindReplace(txt, "http://", "\nhttp://");

		//删除第一行回车
		if (txt.at(0) == '\n')
			txt.erase(0, 1);

		//写回记事本
		file.open(name, ios::trunc | ios::out);
		file << txt;

		//关闭文件
		file.close();
		return SUCCESS;
	}

	bool HttpCut(_typein_)
	{
		string name{};
		cout << "请输入文件名称：" << endl;
		cin >> name;

		return HttpCut(name);
	}


	bool DeleteStr(string& _in_ _out_ str, string _in_ word)
	{
		size_t pos{};
		for (;;)
		{
			pos = str.find(word);
			if (pos != string::npos)
				str.replace(pos, word.length(), "");
			else
				break;
		}
		return SUCCESS;
	}

	bool FindReplace(string& _in_ _out_ str, string _in_ word1,string _in_ word2)
	{
		size_t pos{};
		for (;;)
		{
			pos = str.find(word1, pos);
			if (pos != string::npos)
			{
				str.replace(pos, word1.length(), word2);
				pos += word2.length();
			}
			else
				break;
		}
		return SUCCESS;
	}
}