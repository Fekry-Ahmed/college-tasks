/*
 * utils.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef UTILS_H_
#define UTILS_H_

using namespace std;

#include <iostream>
#include <vector>

////////////////////////// Utilities //////////////////////////
int read_int(int low, int high, bool cancel_choice_allowed = false)
{ // Added parameter. Respect backward compatibility
  if (!cancel_choice_allowed)
    cout << "\nEnter number in range " << low << " - " << high << ": ";
  else
    cout << "\nEnter -1 to cancel or number in range " << low << " - " << high << ": ";

  int value;

  cin >> value;

  if (cancel_choice_allowed && value == -1)
    return value;

  if (low <= value && value <= high)
    return value;

  cout << "ERROR: invalid number...Try again\n";
  return read_int(low, high);
}

int show_read_menu(const vector<string> &choices, string header = "Menu")
{ // Added parameter. Respect backward compatibility
  cout << "\n"
       << header << ":\n";

  for (int ch = 0; ch < (int)choices.size(); ++ch)
  {
    cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
  }
  return read_int(1, choices.size());
}

vector<string> split_tring(string s, string delimiter = ",")
{
  vector<string> strs;

  int pos = 0;
  string substr;
  while ((pos = (int)s.find(delimiter)) != -1)
  {
    substr = s.substr(0, pos);
    strs.push_back(substr);
    s.erase(0, pos + delimiter.length());
  }
  strs.push_back(s);
  return strs;
}

#endif /* UTILS_H_ */
