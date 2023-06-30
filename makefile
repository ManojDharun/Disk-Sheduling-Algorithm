res.exe:ex12Imp.o ex12App.o
                c++ ex12Imp.o ex12App.o -o res.exe
ex12Imp.o:ex12Imp.c++
                c++ -c ex12Imp.o
ex12App.o:ex12App.c++
                c++ -c ex12App.o
