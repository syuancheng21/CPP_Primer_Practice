

int main() {
  char a1[] = {'c', '+', '+'};
  char a2[] = {'c', '+', '+', '\0'};
  char a3[] = "c++";
  const char a4[6] = "Daniel"; //错误： 没有空间存放空字符
  const char a5[7] = "Daniel"; //正确
}