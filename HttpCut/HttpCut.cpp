#include "HttpCut.h"

namespace my
{
	bool HttpCut(string _in_ name)
	{
		//�����ļ����������
		size_t pos_tail = name.find(".txt");
		if (pos_tail == string::npos)
			name += ".txt";

		fstream file;
		file.open(name, ios::in);

		if (!file)
		{
			cout << "�ļ����ƴ���" << endl;
			return FAIL;
		}

		//��ȡ
		string txt, line{};
		while (getline(file, line))
			txt += line;
		file.close();

		//����
		DeleteStr(txt, " ");
		DeleteStr(txt, "\n");

		if (txt.empty() == true)
		{
			cout << "�ı�����Ϊ�գ�" << endl;
			return FAIL;
		}

		FindReplace(txt, "https://", "\nhttps://");
		FindReplace(txt, "http://", "\nhttp://");

		//ɾ����һ�лس�
		if (txt.at(0) == '\n')
			txt.erase(0, 1);

		//д�ؼ��±�
		file.open(name, ios::trunc | ios::out);
		file << txt;

		//�ر��ļ�
		file.close();
		return SUCCESS;
	}

	bool HttpCut(_typein_)
	{
		string name{};
		cout << "�������ļ����ƣ�" << endl;
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