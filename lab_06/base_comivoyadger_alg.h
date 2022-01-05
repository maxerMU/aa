#ifndef BASE_COMIVOYADGER_ALG_H
#define BASE_COMIVOYADGER_ALG_H

class base_comivoyadger_alg {
public:
  base_comivoyadger_alg() = default;
  ~base_comivoyadger_alg() = default;

  virtual double find_shortest_way() = 0;
  double algorithm_time();
};

#endif // BASE_COMIVOYADGER_ALG_H
