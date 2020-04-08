Balan Giorgiana-Lavinia
	331CBb
	Laborator 6


Task 1: -pe fep.grid.pub.ro
		
		Secvential:		Paralel:

-end = 4.000:	real	0m0.006s	real	0m0.016s
		user	0m0.005s	user	0m0.353s

-end = 40.000:	real	0m0.183s	real	0m0.061s
		user	0m0.178s	user	0m1.475s

-end = 100.000:	real	0m0.859s	real	0m0.117s
		user	0m0.853s	user	0m2.177s

-end = 200.000:	real	0m3.216s	real	0m0.393s
		user	0m3.210s	user	0m8.090s

-end = 300.000:	real	0m6.964s	real	0m0.642s
		user	0m6.951s	user	0m13.935s

-end = 400.000:	real	0m12.197s	real	0m0.958s
		user	0m12.194s	user	0m21.355s

	La marirea limitei finale se dubleaza timpul de executie in cazul 
	procesarii secventiale. In cazul de executie paralela, pentru un 
	numar de 4000 de elemente timpul este chiar mai mare decat secvential,
	dar pentru numere mai mari se observa o scadere accentuata a timpului 
	de rulare paralel fata de secvential.


Task 2:
	Solaris Studio:

Secvential:
		Am observat ca instructiunea cea mai costisitoare este 
"if (n % i == 0)" (din functia TestForPrime) care se executa intr-o bucla.
		In assembly se observa ca instructiunea movl %edx, %eax ia cel
mai mult timp din functia TestForPrime() -> 9.126s. De aici putem trage concluzia
ca programul este memory bound.

Paralel:
		Si in acest caz programul petrece cel mai mult timp in functia 
TestForPrime(), si anume 20.785s.
		Spre deosebire de cel secvential, in tabul timeline se observa
cum sunt distribuite thread-urile in timp. Acestea nu ruleaza in ordine asa cum 
ne-am astepta.
		Fiind acelasi cod care se executa, instructiunea "if (n % i == 0)"
dureaza 17.652s, cel mai mult dintre restul instructiunilor.
		Acelasi lucru ca mai sus se intampla si cand ma uit in codul assembly

Task 3:
	Codul secvential ruleaza in 20.237 secunde. Se observa ca prima data este
partea secventiala deoarece se calculeaza linie cu linie de jos in sus imaginea.
	Codul paralel ruleaza in 11.432 secunde. Aici imaginea este completata
aleator cu linii.

Task 4:
	Folosind Solaris Studio se observa faptul ca functiile
sphere_intersect, grid_intersect si render_one_pixel sunt cele care ocupa cel mai mult timp
pe procesor:

Secvential:

	Exclusive        Inclusive        
	Total CPU Time   Total CPU Time   Name
	sec.             sec.             
	 8.436           14.450           render_one_pixel(int, int, unsigned int*, unsigned int&, int, int, int, int).isra.1
	 3.342            5.884           grid_intersect(grid*, ray*)
	 2.422            2.422           sphere_intersect(sphere*, ray*)

Paralel:

	Exclusive        Inclusive        
	Total CPU Time   Total CPU Time   Name
	sec.             sec.             
	 5.494            9.286           grid_intersect(grid*, ray*)
	 3.583            3.583           sphere_intersect(sphere*, ray*)	   
	 0.020            9.567           render_one_pixel(int, int, unsigned int*, unsigned int&, int, int, int, int).isra.1


	Deoarece codul paralelizat este distribuit pe mai multe core-uri functia render_one_pixel
dureaza mai putin overall fata de varianta secventiala. De asemenea, acelasi lucru il pot
spune si despre celelalte doua functii grid_intersect si sphere_intersect.

Task 5:

	Ruland KCachegrind am observat acelasi lucru: cel mai mult timp este petrecut in
functia render_one_pixel la accesarea elementelor din vector (ceea ce implica lucrul cu
memoria -> memory bound), dar si in if-ul "if((iteration_count % 3) == 0)". Aceleasi lucruri
le-am observat in ambele coduri: secvential si paralel.


