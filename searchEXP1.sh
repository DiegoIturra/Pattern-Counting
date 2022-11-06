g++ search.cpp SuffixArray.cpp fmindex.cpp KMP.cpp -o SE.out
echo "search KMP" | tee ResultadosSE1.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE1.csv
for i in {100000..1000000..100000}
do
	./SE.out 30 $i 100 0 | tee -a ResultadosSE1.csv
done
echo "search SuffixArray" | tee -a ResultadosSE1.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE1.csv
for i in {100000..1000000..100000}
do
	./SE.out 30 $i 100 1 | tee -a ResultadosSE1.csv
done
echo "search FMIndex" | tee -a ResultadosSE1.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE1.csv
for i in {100000..1000000..100000}
do
	./SE.out 30 $i 100 2 | tee -a ResultadosSE1.csv
done