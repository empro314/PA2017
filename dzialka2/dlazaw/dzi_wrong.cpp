// Błędne rozwiązanie do zadania Działka 2.
// Na pojedynczym węźle wypisuje liczbę dostępnych kwadracików.

#include "dzialka.h"
#include "message.h"

#include <iostream>

int main() {
  if (MyNodeId() > 0)
    return 0;

  const int NumRows = GetFieldHeight();
  const int NumCols = GetFieldWidth();

  long long Result = 0;
  for (int Row = 0; Row < NumRows; ++Row)
    for (int Col = 0; Col < NumCols; ++Col)
      if (IsUsableCell(Row, Col))
        ++Result;

  std::cout << Result << "\n";
}
