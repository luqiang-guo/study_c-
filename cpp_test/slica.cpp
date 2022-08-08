#include <iostream>
#include <vector>
#include<memory>
#include <limits>


class Slice {
 public:
  Slice() : Slice(0, std::numeric_limits<int64_t>::max(), 1) {std::cout << "Slice()" << std::endl;}
  explicit Slice(int64_t start) : Slice(start, std::numeric_limits<int64_t>::max(), 1) 
  {std::cout << "Slice(int64_t start)" << std::endl;}
  explicit Slice(int64_t start, int64_t end) : Slice(start, end, 1) {}
  explicit Slice(int64_t start, int64_t end, int64_t step)
      : start_(start), end_(end), step_(step) {std::cout << "Slice(int64_t start, int64_t end, int64_t step)" << std::endl;}

  int64_t start() const { return start_; }
  int64_t end() const { return end_; }
  int64_t step() const { return step_; }

 private:
  int64_t start_;
  int64_t end_;
  int64_t step_;
};

int main()
{
    // Slice * a = new Slice();
    // Slice b{};

    Slice* p = new Slice[1](); 

    // Slice z(0, 1, 2);
    return 0;
}