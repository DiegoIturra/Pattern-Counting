g++ search.cpp SuffixArray.cpp fmindex.cpp KMP.cpp -o SE.out
echo "search KMP" | tee ResultadosSE2.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE2.csv
for i in {1000..10000..1000}
do
	./SE.out 30 1000000 $i 0 | tee -a ResultadosSE2.csv
done
echo "search SuffixArray" | tee -a ResultadosSE2.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE2.csv
for i in {1000..10000..1000}
do
	./SE.out 30 1000000 $i 1 | tee -a ResultadosSE2.csv
done
echo "search FMIndex" | tee -a ResultadosSE2.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE2.csv
for i in {1000..10000..1000}
do
	./SE.out 30 1000000 $i 2 | tee -a ResultadosSE2.csv
done