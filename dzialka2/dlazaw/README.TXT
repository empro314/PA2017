Biblioteczka dla zawodnika do zadania Działka 2 (v. 1.1)
----------------------------------------------------------

To archiwum zawiera pliki przydatne do lokalnego testowania zadania Działka 2.
Zawartość:

  * dzialka.h, dzialka.c - kod źródłowy lokalnej biblioteki testującej;
  * dzi0.in - plik opisujący test przykładowy wymieniony w treści zadania;
  * dzi_wrong.cpp - przykładowe (błędne) rozwiązanie zadania.

Aby skompilować program (dla przykładu, dzi.cpp) z biblioteką, pliki
  biblioteczki powinny znajdować się razem z kompilowanym programem.
Zakładamy, że alias 'rpa' wskazuje na program uruchamiający lokalną
  infrastrukturę testującą (dokładne zasady konfiguracji opisane
  są na stronie PA, http://potyczki.mimuw.edu.pl/l/36/).
Należy wydać komendę:

  rpa build --source dzi.cpp --library dzialka.c

Skompilowany program wczytuje test ze standardowego wejścia. Format jest
  intuicyjny; dla przykładu, plansza o 3 wierszach i 7 kolumnach zawierających
  11 używalnych kwadracików jednostkowych w kształcie szachownicy tworzyłaby
  następujący plik:

3 7
1010101
0101010
1010101

Uwaga: ta implementacja biblioteczki wczytuje mapę działki do każdej instancji
  programu. Należy uważać na możliwość przekroczenia pamięci dostępnej
  na Twoim systemie operacyjnym.
