# DELETED CODES

```c++


void car_wash_simulate(unsigned int wash_time, double arrival_prob,
                       unsigned int total_time) {
  cout << "\nIt takes " << wash_time << " seconds to wash a car "
       << "(" << wash_time / 60 << " mins)" << endl;
  cout << "The probability of a customer arriving during a second is "
       << arrival_prob << "." << endl;
  cout << "The total time that the car wash is going to be open is "
       << total_time << " seconds "
       << "(" << total_time / 60 << " minutes and " << total_time % 60
       << " seconds)." << endl;

  bool_source arrival(arrival_prob);
  averager wait_times;
  washer car_wash(wash_time);

  queue<unsigned int> waiting_customers;

  unsigned int current_second = 0;
  unsigned int num_served = 1;

  while (current_second <= total_time) {
    // arrival_time = arrival.query();
    current_second = rand() % 20;
    if (arrival.query()) {
      waiting_customers.push(current_second);
    }
    // unsigned int
    int wash = rand() % (wash_time - 10 +1 );
    if (!car_wash.is_busy() && !waiting_customers.empty()) {
      car_wash.start_washing();
      cout << "\nThe car arrived at second " << current_second << endl;
      wait_times.next_number(wash - waiting_customers.front());
      cout << "The wait time is " << wash - waiting_customers.front()
           << " seconds." << endl;
      cout << "The time when it ends is " << wash + wash_time << "\n"
           << endl;
      waiting_customers.pop();
      ++num_served;
    }

    car_wash.one_second();
    ++current_second;
  }

// while (!waiting_customers.empty()) {
//   wait_times.next_number(current_second - waiting_customers.front());
//   waiting_customers.pop();
//   ++num_served;
// }

void car_wash_simulate(unsigned int wash_time, double arrival_prob,
                       unsigned int total_time) {
  cout << "Simulation Parameters:\n";
  cout << "It takes " << wash_time << " seconds to wash one car.\n";
  cout << "Probability of a customer arriving during a second is "
       << arrival_prob << ".\n";
  cout << "Total simulation time: " << total_time << " seconds.\n";

  bool_source arrival(arrival_prob);
  averager wait_times;
  washer car_wash(wash_time);

  queue<unsigned int> waiting_customers;

  unsigned int current_second = 0;
  unsigned int num_served = 0;

  while (current_second < total_time) {
    if (arrival.query()) {
      waiting_customers.push(current_second);
    }

    if (!car_wash.is_busy() && !waiting_customers.empty()) {
      unsigned int customer_arrival_time = waiting_customers.front();
      waiting_customers.pop();
      car_wash.start_washing();
      unsigned int wait_time = current_second - customer_arrival_time;
      wait_times.next_number(wait_time);
      cout << "The wait time is " << wait_time << endl;

      cout << " The time when it ends is " << current_second << endl;
      num_served++;
    }

    car_wash.one_second();
    current_second++;
  }

  cout << "Total customers served: " << num_served << endl;
  cout << "Average waiting time: " << wait_times.average() << " seconds."
       << endl;
}

 if (num_served > 0)
   wait_times.next_number((total_time - 1));

 cout << "Customers Served: " << wait_times.how_many_numbers() << endl;
 cout << "Average waiting time in seconds: " << wait_times.average() <<
 endl;

```