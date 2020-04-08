    Balan Giorgana-Lavinia
            331CB


    I. Pentru primul task am folosit o dimensiune de 1200 pentru matrici.
Timpii obtinuti pentru varianta clasica(fara optimizari) si pentru cele doua 
optimizari legate de detectarea constantelor din bucle si accesul la vectori sunt :
    lavinia@ubuntu:~/Documents/ASC/lab5$ ./ex1 
    Classic mode: = 12.257664 
    Detectarea constantelor din bucle: = 8.939255 
    Accesul la vectori: = 8.161689 


    II. Task 2: Ordinea buclelor
lavinia@ubuntu:~/Documents/ASC/lab5$ ./ex2
i-j-k: = 12.359072      4.
i-k-j: = 6.520349       2. 
j-i-k: = 11.430285      3.
j-k-i: = 36.577699      6.
k-i-j: = 6.304239       1. 
k-j-i: = 36.264329      5.


    III. Task3: Optimizari pentru Cache -> dimensiune=1200

Multiply matrices 10 times for blocsize = 25...
Time = 89.075677 

Multiply matrices 10 times for blocksize = 50...
Time = 92.121164 

Multiply matrices 10 times for blocksize = 10...
Time = 92.201851 

Multiply matrices 10 times for blocksize = 60...
Time = 90.906061 

Multiply matrices 10 times for blocksize = 120...
Time = 95.671895 

Multiply matrices 10 times for blocksize = 40...
Time = 90.432110 

Multiply matrices 10 times for blocksize = 20...
Time = 88.874408                                    <- optim

Multiply matrices 10 times for blocksize = 100...
Time = 98.573532 




    IV.Bonus: alocare matrici ca vectori de vectori

Multiply matrices 10 times for blocksize = 100...
Time = 105.846368 

Multiply matrices 10 times for blocksize = 50...
Time = 89.002968 

Multiply matrices 10 times for blocksize = 30...
Time = 88.453155 

Multiply matrices 10 times for blocksize = 40...
Time = 91.151480 

Multiply matrices 10 times for blocksize = 200...
Time = 103.974110 

Multiply matrices 10 times for blocksize = 20...
Time = 87.372094                                    <- cel mai optim

Multiply matrices 10 times for blocksize = 60...
Time = 92.314139 

Multiply matrices 10 times for blocksize = 120...
Time = 99.301692 

Multiply matrices 10 times for blocksize = 10...
Time = 91.895830 