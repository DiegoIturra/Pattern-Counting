g++ Const.cpp SuffixArray.cpp fmindex.cpp KMP.cpp -o CE.out
echo "Construccion KMP" | tee ResultadosSE1.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE1.csv
for i in {10000..100000..10000}
do
	./CE.out 30 $i 0 0 | tee -a ResultadosCE.csv
done
echo "Construccion SuffixArray" | tee -a ResultadosSE1.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE1.csv
for i in {10000..100000..10000}
do
	./CE.out 30 $i 0 1 | tee -a ResultadosCE.csv
done
echo "Construccion FMIndex" | tee -a ResultadosSE1.csv
echo "Cantidad de caracteres en texto;Cantidad de caracteres de patron buscado;Tiempo promedio en milisegundos;Varianza en milisegundos al cuadrado;Espacio en bytes" | tee -a ResultadosSE1.csv
for i in {10000..100000..10000}
do
	./CE.out 30 $i 0 2 | tee -a ResultadosCE.csv
done