#include <iostream>
#include "WMS.H"
using namespace std;

void Data::modifychoice(int years, int month, string &target_value, string &new_value)
{
  for (int i = 0; i < copy.size(); ++i)
  {
    for (int j = 0; j < copy[years].size(); ++j)
    {
      for (int k = 0; k < copy[years][month].size(); ++k)
      {
        for (int m = 0; m < copy[years][month][k].size(); ++m)
        {
          if (copy[years][month][k][m] == target_value)
          {
            copy[years][month][k][m] = new_value;
          }
        }
      }
    }
  }
}

void Data::modifydata()
{
  int years, month;
  string target_value, new_value;

  cout << "몇년도를 수정하시겠습니까? (0. 2013년   1.2022년) ";
  cin >> years;
  cout << "수정할 월을 입력하세요 : (1~12월)";
  cin >> month;
  month -= 1;
  cout << "수정할 데이터를 입력하세요 : ";
  cin >> target_value;
  cin.get();
  cout << "새로운 데이터를 입력하세요: ";
  cin >> new_value;
  cin.get();
  modifychoice(years, month, target_value, new_value);
}

void Data::Savedata(string &filename)
{
  ofstream outputfile(filename);
  for (int i = 0; i < copy.size(); i++)
  {
    for (int j = 0; j < copy[i].size(); j++)
    {
      for (int k = 0; k < copy[i][j].size(); k++)
      {
        for (int m = 0; m < copy[i][j][k].size(); m++)
        {
          outputfile << copy[i][j][k][m] << ',';
        }
        outputfile << endl;
      }
    }
  }
  outputfile.close();
  cout << "파일 저장" << endl;
}

void Mon::Cal(string &ch, string &doso_me, int choiceint, string &prod, int month1, int month2, int year)
{
  Check1 = false;
  Check2 = false;
  max = 0;
  max2 = 0;
  min = 10000000;
  min2 = 10000000;
  count = 0;
  count2 = 0;
  sum = 0;
  sum2 = 0;

  for (int j = 0; j < cal_data->copy[year][month1 - 1].size(); j++)
  {
    if (cal_data->copy[year][month1 - 1][j][7] == doso_me && cal_data->copy[year][month1 - 1][j][5] == prod)
    {
      Check1 = true;
      num = stoi(cal_data->copy[year][month1 - 1][j][10]);
      sum += num;
      count++;
      if (max < num)
        max = num;
      if (min > num)
        min = num;
    }
  }
  for (int j = 0; j < cal_data->copy[year][month2 - 1].size(); j++)
  {
    if (cal_data->copy[year][month2 - 1][j][7] == doso_me && cal_data->copy[year][month2 - 1][j][5] == prod)
    {
      Check2 = true;
      num2 = stoi(cal_data->copy[year][month2 - 1][j][10]);
      sum2 += num2;
      count2++;
      if (max2 < num2)
        max2 = num2;
      if (min2 > num2)
        min2 = num2;
    }
  }

  if (doso_me == "6")
  {
    cout << " | 도매가 기준 검색" << endl;
  }
  else if (doso_me == "7")
  {
    cout << " | 소매가 기준 검색" << endl;
  }

  if (Check1)
  {
    cout << " | \"" << month1 << "월 " << prod << "\" 가격 평 균 : " << sum / count << " , 최댓값 : " << max
         << " , 최솟값 : " << min << endl;
  }
  else if (!Check1)
  {
    cout << " | \"" << month1 << "월 " << prod << "\" 일치하는 결과가 없습니다.\n";
  }

  if (Check2)
  {
    cout << " | \"" << month2 << "월 " << prod << "\" 가격 평 균 : " << sum2 / count2 << " , 최댓값 : " << max2
         << " , 최솟값 : " << min2 << endl;
  }
  else if (!Check2)
  {
    cout << " | \"" << month2 << "월 " << prod << "\" 일치하는 결과가 없습니다.\n";
  }
}

void RegionMarket::Cal(string &ch1, string &ch2, string &doso_me, int choiceint, string &prod)
{
  Check1 = false;
  Check2 = false;
  max = 0;
  max2 = 0;
  min = 10000000;
  min2 = 10000000;
  count = 0;
  count2 = 0;
  sum = 0;
  sum2 = 0;

  for (int k = 0; k < cal_data->copy.size(); k++)
  {
    for (int i = 0; i < cal_data->copy[k].size(); i++)
    {
      for (int j = 0; j < cal_data->copy[k][i].size(); j++)
      {
        if (cal_data->copy[k][i][j][choiceint].compare(ch1) == 0 && cal_data->copy[k][i][j][7] == doso_me && cal_data->copy[k][i][j][5] == prod)
        {
          Check1 = true;
          num = stoi(cal_data->copy[k][i][j][10]);
          sum += num;
          count++;
          if (max < num)
            max = num;
          if (min > num)
            min = num;
        }
        else if (cal_data->copy[k][i][j][choiceint].compare(ch2) == 0 && cal_data->copy[k][i][j][7] == doso_me && cal_data->copy[k][i][j][5] == prod)
        {
          Check2 = true;
          num2 = stoi(cal_data->copy[k][i][j][10]);
          sum2 += num2;
          count2++;
          if (max2 < num2)
            max2 = num2;
          if (min2 > num2)
            min2 = num2;
        }
      }
    }
  }

  if (doso_me == "6")
  {
    cout << " | 도매가 기준 검색" << endl;
  }
  else if (doso_me == "7")
  {
    cout << " | 소매가 기준 검색" << endl;
  }

  if (Check1)
  {
    cout << " | \"" << ch1 << " " << prod << "\" 가격 평 균 : " << sum / count << " , 최댓값 : " << max << " , 최솟값 : " << min << endl;
  }
  else if (!Check1)
  {
    cout << " | \"" << ch1 << " " << prod << "\" 일치하는 결과가 없습니다.\n";
  }

  if (Check2)
  {
    cout << " | \"" << ch2 << " " << prod << "\" 가격 평 균 : " << sum2 / count2 << " , 최댓값 : " << max2 << " , 최솟값 : " << min2 << endl;
  }
  else if (!Check2)
  {
    cout << " | \"" << ch2 << " " << prod << "\" 일치하는 결과가 없습니다.\n";
  }
}

void Type::Cal(string &doso_me, int choiceint, string sanmul)
{
  max = 0;
  min = 10000000;
  count = 0;
  sum = 0;
  SSANMUL = 0;
  for (int k = 0; k < cal_data->copy.size(); k++)
  {
    for (int i = 0; i < cal_data->copy[k].size(); i++)
    {
      for (int j = 0; j < cal_data->copy[k][i].size(); j++)
      {
        if (cal_data->copy[k][i][j][7] == doso_me && stoi(cal_data->copy[k][i][j][6]) >= 111 && stoi(cal_data->copy[k][i][j][6]) <= 422 && sanmul == "0")
        {
          num = stoi(cal_data->copy[k][i][j][10]);
          sum += num;
          count++;
          if (max < num)
            max = num;
          if (min > num)
            min = num;
          SSANMUL = 0;
        }

        else if (cal_data->copy[k][i][j][7] == doso_me && stoi(cal_data->copy[k][i][j][6]) >= 512 && stoi(cal_data->copy[k][i][j][6]) <= 535 && sanmul == "1")
        {
          num = stoi(cal_data->copy[k][i][j][10]);
          sum += num;
          count++;
          if (max < num)
            max = num;
          if (min > num)
            min = num;
          SSANMUL = 1;
        }

        else if (cal_data->copy[k][i][j][7] == doso_me && stoi(cal_data->copy[k][i][j][6]) >= 611 && stoi(cal_data->copy[k][i][j][6]) <= 644 && sanmul == "2")
        {
          num = stoi(cal_data->copy[k][i][j][10]);
          sum += num;
          count++;
          if (max < num)
            max = num;
          if (min > num)
            min = num;
          SSANMUL = 2;
        }
      }
    }
  }
  if (doso_me == "6")
  {
    cout << " | 도매가 기준 검색" << endl;
  }
  else if (doso_me == "7")
  {
    cout << " | 소매가 기준 검색" << endl;
  }
  if (SSANMUL == 0)
  {
    SSANAME = "농산물";
  }
  else if (SSANMUL == 1)
  {
    SSANAME = "축산물";
  }
  else if (SSANMUL == 2)
  {
    SSANAME = "수산물";
  }
  cout << " | \""
       << "연간 " << SSANAME << "\" 가격 평 균 : " << sum / count << " , 최댓값 : " << max << " , 최솟값 : " << min << endl;
}

void Product::Cal(string &ch, string &doso_me, int choiceint, string &prod1, string &prod2)
{
  Check1 = false;
  Check2 = false;
  max = 0;
  max2 = 0;
  min = 10000000;
  min2 = 10000000;
  count = 0;
  count2 = 0;
  sum = 0;
  sum2 = 0;

  for (int k = 0; k < cal_data->copy.size(); k++)
  {
    for (int i = 0; i < cal_data->copy[k].size(); i++)
    {
      for (int j = 0; j < cal_data->copy[k][i].size(); j++)
      {
        if (cal_data->copy[k][i][j][7] == doso_me && cal_data->copy[k][i][j][5] == prod1)
        {
          Check1 = true;
          num = stoi(cal_data->copy[k][i][j][10]);
          sum += num;
          count++;
          if (max < num)
            max = num;
          if (min > num)
            min = num;
        }
        else if (cal_data->copy[k][i][j][7] == doso_me && cal_data->copy[k][i][j][5] == prod2)
        {
          Check2 = true;
          num2 = stoi(cal_data->copy[k][i][j][10]);
          sum2 += num2;
          count2++;
          if (max2 < num2)
            max2 = num2;
          if (min2 > num2)
            min2 = num2;
        }
      }
    }
  }

  if (doso_me == "6")
  {
    cout << " | 도매가 기준 검색" << endl;
  }
  else if (doso_me == "7")
  {
    cout << " | 소매가 기준 검색" << endl;
  }

  if (Check1)
  {
    cout << " | \"" << prod1 << "\" 가격 평 균 : " << sum / count << " , 최댓값 : " << max << " , 최솟값 : " << min << endl;
  }
  else if (!Check1)
  {
    cout << " | \"" << prod1 << "\" 일치하는 결과가 없습니다.\n";
  }

  if (Check2)
  {
    cout << " | \"" << prod2 << "\" 가격 평 균 : " << sum2 / count2 << " , 최댓값 : " << max2 << " , 최솟값 : " << min2 << endl;
  }
  else if (!Check2)
  {
    cout << " | \"" << prod2 << "\" 일치하는 결과가 없습니다.\n";
  }
}

void Cheap::Cal(string &doso_me, string &prod)
{
  Check1 = false;
  min = 1000000;
  for (int k = 0; k < cal_data->copy.size(); k++)
  {
    for (int i = 0; i < cal_data->copy[k].size(); i++)
    {
      for (int j = 0; j < cal_data->copy[k][i].size(); j++)
      {
        if (cal_data->copy[k][i][j][7] == doso_me && cal_data->copy[k][i][j][5] == prod)
        {
          Check1 = true;
          num = stoi(cal_data->copy[k][i][j][10]);
          if (min > num)
          {
            min = num;
            cheaper = cal_data->copy[k][i][j][3];
            cheap_price = cal_data->copy[k][i][j][10];
          }
        }
      }
    }
  }

  if (doso_me == "6")
  {
    cout << " | 도매가 기준 검색" << endl;
  }
  else if (doso_me == "7")
  {
    cout << " | 소매가 기준 검색" << endl;
  }

  if (Check1)
  {
    cout << " | 가장 저렴한 시장 : " << cheaper << endl;
    cout << " | 가격: " << cheap_price << endl;
  }
  else if (!Check1)
  {
    cout << " | \"" << prod << "\" 일치하는 결과가 없습니다.\n";
  }
}

void handler::spread(Calculator *All_data, Mon *nn, RegionMarket *Rm, Product *pro, Type *tt, Cheap *cc)
{
  string str1, str2, prod, prod1, prod2, doso, sanmul;
  int entermonth1, entermonth2, want = 0;
  int enteryear = 0;
  void call();
  cout << "조건 입력" << endl;
  cout << "0)월   1)지역   2)시장  3)상품  4)농/축/수  5)물품중 가장 저렴한 시장\n";
  cin >> want;
  cin.get();
  cout << "도소매 입력 (6, 7)" << endl;
  cin >> doso;
  cin.get();
  if (want == 0)
  {
    cout << "원하시는 년도를 골라주세요.\n 0) 2013 \t 1) 2022\n";
    cin >> enteryear;
    cin.get();
    cout << "원하시는 월을 입력해주세요: ";
    cin >> entermonth1;
    cin.get();
    cout << entermonth1 << "월을 입력했습니다.\n";
    cout << "비교하실 월을 입력해주세요: ";
    cin >> entermonth2;
    cin.get();
    cout << entermonth2 << "월을 입력했습니다.\n";
    cout << "상품 입력: ";
    getline(cin, prod1);
    nn->Cal(str1, doso, want, prod1, entermonth1, entermonth2, enteryear);
  }
  else if (want == 1)
  {
    cout << "지역 입력: ";
    getline(cin, str1);
    cout << str1 << "을 입력했습니다.\n";
    cout << "비교 지역 입력: ";
    getline(cin, str2);
    cout << str2 << "을 입력했습니다.\n";
    cout << "상품 입력: ";
    getline(cin, prod1);
    Rm->Cal(str1, str2, doso, want, prod1);
  }
  else if (want == 2)
  {
    cout << "시장 입력: ";
    getline(cin, str1);
    cout << str1 << "을 입력했습니다.\n";
    cout << "비교 시장 입력: ";
    getline(cin, str2);
    cout << str2 << "을 입력했습니다.\n";
    cout << "상품 입력: ";
    getline(cin, prod1);
    Rm->Cal(str1, str2, doso, 3, prod1);
  }
  else if (want == 3)
  {
    cout << "상품 입력: ";
    getline(cin, prod1);
    cout << "비교 상품 입력: ";
    getline(cin, prod2);
    pro->Cal(str1, doso, 5, prod1, prod2);
  }
  else if (want == 4)
  {
    cout << " 0) 농산물      1)축산물        2)수산물" << endl;
    getline(cin, sanmul);
    tt->Cal(doso, 6, sanmul);
  }
  else if (want == 5)
  {
    cout << "검색할 물품을 입력하세요 :";
    getline(cin, prod);
    cc->Cal(doso, prod);
  }
}
