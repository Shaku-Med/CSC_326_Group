#ifndef WASHING_H
#define WASHING_H
//
//
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

class bool_source
{
public:
  bool_source(double p = 0.5);
  bool query() const;

private:
  double probability;
};

class averager
{
public:
  averager();
  void next_number(double value);
  size_t how_many_numbers() const { return count; }
  double average() const;

private:
  size_t count;
  double sum;
};

class washer
{
public:
  washer(unsigned int s = 60);
  void one_second();
  void start_washing();
  bool is_busy() const { return (wash_time_left > 0); }

private:
  unsigned int seconds_for_wash;
  unsigned int wash_time_left;
};

#endif