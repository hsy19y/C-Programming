#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main(void)
{
    // ���α׷��� ����Ǿ��ִ� �ܾ��
    vector<string> words = { "BlockDMask", "banana", "code", "program" };
    int len = static_cast<int>(words.size());

    //ifstream readFromFile;
    //readFromFile.open("words.txt");
    ifstream readFromFile("words.txt");         // �� ���ٰ� ���� ��

    // ����, ������ ���ٸ� ������ ����� �⺻���ڵ� ����
    if (readFromFile.is_open())
    {
        // ������ �����մϴ�.

        words.clear(); //�� �ܾ���� �о���� ���� ���� �ܾ���� �����Ѵ�.

        while (!readFromFile.eof())          // �ܾ����� ����������.
        {
            // ifstream::getline�� �̿��ؼ� char �迭 Ÿ������ �о���� ����� �Ʒ��� �����ϴ�.
            // char arr[256];
            // readFromFile.getline(arr, 256);

            // std::getline �Լ��� �̿��ؼ� string Ÿ������ �о���� ���.
            // �� ����� string�� ����ϱ� �� ���ϱ� ������ ���������� �� ����� ��ȣ�մϴ�.
            string tmp;
            getline(readFromFile, tmp);
            words.push_back(tmp);            // �о�� �ܾ� ����
        }
        readFromFile.close();               // ���� �ȹ����� ���� �ݾ��ݴϴ�.
    }
    else
    {
        //������ ����? ������ ���Ӱ� ������ ������ְ�, ���� �ܾ���� �־����.
        //is_open�� false �� ���� ������ ���ų�, �ش� ���Ͽ� ������ �Ұ����� ���.
        ofstream writeToFile;
        writeToFile.open("words.txt");    //������ ���� ������ݴϴ�.
        for (int i = 0; i < len; ++i)
        {
            string tmp = words[i];
            if (i != len - 1)
            {
                tmp += "\n";    //������ �ܾ� ���� ���� �־��ֱ�
            }

            //tmp.c_str() : C++ string -> const char* Ÿ������ ��ȯ
            writeToFile.write(tmp.c_str(), tmp.size());
        }
        writeToFile.close();    //���� �ݱ�
    }
    return 0;
}