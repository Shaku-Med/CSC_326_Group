#include <cstdlib>
#include <iostream>
#include <queue>
#include "washing.h"

using namespace std;

void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time)
{
  queue<unsigned int> arrival_times; // Waiting customers’ time stamps
  queue<unsigned int> start_times;   // When each car starts being washed
  bool_source arrival(arrival_prob);
  washer car_wash(wash_time);
  averager wait_times;
  unsigned int current_second;

  cout << "\nSeconds to wash one car: " << wash_time << endl;
  cout << "Probability of customer arrival during a second: ";
  cout << arrival_prob << endl;
  cout << "Total simulation seconds: " << total_time << endl;

  for (current_second = 1; current_second <= total_time; ++current_second)
  {

    if (arrival.query())
    {
      arrival_times.push(current_second);
    }

    if (!car_wash.is_busy() && !arrival_times.empty())
    {
      unsigned int arrival_time = arrival_times.front();
      arrival_times.pop();
      wait_times.next_number(current_second - arrival_time);
      car_wash.start_washing();
      start_times.push(current_second);

      // Output information about the car being washed.
      cout << "\nThis is Car number " << wait_times.how_many_numbers() << endl;
      cout << "The car arrived at " << arrival_time << " seconds" << endl;
      cout << "The wait time is " << current_second - arrival_time << " seconds" << endl;
      cout << "The time when it ends is " << current_second + wash_time << " seconds" << endl;
    }

    car_wash.one_second();
  }
  cout << "\nCustomers served: " << wait_times.how_many_numbers() << endl;
  if (wait_times.how_many_numbers() > 0)
    cout << "Average wait: " << wait_times.average() << " sec" << endl;
}

int main()
{
  int wash_time;
  double arrival_prob;
  int total_time;

  cout << "Enter wash time in seconds: " << endl;
  cin >> wash_time;

  cout << "Enter arrival probability(0 <- p <- 1): " << endl;
  cin >> arrival_prob;

  cout << "Enter total time of simulation: " << endl;
  cin >> total_time;

  car_wash_simulate(wash_time, arrival_prob, total_time);

  return 0;
}