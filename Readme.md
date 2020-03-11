# Fila de substrings

Escreva uma função que transforme uma string em uma fila de substrings. As substrings estão separadas por algum caractere delimitador dentro da string. Sua função está declarada assim:

```C++
void separa(string algo, char sep, queue<string> & q);
```

* O parâmetro *algo* é a string a ser separada em substrings. 
* O parâmetro *sep* é o caractere delimitador a ser usado para separar as substrings. 
* Por fim, as substrings devem ser enfileiradas na fila *q* na mesma ordem em que aparecem na string.