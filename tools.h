#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <stdio.h>

class RangeIterator
{
    public:
      int max;
      int count;
      bool loop;
      RangeIterator();
      RangeIterator(int, bool);
      void inc(int);
      void dec(int);
      void _calcChange();
      int get();
};

class StringIterator : public RangeIterator
{
    std::vector<std::string> liste;

    public:
      StringIterator(std::vector<std::string>, bool);
      void next();
      void prev();
      int getCentralNo();
      std::string getCentral();
      std::string getLeft();
      std::string getRight();
      std::vector<std::string> getList();
      int _getCentralIndex();
};

class FlipSwitch
{
    bool value;

    public:
      FlipSwitch(bool valueIn);
      bool flip();
      bool get();
};


#endif

