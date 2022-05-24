# QuickSort

Porównanie strategii wyboru elementu osiowego w Quicksort

Zadanie polega na porównaniu różnych strategii wyboru elementu osiowego w sortowaniu szybkim. Należy rozważyć:

· wybór elementu skrajnego;

· wybór pseudolosowy;

· wybór mediany z 3, 5 oraz 7 elementów;

Badanie proszę przeprowadzić dla tablic o rosnących rozmiarach od 10 000 do 1000 000 elementów (co 10 000) i trzech przypadków ich wypełniania:

· elementami pseudolosowymi z zakresu przekraczającego rozmiar tablicy;

· elementami pseudolosowymi z zakresu 0..99;

· elementami uporządkowanymi niemalejąco.

Całość należy opisać w raporcie uwzględniając zarówno opis implementacji, jak i sposobu generowania danych, pomiaru czasu oraz analizę otrzymanych rezultatów.

Dodatkowo rozważyć i przetestować poprawkę w funkcji partition, która w wypadku wyrazów tabeli równych pivotowi raz dokonuje zamiany, a raz nie (losowo lub deterministycznie).
