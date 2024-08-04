#ifndef wms
#define wms
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Data
{
public:
  vector<vector<vector<vector<string>>>> copy;

  void modifychoice(int years, int month, string &target_value, string &new_value);
  void modifydata();
  void Savedata(string &filename);
};

class Calculator
{
protected:
  bool Check1, Check2;
  int num, num2;
  int max, max2;
  int min, min2;
  long long int count;
  long long int count2;
  long long int sum;
  long long int sum2;

public:
  Data *cal_data;
  Calculator() {}
  Calculator(Data *address) : cal_data(address) {}
  virtual void Cal() {}
};

class Mon : public Calculator
{
public:
  Mon() {}
  Mon(Data *address) : Calculator(address) {}
  void Cal(string &ch, string &doso_me, int choiceint, string &prod, int month1, int month2, int year);
};

class RegionMarket : public Calculator
{
public:
  RegionMarket() {}
  RegionMarket(Data *address) : Calculator(address) {}
  void Cal(string &ch1, string &ch2, string &doso_me, int choiceint, string &prod);
};

class Type : public Calculator
{
public:
  Type() {}
  Type(Data *address) : Calculator(address) {}
  int SSANMUL;
  string SSANAME;
  void Cal(string &doso_me, int choiceint, string sanmul);
};

class Product : public Calculator
{
public:
  Product() {}
  Product(Data *address) : Calculator(address) {}
  void Cal(string &ch, string &doso_me, int choiceint, string &prod1, string &prod2);
};
class Cheap : public Calculator
{
  string cheaper;
  string cheap_price;

public:
  Cheap() {}
  Cheap(Data *address) : Calculator(address) {}

  void Cal(string &doso_me, string &prod);
};
class handler
{
public:
  void spread(Calculator *All_data, Mon *nn, RegionMarket *Rm, Product *pro, Type *tt, Cheap *cc);
};

#endif