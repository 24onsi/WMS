#include <iostream>
#include "WMS.H"
#include "WMS.CPP"

int main()
{
  Data All_data;
  Mon mm;
  Calculator add;
  RegionMarket rm;
  Product pro;
  Type tt;
  Cheap cc;
  vector<vector<string>> address = {{"01.csv", "02.csv", "03.csv", "04.csv", "05.csv", "06.csv", "07.csv", "08.csv", "09.csv", "10.csv", "11.csv", "12.csv"}, {}};

  string aaa;
  cout << "추가할 폴더명과 확장자를 넣어주세요 (Ex. 01.csv)" << endl;
  cin >> aaa;
  cin.get();
  address[1].emplace_back(aaa);
  cout << address[1][0];

  for (int i = 0; i < address.size(); i++)
  {
    vector<vector<vector<string>>> months;
    for (int j = 0; j < address[i].size(); j++)
    {
      string filepath = R"(/home/lms/Cproject/Cpp/WMS/)" + address[i][j];
      ifstream inputFile(filepath);
      if (!inputFile.is_open())
        cerr << "파일을 열 수 없습니다." << endl;

      string line;
      vector<vector<string>> dates;
      while (getline(inputFile, line))
      {
        stringstream ss(line);
        vector<string> row;
        string token;
        while (getline(ss, token, ','))
        {
          row.emplace_back(token);
        }
        dates.emplace_back(row);
        row.clear();
      }
      months.emplace_back(dates);
      inputFile.close();
      dates.clear();
    }
    All_data.copy.emplace_back(months);
    months.clear();
    add = Calculator(&All_data);
    mm = Mon(&All_data);
    rm = RegionMarket(&All_data);
    pro = Product(&All_data);
    tt = Type(&All_data);
    cc = Cheap(&All_data);
  }
  handler controler;
  controler.spread(&add, &mm, &rm, &pro, &tt, &cc);
  cout << "데이터를 수정하시겠습니까? (예 1, 아니요 2)";
  int modifychoice;
  cin >> modifychoice;
  cin.get();
  if (modifychoice == 1)
  {
    All_data.modifydata();
    string filename;
    cout << "저장할 파일명을 입력하세요 : ";
    cin >> filename;
    All_data.Savedata(filename);
  }
  else
  {
    cout << "종료합니다" << endl;
  }
  return 0;
}
