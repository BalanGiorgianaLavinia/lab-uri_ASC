Balan Giorgiana-Lavinia
    331CB


->Task1a
    Am incercat cu mai multe valori pentru numarul de elemente al vectorului 
declarat global si am observat ca de la valori de 600.000.000 procesul este 
omorat de sistem.

->Task1b
    Nu am reusit sa aloc pe stiva un vector de tipul structurii particle 
cu mai mult de 2.700.000 de elemente deoarece primesc segmentation fault pentru 
mai mult. Dimensiunea stivei este de 8MB.

->Task1c
    Laptopul meu are 8 GB ram, deci procesul considera ca are la dispozitie 
aproape 8GB - dimensiunea stivei - ce ocupa kernelul.

->Task2
    Folosind o matrice liniarizata am descoperit cum pot sa parcurg elementele 
folosind un pointer. Fiecare linie are n structuri cu cate 3 * int8_t.

->Task3
    Am observat ca intre campurile din structura pot ramane spatii libere in 
memorie deoarece nu sunt aliniate. Dimensiunile structurilor sunt mai mari decat 
dimensiunile campurilor componente adunate(se adauga padding).

->Task4
    In imaginea L1 se gaseste plotul care ilustreaza dimensiunea cacheului L1. 
In grafic se observa ca performanta incepe sa scada cam de pe la 32K, care 
este fix dimensiunea cacheului L1 al procesorului meu.

-> Task5
    Din graficul L3 se observa ca linia este fix pe valoarea 512K, adica
dimensiunea cache-ului L3 din procesor.