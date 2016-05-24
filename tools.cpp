#include <iostream>
#include <stdio.h>
#include <vector>
#include "tools.h"

// --- RangeIterator -------------------------------------------------------------------------

RangeIterator::RangeIterator()
{
    count = 0;
}

RangeIterator::RangeIterator(int valueInd, bool loopInd)
{
    max = valueInd;
    count = 0;
    loop = loopInd;
}

void RangeIterator::inc(int countInc = 1)
{
    count += countInc;
    _calcChange();
}

void RangeIterator::dec(int countDec = 1)
{
    count -= countDec;
    _calcChange();
}

void RangeIterator::_calcChange()
{
    if (count > max)
    {
      if (loop)
        count = count - max - 1;
      else
        count = max;
    }
    if (count < 0)
    {
      if (loop)
        count = count + max + 1;
      else
        count = 0;
    }
}

int RangeIterator::get()
{
    return count;
}

// --- StringIterator -------------------------------------------------------------------------

StringIterator::StringIterator(std::vector<std::string> listeIn, bool LoopInd) : RangeIterator()
{
    max = listeIn.size() - 1;
    liste = listeIn;
    loop = true;
}

int StringIterator::getCentralNo()
{
  return count;
}

std::string StringIterator::getCentral()
{
  return liste[count];
}

std::string StringIterator::getLeft()
{
  return liste[count - 1];
}

std::string StringIterator::getRight()
{
  return liste[count + 1];
}

std::vector<std::string> StringIterator::getList()
{
  return liste;
}

// Returns the index of the middle, focused string
int StringIterator::_getCentralIndex()
{
  if (liste.size() % 2)
    return liste.size() / 2;
  else
    return (liste.size() / 2) - 1;
}

// --- FlipSwitch ----------------------------------------------------------------------------

FlipSwitch::FlipSwitch(bool valueIn = true)
{
    value = valueIn;
}

bool FlipSwitch::flip()
{
    if (value == true)
      value = false;
    else
      value = true;
    return 1;
}

bool FlipSwitch::get()
{
    return value;
}

