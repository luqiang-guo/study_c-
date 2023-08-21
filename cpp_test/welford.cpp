void welford(const float *input_ptr, int num, float &mean, float &var) {
  int n = 0;
  float m2 =  0;
  
  mean = 0;
  for(int i = 0; i < num; i++)
  {
    n = i + 1;
    float delta  = input_ptr[i] - mean;
    float new_mean = mean + delta / n;
    float new_delta = input_ptr[i] - new_mean;
    m2 += delta * new_delta;
    mean = new_mean;
  }
  var = m2 / n;
}
