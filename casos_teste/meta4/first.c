int main(void)
{
  char i = 'A';
  int a = 10;

  while (i <= 'Z')
  {
    putchar(i);
    i = i + 1;
  }
  putchar('\n');

  putchar('\n');

  if (a)
    putchar('T');
  else
    putchar('F');

  putchar('\n');
  return 0;
}
