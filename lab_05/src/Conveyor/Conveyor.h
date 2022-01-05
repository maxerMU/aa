#ifndef SRC_CONVEYOR_H
#define SRC_CONVEYOR_H
#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
#define th 8
template <typename type> class SafeQueue {
public:
  void push(type val);
  void pop();
  bool empty();
  type front();

private:
  std::queue<type> q;
};
class Cookies {
public:
  void calcButter(int num, int deg);
  void calcFlour(long n);
  void calcEgg(int n);

private:
  int eggs;
  int flour;
  int butter;
};
typedef struct {
  unsigned long long system_time;
  unsigned long long proc_time;
  unsigned long long task1_time;
  unsigned long long task2_time;
  unsigned long long task3_time;
  unsigned long long start_time;
} task_stats_t;
typedef enum {
  TASK_1_STARTED,
  TASK_1_ENDED,
  TASK_2_STARTED,
  TASK_2_ENDED,
  TASK_3_STARTED,
  TASK_3_ENDED
} event_t;
class Conveyor {
public:
  Conveyor();
  ~Conveyor();
  void run_par(size_t count, task_stats_t *stats);
  void run_seq(size_t count);
  std::vector<std::string> get_logs();

private:
  void log_current_event(size_t task_num, task_stats_t *stats, event_t event);
  void calcButter();
  void calcFlour();
  void calcEgg();
  std::vector<std::shared_ptr<Cookies>> cookies;
  std::thread threads[th];
  SafeQueue<std::shared_ptr<Cookies>> q1;
  SafeQueue<std::shared_ptr<Cookies>> q2;
  SafeQueue<std::shared_ptr<Cookies>> q3;
  task_stats_t *stats;
  std::vector<std::string> logs;
  bool first_working = true;
  bool second_working = true;

  char *buf;
};

#endif // SRC_CONVEYOR_H
