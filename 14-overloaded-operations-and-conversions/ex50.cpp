struct LongDouble
{
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

int main()
{
  LongDouble ld;
  int ex1 = ld;
  float ex2 = ld;
}