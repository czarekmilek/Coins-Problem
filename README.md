# **Monety-AiSD**
## Pracownia C
---

> Dostępna pamięć: 32 MB

W pudełku znajduje się pewna liczba monet o sumarycznej masie 𝐹 gramów. Czy można bez otwierania pudełka stwierdzić, ile warte są pieniądze w środku?

Przykładowo załóżmy, że dostępne na rynku monety to moneta 1-groszowa ważąca 1 gram oraz moneta 30-groszowa ważąca 50 gramów, zaś całość waży 𝐹 = 100 gramów. Wtedy minimalna możliwa wartość monet w pudełku to 60 groszy (2 monety 30-groszowe), zaś maksymalna — 100 groszy (100 monet jednogroszowych).

## Specyfikacja danych wejściowych
W pierwszym wierszu wejścia znajduje się dodatnia liczba całkowita 𝐹 ⩽ 106, będąca sumaryczną masą monet w pudełku w gramach. W drugim wierszu wejścia znajduje się dodatnia liczba całkowita 𝐶 ⩽ 100, będąca liczbą dostępnych na rynku monet. 

W każdym z kolejnych 𝐶 wierszy wejścia znajduje się opis 𝑖-tej monety, gdzie 𝑖 ∈ {1, . . . , 𝐶}. Opis monety jest parą dodatnich liczb całkowitych oddzielonych spacją: 𝑝𝑖 ⩽ 105 będąca nominałem w groszach i 𝑤𝑖 ⩽ 105 będąca wagą w gramach. Może istnieć wiele monet o takim samym nominale, ale różnych wagach i wiele monet o takiej samej wadze, ale różnych nominałach.

## Specyfikacja danych wyjściowych
Pierwszy wiersz wyjścia powinien zawierać słowo TAK, jeśli masa 𝐹 jest możliwa do uzyskania za pomocą dostępnych na rynku monet, zaś słowo NIE w przeciwnym przypadku.

W przypadku odpowiedzi pozytywnej Twój program powinien wypisać cztery dodatkowe wiersze.W drugim wierszu wyjścia powinna znajdować się wtedy liczba $𝑃_{min}$, będąca możliwą sumaryczną minimalną wartością monet (w groszach) znajdujących się w pudełku. Trzeci wiersz wyjścia powinien zawierać opis uzyskania wartości 𝑃min: 𝐶 liczb naturalnych 𝑥1, 𝑥2, . . . , 𝑥𝐶 oddzielonych pojedynczymi spacjami, oznaczających że 𝑖-tą monetę bierzemy 𝑥𝑖 razy, tzn. spełniających warunki ${\sum}^𝐶_{𝑖=1}$𝑥𝑖 · 𝑝𝑖 = $𝑃_{min}$ oraz ${\sum}^𝐶_{𝑖=1}$ 𝑥𝑖 · 𝑤𝑖 = 𝐹.

W czwartym wierszu wyjścia powinna znajdować się liczba $𝑃_{max}$ będąca możliwą sumaryczną maksymalną wartością monet w pudełku, zaś piąty wiersz powinien zawierać opis uzyskania $𝑃_{max}$ w identycznym formacie jak w przypadku wiersza trzeciego.

Jeśli istnieje wiele możliwych sposobów uzyskania wartości $𝑃_{min}$ lub $𝑃_{max}$, Twój program powinien opisać dowolną z nich.

---
### Przykład A
#### Wejście:
```
100
2
1 1
30 50
```
#### Wyjście:
```
TAK
60
0 2
100
100 0
```
---
### Przykład B
#### Wejście:
```
10
3
1 1
2 4
4 16
```
#### Wyjście:
```
TAK
6
2 2 0
10
10 0 0
```
---
### Przykład C
#### Wejście:
```
5
3
1 2
1 4
2 4
```
#### Wyjście:
```
NIE
```
